# Directories
SRC_DIR        := src
ARENA_DIR      := $(SRC_DIR)/arena
INC_DIR        := include
INT_DIR        := internal

# Source files
SRC_FILES      := ft_memcpy.c ft_memset.c ft_strlen.c
ARENA_FILES    := arena.c arena_str.c scratch.c
SRCS           := $(addprefix $(SRC_DIR)/, $(SRC_FILES)) \
                  $(addprefix $(ARENA_DIR)/, $(ARENA_FILES))

# Header files
INC_FILES      := libft.h arena.h
INT_FILES      := 
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
