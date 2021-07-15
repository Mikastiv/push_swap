NAME		= push_swap

LIBFT		= ft
LIBFTDIR	= libft
MAKELIBFT	= @$(MAKE) -C $(LIBFTDIR)

SRC			= src
INC			= include
OBJ			= obj
CFILES		= main.c stack.c swap.c push.c rotate.c rev_rotate.c parse.c quicksort.c\
			stack2.c stack3.c sort.c split.c parse2.c sort2.c
HFILES		= stack.h parse.h pswap.h
OFILES		= $(CFILES:.c=.o)
SRCS		= $(addprefix $(SRC)/, $(CFILES))
OBJS		= $(addprefix $(OBJ)/, $(OFILES))
HEADERS		= $(addprefix $(INC)/, $(HFILES))

CC			= clang
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -rf

$(OBJ)/%.o:	$(SRC)/%.c
			$(CC) $(CFLAGS) -I$(LIBFTDIR) -I$(INC) -c $< -o $@

$(NAME):	$(OBJ) $(OBJS)
			$(MAKELIBFT)
			$(CC) $(OBJS) -L$(LIBFTDIR) -l$(LIBFT) -o $(NAME)

$(OBJ):
			@mkdir -p $(OBJ)

all:		$(NAME)

clean:
			$(MAKELIBFT) fclean
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

norme:
			$(MAKELIBFT) norme
			norminette $(SRCS) $(HEADERS)

visual:		all
			python3 pyviz.py 24 41 27 48 5 33 32 12 31 30 6 34 9 43 36 26 29 45 22 1 50 17 10 15 14 0 7 37 8 39 35 46 18 20 19 13 38 4 2 42 28 3 11 49 40 16 23 25 47 21 44

.PHONY:		all clean fclean re norme visual
