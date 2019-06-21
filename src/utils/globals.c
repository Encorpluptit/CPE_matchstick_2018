/*
** EPITECH PROJECT, 2019
** Matchstick
** File description:
** Functions that keep in memory globals variables.
*/

#include "matchstick.h"
#include "globals.h"

uint8_t get_bs(int board_size, bool flag)
{
    static uint8_t board_save = 0;

    if (!flag) {
        board_save = board_size;
        return SUCCESS;
    }
    else
        return board_save;
}

uint8_t get_mm(int matches_max, bool flag)
{
    static uint8_t max_matches_save = 0;

    if (!flag) {
        max_matches_save = matches_max;
        return SUCCESS;
    } else
        return max_matches_save;
}

int get_matches(int board_size, nb_matches_t flag, int variation)
{
    static int nb_matches_save = 0;

    if (!flag) {
        nb_matches_save = board_size * board_size;
        return SUCCESS;
    }
    else if (flag == SUB)
        return (nb_matches_save -= variation);
    else
        return nb_matches_save;
}
