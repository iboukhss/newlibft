CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -MMD -g3 -fsanitize=address,undefined

LIB_NAME = libft.a

vpath %.c libft libft/arena
vpath %.h include

LIB_INCS = libft.h arena.h

# Standard libc
LIB_SRCS := ft_memcpy.c ft_memset.c
LIB_SRCS += ft_strlen.c

# Arena lib
LIB_SRCS += arena.c scratch.c arena_str.c

LIB_OBJS = $(LIB_SRCS:.c=.o)
LIB_DEPS = $(LIB_OBJS:.o=.d)

all: $(LIB_NAME)

$(LIB_NAME): $(LIB_OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

norm: $(LIB_INCS) $(LIB_SRCS)
	-norminette $^

clean:
	rm -f *.o *.d

fclean:
	rm -f $(LIB_NAME)

re: fclean all

-include $(LIB_DEPS)

.PHONY: all norm clean fclean re
