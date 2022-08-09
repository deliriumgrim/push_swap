NAME 	=	push_swap

NAME_B	= 	checker

CFILES	=	main.c check_input.c help/free_functions.c help/list_functions.c sort_functions1.c\
			help/actions1.c small/sort_small1.c small/sort_utils1.c help/actions2.c big/big_sort.c\
			big/big_sort_utils.c main_utils.c

CFILES_B	=	bonus/checker_bonus.c bonus/checker_check_input_bonus.c bonus/checker_utils1_bonus.c bonus/checker_utils2_bonus.c\
				bonus/input_pars_bonus.c	bonus/actions/actions1_bonus.c bonus/actions/actions2_bonus.c bonus/actions/actions3_bonus.c

OBJECTS	= $(CFILES:.c=.o)

OBJECTS_B = $(CFILES_B:.c=.o)

D_FILES =	$(patsubst %.c,%.d,$(CFILES))

D_FILES_B =	$(patsubst %.c,%.d,$(CFILES_B))

LIB_PATH = libft/

BONUS_PATH = bonus/

CC = cc

CFLAGS = -Wall -Wextra -Werror

.PHONY	:	all clean fclean re bonus

all		: lib $(NAME)

bonus	: lib $(NAME_B)

lib		:
	make -C $(LIB_PATH) all

$(NAME)	:	$(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIB_PATH)libft.a -o $(NAME)

$(NAME_B)	:	$(OBJECTS_B)
	$(CC) $(CFLAGS) $(OBJECTS_B) $(LIB_PATH)libft.a -o $(NAME_B)

%.o 	:	%.c	$(LIB_PATH)libft.a Makefile
	$(CC) $(CFLAGS) -c $< -o $@ -MD


include $(wildcard $(D_FILES))
include $(wildcard $(D_FILES_B))

clean	:
	make -C $(LIB_PATH) clean
	rm -f $(OBJECTS_B) $(D_FILES_B)
	rm -f $(OBJECTS) $(D_FILES)

fclean	:	clean
	make -C $(LIB_PATH) fclean
	rm -f $(NAME_B)
	rm -f $(NAME)

re		:	fclean all
