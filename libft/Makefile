NAME		=	libft.a
LIBFTSRCS	=	ft_atoi.c ft_calloc.c ft_itoa.c ft_itoa_base.c ft_memmove.c \
				ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_putstr_fd.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
				ft_strlen.c ft_strndup.c ft_substr.c ft_bzero.c \
				ft_isdigit.c ft_uitoa.c
LIBFTOBJS	=	$(LIBFTSRCS:.c=.o)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -c
RM			=	rm -f
AR			=	ar -rcs

all:		$(NAME)
$(NAME):	$(LIBFTOBJS)
			$(AR) $(NAME) $(LIBFTOBJS)

clean:
			$(RM) $(LIBFTOBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re %.o
