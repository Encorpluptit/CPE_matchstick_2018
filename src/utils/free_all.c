/*
** EPITECH PROJECT, 2019
** Matchstick
** File description:
** Fonction that free everything (deconstructor attribute).
*/

#include <stdlib.h>
#include "matchstick.h"
#include "globals.h"

char **get_map(char **map, fct_map_flag_t flag)
{
    static char **map_save = NULL;

    if (!flag) {
        map_save = map;
        return NULL;
    }
    if (flag == GIVE)
        return map_save;
    if (flag == FREE) {
        for (int i = 0; map_save[i]; ++i)
            map_save[i] ? free(map_save[i]) : 0;
        free(map_save);
        return NULL;
    }
    return map_save;
}
