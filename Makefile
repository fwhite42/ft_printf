NAME	:= libftprintf.a
HEADER	:= libftprintf.h

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -Iinclude

AR			:= ar
ARFLAGS		:= -rcs

###############################################################################
# Files To Compile
define FILES
	ft_printf\
	ftpf_format\
	ftpf_load_printer\
	ftpf_print_c\
	ftpf_print_escape\
	ftpf_print_i\
	ftpf_print_p\
	ftpf_print_s\
	ftpf_print_u\
	ftpf_print_x_lc\
	ftpf_print_x_uc\
	ftpf_character_utils\
	ftpf_number_utils\
	ftpf_read_write_utils
endef
###############################################################################

vpath %.c source
vpath %.h include

OBJECTS := $(FILES:%=%.o)

$(NAME) : $(HEADER) $(NAME)($(OBJECTS))

all: $(NAME)

bonus: all

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
