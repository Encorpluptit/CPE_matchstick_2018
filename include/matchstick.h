/*
** EPITECH PROJECT, 2019
** Matchstick
** File description:
** header for the entire project.
*/

#ifndef UNUSED
#define UNUSED __attribute__ ((unused))
#endif /* UNUSED */

#ifndef HIDDEN
#define HIDDEN __attribute__ ((visibility ("hidden")))
#endif /* HIDDEN */

//<===============================================>
//<===============================================>
// Essentials Static Constantes.
#ifndef _STATICS_CONST_RETURN_
#define _STATICS_CONST_RETURN_
#include <stddef.h>
static const int ERROR = 84;
static const int SUCCESS = 0;
UNUSED static const char *MALLOC_FAILED = NULL;
#endif /* _STATICS_CONST_RETURN_ */


#ifndef _MATCHSTICK_H_
#define _MATCHSTICK_H_

#include <inttypes.h>
#include <stdbool.h>

#define STDIN 0

static const uint8_t PLAYER_WIN = 1;
static const uint8_t IA_WIN = 2;
static const int CTRLD = 0;

UNUSED static const char *PWIN = "I lost... snif... \
but I'll get you next time!!";
UNUSED static const char *TERMINATOR = "You lost, too bad...";

#define INVALID_MATCHES "Error: invalid input (positive number expected)\n"
#define ZERO_MATCHES "Error: you have to remove at least one match\n"

#define LINE_BS(x) (x * 2 + 1)
#define MATCHES(x) (x * 2 - 1)

//<===============================================>
// matchstick.c prototypes.
int matchstick(int board_size, int matches_max);

//<===============================================>
// player.c prototypes.
int player_turn(void);

//<===============================================>
// board_generator.c prototypes.
char **board_generator(int board_size);

//<===============================================>
// free_all.c prototypes.
char **free_board(char **map);


//<===============================================>
// ia_core.c prototypes.
int ia_turn(char **map);

//<===============================================>
// globals.c prototypes.
uint8_t get_bs(int board_size, bool flag);
uint8_t get_mm(int matches_max, bool flag);

//<===============================================>
// Lib function prototypes.
int my_str_isnum(char const *str);
int my_atoi(char const *str);

static inline int get_board_size(char const *str)
{
    int res = my_atoi(str);

    if (res > 100 || res < 1)
        return false;
    return res;
}

static inline int get_matches_max(char const *str)
{
    int res = my_atoi(str);

    if (res < 0)
        return false;
    return res;
}

static inline bool check_args(char *arg)
{
    return (my_str_isnum(arg));
}

static inline int check_matches_in_line(char *line)
{
    size_t i = 0;

    for (; line[i] != '\0'; line[i] == '|' ? i += 1 : (size_t)line++);
    return i;
}

static inline int remove_line(char **line, int matches)
{
    for (int i = MATCHES(get_bs(0, true)); i && (*line)[i] && matches; --i)
        (*line)[i] == '|' ? (*line)[i] = ' ', matches -= 1 : 0;
    return SUCCESS;
}

#endif
