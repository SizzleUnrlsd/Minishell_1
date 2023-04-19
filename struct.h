/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct set_env_s {
        char **env_array;
        char **path_env;
    }set_env_t;

    typedef struct garbage_really_s {
        int a;
        void *pointer;
    }garbage_really_t;

    typedef struct garbage_collector_s {
        unsigned int index;
        void *pointer;
    }garbage_collector_t;

    typedef struct all_struct_s {
        set_env_t *set_env;
        garbage_collector_t **garbage;
        bool print;
        int binary;
        int command_not_found;
        int built_all_type_env;
        int built_exit;
        int built_nothing;
        char *line;
        int *several_arg_builtin;
        int len_arg;
        int mode;
        int status;
        char *cd_old_path;
        char *cd_new_path;
        unsigned int io;
    }all_struct_t;

    typedef struct bultin_list_s {
        char *index;
        int(*function)(all_struct_t *all, char *str);
    }bultin_list_t;

    typedef struct sig_error_s {
        int index;
        void(*function)(all_struct_t *all, int status);
    }sig_error_t;

#endif /* !STRUCT_H_ */
