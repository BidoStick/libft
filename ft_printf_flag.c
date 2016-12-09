/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:00:26 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/09 12:52:57 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_itoa(int n)
{
	int		len;
	char	*str;

	str = ft_itoa(n);
	len = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
	return (len);
}

int	ft_printf_uitoa_base(unsigned int n, short base, char c)
{
	int		len;
	char	*str;

	str = ft_uitoa_base(n, base);
	if (c == 'X')
		str = ft_strtoupper(str);
	len = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
	return (len);
}

int	ft_printf_str(va_list arg)
{
	char	*str;
	int		len;

	if (!(str = va_arg(arg, char*)))
	{
		ft_putstr("(null)");
		return (6);
	}
	len = ft_strlen(str);
	ft_putstr(str);
	return (len);
}

int	ft_printf_wc(va_list arg)
{
	wchar_t	c;
	int		len;

	c = va_arg(arg, wint_t);
	len = ft_wcharlen(c);
	ft_putwchar(c);
	return (len);
}

int	ft_printf_ws(va_list arg)
{
	wchar_t	*wstr;
	int		len;

	len = 0;
	if (!(wstr = va_arg(arg, wchar_t*)))
	{
		ft_putstr("(null)");
		return (6);
	}
	len = ft_wstrlen(wstr);
	ft_putwstr(wstr);
	return (len);
}
