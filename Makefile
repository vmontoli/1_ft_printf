# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 17:12:41 by vmontoli          #+#    #+#              #
#    Updated: 2023/08/14 08:10:08 by vmontoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:= libftprintf.a

OBJS_DIR			:= ./objs

LIBFT_DIR			:= ./libft
LIBFT_LIB			:= $(LIBFT_DIR)/libft.a


#TODO: HARDCODE THE SRCS
BONUS_ONLY_SRCS		:= $(wildcard *_bonus.c)
MANDATORY_SRCS		:= $(filter-out $(BONUS_ONLY_SRCS),$(wildcard *.c))

MANDATORY_OBJS		:= $(MANDATORY_SRCS:%.c=$(OBJS_DIR)/%.o)
BONUS_ONLY_OBJS		:= $(BONUS_SRCS:%.c=$(OBJS_DIR)/%.o)

BONUS_SRCS			:= $(MANDATORY_SRCS) $(BONUS_ONLY_SRCS)
BONUS_OBJS			:= $(MANDATORY_OBJS) $(BONUS_ONLY_OBJS)

CFLAGS 				:= -Wall -Werror -Wextra
ARFLAGS 			:= -rucs

.DELETE_ON_ERROR:
.PHONY: all bonus clean fclean re $(LIBFT_LIB)

all: $(NAME)

$(NAME): $(OBJS_DIR) $(MANDATORY_OBJS) $(LIBFT_LIB)
	@#TODO: SILENCE WITH '@#' ALL LINES EXCEPT ar
	@echo
	@echo "MANDATORY_SRCS:"
	@echo $(MANDATORY_SRCS)
	@echo
	-norminette
	@echo
	ar $(ARFLAGS) $(NAME) $(MANDATORY_OBJS)

bonus: $(OBJS_DIR) $(BONUS_OBJS) $(LIBFT_LIB)
	@#TODO: SILENCE WITH '@#' ALL LINES EXCEPT ar
	@echo
	@echo "MANDATORY_SRCS:"
	@echo $(MANDATORY_SRCS)
	@echo
	@echo "BONUS_ONLY_SRCS:"
	@echo $(BONUS_ONLY_SRCS)
	@echo
	#@-norminette
	@echo
	ar $(ARFLAGS) $(NAME) $(BONUS_OBJS)

$(LIBFT_LIB):
	@echo
	@echo "___ Building libft: ___"
	cd $(LIBFT_DIR) && $(MAKE)
	@echo " __ libft built __ "
	cp $(LIBFT_LIB) $(NAME)
	@echo

$(OBJS_DIR)/%.o: %.c
	@#TODO: Remove the minus of cc
	cc $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	cd $(LIBFT_DIR) && $(MAKE) clean
	-rm -r $(OBJS_DIR)

fclean:
	cd $(LIBFT_DIR) && $(MAKE) fclean
	-rm -r $(OBJS_DIR)
	-rm $(NAME)

re: fclean all
