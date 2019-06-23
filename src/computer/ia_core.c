/*
** EPITECH PROJECT, 2019
** Matchstick.
** File description:
** Manage the core of the ia.
*/

#include "matchstick.h"
#include "printf.h"
#include "ia.h"

static int uneven(char **map, map_t map_info);
static int even(char **map, map_t map_info);
static int play_ia_move(char *map_line, int matches, int line);

int ia_turn(char **map)
{
    int rt = FAIL;
    map_t map_info = get_map_info(map);

    my_printf("AI's turn...\n");
    if (!TAB)
        return FAIL;
    if (NB_LINE % 2 == 1) {
        if ((rt = uneven(map, map_info) == PLAYER_WIN))
            return PLAYER_WIN;
    }
    if (NB_LINE % 2 == 0) {
        if ((rt = even(map, map_info) == PLAYER_WIN))
            return PLAYER_WIN;
    }
    return (play_ia_move(map[MAX_MAP_LINE], 1, MAX_MAP_LINE));
}

static int uneven(char **map, map_t map_info)
{
    if (LINE_FILLED == 2 || LINE_FILLED == 3)
        return (play_ia_move(map[MAX_MAP_LINE], 1, MAX_MAP_LINE));
    if (line_filled(map_info) && (TAB[MAX_INDEX] <= (get_mm(NO, true) + 1)))
        return (play_ia_move(map[MAX_MAP_LINE], REMOVE(TAB[MAX_INDEX]) - 1,
                            MAX_MAP_LINE));
    if (line_filled(map_info) && (TAB[MAX_INDEX] > (get_mm(NO, true))))
        return (play_ia_move(map[MAX_MAP_LINE], 1, MAX_MAP_LINE));
    return FAIL;
}

static int even(char **map, map_t map_info)
{
    int matches = get_mm(NO, true);

    if (LINE_FILLED == 1 && NB_LINE == 2 && (square(map_info)))
        return (play_ia_move(map[MAX_MAP_LINE], REMOVE(TAB[MAX_INDEX]),
                                MAX_MAP_LINE));
    if (LINE_FILLED == 1 && NB_LINE == 2 && can_remove(map_info))
        return (play_ia_move(map[MAX_MAP_LINE], REMOVE(TAB[MAX_INDEX]),
                                MAX_MAP_LINE));
    if (LINE_FILLED == 1 && NB_LINE == 2 && (!square(map_info)))
        return (play_ia_move(map[MAX_MAP_LINE], 1, MAX_MAP_LINE));
    if (NB_LINE == LINE_FILLED && (get_matches(NO, RETURN, NO) > (matches * 2)))
        return (play_ia_move(map[MAX_MAP_LINE], REMOVE(TAB[MAX_INDEX]),
                                MAX_MAP_LINE));
    if (NB_LINE >= 2 && (square(map_info)))
        return (play_ia_move(map[MAX_MAP_LINE], REMOVE(TAB[MAX_INDEX]),
                                MAX_MAP_LINE));
    if (NB_LINE >= 2 && (!square(map_info)))
        return (play_ia_move(map[MAX_MAP_LINE], 1, MAX_MAP_LINE));
    return FAIL;
}

static int play_ia_move(char *map_line, int matches, int line)
{
    remove_line(&map_line, matches);
    get_matches(NO, SUB, matches);
    my_printf("AI removed %d match(es) from line %d\n", matches, line);
    return PLAYER_WIN;
}
