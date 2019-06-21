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

static const int NIM = 42;
static const int FAIL = -42;
static const int NOP = 0;

static inline int ia_count_line(char **map, int *line_filled,
                                int *index, int *stop)
{
    int count = 0;
    int tmp = 0;
    int stock = 0;

    for (int i = 0; map[i]; ++i) {
        tmp = check_matches_in_line(map[i]);
        if (tmp > 0) {
            count += 1;
            *line_filled += (tmp > 1 ? 1 : 0);
        }
        if ((*line_filled) != 1 && (*line_filled) != 0)
            *stop = FAIL;
        if (tmp > stock) {
            *index = i;
            stock = tmp;
        }
        tmp = 0;
    }
    return count;
}

static inline int count_lines(char **map)
{
    int count = 0;
    int tmp = 0;

    for (int i = 0; map[i]; ++i) {
        tmp = check_matches_in_line(map[i]);
        count += (tmp > 0 ? 1 : 0);
        tmp = 0;
    }
    return count;
}

static inline int check_ia_move(char *line, int variation)
{
    if (check_matches_in_line(line) <= (get_bs(NO, true) + variation))
        return NIM;
    else
        return FAIL;
}

#endif /* _IA_H_ */
