NAME = pkeita.filler

SRC = main.c\
      ft_piece.c\
      ft_parse.c\
      ft_place.c\
      ft_annexe.c

OBJ = $(SRC:.c=.o)

SRCDIR = srcs/
OBJDIR = objs/

SRCS = $(addprefix $(SRCDIR), $(SRC))
OBJS = $(addprefix $(OBJDIR), $(OBJ))
HEADER = -I includes

CC = gcc
FLAGS = -Wall -Wextra -Werror

C_NO = "\033[00m"
C_OK = "\033[35m"
C_GOOD = "\033[32m"
C_ERROR = "\033[31m"
C_WARN = "\033[33m"

SUCCESS = $(C_GOOD)SUCCESS$(C_NO)
OK = $(C_OK)OK$(C_NO)

.PHONY: all clean fclean re libft/libft.a

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@/bin/mkdir -p $(OBJDIR)
	@$(CC) $(FLAGS) $(HEADER) -I libft/include -c $< -o $@
	@echo "Linking" [ $< ] $(OK)

libft/libft.a :
	make -C libft

$(NAME): $(OBJS) libft/libft.a
	@$(CC) $(FLAGS) $(SRCS) libft/libft.a $(HEADER) -o $@

clean:
	make clean -C libft/
	@/bin/rm -rf $(OBJDIR)
	@echo "Delete" [ objs ] $(OK)

fclean: clean
	rm -f libft/libft.a
	@/bin/rm -f $(NAME)
	@echo "Delete" [ $(NAME) ] $(OK)

re: fclean all
