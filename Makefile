# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 02:50:40 by fwhite42          #+#    #+#              #
#    Updated: 2024/01/19 10:35:06 by fwhite42         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	libprintf.a

# **************************************************************************** #
# Description
# ...
#
###############################################################################
# Directories

INCLUDE_DIR			:=	include main
OBJ_DIR				:=	objects
SRC_DIR				:=	main parse print utils

###############################################################################
# Files To Compile

MAIN_FILES			:=\
					  main/ft_printf.c
PARSE_FILES			:=\
					  parse/ftpf_parsing_actions.c	\
					  parse/ftpf_parse.c
PRINT_FILES			:=\
					  print/ftpf_print_c.c			\
					  print/ftpf_print_d.c			\
					  print/ftpf_print_i.c			\
					  print/ftpf_print_p.c			\
					  print/ftpf_print_s.c			\
					  print/ftpf_print_u.c			\
					  print/ftpf_print_x_lc.c		\
					  print/ftpf_print_x_up.c
UTIL_FILES			:=\
					  utils/ftpf_character_utils.c	\
					  utils/ftpf_number_utils.c		\
					  utils/ftpf_read_write_utils.c
ALL_FILES			:=\
					  $(MAIN_FILES)					\
					  $(PARSE_FILES)				\
					  $(PRINT_FILES)				\
					  $(UTIL_FILES)

###############################################################################
# Archives to be created

ARCHIVE_LIST	:=	main.a print.a parse.a utils.a

###############################################################################
# Objects To Archive

MAIN_OBJECTS		:= $(MAIN_FILES:main/%.c=objects/%.o)
PARSE_OBJECTS		:= $(PARSE_FILES:parse/%.c=objects/%.o)
PRINT_OBJECTS 		:= $(PRINT_FILES:print/%.c=objects/%.o)
UTIL_OBJECTS 		:= $(UTIL_FILES:utils/%.c=objects/%.o)
ALL_OBJECTS			:=\
					  $(MAIN_OBJECTS)				\
					  $(PARSE_OBJECTS)				\
					  $(PRINT_OBJECTS)				\
					  $(UTIL_OBJECTS)

###############################################################################
# Compile Options

COMPILE_CMD			:=	cc
WITHOUT_LINKING		:=	-c
COMPILE_FLAGS		:=	-Wall -Werror -Wextra
INCLUDE_HEADERS		:=	$(INCLUDE_DIR:%=-I%)
COMPILE				:=\
					  $(COMPILE_CMD)				\
					  $(COMPILE_FLAGS)				\
					  $(WITHOUT_LINKING)			\
					  $(INCLUDE_HEADERS)			

###############################################################################
# Compilation Rules

objects				:
	mkdir objects

$(MAIN_OBJECTS)		: objects/%.o:main/%.c objects
	@$(COMPILE) $< -o $@
$(PARSE_OBJECTS) 	: objects/%.o:parse/%.c objects
	@$(COMPILE) $< -o $@
$(PRINT_OBJECTS) 	: objects/%.o:print/%.c objects
	@$(COMPILE) $< -o $@
$(UTIL_OBJECTS) 	: objects/%.o:utils/%.c objects
	@$(COMPILE) $< -o $@

###############################################################################
# Archive Options`

ARCHIVE_CMD			:= ar
ARCHIVE_FLAGS		:= -rcs
ARCHIVE				:= $(ARCHIVE_CMD) $(ARCHIVE_FLAGS)

define make_archive
	mkdir -p lib
	$(ARCHIVE) $1 $2
	$(MAKE) clean
endef

###############################################################################
# Rules (user defined)

./lib/main.a	: $(MAIN_OBJECTS)
	$(call make_archive,$@,$^)
./lib/parse.a	: $(PARSE_OBJECTS)
	$(call make_archive,$@,$^)
./lib/print.a	: $(PRINT_OBJECTS)
	$(call make_archive,$@,$^)
./lib/utils.a	: $(UTIL_OBJECTS)
	$(call make_archive,$@,$^)

###############################################################################
# Rules (mandatory)

$(NAME) : $(ARCHIVE_LIST:%=./lib/%)
	$(ARCHIVE) $@ $^

all		:
	$(MAKE) $(NAME)

clean	:
	rm -r objects

fclean	:
	rm -f *.a
	rm -rf lib

re		: fclean $(NAME)

.PHONY	: all clean fclean $(NAME) re
