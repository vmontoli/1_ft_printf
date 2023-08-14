# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 17:12:41 by vmontoli          #+#    #+#              #
#    Updated: 2023/08/14 10:20:51 by vmontoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:= libftprintf.a

OBJS_DIR			:= ./objs

LIBFT_DIR			:= ./libft
LIBFT_LIB			:= $(LIBFT_DIR)/libft.a


#TODO: HARDCODE THE SRCS
#BONUS_ONLY_SRCS	:= $(wildcard *_bonus.c)
#MANDATORY_SRCS		:= $(filter-out $(BONUS_ONLY_SRCS),$(wildcard *.c))
MANDATORY_SRCS		:= ft_printf.c \
						ft_printf_conv_func_char_str.c \
						ft_printf_conv_func_hex_ptr.c \
						ft_printf_conv_func_int_uint.c \
						ft_printf_detect_flags_and_conv_func.c \
						ft_printf_itoa_atoi.c \
						ft_printf_malloc_write_fail.c

MANDATORY_OBJS		:= $(MANDATORY_SRCS:%.c=$(OBJS_DIR)/%.o)
#BONUS_ONLY_OBJS	:= $(BONUS_SRCS:%.c=$(OBJS_DIR)/%.o)

BONUS_SRCS			:= $(MANDATORY_SRCS) $(BONUS_ONLY_SRCS)
BONUS_OBJS			:= $(MANDATORY_OBJS) $(BONUS_ONLY_OBJS)

CFLAGS 				:= -Wall -Werror -Wextra
ARFLAGS 			:= -rucs

.DELETE_ON_ERROR:
.PHONY: all bonus clean fclean re $(LIBFT_LIB)

all: $(NAME)

$(NAME): $(OBJS_DIR) $(MANDATORY_OBJS) $(LIBFT_LIB)
	@#TODO: SILENCE WITH '@#' ALL LINES EXCEPT ar
	@#@echo
	@#@echo "MANDATORY_SRCS:"
	@#@echo $(MANDATORY_SRCS)
	@#@echo
	@#-norminette
	@#@echo
	ar $(ARFLAGS) $(NAME) $(MANDATORY_OBJS)

bonus: $(OBJS_DIR) $(BONUS_OBJS) $(LIBFT_LIB)
	@#TODO: SILENCE WITH '@#' ALL LINES EXCEPT ar
	@#@echo
	@#@echo "MANDATORY_SRCS:"
	@#@echo $(MANDATORY_SRCS)
	@#@echo
	@#@echo "BONUS_ONLY_SRCS:"
	@#@echo $(BONUS_ONLY_SRCS)
	@#@echo
	@#-norminette
	@#@echo
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
