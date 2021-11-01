/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ltoa_ptr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 11:07:03 by kde-rooi      #+#    #+#                 */
/*   Updated: 2020/12/06 10:53:35 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		nbr_length_base(unsigned long nbr, long baselen)
{
	unsigned long i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr)
	{
		i++;
		nbr /= baselen;
	}
	return (i);
}

char			*ft_ltoa_ptr(unsigned long nbr, t_flag *flag, int uplo)
{
	int					len;
	unsigned long		baselen;
	char				*base;
	char				*ret;

	baselen = 16;
	base = (uplo) ? ft_strdup("0123456789ABCDEF")
					: ft_strdup("0123456789abcdef");
	len = nbr_length_base(nbr, baselen) + 2;
	if (flag->prec != -2 && (flag->prec > len || flag->prec == 0))
		len = flag->prec + 2;
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!ret || !base)
		return (NULL);
	ret[len] = '\0';
	while (len)
	{
		ret[len - 1] = base[nbr % baselen];
		nbr /= baselen;
		len--;
	}
	ret[0] = '0';
	ret[1] = (uplo) ? 'X' : 'x';
	free(base);
	return (ret);
}
