/*
** EPITECH PROJECT, 2019
** Matchstick
** File description:
** Header for static inline functions that create board.
*/

#ifndef _BOARD_GENERATION_
#define _BOARD_GENERATION_

static inline bool star_line(int i, int board_size)
{
    return (i == 0 || i == board_size + 1);
}

static inline char *fill_line(char *line, int board_size, int i)
{
    for (int j = 0; j < LINE_BS(board_size); ++j) {
        if (!j || j == board_size * 2)
            line[j] = '*';
        else if (j <= board_size - i || j >= board_size + i )
            line[j] = ' ';
        else
            line[j] = '|';
    }
    return line;
}

static inline char *fill_star_line(char *line, int board_size)
{
    for (int i = 0; i < LINE_BS(board_size); ++i)
        line[i] = '*';
    return line;
}

#endif /* _BOARD_GENERATION_ */
