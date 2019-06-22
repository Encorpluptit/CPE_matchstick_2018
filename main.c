/*
** EPITECH PROJECT, 2019
** Project.
** File description:
** Project test main.
*/

#include "essentials.h"
#include "printf.h"
#include "matchstick.h"
#include "globals.h"

static int print_help(char **av);

__attribute__((destructor)) void end(void)
{
    char **map = get_map(NULL, GIVE);

    for (int i = 1; i <= get_bs(NO, true) + 2; ++i)
        free(map[i]);
    free(map);
}

int main(int ac, char **av , char **env)
{
    int matches = 0;
    int board = 0;

    if (!(*env))
        return ERROR;
    if (ac == 2 && (my_strcmp_alpha(av[1], "-Help") == EQUAL))
        return (print_help(av));
    if (ac == 3 && !check_args(av[1]) && !check_args(av[2])) {
        if ((board = get_board_size(av[1])) &&
            (matches = get_matches_max(av[2]))) {
            return (matchstick(board, matches));
        } else
            my_printf("Wrong arguments, type '%s -help' for usage\n", av[0]);
    } else
        my_printf("Wrong arguments, type '%s -help' for usage\n", av[0]);
    return (ERROR);
}

static int print_help(char **av)
{
    my_printf("Usage:\n");
    my_printf("\t%s\tBoard size\t", av[0]);
    my_printf("Maximum numbers of matches that can be removed per turn.\n");
    my_printf("Board size must be between 1 and 100.\n");
    my_printf("Number of maximum matches must be coherent.\n");
    return SUCCESS;
}
