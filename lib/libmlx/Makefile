# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 16:48:08 by bda-silv          #+#    #+#              #
#*   Updated: 2023/09/29 03:39:25 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

PROJ				=	libmlx

# MLX support for Linux and macOS:
# Compiled library will be avaliable at lib/mlx/libmlx.a

# **************************************************************************** #
#                           Paths
# **************************************************************************** #

NAME				=	$(addsuffix .a, $(PROJ))
DIR					=	$(shell uname -s)

# **************************************************************************** #
#                           Settings
# **************************************************************************** #

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror

MD					=	mkdir -p
AR					=	ar rcs
RL					=	ranlib
RM					=	rm -rf
MK					=	make -C
CP					=	cp

# **************************************************************************** #
#                           Rules
# **************************************************************************** #

all :  $(NAME)

$(NAME) :
	${AT} ${MK} $(DIR) ${BLK}
	${AT} ${COMPILED} $@ ${BLK}
	${AT} ${CP} $(DIR)/$(NAME) . ${BLK}

clean :
	${AT} ${MK} ${DIR} $@ ${BLK}

fclean : clean
	${AT} $(RM) $(NAME) ${BLK}
	${AT} $(DELETED) $(NAME) $(BLK)

re : fclean all

.PHONY : all clean fclean re

# **************************************************************************** #
#                           Norminette
# **************************************************************************** #

.PHONY: norm
norm:
	${AT}${msg} "$(pnk)\c"; \
	norminette ${SRCS} ${INCD} | grep "Error" || \
	${msg} "$(grn)$(ok)	Norminette		OK!" ${BLK}

# **************************************************************************** #
#                           Visuals
# **************************************************************************** #

ok:=✓
ko:=✗
ck:=・

s:=\033[0
red:=$s31m
grn:=$s32m
yel:=$s33m
blu:=$s34m
pnk:=$s35m
cya:=$s36m
wht:=$s37m
rst:=$s00m
ora:=$s38;2;255;153;0m
msg:=echo "${rst}"

_CPLD		:= ${grn}${ok}	Compiled		${}
_CRTD		:= ${ora}${ck}	Creating		${}
_DELD		:= ${red}${ko}	Removing		${}

COMPILED	:= ${msg} "$(_CPLD)"
CREATED		:= ${msg} "$(_CRTD)"
DELETED		:= ${msg} "$(_DELD)"

# **************************************************************************** #
#                          Verbose Check
# **************************************************************************** #

# Verbose levels:
# 0: Make will be totaly silenced
# 1: Make will print echos and printf
# 2: Make will not be silenced but target commands will not be printed
# 3: Make will print each command
# 4: Make will print all debug info
#
# If no value is specified or an incorrect value is given make will print only
# echoes like if VERBOSE was set to 1.

VERBOSE		:= 1

ifeq (${VERBOSE}, 0)
	MAKEFLAGS += --silent
	BLK := >/dev/null 2>&1
else ifeq (${VERBOSE}, 1)
	MAKEFLAGS += --silent
	BLK := 2>/dev/null
	AT := @
else ifeq (${VERBOSE}, 2)
	AT := @
else ifeq (${VERBOSE}, 4)
	MAKEFLAGS += --debug=v
endif

# **************************************************************************** #
