NAME		=	libftprintf.a
PRINTFSRCS	=	ft_printf.c ft_printf_utils.c ft_make_substr.c \
				ft_check_flag.c ft_make_data.c ft_lists.c \
				ft_itoa_hex.c ft_ltoa_ptr.c \
				ft_make_alphabetical.c ft_make_numerical.c
BONUSSRCS	=	ft_printf.c ft_printf_utils_bonus.c ft_make_substr_bonus.c \
				ft_check_flag_bonus.c ft_make_data_bonus.c ft_lists.c \
				ft_itoa_hex.c ft_ltoa_ptr.c \
				ft_make_alphabetical.c ft_make_numerical.c
LIBFT		=	libft/libft.a
LIBPATH		=	libft
HEADER		=	ft_printf.h
PRINTFOBJS	=	$(PRINTFSRCS:.c=.o)
BONUSOBJS	=	$(BONUSSRCS:.c=.o)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
AR			=	ar -rcs
LIBTF_MAKE	=	$(MAKE) -C $(LIBPATH)

ifdef WITH_BONUS
OBJ_FILES = $(BONUSOBJS)
else
OBJ_FILES = $(PRINTFOBJS)
endif

all:		$(NAME)
$(NAME):	$(OBJ_FILES) $(HEADER)
			$(LIBTF_MAKE)
			cp $(LIBFT) ./$(NAME)
			$(AR) $(NAME) $(OBJ_FILES)

bonus:
			$(MAKE) WITH_BONUS=1 all

clean:
			$(RM) $(PRINTFOBJS) $(BONUSOBJS)
			$(LIBTF_MAKE) clean

fclean:		clean
			$(RM) $(NAME)
			$(LIBTF_MAKE) fclean

re:			fclean all

.PHONY:		all bonus clean fclean re %.o
