/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** concat_char_str
*/
#include "../../my.h"

char *concat_char_str(char concat, char *str, int futur, int a)
{
    char *dest = malloc(sizeof(char) * (my_strlen(str) + futur + 2));

    if (a == 0) {
        dest[0] = concat;
        for (int i = 1; i != my_strlen(str) + 1; i++)
            dest[i] = str[i - 1];
    }
    if (a == 1) {
        for (int i = 0; i != my_strlen(str) + 1; i++)
            dest[i] = str[i];
        dest[my_strlen(str)] = concat;
    }
    dest[my_strlen(str) + 1] = '\0';
    return dest;
}
