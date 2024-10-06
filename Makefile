# Directories
LIBFT_DIR      := src
ARENA_DIR      := $(LIBFT_DIR)/arena
VECTOR_DIR     := $(LIBFT_DIR)/vector
PRINTF_DIR     := $(LIBFT_DIR)/printf
CIRBUF_DIR     := $(LIBFT_DIR)/cirbuf
INC_DIR        := include
INT_DIR        := internal

# Source files
LIBFT_FILES    := ft_memcpy.c ft_memset.c ft_strlen.c \
                  ft_isdigit.c ft_isspace.c \
                  ft_qsort.c

LIBFT_FILES    += int_parse.c int_format.c uint_format.c

ARENA_FILES    := arena.c scratch.c arena_str.c alloc.c

VECTOR_FILES   := vector.c strv_dup.c strv_ndup.c \
                  strv_split.c intv_parse.c

PRINTF_FILES   := ft_printf.c ft_dprintf.c ft_vdprintf.c \
                  append_chars.c append_ints.c pribuf.c \
                  ft_puts.c

CIRBUF_FILES   := cirbuf.c cirbuf_ops.c cirbuf_peek.c \
                  cirbuf_shift.c

# Header files
INC_FILES      := libft.h arena.h vector.h cirbuf.h
INT_FILES      := pribuf.h

# Sources list
SRCS           := $(addprefix $(LIBFT_DIR)/, $(LIBFT_FILES)) \
                  $(addprefix $(ARENA_DIR)/, $(ARENA_FILES)) \
                  $(addprefix $(VECTOR_DIR)/, $(VECTOR_FILES)) \
                  $(addprefix $(PRINTF_DIR)/, $(PRINTF_FILES)) \
                  $(addprefix $(CIRBUF_DIR)/, $(CIRBUF_FILES))

# Includes list
INCS           := $(addprefix $(INC_DIR)/, $(INC_FILES)) \
                  $(addprefix $(INT_DIR)/, $(INT_FILES))

# Objects and dependencies
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
