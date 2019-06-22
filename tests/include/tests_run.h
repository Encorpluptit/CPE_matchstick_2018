/*
** EPITECH PROJECT, 2019
** Any Project
** File description:
** Header for Unit Test using criterion.
*/

#ifdef WRAP
#include <stddef.h>

static inline void *malloc(size_t size)
{
    return NULL;
}

#endif /* _WRAP_MALLOC_ */

#ifndef _TESTS_RUN_
#define _TESTS_RUN_

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "essentials.h"

static inline void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

#endif /* _TESTS_RUN_ */
