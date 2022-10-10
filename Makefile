NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
ARFLAGS := -rcs
INCLUDE = -I./include
LDFLAGS = -Llib/ft_printf -Llib/libft -Llib/gnl
LIBS = -lftprintf -lft -lgnl

os = $(shell uname)

ifeq ($(os), Darwin)
	LIBMLX = ./minilibx-linux/libmlx.a ./minilibx-linux/libmlx_Darwin.a
	MLXFLAGS +=  -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit #-fsanitize=address
else
	LIBMLX = minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm
	MLXFLAGS +=
endif

SRCS_DIR := ./src
SRCS_DIR/ := $(if $(SRCS_DIR),$(patsubst %//,%/,$(SRCS_DIR)/),)
SRCS := $(addprefix $(SRCS_DIR/), main.c)

OBJS_DIR := ./objs
OBJS_DIR/ := $(if $(OBJS_DIR),$(patsubst %//,%/,$(OBJS_DIR)/),)
OBJS := $(SRCS:$(SRCS_DIR/)%.c=$(OBJS_DIR/)%.o)

OUTPUT_DIR := .
OUTPUT_DIR/ := $(if $(OUTPUT_DIR),$(patsubst %//,%/,$(OUTPUT_DIR)/),)

LIBFT_DIR = ./lib/libft
FT_PRINTF_DIR = ./lib/ft_printf
GNL_DIR = ./lib/gnl
MLX_DIR = ./minilibx-linux

all:  libMake ${NAME}

${NAME}: $(OBJS) $(OUTPUT_DIR/).keep
	make -C $(LIBFT_DIR)
	make -C $(FT_PRINTF_DIR)
	make -C $(GNL_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(MLXFLAGS) ${INCLUDE} $(OBJS) ${LDFLAGS} ${LIBS} $(LIBMLX) -o $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean
	make -C $(FT_PRINTF_DIR) clean
	make -C $(MLX_DIR) clean
	rm -rf $(OBJS_DIR) $(OUTPUT_DIR/).keep

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean
	rm $(NAME)

re: fclean all

libMake: $(OBJS_DIR/).keep

$(OBJS_DIR/)%.o: $(SRCS_DIR/)%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJS_DIR/).keep $(OUTPUT_DIR/).keep:
	mkdir -p $(@D)
	touch $@

.PHONY: all clean fclean re
