/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 11:40:40 by kde-rooi      #+#    #+#                 */
/*   Updated: 2020/12/04 13:42:39 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	shift_print(va_list args, const char *str, t_list **lst)
{
	int			i;
	int			ret;
	char		*buf;

	ret = 0;
	i = 0;
	while (i < (int)ft_strlen(str) && str[i] && ret == 0)
	{
		buf = ft_strndup(&str[i], look_for_var(&str[i]));
		if (!buf)
			return (-1);
		ret = lstadd_back(lst, ft_lstnew(ft_strlen(buf), buf));
		i += look_for_var(&str[i]);
		if (str[i - 1] == '%' && ret == 0)
		{
			ret = make_substr(args, &str[i], lst);
			while (!is_specifier(str[i]) && str[i])
				i++;
			i++;
		}
	}
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	va_list args;
	t_list	**lst;
	t_list	*buffer;
	int		ret;

	va_start(args, format);
	lst = (t_list **)malloc(sizeof(t_list*));
	if (!lst)
		return (-1);
	*lst = NULL;
	ret = shift_print(args, format, lst);
	if (ret == -1)
		return (-1);
	while (*lst)
	{
		write(1, (*lst)->content, (*lst)->len);
		ret += (*lst)->len;
		buffer = (*lst)->next;
		free((*lst)->content);
		free((*lst));
		*lst = buffer;
	}
	free(lst);
	va_end(args);
	return (ret);
}
