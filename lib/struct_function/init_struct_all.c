/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** init_struct_all
*/
#include "../../my.h"

all_struct_t *init_all(void)
{
    all_struct_t *all = malloc(sizeof(all_struct_t));
    if (all == NULL)
        exit(84);
    bool print = true;
    all->binary = 0;
    all->command_not_found = 0;
    all->built_all_type_env = 0;
    all->built_exit = 0;
    all->built_nothing = 0;
    if (isatty(0) == 0)
        print = false;
    all->print = print;
    all->line = 0;
    all->several_arg_builtin = NULL;
    all->len_arg = 0;
    all->mode = -1;
    all->set_env = NULL;
    all->status = 0;
    all->io = 0;
    return all;
}
