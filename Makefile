NAME		= push_swap

LIBFT		= ft
LIBFTDIR	= libft
MAKELIBFT	= $(MAKE) -C $(LIBFTDIR)

SRC			= src
INC			= include
CFILES		= main.c array.c swap.c push.c rotate.c rev_rotate.c
HFILES		= array.h
SRCS		= $(addprefix $(SRC)/, $(CFILES))
OBJS		= $(SRCS:.c=.o)
HEADERS		= $(addprefix $(INC)/, $(HFILES))

CC			= clang
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

%.o:		%.c
			$(CC) $(CFLAGS) -I$(LIBFTDIR) -I$(INC) -c $< -o $@

$(NAME):	$(OBJS)
			$(MAKELIBFT)
			$(CC) $(OBJS) -L$(LIBFTDIR) -l$(LIBFT) -o $(NAME)

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

.PHONY:		all clean fclean re norme
