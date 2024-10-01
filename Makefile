# Directories
LIB_DIR        := src
ARENA_DIR      := $(LIB_DIR)/arena
VECTOR_DIR     := $(LIB_DIR)/vector
PRINTF_DIR     := $(LIB_DIR)/printf
INC_DIR        := include
INT_DIR        := internal

# Library files by category
LIB_FILES      := ft_memcpy.c ft_memset.c ft_strlen.c \
                  ft_isdigit.c ft_isspace.c

LIB_FILES      := int_parse.c int_format.c uint_format.c

ARENA_FILES    := arena.c arena_str.c

VECTOR_FILES   := vector.c strv_dup.c strv_ndup.c

PRINTF_FILES   := ft_printf.c ft_dprintf.c ft_vdprintf.c \
                  append_chars.c append_ints.c pribuf.c

SRCS           := $(addprefix $(LIB_DIR)/, $(LIB_FILES)) \
                  $(addprefix $(ARENA_DIR)/, $(ARENA_FILES)) \
                  $(addprefix $(VECTOR_DIR)/, $(VECTOR_FILES)) \
                  $(addprefix $(PRINTF_DIR)/, $(PRINTF_FILES))

# Header files
INC_FILES      := libft.h arena.h vector.h
INT_FILES      := pribuf.h

INCS           := $(addprefix $(INC_DIR)/, $(INC_FILES)) \
                  $(addprefix $(INT_DIR)/, $(INT_FILES))

# Object and dependency files
OBJS           := $(SRCS:.c=.o)
DEPS           := $(OBJS:.o=.d)

# Build configuration
NAME           := libft.a
CC             := clang
CFLAGS         := -Wall -Wextra -Werror
CFLAGS         += -MMD -g3 -fsanitize=address,undefined
CFLAGS         += -I$(INC_DIR) -I$(INT_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

norm:
	-norminette $(SRCS) $(INCS)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all norm clean fclean re
