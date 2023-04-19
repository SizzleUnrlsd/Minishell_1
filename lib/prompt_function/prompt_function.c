/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** prompt_function
*/
#include "../../my.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

void switch_sig(all_struct_t *all, int wstatus)
{
    if (wstatus == 256)
        all->status = 1;
    else
        all->status = wstatus;
    if (WIFSIGNALED(wstatus)) {
        if (WTERMSIG(wstatus) == SIGABRT)
            print_str("Abort", 0, true, 2);
        if (WTERMSIG(wstatus) == SIGBUS)
            print_str("Bus error", 0, true, 2);
        if (WTERMSIG(wstatus) == SIGFPE)
            print_str("Floating exception", 0, true, 2);
        if (WTERMSIG(wstatus) == SIGSEGV)
            print_str("Segmentation fault", 0, true, 2);
        if (WCOREDUMP(wstatus))
            print_str(" (core dumped)", '\n', true, 2);
    }
    return;
}

int prompt_function(all_struct_t *all, set_env_t *env_set, char **env)
{
    int wstatus = 0;
    pid_t pid = fork();
    char *line = all->line;
    if (pid == -1)
        return 84;
    if (pid != 0) {
        waitpid(pid, &wstatus, 0);
        switch_sig(all, wstatus);
        parent_exit(all, wstatus);
    }
    if (pid == 0) {
        if (line == NULL)
            exit(0);
        open_directory(all, env_set->path_env, parse_stdin(line, all), env);
        if (access_file(all, parse_stdin(line, all), env) == 1)
            all->status = 1;
        exit(1);
    }
    all->command_not_found = 0;
    return 0;
}
