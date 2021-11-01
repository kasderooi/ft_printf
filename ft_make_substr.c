/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_substr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 12:01:24 by kde-rooi      #+#    #+#                 */
/*   Updated: 2020/12/07 09:43:38 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_len	take_len(t_len len, t_flag *flag)
{
	if (flag->type == 'c' || flag->type == 's')
	{
		if (flag->type == 'c' && flag->width > 0)
			flag->width--;
		len.ret = (flag->width > len.str) ? flag->width : len.str;
	}
	else if (flag->prec == 0 && flag->sign == -1)
	{
		len.str = 0;
		len.prec = 0;
		len.ret = (flag->width > len.prec) ? flag->width : len.prec;
	}
	else
	{
		len.prec = (flag->prec > len.str) ? flag->prec : len.str;
		if (flag->sign == 1)
			len.prec++;
		len.ret = (flag->width > len.prec) ? flag->width : len.prec;
	}
	return (len);
}

int		make_substr(va_list args, const char *str, t_list **lst)
{
	t_flag	*flag;
	int		ret;

	flag = (t_flag*)malloc(sizeof(t_flag));
	if (!flag)
		return (-1);
	flag = check_flag(flag, str, args, lst);
	if (!flag->data)
		return (-1);
	if (flag->type == 's' || flag->type == 'c')
		ret = make_alhpabetical_lst(flag, lst);
	else
		ret = make_numerical_lst(flag, lst);
	free(flag);
	if (!(*lst) || !(*lst)->content)
		return (-1);
	return (ret);
}
