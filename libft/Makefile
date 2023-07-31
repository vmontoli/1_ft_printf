# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 11:49:16 by vmontoli          #+#    #+#              #
#    Updated: 2023/05/21 01:40:35 by vmontoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:= libft.a

OBJS_DIR			:= ./objs
HEADER				:= libft.h

#MANDATORY_SRCS		:= $(flter-out $(wildcard *_bonus.c),$(wildcard *.c))
MANDATORY_SRCS		:= ft_atoi.c ft_calloc.c ft_char_is_in_str.c \
					ft_isascii_more.c ft_isupper_islower.c ft_itoa.c \
					ft_memcpy_memmove.c ft_memset_bzero.c ft_putnbr.c \
					ft_putstr_more.c ft_size_t_max_min.c ft_split.c \
					ft_strchr_memchr.c ft_strdup.c ft_striteri_strmapi.c \
					ft_strjoin.c ft_strlcpy_strlcat.c ft_strlen.c \
					ft_strncmp_memcmp.c ft_strnstr.c ft_strtrim.c \
					ft_substr.c ft_toupper_tolower.c
MANDATORY_OBJS		:= $(MANDATORY_SRCS:%.c=$(OBJS_DIR)/%.o)

#BONUS_SRCS			:= $(wildcard *.c)
BONUS_SRCS			:= $(MANDATORY_SRCS) \
					ft_lstadd_front_bonus.c ft_lstdelone_clear_iter_bonus.c \
					ft_lstmap_bonus.c ft_lstnew_bonus.c \
					ft_lstsize_last_back_bonus.c
BONUS_OBJS			:= $(BONUS_SRCS:%.c=$(OBJS_DIR)/%.o)

CFLAGS 				:= -Wall -Werror -Wextra
ARFLAGS 			:= -crs

.DELETE_ON_ERROR:
.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJS_DIR) $(MANDATORY_OBJS)
	@#echo $(MANDATORY_SRCS)
	@#norminette $(MANDATORY_SRCS) $(HEADER)
	ar $(ARFLAGS) $(NAME) $(MANDATORY_OBJS)

bonus: $(OBJS_DIR) $(BONUS_OBJS)
	@#echo $(MANDATORY_SRCS)
	@#echo $(filter $(wildcard *_bonus.c),$(BONUS_SRCS))
	@#norminette $(BONUS_SRCS) $(HEADER)
	ar $(ARFLAGS) $(NAME) $(BONUS_OBJS)

$(OBJS_DIR)/%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	-rm -r $(OBJS_DIR)

fclean: clean
	-rm $(NAME)

re: fclean all
