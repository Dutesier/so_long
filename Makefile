# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dareias- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 19:34:16 by dareias-          #+#    #+#              #
#    Updated: 2021/10/19 17:47:59 by dareias-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Name
NAME	= so_long

# Compiler
CC		= gcc

# Flags
CFLAGS	= -Wall -Werror -Wextra
MLXF	= -L ./mlx -lmlx -framework OpenGL -framework AppKit

# Library Management
AR		= ar rc
L_FDER	= lib
L_FLE	= so_long.a

# Folder Management
RM		= rm -rf
MKFDER	= mkdir -p

# Colors
NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'


# Files
INC		= -I ./mlx -I ./includes
SRCS	= srcs/main.c \
		  srcs/display.c \
		  srcs/hooks.c \
		  srcs/loops.c \
		  srcs/render.c \
		  srcs/movement.c \
		  srcs/gamestate.c \
		  render/textures.c \
		  render/ft_map.c \
		  render/map_checker.c \
		  render/map_checker_utils.c \
		  render/sprite.c \
		  render/tile.c \
		  utils/ft_strcmp.c \
		  utils/cleaning.c \
		  gnl/get_next_line.c \
		  gnl/get_next_line_utils.c \
		  

OBJS	= ${SRCS:.c=.o}

# Rules
.c.o:
			${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS}
			@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)... -" $(NONE)
			@cd mlx && $(MAKE)
			@${CC} ${CFLAGS} ${OBJS} ${INC} ${MLXF} -o ${NAME}
			@mv -f mlx/libmlx.dylib libmlx.dylib
			@echo ${GREEN}"- Compiled -"${NONE}

clean:
			${RM} ${OBJS}
			${RM} ${NAME}

fclean:		clean
			${RM} ${L_FDER}/${L_FLE}
			${RM} ${L_FDER}

re:			fclean all

norm:
			norminette ${INC} ${SRCS}

.PHONY:		all clean fclean re

