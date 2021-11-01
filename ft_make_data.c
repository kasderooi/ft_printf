/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_data.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 10:23:14 by kde-rooi      #+#    #+#                 */
/*   Updated: 2020/12/07 09:50:52 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_strdup_special(t_flag *flag, const char *s)
{
	if (!s)
	{
		if (flag->prec >= 0)
			return (ft_strndup("(null)", flag->prec + 1));
		return (ft_strdup("(null)"));
	}
	if (flag->prec >= 0)
		return (ft_strndup(s, flag->prec + 1));
	return (ft_strdup(s));
}

static size_t	reset_sign(t_flag *flag, size_t nbr)
{
	if (nbr == 0)
	{
		flag->sign = -1;
	}
	return (nbr);
}

static t_flag	*data_number(t_flag *flag, va_list args)
{
	long	nbr;

	nbr = reset_sign(flag, va_arg(args, int));
	if (nbr < 0)
	{
		nbr *= -1;
		flag->sign = 1;
	}
	if (nbr == 2147483648 && (flag->type == 'd' || flag->type == 'i'))
		flag->data = ft_strdup("2147483648");
	else
		flag->data = ft_itoa(nbr);
	return (flag);
}

static t_flag	*data_hex(t_flag *flag, va_list args)
{
	unsigned int	nbr;

	nbr = reset_sign(flag, va_arg(args, unsigned int));
	if (flag->type == 'x')
		flag->data = ft_itoa_base(nbr, "0123456789abcdef");
	if (flag->type == 'X')
		flag->data = ft_itoa_base(nbr, "0123456789ABCDEF");
	return (flag);
}

t_flag			*make_data(t_flag *flag, va_list args, t_list **lst)
{
	if (flag->type == 'd' || flag->type == 'i')
		flag = data_number(flag, args);
	if (flag->type == 'u')
		flag->data = ft_uitoa(reset_sign(flag, va_arg(args, unsigned int)));
	if (flag->type == 'x' || flag->type == 'X')
		flag = data_hex(flag, args);
	if (flag->type == 's')
		flag->data = ft_strdup_special(flag, va_arg(args, char*));
	if (flag->type == 'c' || flag->type == '%')
	{
		flag->data = (flag->type == 'c') ? ch_str(va_arg(args, int))
										: ch_str('%');
		flag->type = 'c';
		lstadd_back(lst, ft_lstnew(1, ft_strndup(flag->data, 2)));
	}
	if (flag->type == 'p')
	{
		flag->zero = 0;
		flag->data = ft_ltoa_ptr(va_arg(args, unsigned long), flag, 0);
	}
	return (flag);
}
