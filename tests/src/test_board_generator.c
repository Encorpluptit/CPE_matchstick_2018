/*
** EPITECH PROJECT, 2019
** Any project
** File description:
** Template for criterion unit test.
*/

#include "tests_run.h"
#include "matchstick.h"
#include "board_generation.h"

Test(fct, test_01)
{
    int board_size = 4;
    int i = 0;
    bool res = star_line(i, board_size);

    cr_assert_eq(res, true, "resultat = %d", res);
}

Test(fct, test_02)
{
    int board_size = 3;
    int i = 4;
    bool res = star_line(i, board_size);

    cr_assert_eq(res, true, "resultat = %d", res);
}

Test(fct, test_03)
{
    int board_size = 4;
    int i = 2;
    bool res = star_line(i, board_size);

    cr_assert_eq(res, false, "resultat = %d", res);
}

Test(fct, test_04)
{
    int board_size = 3;
    char *line = malloc(sizeof(char) * (board_size * 2 + 2));
    char *expected = "*******";

    *(line + (board_size * 2 + 1)) = '\0';
    line = fill_star_line(line, board_size);
    cr_assert_str_eq(line, expected, "resultat = %s", line);
}

Test(fct, test_05)
{
    int board_size = 2;
    char *line = malloc(sizeof(char) * (board_size * 2 + 2));
    char *expected = "*****";

    *(line + (board_size * 2 + 1)) = '\0';
    line = fill_star_line(line, board_size);
    cr_assert_str_eq(line, expected, "resultat = %s", line);
}

Test(fct, test_06)
{
    int board_size = 4;
    char *line = malloc(sizeof(char) * (board_size * 2 + 2));
    char *expected = "*********";

    *(line + (board_size * 2 + 1)) = '\0';
    line = fill_star_line(line, board_size);
    cr_assert_str_eq(line, expected, "resultat = %s", line);
}

Test(fct, test_07)
{
    int board_size = 2;
    char *line_1 = malloc(sizeof(char) * (board_size * 2 + 2));
    char *line_1_exp = "* | *";
    int i = 1;

    *(line_1 + (board_size * 2 + 1)) = '\0';
    line_1 = fill_line(line_1, board_size, i);
    cr_assert_str_eq(line_1, line_1_exp, "result = %s", line_1);
}

Test(fct, test_08)
{
    int board_size = 2;
    char *line_2 = malloc(sizeof(char) * (board_size * 2 + 2));
    char *line_2_exp = "*|||*";
    int i = 2;

    *(line_2 + (board_size * 2 + 1)) = '\0';
    line_2 = fill_line(line_2, board_size, i);
    cr_assert_str_eq(line_2, line_2_exp, "result = %s", line_2);
}

Test(fct, test_09)
{
    int board_size = 3;
    char *line_1 = malloc(sizeof(char) * (board_size * 2 + 2));
    char *line_1_exp = "*  |  *";
    int i = 1;

    *(line_1 + (board_size * 2 + 1)) = '\0';
    line_1 = fill_line(line_1, board_size, i);
    cr_assert_str_eq(line_1, line_1_exp, "result = %s", line_1);
}

Test(fct, test_10)
{
    int board_size = 3;
    char *line_2 = malloc(sizeof(char) * (board_size * 2 + 2));
    char *line_2_exp = "* ||| *";
    int i = 2;

    *(line_2 + (board_size * 2 + 1)) = '\0';
    line_2 = fill_line(line_2, board_size, i);
    cr_assert_str_eq(line_2, line_2_exp, "result = %s", line_2);
}

Test(fct, test_11)
{
    int board_size = 3;
    char *line_3 = malloc(sizeof(char) * (board_size * 2 + 2));
    char *line_3_exp = "*|||||*";
    int i = 3;

    *(line_3 + (board_size * 2 + 1)) = '\0';
    line_3 = fill_line(line_3, board_size, i);
    cr_assert_str_eq(line_3, line_3_exp, "result = %s", line_3);
}

Test(fct, test_12)
{
    int board_size = 3;
    char **map = board_generator(board_size);
    char *line_0_exp = "*******";
    char *line_1_exp = "*  |  *";
    char *line_2_exp = "* ||| *";
    char *line_3_exp = "*|||||*";
    char *line_4_exp = "*******";

    cr_expect_str_eq(map[0], line_0_exp, "result = %s", map[0]);
    cr_expect_str_eq(map[1], line_1_exp, "result = %s", map[1]);
    cr_expect_str_eq(map[2], line_2_exp, "result = %s", map[2]);
    cr_expect_str_eq(map[3], line_3_exp, "result = %s", map[3]);
    cr_expect_str_eq(map[4], line_4_exp, "result = %s", map[4]);
    cr_expect_null(map[5]);
}
Test(fct, test_13)
{
    int board_size = 4;
    char **map = board_generator(board_size);
    char *line_0_exp = "*********";
    char *line_1_exp = "*   |   *";
    char *line_2_exp = "*  |||  *";
    char *line_3_exp = "* ||||| *";
    char *line_4_exp = "*|||||||*";
    char *line_5_exp = "*********";

    cr_expect_str_eq(map[0], line_0_exp, "result = %s", map[0]);
    cr_expect_str_eq(map[1], line_1_exp, "result = %s", map[1]);
    cr_expect_str_eq(map[2], line_2_exp, "result = %s", map[2]);
    cr_expect_str_eq(map[3], line_3_exp, "result = %s", map[3]);
    cr_expect_str_eq(map[4], line_4_exp, "result = %s", map[4]);
    cr_expect_str_eq(map[5], line_5_exp, "result = %s", map[5]);
    cr_expect_null(map[6]);
}
