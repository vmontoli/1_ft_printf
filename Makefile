# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 17:12:41 by vmontoli          #+#    #+#              #
#    Updated: 2023/07/28 17:33:00 by vmontoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:= libftprintf.a

OBJS_DIR			:= ./objs

#TODO: HARDCODE THE SRCS
BONUS_ONLY_SRCS		:= $(wildcard *_bonus.c)
MANDATORY_SRCS		:= $(filter-out $(BONUS_ONLY_SRCS),$(wildcard *.c))

#TODO: CONFIRM HEADERS (FOR NORMINETTE TESTING)
BONUS_ONLY_HEADER	:= ft_printf_bonus.h
MANDATORY_HEADER	:= ft_printf.h

MANDATORY_OBJS		:= $(MANDATORY_SRCS:%.c=$(OBJS_DIR)/%.o)
BONUS_ONLY_OBJS		:= $(BONUS_SRCS:%.c=$(OBJS_DIR)/%.o)

BONUS_SRCS			:= $(MANDATORY_SRCS) $(BONUS_ONLY_SRCS)
BONUS_OBJS			:= $(MANDATORY_OBJS) $(BONUS_ONLY_OBJS)

CFLAGS 				:= -Wall -Werror -Wextra
ARFLAGS 			:= -crs

.DELETE_ON_ERROR:
.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJS_DIR) $(MANDATORY_OBJS)
	@#TODO: SILENCE WITH '@#' ALL LINES EXCEPT ar
	@echo "MANDATORY_SRCS:"
	@echo $(MANDATORY_SRCS)
	@echo
	norminette $(MANDATORY_SRCS) $(MANDATORY_HEADER)
	@echo
	ar $(ARFLAGS) $(NAME) $(MANDATORY_OBJS)

bonus: $(OBJS_DIR) $(BONUS_OBJS)
	@#TODO: SILENCE WITH '@#' ALL LINES EXCEPT ar
	@echo "MANDATORY_SRCS:"
	@echo $(MANDATORY_SRCS)
	@echo
	@echo "BONUS_ONLY_SRCS:"
	@echo $(BONUS_ONLY_SRCS)
	@echo
	norminette $(BONUS_SRCS) $(BONUS_HEADER)
	@echo
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