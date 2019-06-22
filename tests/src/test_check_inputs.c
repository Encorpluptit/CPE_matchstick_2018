/*
** EPITECH PROJECT, 2019
** Any project
** File description:
** Template for criterion unit test.
*/

#include "tests_run.h"
#include "matchstick.h"
#include "check_inputs.h"

Test(check_input, test_good)
{
    char *input = "2";
    int res = check_input(input);

    cr_assert_eq(res, 1, "resultat = %d", res);
}

Test(check_input, test_letter)
{
    char *input = "azd";
    int res = check_input(input);

    cr_assert_eq(res, 0, "resultat = %d", res);
}

Test(check_input, test_neg)
{
    char *input = "-1";
    int res = check_input(input);

    cr_assert_eq(res, 0, "resultat = %d", res);
}

Test(check_input, test_zero)
{
    char *input = "0";
    int res = check_input(input);

    cr_assert_eq(res, 1, "resultat = %d", res);
}

Test(good_input, test_good)
{
    char *input = "2";
    int res = good_input(input);

    cr_assert_eq(res, 1, "resultat = %d", res);
}

Test(good_input, test_letter)
{
    char *input = "azd";
    int res = good_input(input);

    cr_assert_eq(res, 0, "resultat = %d", res);
}

Test(good_input, test_neg)
{
    char *input = "-1";
    int res = good_input(input);

    cr_assert_eq(res, 0, "resultat = %d", res);
}

Test(good_input, test_zero)
{
    char *input = "0";
    int res = good_input(input);

    cr_assert_eq(res, 0, "resultat = %d", res);
}

Test(check_matches_in_line, test_5)
{
    char *line = "*|||||*";
    int res = check_matches_in_line(line);

    cr_assert_eq(res, 5, "resultat = %d", res);
}

Test(line_range, test_4)
{
    char *line = "4";
    int res = -42;

    get_bs(4, false);
    res = line_range(line);
    cr_assert_eq(res, 0, "resultat = %d", res);
}

Test(line_range, test_5)
{
    char *line = "5";
    int res = -42;

    get_bs(5, false);
    res = line_range(line);
    cr_assert_eq(res, 0, "resultat = %d", res);
}

Test(line_range, test_5_and_zero)
{
    char *line = "5";
    int res = -42;

    get_bs(0, false);
    res = line_range(line);
    cr_assert_eq(res, 1, "resultat = %d", res);
}

Test(line_range, test_aero_and_5)
{
    char *line = "0";
    int res = -42;

    get_bs(5, false);
    res = line_range(line);
    cr_assert_eq(res, 1, "resultat = %d", res);
}

Test(line_range, test_0)
{
    char *line = "0";
    int res = -42;

    get_bs(0, false);
    res = line_range(line);
    cr_assert_eq(res, 1, "resultat = %d", res);
}

Test(authorised_entry, test_4)
{
    char *input = "4";
    char *line = "*|||||*";
    int entry = 4;
    int res = -42;

    get_bs(4, false);
    res = authorised_entry(line, entry, input);
    cr_assert_eq(res, 1, "resultat = %d", res);
}

Test(authorised_entry, test_input_letter)
{
    char *input = "a";
    char *line = "*|||||*";
    int entry = 4;
    int res = -42;

    get_bs(4, false);
    res = authorised_entry(line, entry, input);
    cr_assert_eq(res, 0, "resultat = %d", res);
}

Test(authorised_entry, test_input_2)
{
    char *input = "2";
    char *line = "*|||||*";
    int entry = 4;
    int res = -42;

    get_bs(4, false);
    res = authorised_entry(line, entry, input);
    cr_assert_eq(res, 1, "resultat = %d", res);
}

Test(authorised_entry, test_input_2_and_zero)
{
    char *input = "2";
    char *line = "*|||||*";
    int entry = 4;
    int res = -42;

    get_bs(0, false);
    res = authorised_entry(line, entry, input);
    cr_assert_eq(res, 1, "resultat = %d", res);
}

Test(authorised_entry, test_input_4and2)
{
    char *input = "4";
    char *line = "*|||||*";
    int entry = 2;
    int res = -42;

    get_bs(4, false);
    res = authorised_entry(line, entry, input);
    cr_assert_eq(res, 1, "resultat = %d", res);
}

Test(authorised_entry, test_input_4and7)
{
    char *input = "4";
    char *line = "*|||||*";
    int entry = 7;
    int res = -42;

    get_bs(7, false);
    res = authorised_entry(line, entry, input);
    cr_assert_eq(res, 0, "resultat = %d", res);
}

Test(authorised_entry, test_bad_input)
{
    char *input = "a";
    char *line = "*|||||*";
    int entry = 7;
    int res = -42;

    get_bs(7, false);
    res = authorised_entry(line, entry, input);
    cr_assert_eq(res, 0, "resultat = %d", res);
}

Test(get_board_size, test_neg)
{
    char *str = "-2";
    int res = get_board_size(str);

    cr_expect_eq(res, 0, "result = %d", res);
}

Test(get_board_size, test_zero)
{
    char *str = "0";
    int res = get_board_size(str);

    cr_expect_eq(res, 0, "result = %d", res);
}

Test(get_board_size, test_good)
{
    char *str = "4";
    int res = get_board_size(str);

    cr_expect_eq(res, 4, "result = %d", res);
}

Test(get_board_size, test_too_much)
{
    char *str = "200";
    int res = get_board_size(str);

    cr_expect_eq(res, 0, "result = %d", res);
}

Test(my_str_isnum, test_good)
{
    char *str = "200";
    int res = my_str_isnum(str);

    cr_expect_eq(res, 0, "result = %d", res);
}

Test(my_str_isnum, test_bad)
{
    char *str = "afv";
    int res = my_str_isnum(str);

    cr_expect_neq(res, 0, "result = %d", res);
}

Test(get_matches_max, test_neg1)
{
    char *str = "-2";
    int res = get_matches_max(str);

    cr_expect_eq(res, 0, "result = %d", res);
}

Test(get_matches_max, test_neg2)
{
    char *str = "-2";
    int res = get_matches_max(str);

    cr_expect_eq(res, 0, "result = %d", res);
}

Test(get_matches_max, test_zero1)
{
    char *str = "0";
    int res = get_matches_max(str);

    cr_expect_eq(res, 0, "result = %d", res);
}

Test(get_matches_max, test_zero2)
{
    char *str = "0";
    int res = get_matches_max(str);

    cr_expect_eq(res, 0, "result = %d", res);
}

Test(get_matches_max, test_zero3)
{
    char *str = "4";
    int res = get_matches_max(str);

    cr_expect_eq(res, 4, "result = %d", res);
}

Test(get_matches_max, test_good1)
{
    char *str = "4";
    int res = get_matches_max(str);

    cr_expect_eq(res, 4, "result = %d", res);
}

Test(get_matches_max, test_good2)
{
    char *str = "4";
    int res = get_matches_max(str);

    cr_expect_eq(res, 4, "result = %d", res);
}

Test(get_matches_max, test_good3)
{
    char *str = "4";
    int res = get_matches_max(str);

    cr_expect_eq(res, 4, "result = %d", res);
}

Test(get_matches_max, test_good4)
{
    char *str = "4";
    int res = get_matches_max(str);

    cr_expect_eq(res, 4, "result = %d", res);
}

Test(get_matches_max, test_too_much1)
{
    char *str = "200";
    int res = get_matches_max(str);

    cr_expect_eq(res, 200, "result = %d", res);
}

Test(get_matches_max, test_too_much2)
{
    char *str = "-1";
    int res = get_matches_max(str);

    cr_expect_eq(res, 0, "result = %d", res);
}

Test(get_matches_max, test_too_much3)
{
    char *str = "70";
    int res = get_matches_max(str);

    cr_expect_eq(res, 70, "result = %d", res);
}
