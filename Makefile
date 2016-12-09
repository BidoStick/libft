# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 14:33:35 by jgoncalv          #+#    #+#              #
#    Updated: 2016/12/09 12:52:21 by jgoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LDFLAGS = -L.

LDLIBS = -lft

SRC_PATH = .

SRC_NAME = ft_putchar.c\
		ft_putchar_fd.c\
		ft_putstr.c\
		ft_putnstr.c\
		ft_putstr_fd.c\
		ft_putnbr.c\
		ft_putnbr_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_strlen.c\
		ft_strdup.c\
		ft_strcpy.c\
		ft_strncpy.c\
		ft_strcat.c\
		ft_strncat.c\
		ft_strlcat.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strstr.c\
		ft_strnstr.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_strsplit.c\
		ft_strtoupper.c\
		ft_atoi.c\
		ft_itoa.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_lstadd_end.c\
		ft_realloc.c\
		ft_tabnew.c\
		ft_tablen.c\
		ft_realloc_tab.c\
		ft_uitoa.c\
		ft_uitoa_base.c\
		ft_putwchar.c\
		ft_putwstr.c\
		ft_printf.c\
		ft_printf_flag.c\
		ft_wstrlen.c\
		ft_wcharlen.c\

AR = ar rc

CPPFLAGS = -Iinclude

OBJ_PATH = .

OBJ_NAME = $(SRC:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
