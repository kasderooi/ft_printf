/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 13:17:05 by kde-rooi      #+#    #+#                 */
/*   Updated: 2020/12/07 09:32:12 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' ||
		c == 'd' || c == 'i' || c == 'u' ||
		c == 'x' || c == 'X' || c == '%')
		return ((int)c);
	return (0);
}

int		is_type(const char *str)
{
	int i;

	i = 0;
	while (!is_specifier(str[i]) && str[i])
		i++;
	return (is_specifier(str[i]));
}

int		look_for_var(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	if (str[0] == '\0')
		return (-1);
	return (i + 1);
}

int		set_sign(t_flag *flag)
{
	if (flag->sign == 1)
		return ('-');
	return (0);
}

void	*ch_str(int ch)
{
	char	*ret;

	ret = ft_calloc(1, sizeof(char));
	if (!ret)
		return (NULL);
	*ret = (char)ch;
	if (!ch)
		*ret = 0;
	return ((void*)ret);
}
