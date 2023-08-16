# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 17:12:41 by vmontoli          #+#    #+#              #
#    Updated: 2023/08/16 07:54:27 by vmontoli         ###   ########.fr        #
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

COMMON_DEPS			:= Makefile ft_printf.h libft/libft.h

.DELETE_ON_ERROR:
.PHONY: all bonus clean fclean re always

all: $(NAME)

$(NAME): $(MANDATORY_OBJS) $(LIBFT_LIB)
	@#TODO: SILENCE WITH '@#' ALL LINES EXCEPT ar
	@#@echo
	@#@echo "MANDATORY_SRCS:"
	@#@echo $(MANDATORY_SRCS)
	@#@echo
	@#-norminette
	@#@echo
	cp $(LIBFT_LIB) $(NAME)
	ar $(ARFLAGS) $(NAME) $(MANDATORY_OBJS)

bonus: $(BONUS_OBJS) $(LIBFT_LIB)
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
	cp $(LIBFT_LIB) $(NAME)
	ar $(ARFLAGS) $(NAME) $(BONUS_OBJS)

$(LIBFT_LIB): always
	@echo
	@echo "___ Building libft: ___"
	$(MAKE) -C $(LIBFT_DIR)
	@echo " __ libft built __ "
	@echo

$(OBJS_DIR)/%.o: %.c $(COMMON_DEPS) | $(OBJS_DIR)
	@#TODO: Remove the minus of cc
	cc $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -r $(OBJS_DIR) | true

fclean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -r $(OBJS_DIR) | true
	rm $(NAME) | true

re: fclean all
