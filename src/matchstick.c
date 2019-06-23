/*
** EPITECH PROJECT, 2019
** Matchstick.
** File description:
** Functions that manages Matchstick functions.
*/

#include "printf.h"
#include "matchstick.h"
#include "globals.h"

static char **stock_everything(int board_size, int matches_max);
static int print_victory(int win);

int matchstick(int board_size, int matches_max)
{
    int win = SUCCESS;
    char **map = stock_everything(board_size, matches_max);

    if (!map)
        return ERROR;
    do {
        my_printf("%w\n", map);
        win = player_turn();
        if (get_matches(board_size, RETURN, NO) <= 0 || win == CTRLD)
            break;
        my_printf("%w\n", map);
        win = ia_turn(map);
        if (get_matches(board_size, RETURN, NO) <= 0)
            break;
    } while (get_matches(board_size, RETURN, NO) > 0);
    if (win == CTRLD)
        return (get_map(NULL, FREE) ? CTRLD : CTRLD);
    my_printf("%w", map);
    get_map(NULL, FREE);
    return (print_victory(win));
}

static char **stock_everything(int board_size, int matches_max)
{
    char **map = board_generator(board_size);

    if (!map)
        return (NULL);
    get_mm(matches_max, false);
    get_bs(board_size, false);
    get_matches(board_size, STOCK_MATCHES, NO);
    get_map(map, STOCK_MAP);
    return map;
}

static int print_victory(int win)
{
    if (win == CTRLD)
        return SUCCESS;
    my_printf("%s\n", win == 1 ? PWIN : TERMINATOR);
    return win;
}
