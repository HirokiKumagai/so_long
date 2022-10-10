NAME = libgnl.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
ARFLAGS := -rcs
INCLUDE = -I./include

SRCS_DIR := ./src
SRCS_DIR/ := $(if $(SRCS_DIR),$(patsubst %//,%/,$(SRCS_DIR)/),)
SRCS := $(addprefix $(SRCS_DIR/), get_next_line_bonus.c get_next_line_utils_bonus.c)

OBJS_DIR := ./objs
OBJS_DIR/ := $(if $(OBJS_DIR),$(patsubst %//,%/,$(OBJS_DIR)/),)
OBJS := $(SRCS:$(SRCS_DIR/)%.c=$(OBJS_DIR/)%.o)

OUTPUT_DIR := .
OUTPUT_DIR/ := $(if $(OUTPUT_DIR),$(patsubst %//,%/,$(OUTPUT_DIR)/),)

all: libMake $(NAME)

${NAME}: $(OBJS) $(OUTPUT_DIR/).keep
	ar $(ARFLAGS) $@ $(OBJS) $(OUTPUT_DIR/).keep

clean:
	rm -rf ${OBJS_DIR} $(OUTPUT_DIR/).keep

fclean: clean
	rm $(NAME)

re: fclean all

libMake: $(OBJS_DIR/).keep

$(OBJS_DIR/).keep $(OUTPUT_DIR/).keep:
	mkdir -p $(@D)
	touch $@

$(OBJS_DIR/)%.o: $(SRCS_DIR/)%.c
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: all clean fclean re
