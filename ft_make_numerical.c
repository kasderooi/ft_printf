/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_numerical.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 11:07:08 by kde-rooi      #+#    #+#                 */
/*   Updated: 2020/12/07 08:53:48 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	remake_data(t_flag *flag, t_len len)
{
	char *new_data;

	new_data = (char*)ft_calloc(flag->prec + 1, sizeof(char));
	if (!new_data)
		return (-1);
	ft_memset(new_data, '0', flag->prec - len.str);
	ft_memmove(&new_data[flag->prec - len.str], flag->data, len.str);
	free(flag->data);
	flag->data = new_data;
	return (ft_strlen(flag->data));
}

static void	resolve_flags(char *dest, t_flag *flag, t_len len)
{
	const char	sign = (char)set_sign(flag);
	int			i;

	i = 0;
	if ((flag->dash || flag->zero) && sign)
	{
		ft_memset(dest, sign, 1);
		i++;
	}
	else if (sign)
		ft_memset(&dest[len.ret - len.prec], sign, 1);
	if (flag->dash)
	{
		ft_memset(&dest[i + len.str], ' ', len.ret - len.prec);
		ft_memmove(&dest[i], flag->data, len.str);
	}
	else
	{
		if (flag->zero)
			ft_memset(&dest[i], '0', len.ret - len.str);
		else
			ft_memset(&dest[i], ' ', len.ret - len.prec);
		ft_memmove(&dest[len.ret - len.str], flag->data, len.str);
	}
}

static char	*make_numerical(t_flag *flag)
{
	t_len	len;
	char	*dest;

	len.str = ft_strlen(flag->data);
	len = take_len(len, flag);
	if (flag->prec >= len.str)
		len.str = remake_data(flag, len);
	dest = (char*)ft_calloc(len.ret + 1, sizeof(char));
	if (!dest || len.str == -1)
		return (NULL);
	resolve_flags(dest, flag, len);
	free(flag->data);
	return (dest);
}

int			make_numerical_lst(t_flag *flag, t_list **lst)
{
	char	*buf;

	buf = make_numerical(flag);
	if (!buf)
		return (-1);
	return (lstadd_back(lst, ft_lstnew(ft_strlen(buf), buf)));
}
