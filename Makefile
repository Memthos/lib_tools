VPATH=srcs:srcs/libft:srcs/ft_printf:srcs/get_next_line:srcs/math_ops
OBJS_DIR=objs/
HEADERS=includes/
SRCS=ft_atoi.c ft_bzero.c ft_calloc.c ft_free_str.c ft_free_tab.c ft_isalnum.c \
	ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c ft_itoa.c \
	ft_memchr.c	ft_memcmp.c	ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strcmp.c \
	ft_strdup.c ft_striteri.c ft_strjoin_sep.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strncpy.c ft_strnstr.c \
	ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
	get_next_line.c get_next_line_utils.c \
	conversions_bonus.c conversions_checks_bonus.c conversions_utils_bonus.c \
	ft_printf_bonus.c ft_printf_utils_bonus.c maths_utils_bonus.c

OBJS=$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
CC=cc
CFLAGS=-Wall -Wextra -Werror -I$(HEADERS)
NAME=lib_tools.a

all: $(NAME)

$(NAME): $(OBJS) $(FTPRINTF)
	@ar -rcs $@ $^
	@echo "Finished compiling libft"

$(OBJS_DIR)%.o: %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@rm -drf $(OBJS_DIR)
	@echo "Cleaned libft object files"

fclean:
	@rm -f $(NAME)
	@rm -drf $(OBJS_DIR)
	@echo "Cleaned libft"

re: fclean all

.PHONY: all clean fclean re
