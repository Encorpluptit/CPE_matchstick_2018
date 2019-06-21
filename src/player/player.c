/*
** EPITECH PROJECT, 2019
** Matchstick
** File description:
** Manage Player turn.
*/

#include "essentials.h"
#include "matchstick.h"
#include "printf.h"
#include "get_next_line.h"
#include "check_inputs.h"
#include "globals.h"

static int player_line_select(void);
static int player_matches_select(int line);
static int player_move(int line, int entry, char *input);

int player_turn(void)
{
    int rt = 0;

    if (get_matches(NO, RETURN, NO) < 1)
        return IA_WIN;
    my_printf("Your turn:\n");
    do {
        if ((rt = player_line_select()) == FAILED_MALLOC) {
            my_printf("\n");
            return (CTRLD);
        }
    } while (rt != PLAYER_WIN);
    return (rt);
}

static int player_line_select(void)
{
    char *input = NULL;
    int line = 0;

    do {
        my_printf("Line: ");
        input = get_next_line(STDIN);
        if (!input)
            return FAILED_MALLOC;
        if (!check_input(input)) {
            my_printf("Error: invalid input (positive number expected)\n");
            continue;
        }
        if (line_range(input)) {
            my_printf("Error: this line is out of range\n");
            continue;
        }
    } while (!authorised_line(input));
    line = my_atoi(input);
    return (player_matches_select(line));
}

static int player_matches_select(int line)
{
    char *input = NULL;
    int entry = 0;

    my_printf("Matches: ");
    input = get_next_line(STDIN);
    if (!input)
        return FAILED_MALLOC;
    if (!good_input(input)) {
        my_printf("%s", my_str_isnum(input) == NOT_VALID ?
                    INVALID_MATCHES : ZERO_MATCHES);
        return ERROR;
    }
    if ((entry = my_atoi(input)) > get_mm(NO, true)) {
        my_printf("Error: you cannot remove more than %d matches per turn\n",
                    get_mm(NO, true));
        return ERROR;
    }
    return (player_move(line, entry, input));
}

static int player_move(int line, int entry, char *input)
{
    char **map = get_map(NULL, GIVE);

    if (!authorised_entry(map[line], entry, input)) {
        my_printf("Error: not enough matches on this line\n");
        return ERROR;
    }
    remove_line(&(map[line]), entry);
    get_matches(NO, SUB, entry);
    my_printf("Player removed %d match(es) from line %d\n", entry, line);
    return PLAYER_WIN;
}
