COMPILER = cc
FLAGS = -Wall -Werror -Wextra
PROGRAM_NAME = fractol
MANDATORY = main.c fractal.c complex_op.c utils.c utils2.c utils3.c check_c.c
MANDATORY_OBJECTS = $(MANDATORY:.c=.o)
LIBFT_A = libft/libft.a

OS = $(shell uname -s)
LINUX_MINIMLX_A = minilibx-linux/libmlx_Linux.a -lX11 -lXext -lm
MACOS_MINIMLX_A = minilibx/libmlx.a -framework OpenGL -framework AppKit
MINIMLX_A =

ifeq ($(OS), Linux)
	MINIMLX_A +=$(LINUX_MINIMLX_A)
else ifeq ($(OS), DARWIN)
	MINIMLX_A +=$(MACOS_MINIMLX_A)
endif
all: libft libmlx mandatory

mandatory: $(MANDATORY_OBJECTS)
	$(COMPILER) $(FLAGS) $(MANDATORY_OBJECTS) $(LIBFT_A) $(MINIMLX_A) -o $(PROGRAM_NAME)

libft_all:
	cd libft ; make

libft:
	cd libft ; make

libft_clean:
	cd libft ; make clean

libft_fclean:
	cd libft ; make fclean

libft_re:
	cd libft ; make re


libmlx:
 ifeq ($(OS), Linux)
	cd minilibx-linux ; make
 else ifeq ($(OS), DARWIN)
	cd minilibx ; make
 endif
libmlx_clean:
 ifeq ($(OS), Linux)
	cd minilibx-linux ; make clean
 else ifeq ($(OS), DARWIN)
	cd minilibx ; make clean
 endif
clean: libft_clean
	rm -rf *.o *.out *.gch .vscode

fclean: clean libft_fclean
	rm -rf $(PROGRAM_NAME)

re: fclean all

.PHONY: all clean fclean re libft libft_clean libft_fclean libft_re libmlx libmlx_clean