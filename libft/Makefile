NAME = libft.a
CC = gcc
SRC = ft_atoi.c\
	  ft_strcdup.c\
	  ft_strnjoin.c\
	  ft_atlli_base.c\
	  ft_deltab2.c\
	  ft_tab_lenght.c\
	  ft_bzero.c\
	  get_next_line.c\
	  ft_count_word.c\
	  ft_add_char.c\
	  ft_str_replace.c\
	  ft_unicode.c\
	  ft_unicode2.c\
	  ft_printf.c\
	  ft_stradd_start.c\
	  ft_strnfdup.c\
	  ft_prec_and_padd.c\
	  ft_cast.c\
	  ft_cast2.c\
	  ft_flag.c\
	  ft_parse.c\
	  ft_add_char_end.c\
	  ft_convert.c\
	  ft_deltabi2.c\
	  ft_printtab2i.c\
	  ft_tabicopy.c\
	  ft_tabi2copy.c\
	  ft_creat_tabi2.c\
	  ft_ullitoa_base.c\
	  ft_exit.c\
	  ft_strcountchar.c\
	  ft_llitoa_base.c\
	  ft_strnfdup.c\
	  ft_epurstr.c\
	  ft_isalnum.c\
	  ft_strchri.c\
	  ft_isalpha.c\
	  ft_isascii.c\
	  ft_isdigit.c\
	  ft_isprim.c\
	  ft_strndup.c\
	  ft_isprint.c\
	  ft_stradd_start.c\
	  ft_find_next_prim.c\
	  ft_itoa.c\
	  ft_lstadd.c\
	  ft_lstdel.c\
	  ft_lstdelone.c\
	  ft_lstiter.c\
	  ft_printtab.c\
	  ft_lstmap.c\
	  ft_swap.c\
	  ft_printtabi.c\
	  ft_sorttab.c\
	  ft_lstnew.c\
	  ft_memalloc.c\
	  ft_memccpy.c\
	  ft_tabicmp.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_memcpy.c\
	  ft_memdel.c\
	  ft_memmove.c\
	  ft_memset.c\
	  ft_putchar.c\
	  ft_putchar_fd.c\
	  ft_putendl.c\
	  ft_putendl_fd.c\
	  ft_putnbr.c\
	  ft_putnbr_fd.c\
	  ft_putstr.c\
	  ft_putstr_fd.c\
	  ft_stradd.c\
	  ft_strcat.c\
	  ft_strchr.c\
	  ft_strclr.c\
	  ft_strcmp.c\
	  ft_strcpy.c\
	  ft_strdel.c\
	  ft_strdup.c\
	  ft_strequ.c\
	  ft_strfsub.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strjoin.c\
	  ft_strlcat.c\
	  ft_strlen.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strncat.c\
	  ft_strncmp.c\
	  ft_strncpy.c\
	  ft_strnequ.c\
	  ft_strnew.c\
	  ft_strnstr.c\
	  ft_strrchr.c\
	  ft_split2.c\
	  ft_strstr.c\
	  ft_strsub.c\
	  ft_strtrim.c\
	  ft_tolower.c\
	  ft_toupper.c\
	  ft_strrev.c\
	  ft_strfdup.c\
	  ft_ishexa.c\
	  ft_printtab2i.c

FLAGS = -Wall -Wextra -Werror -g -g3

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $@ $^

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean $(NAME)

total : fclean $(NAME)
	@rm -f $(OBJ)

%.o : %.c
	@$(CC) $(FLAGS) -c $<
