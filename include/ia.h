/*
** EPITECH PROJECT, 2019
** Matchstick
** File description:
** Header for ia management.
*/

#ifndef _IA_H_
#define _IA_H_

#include "matchstick.h"
#include "globals.h"
#include <stdlib.h>

#define NB_LINE map_info.nb_line
#define LINE_FILLED map_info.line_filled
#define DIFF map_info.diff
#define WEAK map_info.weak
#define TAB map_info.tab_matches
#define MAX_INFO map_info.maximum
#define MAX_MAP_LINE map_info.maximum.map_line
#define MAX_INDEX map_info.maximum.index
#define MAX_VALUE map_info.maximum.value

#define REMOVE(x) (x > get_mm(NO, true) ? get_mm(NO, true) : TAB[MAX_INDEX])

static const uint8_t NIM = 42;
static const uint8_t FAIL = -42;

typedef struct maximum_s {
    uint8_t index;
    uint8_t value;
    uint8_t map_line;
} max_t;

typedef struct map_info_s {
    int nb_line;
    int line_filled;
    int diff;
    int16_t weak;
    max_t maximum;
    int *tab_matches;
} map_t;

static inline max_t fill_max_info(map_t map_info, int i)
{
    return ((max_t) {.index = i, .value = TAB[i], .map_line = i + 1});
}

static inline map_t get_map_info(char **map)
{
    int i = 0;
    int res = 0;
    map_t map_info = (map_t) {0, 0, 0, 0, .maximum = (max_t) {0, 0}, NULL};

    if ((TAB = malloc(sizeof(int) * (get_bs(NO, true) + 1))) == NULL)
        return (map_info);
    TAB[get_bs(NO, true)] = -1;
    for (i = 0; i <= get_bs(NO, true); i += 1) {
        TAB[i] = check_matches_in_line(map[i + 1]);
        if (TAB[i] > 0) {
            NB_LINE += (TAB[i] ? 1 : 0);
            LINE_FILLED += (TAB[i] > 1 ? 1 : 0);
            WEAK = i + 1;
        }
        if (i && TAB[i] > TAB[i - 1])
            MAX_INFO = fill_max_info(map_info, i);
    }
    !MAX_MAP_LINE ? MAX_MAP_LINE = WEAK : 0;
    return (map_info);
}

static inline int last_line(map_t map_info)
{
    return (NB_LINE == 1 && TAB[MAX_INDEX] > 1);
}

static inline int can_remove(map_t map_info)
{
    return (TAB[MAX_INDEX] <= (get_mm(NO, true)));
}

static inline int square(map_t map_info)
{
    return (can_remove(map_info) && TAB[MAX_INDEX] > (2 * get_mm(NO, true)));
}

static inline int line_filled(map_t map_info)
{
    return ((NB_LINE == 1 || LINE_FILLED >= 1) && TAB[MAX_INDEX] > 1);
}

#endif /* _IA_H_ */
