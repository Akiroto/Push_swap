# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 17:41:48 by lseiller          #+#    #+#              #
#    Updated: 2022/04/11 17:16:11 by lseiller         ###   ########.fr        #
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
MAKEFLAGS 	+=	--silent

## DIRECTORIES ##
SRCS		=	./srcs
DIR			=	./

# CMDS #
RM			=	rm -rf
CP			=	cp -f

# COMPILED_SOURCES #
BONUS		=	checker
PUSH_SWAP	=	push_swap
LIBFT		=	libft

# **************************************************************************** #

all:			$(PUSH_SWAP)

$(LIBFT):
				echo -n	"\033[2K\r$(_BLUE)$(_BOLD)$(LIBFT) $(_END)\n"
				$(MAKE) -C $(SRCS)/$(LIBFT)

$(PUSH_SWAP):	$(LIBFT)
				echo -n	"\033[2K\r$(_BLUE)$(_BOLD)$(PUSH_SWAP) $(_END)\n"
				$(MAKE) -C $(SRCS)/$(PUSH_SWAP)
				$(CP) $(SRCS)/$(PUSH_SWAP)/$(PUSH_SWAP) $(DIR)

bonus:			$(LIBFT)
				echo -n	"\033[2K\r$(_BLUE)$(_BOLD)$(BONUS) $(_END)\n"
				$(MAKE) -C $(SRCS)/$(BONUS)
				$(CP) $(SRCS)/$(BONUS)/$(BONUS) $(DIR)

clean:
				echo -n	"\033[2K\r$(_BLUE)$(_BOLD)$(LIBFT) $(_END)\n"
				make clean -C $(SRCS)/$(LIBFT)
				echo -n	"\033[2K\r$(_BLUE)$(_BOLD)$(PUSH_SWAP) $(_END)\n"
				make clean -C $(SRCS)/$(PUSH_SWAP)
				echo -n	"\033[2K\r$(_BLUE)$(_BOLD)$(BONUS) $(_END)\n"
				make clean -C $(SRCS)/$(BONUS)

fclean:
				echo -n	"\033[2K\r$(_BLUE)$(_BOLD)$(LIBFT) $(_END)\n"
				make fclean -C $(SRCS)/$(LIBFT)
				echo -n	"\033[2K\r$(_BLUE)$(_BOLD)$(PUSH_SWAP) $(_END)\n"
				make fclean -C $(SRCS)/$(PUSH_SWAP)
				$(RM) $(PUSH_SWAP)
				echo -n	"\033[2K\r$(_BLUE)$(_BOLD)$(BONUS) $(_END)\n"
				make fclean -C $(SRCS)/$(BONUS)
				$(RM) $(BONUS)

re:				fclean all

.PHONY:			all clean fclean re push_swap bonus libft
