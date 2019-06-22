/*
** EPITECH PROJECT, 2019
** Matchstick.
** File description:
** Manage the core of the ia.
*/

#include "matchstick.h"
#include "printf.h"
#include "ia.h"

static int uneven(char **map);
static int even(char **map);
static int hellsing(char *line, int i);

int ia_turn(char **map)
{
    int rt = -42;

    my_printf("AI's turn...\n");
    if ((rt = uneven(map)) == NIM)
        return IA_WIN;
    if ((rt = even(map)) == NIM)
        return IA_WIN;
    for (int i = get_bs(NO, true); map[i]; --i) {
        if (hellsing(map[i], i) == NIM)
            return (IA_WIN);
    }
    return rt;
}

static int uneven(char **map)
{
    int line_filled = 0;
    int index = 0;
    int stop = 0;
    int nb_line = ia_count_line(map, &line_filled, &index, &stop);
    int res = 0;
    char *line = NULL;

    if ((nb_line != 1 && stop == FAIL) || (nb_line % 2) != 1)
        return NOP;
    if (check_ia_move(map[index], NO) == NIM) {
        line = map[index];
        res = check_matches_in_line(line)  - NO;
        remove_line(&line, res);
        get_matches(NO, SUB, res);
        my_printf("AI removed %d match(es) from line %d\n", res, index + 1);
        return NIM;
    }
    return FAIL;
}

static int even(char **map)
{
    int line_filled = 0;
    int index = 0;
    int stop = 0;
    int nb_line = ia_count_line(map, &line_filled, &index, &stop);
    int res = 0;
    char *line = NULL;

    if ((nb_line != 2 && stop == FAIL) || (nb_line % 2) != 0)
        return NOP;
    if (check_ia_move(map[index], VAR) == NIM) {
        line = map[index];
        res = check_matches_in_line(line)  - NO;
        remove_line(&line, res);
        get_matches(NO, SUB, res);
        my_printf("AI removed %d match(es) from line %d\n", res, index + 1);
        return NIM;
    }
    return FAIL;
}

static int hellsing(char *line, int i)
{
    int res = 0;

    res = check_matches_in_line(line);
    if (res > 0) {
        if (res > get_mm(NO, true))
            res = get_mm(NO, true);
        remove_line(&line, res);
        get_matches(NO, SUB, res);
        my_printf("AI removed %d match(es) from line %d\n", res, i);
        return NIM;
    }
    return FAIL;
}
