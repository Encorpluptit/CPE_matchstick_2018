/*
** EPITECH PROJECT, 2019
** Matchstick.
** File description:
** Handle flag for global map function.
*/

#ifndef _MAP_FLAG_
#define _MAP_FLAG_

#ifndef NO
#define NO 0
#endif /* NO */

#ifndef VAR
#define VAR 1
#endif /* VAR */

typedef enum fct_map_flag_s {
    STOCK_MAP,
    GIVE,
    FREE,
} fct_map_flag_t;

typedef enum nb_matches_s {
    STOCK_MATCHES,
    SUB,
    RETURN,
} nb_matches_t;

//<===============================================>
// globals.c prototypes.
uint8_t get_bs(int board_size, bool flag);
uint8_t get_mm(int matches_max, bool flag);
char **get_map(char **map, fct_map_flag_t flag);
int get_matches(int board_size, nb_matches_t flag, int variation);

#endif
