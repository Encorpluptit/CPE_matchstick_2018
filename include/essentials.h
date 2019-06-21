/*
** EPITECH PROJECT, 2019
** any_project
** File description:
** Essentials Functions of Lib C.
*/

//<===============================================>
//<===============================================>
// Essentials Defines.
#ifndef UNUSED
#define UNUSED __attribute__((unused))
#endif /* UNUSED */

#ifndef HIDDEN
#define HIDDEN __attribute__((visibility ("hidden")))
#endif /* HIDDEN */



//<===============================================>
//<===============================================>
// Essentials Static Constantes.
#ifndef _STATICS_CONST_RETURN_
#define _STATICS_CONST_RETURN_
#include <stddef.h>
static const int ERROR = 84;
static const int NOT_VALID = -42;
static const int SUCCESS = 0;
UNUSED static const char *MALLOC_FAILED = NULL;
#endif /* _STATICS_CONST_RETURN_ */



//<===============================================>
//<===============================================>
#ifndef _ESSENTIALS_FUNCTIONS_
#define _ESSENTIALS_FUNCTIONS_

//<===============================================>
// Necessary includes.
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

//<===============================================>
// Essentials functions.
static inline size_t my_strlen(char const *str)
{
    size_t i = 0;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

static inline char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

static inline char *my_strdup(char const *src)
{
    int src_len = my_strlen(src);
    char *dest;

    dest = malloc(sizeof(char) * src_len);
    dest = my_strcpy(dest, src);
    dest[src_len] = '\0';
    return dest;
}

static const int S1_LONGER = 1;
static const int S2_LONGER = 2;
static const int S1_UPPER = -1;
static const int S2_UPPER = -2;
static const int EQUAL = 0;

static inline int my_strcmp(char const *s1, char const *s2)
{
    int s1_lenght = 0;
    int s2_lenght = 0;

    for (int i = 0; s1[i] != '\0'; i++)
        s1_lenght++;
    for (int i = 0; s2[i] != '\0'; i++)
        s2_lenght++;
    if (s1_lenght > s2_lenght)
        return (S1_LONGER);
    if (s1_lenght < s2_lenght)
        return (S2_LONGER);
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] > s2[i])
            return (S1_UPPER);
        if (s1[i] < s2[i])
            return (S2_UPPER);
    }
    return (EQUAL);
}

static inline int my_strcmp_alpha(char const *s1, char const *s2)
{
    int s1_lenght = 0;
    int s2_lenght = 0;

    for (int i = 0; s1[i] != '\0'; i++)
        s1_lenght++;
    for (int i = 0; s2[i] != '\0'; i++)
        s2_lenght++;
    if (s1_lenght > s2_lenght)
        return (S1_LONGER);
    if (s1_lenght < s2_lenght)
        return (S2_LONGER);
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (((s1[i] >= 'A' && s1[i] <= 'Z') ? (s1[i] + 32) : s1[i]) >
            ((s2[i] >= 'A' && s2[i] <= 'Z') ? (s2[i] + 32) : s2[i]))
            return (S1_UPPER);
        if (((s1[i] >= 'A' && s1[i] <= 'Z') ? (s1[i] + 32) : s1[i]) <
            ((s2[i] >= 'A' && s2[i] <= 'Z') ? (s2[i] + 32) : s2[i]))
            return (S2_UPPER);
    }
    return (EQUAL);
}

static inline int my_strcmp_only_alpha(char const *s1, char const *s2)
{
    int i = 0;

    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (((s1[i] >= 'A' && s1[i] <= 'Z') ? (s1[i] + 32) : s1[i]) >
            ((s2[i] >= 'A' && s2[i] <= 'Z') ? (s2[i] + 32) : s2[i]))
            return (S1_UPPER);
        if (((s1[i] >= 'A' && s1[i] <= 'Z') ? (s1[i] + 32) : s1[i]) <
            ((s2[i] >= 'A' && s2[i] <= 'Z') ? (s2[i] + 32) : s2[i]))
            return (S2_UPPER);
    }
    if (s1[i] == '\0' && s2[i] != '\0')
        return (S1_LONGER);
    if (s2[i] == '\0' && s1[i] != '\0')
        return (S2_LONGER);
    return (EQUAL);
}

#endif /* _ESSENTIALS_FUNCTIONS_ */
