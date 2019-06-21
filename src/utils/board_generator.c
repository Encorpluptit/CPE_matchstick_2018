/*
** EPITECH PROJECT, 2019
** Matchstick.
** File description:
** Function that take board_size and return map.
*/

#include "../../tests/include/tests_run.h"
#include <stdlib.h>
#include "matchstick.h"
#include "board_generation.h"

static char **alloc_map(int board_size);

char **board_generator(int board_size)
{
    char **map = alloc_map(board_size);

    if (map == NULL)
        return NULL;
    for (int i = 0; i < board_size + 2; ++i) {
        if ((star_line(i, board_size)))
            map[i] = fill_star_line(map[i], board_size);
        else
            map[i] = fill_line(map[i], board_size, i);
    }
    return map;
}

static char **alloc_map(int board_size)
{
    char **map = malloc(sizeof(char *) * (board_size + 3));
    int i = 0;

    if (!map)
        return NULL;
    for (i = 0; i < board_size + 2; ++i) {
        map[i] = malloc(sizeof(char) * (board_size * 2 + 2));
        if (!(map[i])) {
            free(map);
            return (NULL);
        }
        map[LINE_BS(board_size)] = '\0';
    }
    map[i] = NULL;
    return map;
}
