/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** bye
*/
#include "../../my.h"

void bye(all_struct_t *all)
{
    unsigned int i = 0;
    for (; i != all->io; i++) {
        if (all->garbage[i] == NULL)
            continue;
        garbage_uncollector(all->garbage[i]);
        free(all->garbage[i]);
        all->garbage[i] = NULL;
    }
    free(all->garbage);
    free(all->line);
    free(all);
    return;
}
