/*
** EPITECH PROJECT, 2019
** Any project
** File description:
** Template for criterion unit test.
*/

#include "tests_run.h"
#include "matchstick.h"
#include "globals.h"

Test(get_bs, get_bs_simple)
{
    int board_size = 4;
    int stock = get_bs(board_size, false);
    int res = get_bs(board_size, true);

    cr_expect_eq(stock, SUCCESS, "result= %d", stock);
    cr_expect_eq(res, board_size, "result= %d", res);
}

Test(get_mm, get_mm_simple)
{
    int matches_max = 4;
    int stock = get_mm(matches_max, false);
    int res = get_mm(matches_max, true);

    cr_expect_eq(stock, SUCCESS, "result= %d", stock);
    cr_expect_eq(res, matches_max, "result= %d", res);
}

Test(get_matches, get_matches_simple)
{
    int board_size = 4;
    int matches = 2;
    int expected = board_size * board_size - matches;
    int stock = get_matches(board_size, STOCK_MATCHES, 0);
    int res = get_matches(board_size, SUB, matches);
    int ret = get_matches(board_size, RETURN, matches);

    cr_expect_eq(stock, SUCCESS, "result= %d", stock);
    cr_expect_eq(res, expected, "result= %d", res);
    cr_expect_eq(ret, expected, "result= %d", ret);
}
