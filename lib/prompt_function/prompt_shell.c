/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** prompt_shell
*/
#include "../../my.h"

int prompt_shell(all_struct_t *all)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;
    print_str("$>", ' ', RD_TTY, 1);
    read = getline(&line, &len, stdin);
    if (read == -1)
        return (42);
    all->line = line;
    return 0;
}
