# **************************************************************************** #
#                                  Makefile                                    #
# **************************************************************************** #

NAME = ../cub3d

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fPIE --sanitize=address

SRCDIR = srcs
EXECDIR = $(SRCDIR)/exec
PARDIR = $(SRCDIR)/parsing
MOVDIR = $(SRCDIR)/movement
UTILDIR = $(SRCDIR)/utils



INCDIR = ./include
LIBFTDIR = ../libft
MLXDIR = ../mlx
OBJDIR = objs

SRCS =	$(SRCDIR)/main.c \
		$(PARDIR)/parsing.c $(PARDIR)/map.c $(PARDIR)/texture.c \
		$(EXECDIR)/exec.c $(EXECDIR)/get_rayon_data.c $(EXECDIR)/graphical.c \
		$(EXECDIR)/get_color.c \
		$(MOVDIR)/key_controls.c $(MOVDIR)/move_player.c $(MOVDIR)/rotate_camera.c \
		$(UTILDIR)/free.c $(UTILDIR)/free_graphical.c

OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFTDIR)/libft.a
MLX = $(MLXDIR)/libmlx.a
LIBS = -L$(LIBFTDIR) -lft -L$(MLXDIR) -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

INCLUDES = -I $(INCDIR) -I $(LIBFTDIR) -I $(MLXDIR) -I/usr/include

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -I include -o $(NAME)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

clean:
	@$(MAKE) -C $(LIBFTDIR) clean
	$(RM) -f $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFTDIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
