NAME		:=	libprintf.a

# Variables
INCLUDE_DIR	:=	include
SOURCE_DIR	:=	src
OBJ_DIR		:=	objects

COMPILE_FLAGS	:=	-Wall -Werror -Wextra
COMPILE		:=	cc -Iinclude
WITHOUT_RELINK	:=	-c

# Rules
$(NAME) :

all	:

clean	:

fclean	:

.PHONY: clean fclean all $(NAME)
