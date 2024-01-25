# **************************************************************************** #
#                                                                              #
#                                                                              #
#    Makefile                                                4 2               #
#                                                         (@)-=-(@)            #
#    By: fwhite42 <FUCK THE NORM>                          (  o  )             #
#                                                        _/'-----'\_           #
#    Created: 2024/01/21 17:24:42 by fwhite42          \\ \\     // //         #
#    Updated: 2024/01/25 02:04:00 by fwhite42           _)/_\---/_\(_          #
#                                                                              #
# **************************************************************************** #

NAME			:=	libftprintf.a

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
					  print/ftpf_load_printer.c		\
					  print/ftpf_print_c.c			\
					  print/ftpf_print_i.c			\
					  print/ftpf_print_p.c			\
					  print/ftpf_print_s.c			\
					  print/ftpf_print_u.c			\
					  print/ftpf_print_x_lc.c		\
					  print/ftpf_print_x_uc.c
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

ARCHIVE_LIST		:=	main.a print.a parse.a utils.a

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
	@mkdir -p objects

$(MAIN_OBJECTS)		: objects/%.o:main/%.c objects
	@echo "> compiling $< into $@ ..."
	@$(COMPILE) $< -o $@
	@echo "...done compiling !"
$(PARSE_OBJECTS) 	: objects/%.o:parse/%.c objects
	@echo "> compiling $< into $@ ..."
	@$(COMPILE) $< -o $@
	@echo "...done compiling !"
$(PRINT_OBJECTS) 	: objects/%.o:print/%.c objects
	@echo "> compiling $< into $@ ..."
	@$(COMPILE) $< -o $@
	@echo "...done compiling !"
$(UTIL_OBJECTS) 	: objects/%.o:utils/%.c objects
	@echo "> compiling $< into $@ ..."
	@$(COMPILE) $< -o $@
	@echo "...done compiling !"

###############################################################################
# Archive Options`

ARCHIVE_CMD			:= ar
ARCHIVE_FLAGS		:= -rcs
ARCHIVE				:= $(ARCHIVE_CMD) $(ARCHIVE_FLAGS)

define make_archive
	mkdir -p lib
	$(ARCHIVE) $1 $2
endef

###############################################################################
# Rules (user defined)
./lib/main.a	: $(MAIN_OBJECTS)
	@$(call make_archive,$@,$^)
./lib/parse.a	: $(PARSE_OBJECTS)
	@$(call make_archive,$@,$^)
./lib/print.a	: $(PRINT_OBJECTS)
	@$(call make_archive,$@,$^)
./lib/utils.a	: $(UTIL_OBJECTS)
	@$(call make_archive,$@,$^)

###############################################################################
# Rules (mandatory)

$(NAME) : $(ALL_FILES)
	@$(MAKE) ./lib/utils.a
	@$(MAKE) ./lib/parse.a
	@$(MAKE) ./lib/print.a
	@$(MAKE) ./lib/main.a
	@echo "> archiving all objects in $@ ..."
	@$(ARCHIVE) $@ $(ALL_OBJECTS)
	@echo "...done archving !"
	@$(MAKE) clean
	@rm -rf lib

all		:
	$(MAKE) $(NAME)

clean	:
	@echo "> deleting all objects..."
	@rm -rf objects
	@echo "...done deleting!"

fclean	:
	@echo "> cleaning up everything ..."
	@rm -f *.a
	@rm -f *.exe
	@rm -rf lib
	@echo "...done cleaning !"

re		: fclean $(NAME)

bonus: $(NAME)
###############################################################################
# Creates tests files
% : tests/%.c $(NAME)
	gcc -L. -lftprintf -Iinclude -Imain tests/$*.c -o test.exe

.PHONY	: clean fclean
