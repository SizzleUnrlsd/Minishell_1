##
## EPITECH PROJECT, 2023
## B-PSU-100-RUN-1-1-bsnavy-hugo.payet
## File description:
## Makefile
##

SRC	=	lib/*.c

SRC_BASIC_FUNCTION =  lib/basic_function/*.c

SRC_BUILTIN = lib/builtin/*.c

SRC_BUILTIN_SETENV = lib/builtin/builtin_set_unset_env/*.c

SRC_BUILTIN_CD = lib/builtin/cd/*.c

SRC_BUILTIN_EXIT = lib/builtin/exit/*.c

SRC_PROMPT_FUNCTION = lib/prompt_function/*.c

SRC_STRUCT_FUNCTION = lib/struct_function/*.c

BONUS = bonus/*.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

FLAGS 	=	-W -Wall -Wextra -Werror -g3

TEST_BIN =	unit_tests

TEST_SRC =	tests/*.c

all	:	$(OBJ)
	gcc -o $(NAME) $(FLAGS) $(SRC) $(SRC_BASIC_FUNCTION) $(SRC_BUILTIN) \
	$(SRC_BUILTIN_SETENV) $(SRC_PROMPT_FUNCTION) $(SRC_STRUCT_FUNCTION) \
	$(SRC_BUILTIN_CD) $(SRC_BUILTIN_EXIT)

clean	:
	rm -f $(OBJ)
	rm -f a.out
	rm -f *.gcno
	rm -f *.gcda
	rm -f *.c~

fclean	: clean
	rm -f $(NAME)
	rm -f $(TEST_BIN)

re	: fclean all

$(TEST_BIN): all
	gcc -o $(TEST_BIN) $(FLAGS) $(SRC_00) $(TEST_SRC) --coverage -lcriterion

tests_run:	$(TEST_BIN)
	./$(TEST_BIN)
