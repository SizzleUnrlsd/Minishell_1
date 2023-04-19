/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** my_sh
*/
#include "../my.h"

int main(int ac, char **av, char **env)
{
    (void) av;
    if (ac != 1)
        return 84;
    int rd_builtin = 0;
    all_struct_t *all = init_all();
    all->garbage = malloc(sizeof(garbage_collector_t *) * LEN_ARRAY_STRUCT);
    set_env_t *env_set = set_env(all, env);
    all->set_env = env_set;
    ENV_PATH = cut_path_env(all, ENV_SET_ARRAY);
    while (true) {
        reset_var_shell(all);
        if (prompt_shell(all) == 42)
            break;
        builtin(all, parse_stdin(all->line, all), &rd_builtin);
        if (BUILT_INT_EXIT != 0)
            exit(0);
        if (ALL_ENV == 0 && rd_builtin == 0 && BINARY == 0)
            prompt_function(all, env_set, env);
    }
    return 0;
}
