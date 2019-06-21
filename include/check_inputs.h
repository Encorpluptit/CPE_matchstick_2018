/*
** EPITECH PROJECT, 2019
** Matchstick.
** File description:
** Functions static inline that check entries.
*/

#ifndef _CHECK_INPUTS_
#define _CHECK_INPUTS_

#include "globals.h"

static inline int check_input(char *input)
{
    return (!my_str_isnum(input) && my_atoi(input) >= 0);
}

static inline int good_input(char *input)
{
    return (!my_str_isnum(input) && my_atoi(input) > 0);
}

static inline int line_range(char *input)
{
    return (!(my_atoi(input) <= get_bs(0, true)) || my_atoi(input) == 0);
}

static inline int authorised_line(char *input)
{
    return (good_input(input) && my_atoi(input) <= get_bs(0, true));
}

static inline int authorised_entry(char *line, int entry, char *input)
{
    return (good_input(input) && (entry <= check_matches_in_line(line)));
}

#endif /* _CHECK_INPUTS_ */
