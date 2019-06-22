/*
** EPITECH PROJECT, 2019
** Any project
** File description:
** Template for criterion unit test.
*/

#include "tests_run.h"
#include "printf.h"
#include "matchstick.h"

Test(check_args, test_arg4)
{
    char *arg = "4";
    int res = check_args(arg);
    int expected = 0;

    cr_assert_eq(res, expected, "resultat = %d", res);
}

Test(check_args, test_arga)
{
    char *arg = "a";
    int res = check_args(arg);
    int expected = 1;

    cr_assert_eq(res, expected, "resultat = %d", res);
}

Test(get_board_size, test_size4)
{
    char *arg = "4";
    int res = get_board_size(arg);
    int expected = 4;

    cr_assert_eq(res, expected, "resultat = %d", res);
}

Test(get_board_size, test_sizea)
{
    char *arg = "a";
    int res = get_board_size(arg);
    int expected = 0;

    cr_assert_eq(res, expected, "resultat = %d", res);
}

Test(get_matches_max, test_matches3_size3)
{
    char *arg = "3";
    int res = get_matches_max(arg);
    int expected = 3;

    cr_assert_eq(res, expected, "resultat = %d", res);
}

Test(get_matches_max, test_matches101_size3)
{
    char *arg = "101";
    int res = get_matches_max(arg);
    int expected = 101;

    cr_assert_eq(res, expected, "resultat = %d", res);
}

Test(get_matches_max, test_matches8_size3)
{
    char *arg = "8";
    int res = get_matches_max(arg);
    int expected = 8;

    cr_assert_eq(res, expected, "resultat = %d", res);
}

Test(my_printf_header, test_output_nbr, .init = redirect_all_std)
{
    int nb = 5;
    char *expected = "nb = 5\n";

    my_printf("nb = %d\n", nb);
    cr_assert_stdout_eq_str(expected);
}

Test(my_printf_header, test_output_string, .init = redirect_all_std)
{
    char *str = "nb = 5";
    char *expected = "nb = 5\n";

    my_printf("%s\n", str);
    cr_assert_stdout_eq_str(expected);
}

Test(my_printf_header, test_output_char, .init = redirect_all_std)
{
    char nb = '5';
    char *expected = "nb = 5\n";

    my_printf("nb = %c\n", nb);
    cr_assert_stdout_eq_str(expected);
}

Test(my_printf_header, test_output_uint, .init = redirect_all_std)
{
    unsigned int nb = 5;
    char *expected = "nb = 5\n";

    my_printf("nb = %u\n", nb);
    cr_assert_stdout_eq_str(expected);
}

Test(my_printf_header, test_output_iflag, .init = redirect_all_std)
{
    uint8_t nb = 5;
    char *expected = "nb = 5\n";

    my_printf("nb = %\n", nb);
    cr_assert_stdout_eq_str(expected);
}
