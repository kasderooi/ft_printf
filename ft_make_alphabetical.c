/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_alphabetical.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 11:05:28 by kde-rooi      #+#    #+#                 */
/*   Updated: 2020/12/04 13:37:56 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*make_alhpabetical(t_flag *flag)
{
	t_len	len;
	char	*dest;

	len.str = (flag->type != 'c') ? ft_strlen(flag->data) : 0;
	len = take_len(len, flag);
	dest = (char*)ft_calloc(len.ret + 1, sizeof(char));
	if (!dest)
		return (NULL);
	if (flag->dash)
	{
		if (flag->type != 'c')
			ft_memmove(dest, flag->data, len.str);
		ft_memset(&dest[len.str], ' ', len.ret - len.str);
	}
	else
	{
		if (flag->type != 'c')
			ft_memmove(&dest[len.ret - len.str], flag->data, len.str);
		if (flag->zero)
			ft_memset(dest, '0', len.ret - len.str);
		else
			ft_memset(dest, ' ', len.ret - len.str);
	}
	free(flag->data);
	return (dest);
}

int			make_alhpabetical_lst(t_flag *flag, t_list **lst)
{
	char	*buf;
	int		ret;

	buf = make_alhpabetical(flag);
	if (!buf)
		return (-1);
	if (!flag->dash && flag->type == 'c')
		ret = lstadd_before_back(lst, ft_lstnew(ft_strlen(buf), buf));
	else
		ret = lstadd_back(lst, ft_lstnew(ft_strlen(buf), buf));
	return (ret);
}
