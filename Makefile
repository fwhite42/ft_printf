NAME			:=	libprintf.a

# Variables
INCLUDE_DIRECTORY	:=	include
OBJECT_DIRECTORY	:=	objects
SOURCE_DIRECTORIES	:=	main parse print utils 

COMPILE_FLAGS		:=	-Wall -Werror -Wextra
COMPILE			:=	cc
WITHOUT_LINKING		:=	-c

$(OBJECT_DIRECTORY):
	mkdir objets
# Rules
$(NAME) :


all	:

clean	:

fclean	:

.PHONY: clean fclean all $(NAME)
