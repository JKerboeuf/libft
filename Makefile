# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jukerboe <jukerboe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 11:26:10 by jukerboe          #+#    #+#              #
#    Updated: 2021/09/20 15:04:23 by jukerboe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m

NAME = libft.a
DIR_NAME = libft

SRC_DIR = ./sources
SRC =	char/ft_isalnum.c \
		char/ft_isalpha.c \
		char/ft_isascii.c \
		char/ft_isdigit.c \
		char/ft_islower.c \
		char/ft_isprint.c \
		char/ft_isspace.c \
		char/ft_isupper.c \
		char/ft_tolower.c \
		char/ft_toupper.c \
		\
		list/ft_lstadd_back.c \
		list/ft_lstadd_front.c \
		list/ft_lstclear.c \
		list/ft_lstdelone.c \
		list/ft_lstiter.c \
		list/ft_lstlast.c \
		list/ft_lstmap.c \
		list/ft_lstnew.c \
		list/ft_lstsize.c \
		\
		math/ft_abs.c \
		math/ft_fact.c \
		math/ft_isprime.c \
		math/ft_pow.c \
		math/ft_sqrt.c \
		\
		mem/ft_bzero.c \
		mem/ft_calloc.c \
		mem/ft_memalloc.c \
		mem/ft_memccpy.c \
		mem/ft_memchr.c \
		mem/ft_memcmp.c \
		mem/ft_memcpy.c \
		mem/ft_memdel.c \
		mem/ft_memmove.c \
		mem/ft_memset.c \
		mem/ft_realloc.c \
		mem/ft_swap.c \
		\
		put/ft_putchar.c \
		put/ft_putchar_fd.c \
		put/ft_putendl.c \
		put/ft_putendl_fd.c \
		put/ft_putnbr.c \
		put/ft_putnbr_fd.c \
		put/ft_putnbr_tab.c \
		put/ft_putstr.c \
		put/ft_putstr_fd.c \
		put/ft_putstr_tab.c \
		\
		str/ft_atoi.c \
		str/ft_atoll.c \
		str/ft_itoa.c \
		str/ft_str_isalnum.c \
		str/ft_str_isalpha.c \
		str/ft_str_isascii.c \
		str/ft_str_isdigit.c \
		str/ft_str_islower.c \
		str/ft_str_isprint.c \
		str/ft_str_isupper.c \
		str/ft_str_tolower.c \
		str/ft_str_toupper.c \
		str/ft_strcat.c \
		str/ft_strchr.c \
		str/ft_strchri.c \
		str/ft_strclr.c \
		str/ft_strcmp.c \
		str/ft_strcpy.c \
		str/ft_strdel.c \
		str/ft_strdup.c \
		str/ft_stredit.c \
		str/ft_striter.c \
		str/ft_striteri.c \
		str/ft_strjoin.c \
		str/ft_strlcat.c \
		str/ft_strlcpy.c \
		str/ft_strlen.c \
		str/ft_strmap.c \
		str/ft_strmapi.c \
		str/ft_strncat.c \
		str/ft_strncmp.c \
		str/ft_strncpy.c \
		str/ft_strndup.c \
		str/ft_strnew.c \
		str/ft_strnstr.c \
		str/ft_strrchr.c \
		str/ft_strrchri.c \
		str/ft_strsplit.c \
		str/ft_strstr.c \
		str/ft_strsub.c \
		str/ft_strsurr.c \
		str/ft_strtrim.c \
		\
		ft_printf/ft_printf.c \
		ft_printf/pf_dispatch.c \
		ft_printf/pf_parsing.c \
		ft_printf/pf_print_char.c \
		ft_printf/pf_print_hex.c \
		ft_printf/pf_print_nbr.c \
		ft_printf/pf_print_ptr.c \
		ft_printf/pf_print_str.c \
		ft_printf/pf_put.c \
		\
		get_next_line/get_next_line.c

FLAGS = -Wall -Wextra -Werror

INC = -I $(INC_DIR)
INC_DIR = includes

OBJ = $(SRC:.c=.o)
OBJ_DIR = objects
OBJ_SUB_DIRS = char list math mem put str ft_printf get_next_line
OBJ_PRE = $(addprefix $(OBJ_DIR)/, $(OBJ))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(MAGENTA)[$(DIR_NAME)] $(GREEN)Compiling $(BLUE)$^$(WHITE) > $(CYAN)$@$(WHITE)"
	@gcc $(FLAGS) $(INC) -c $^ -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(addprefix $(OBJ_DIR)/, $(OBJ_SUB_DIRS))

$(NAME): $(OBJ_DIR) $(OBJ_PRE)
	@echo "$(MAGENTA)[$(DIR_NAME)] $(GREEN)Compiling $(YELLOW)$(NAME)$(WHITE) < $(CYAN).o files$(WHITE)"
	@ar rcs $(NAME) $(OBJ_PRE)

clean:
	@echo "$(MAGENTA)[$(DIR_NAME)] $(RED)Removed $(CYAN)objects$(WHITE)"
	@rm -rf $(OBJ_DIR)

del:
	@echo "$(MAGENTA)[$(DIR_NAME)] $(RED)Removed $(YELLOW)$(NAME)$(WHITE)"
	@rm -f $(NAME)
	@rm -f a.out

fclean: clean del

re: fclean all

.PHONY: all clean del fclean re