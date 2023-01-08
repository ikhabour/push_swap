NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wextra -Werror -Wall
SRCS = 	push_swap.c\
		linked_list_utils.c\
		utils.c\
		utils1.c\
		utils2.c\
		a_instructions.c\
		b_instructions.c\
		instructions.c\
		quick_sort.c\
		sort.c\
		ft_split.c

BONUS_SRCS =	bonus/checker_bonus.c\
				bonus/get_next_line_utils_bonus.c\
				bonus/get_next_line_bonus.c\
				bonus/a_instructions_bonus.c\
				bonus/b_instructions_bonus.c\
				bonus/instructions_bonus.c\
				bonus/linked_list_utils_bonus.c\
				bonus/utils1_bonus.c\
				bonus/utils2_bonus.c\
				bonus/ft_split_bonus.c

OBJECTS = $(SRCS:.c=.o)

BONUS_OBJECTS = $(BONUS_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

bonus : $(BONUS_OBJECTS)
	$(CC) $(CFLAGS) $(BONUS_SRCS) -o $(BONUS_NAME)

clean :
	rm -rf $(OBJECTS) $(BONUS_OBJECTS)

fclean : clean
	rm -rf $(NAME) $(BONUS_NAME)

re : fclean clean all

.PHONY: all clean fclean re