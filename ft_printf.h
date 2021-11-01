/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 12:15:24 by kde-rooi      #+#    #+#                 */
/*   Updated: 2020/12/07 09:10:36 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct		s_flag
{
	int				dash;
	int				sign;
	int				plus;
	int				zero;
	int				space;
	int				hash;
	int				width;
	int				prec;
	char			type;
	void			*data;
}					t_flag;

typedef struct		s_len
{
	int				ret;
	int				str;
	int				prec;
}					t_len;

typedef struct		s_list
{
	int				len;
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_printf(const char *format, ...);

int					make_substr(va_list args, const char *str, t_list **lst);
t_len				take_len(t_len len, t_flag *flag);
int					make_alhpabetical_lst(t_flag *flag, t_list **lst);
int					make_numerical_lst(t_flag *flag, t_list **lst);

t_flag				*check_flag(t_flag *flag, const char *str,
									va_list args, t_list **lst);
t_flag				*make_data(t_flag *flag, va_list args, t_list **lst);

int					is_specifier(char c);
int					is_type(const char *str);
void				*ch_str(int ch);
int					look_for_var(const char *str);
int					set_sign(t_flag *flag);

t_list				*ft_lstnew(int len, void *content);
int					lstadd_back(t_list **lst, t_list *new);
int					lstadd_before_back(t_list **lst, t_list *new);

char				*ft_ltoa_ptr(unsigned long nbr, t_flag *flag, int uplo);
char				*ft_itoa_hex(unsigned int nbr, t_flag *flag, int uplo);

#endif
