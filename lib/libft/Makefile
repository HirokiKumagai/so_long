NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

ARFLAGS := -rcs

SRCS_DIR = ./src

SRCS_DIR/ := $(if $(SRCS_DIR),$(patsubst %//,%/,$(SRCS_DIR)/),)

SRCS := $(addprefix $(SRCS_DIR/),ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstsearch.c ft_atoi_error.c ft_strcount.c)

OBJS_DIR := ./objs

OBJS_DIR/ := $(if $(OBJS_DIR),$(patsubst %//,%/,$(OBJS_DIR)/),)

OBJS := $(SRCS:$(SRCS_DIR/)%.c=$(OBJS_DIR/)%.o)

RM = rm -rf

OUTPUT_DIR := .

OUTPUT_DIR/ := $(if $(OUTPUT_DIR),$(patsubst %//,%/,$(OUTPUT_DIR)/),)

all: ${NAME}

$(NAME): $(OBJS) $(OUTPUT_DIR/).keep
	ar $(ARFLAGS) $@ $^

clean:
	${RM} ${OBJS_DIR} $(OUTPUT_DIR/).keep

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re mkd

$(OBJS_DIR/)%.o: $(SRCS_DIR/)%.c $(OBJS_DIR/).keep
	$(COMPILE.c) $< -o $@

$(OUTPUT_DIR/).keep $(OBJS_DIR/).keep:
	mkdir -p $(@D)
	touch $@
