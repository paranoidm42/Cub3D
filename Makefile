MAKEFLAGS	= --silent
LOCLIBFT	= ./lib/libft
LOCHEADER	= ./inc
SRCDIR		= ./src
SRCS		= $(shell find $(SRCDIR) -name '*.c')
OBJS		= $(SRCS:.c=.o)
NAME		= cub3d
RM			= rm -f
OS			= $(shell uname)
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

ifeq ($(OS), Linux)
	MLX		= lib/libmlx/Linux
	MLX_LNK	= -L $(MLX) -l mlx -lXext -lX11
else
	MLX		= lib/libmlx/Darwin
	MLX_LNK	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit
endif

all: $(NAME)

%.o: %.c
	@${CC} -c $< -o ${<:.c=.o}
	@printf "\033[0;32m#\e[m"

$(NAME): main.c $(LOCLIBFT)/libft.a $(OBJS) $(LOCHEADER)/$(NAME).h $(MLX)/libmlx.a
	$(CC) $(CFLAGS) main.c $(OBJS) $(MLX_LNK) -O3 -o $(NAME) -L $(LOCLIBFT) -lft -lm
	@printf "\033[0;33m cub3d compiled [OK]\e[m\n"

$(LOCLIBFT)/libft.a:
	make -C $(LOCLIBFT)

$(MLX)/libmlx.a:
	make -C $(MLX)

clean:
	make clean -C $(MLX)
	make clean -C $(LOCLIBFT)
	$(RM) $(OBJS)
	@printf "\033[0;33m cub3d cleaned [OK]\e[m\n"

fclean: clean
	make fclean -C $(LOCLIBFT)
	$(RM) $(NAME)

re: fclean all

norminette:
	norminette -R CheckDefineForbiddenSourceHeader

.PHONY: all $(NAME) clean fclean re norminette
