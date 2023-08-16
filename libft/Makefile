# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 11:49:16 by vmontoli          #+#    #+#              #
#    Updated: 2023/08/16 07:52:47 by vmontoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:= libft.a

OBJS_DIR			:= ./objs
HEADER				:= libft.h

ALL_SRCS			:= ft_atoi.c ft_calloc.c ft_char_is_in_str.c \
					ft_isascii_more.c ft_isupper_islower.c ft_itoa.c \
					ft_memcpy_memmove.c ft_memset_bzero.c ft_putnbr.c \
					ft_putstr_more.c ft_size_t_max_min.c ft_split.c \
					ft_strchr_memchr.c ft_strdup.c ft_striteri_strmapi.c \
					ft_strjoin.c ft_strlcpy_strlcat.c ft_strlen.c \
					ft_strncmp_memcmp.c ft_strnstr.c ft_strtrim.c \
					ft_substr.c ft_toupper_tolower.c \
					ft_lstadd_front_bonus.c ft_lstdelone_clear_iter_bonus.c \
					ft_lstmap_bonus.c ft_lstnew_bonus.c \
					ft_lstsize_last_back_bonus.c

ALL_OBJS			:= $(ALL_SRCS:%.c=$(OBJS_DIR)/%.o)

COMMON_DEPS			:= $(HEADER) Makefile

CFLAGS 				:= -Wall -Werror -Wextra
ARFLAGS 			:= -rucs

.DELETE_ON_ERROR:
.PHONY: all bonus clean fclean re

all bonus: $(NAME)

$(NAME): $(ALL_OBJS)
	@#echo $(MANDATORY_SRCS)
	@#norminette $(MANDATORY_SRCS) $(HEADER)
	ar $(ARFLAGS) $(NAME) $(ALL_OBJS)

$(OBJS_DIR)/%.o: %.c $(COMMON_DEPS) | $(OBJS_DIR)
	cc $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	rm -r $(OBJS_DIR) | true

fclean:
	rm -r $(OBJS_DIR) | true
	rm $(NAME) | true

re: fclean all
