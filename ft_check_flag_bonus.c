/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_flag.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 10:24:30 by kde-rooi      #+#    #+#                 */
/*   Updated: 2020/12/07 09:20:05 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_flag(const char *str, char c)
{
	int i;

	i = 0;
	while (!is_specifier(str[i]) && str[i])
	{
		if (ft_isdigit(str[i]) && str[i] != '0')
			break ;
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	is_width(const char *str)
{
	int i;
	int	out;

	i = 0;
	out = 0;
	while (!is_specifier(str[i]) && str[i])
	{
		if (str[i] == '*' && str[i - 1] != '.')
			return (-1);
		if (ft_isdigit(str[i]))
		{
			out *= 10;
			out += str[i] - 48;
		}
		if (str[i] == '.')
			break ;
		i++;
	}
	if (out > 0)
		return (out);
	return (0);
}

static int	is_precision(const char *str, t_flag *flag)
{
	int i;
	int	out;

	i = 0;
	out = 0;
	while (!is_specifier(str[i]) && str[i])
	{
		if (str[i] == '.')
		{
			i++;
			if (str[i] == '*')
				return (-1);
			flag->zero = 0;
			while (ft_isdigit(str[i]))
			{
				out *= 10;
				out += str[i] - 48;
				i++;
			}
			if (out >= 0)
				return (out);
		}
		i++;
	}
	return (-2);
}

static int	set_width_prec(int type, int arg, t_flag *flag)
{
	if (arg < 0)
	{
		if (type == 1)
		{
			flag->dash = 1;
			return (-arg);
		}
		if (type == 0 && flag->type != 'c' && flag->type != 's')
			return (1);
		else if (type == 0)
			return (-2);
	}
	if (type == 0)
		flag->zero = 0;
	return (arg);
}

t_flag		*check_flag(t_flag *flag, const char *str,
							va_list args, t_list **lst)
{
	flag->sign = 0;
	flag->type = is_type(str);
	flag->dash = (is_flag(str, '-')) ? 1 : 0;
	flag->plus = (is_flag(str, '+')) ? 1 : 0;
	flag->zero = (is_flag(str, '0') && flag->dash == 0) ? 1 : 0;
	flag->space = (is_flag(str, ' ') && flag->plus == 0) ? 1 : 0;
	flag->hash = (is_flag(str, '#')) ? 1 : 0;
	flag->width = (is_width(str)) ? is_width(str) : 0;
	flag->width = (flag->width == -1) ?
				set_width_prec(1, va_arg(args, int), flag) : flag->width;
	flag->prec = (is_precision(str, flag) == -2) ? -2 : is_precision(str, flag);
	flag->prec = (flag->prec == -1) ?
				set_width_prec(0, va_arg(args, int), flag) : flag->prec;
	flag = make_data(flag, args, lst);
	return (flag);
}
