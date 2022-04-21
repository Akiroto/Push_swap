# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 00:14:08 by lseiller          #+#    #+#              #
#    Updated: 2022/04/11 16:39:40 by lseiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS #
_END		=	\e[0m
_BOLD		=	\e[1m
_GREY		=	\e[30m
_RED		=	\e[31m
_GREEN		=	\e[32m
_YELLOW		=	\e[33m
_BLUE		=	\e[34m

## VARIABLES ##

# FLAGS #
MAKEFLAGS	+=	--silent
CC			=	clang
CC_FLAGS	=	-Wall -Wextra -Werror
LDFLAGS		=	-L$(DIR_LIBFT) -lft

# CMDS #
RM			=	rm -rf

# DIRECTORIES #
DIR_HEADERS =	includes/
DIR_SRCS	=	srcs/
DIR_OBJS	=	objs/
DIR_LIBFT	=	../libft/

# FILES #
SRCS			=	push_swap.c \
				index.c\
				list_tools.c \
				push.c \
				reverse_rotate.c \
				rotate.c \
				swap.c \
				parse_tools.c \
				parse.c \
				big_sort.c \
				pre_sort_to_b.c \
				small_sort.c \
				sort_to_a.c \
				sort_tools.c

# COMPILED_SOURCES #
OBJS 		=	$(SRCS:%.c=$(DIR_OBJS)%.o)
NAME 		=	push_swap

# **************************************************************************** #

all:			$(NAME)

$(NAME):		$(OBJS)
				echo -n "\033[2K\r✔️$(_GREEN) All files compiled into '$(DIR_OBJS)'. $(_END)\n"
				$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) $(OBJS) ${LDFLAGS} -o $(NAME) || ${MAKE} ${NAME}
				echo -n "\033[2K\r✔️$(_GREEN) Program '$(NAME)' created. $(_END)\n"

$(OBJS):		| $(DIR_OBJS)

$(DIR_OBJS)%.o: $(DIR_SRCS)%.c
				echo -n "\033[2K\r $(_YELLOW)Compiling $< $(_END)"
				$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) -c $< -o $@

$(DIR_OBJS):
				mkdir $(DIR_OBJS)
clean:
				$(RM) $(DIR_OBJS)
				echo -n "\033[2K\r$(_RED) '"$(DIR_OBJS)"' has been deleted. $(_END)\n"

fclean:			clean
				$(RM) $(NAME)
				echo -n "\033[2K\r$(_RED) '"$(NAME)"' has been deleted. $(_END)\n"

re:				fclean all

.PHONY:			all clean fclean re
