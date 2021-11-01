/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 10:52:28 by kde-rooi      #+#    #+#                 */
/*   Updated: 2020/12/06 10:25:17 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((char)c == '\t' || (char)c == '\n' || (char)c == '\v'
		|| (char)c == '\f' || (char)c == '\r' || (char)c == ' ')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	nbr = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-')
		i++;
	if (str[i] == '+' && sign > 0)
		i++;
	while (i < (int)ft_strlen(str) && ft_isdigit(str[i]) == 1)
	{
		nbr *= 10;
		nbr += str[i] - 48;
		if (nbr > 9223372036854775807 || i > 19)
			return ((sign > 0) ? -1 : 0);
		i++;
	}
	return (nbr * sign);
}
