/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:11:17 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/09 12:35:32 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_flag(va_list arg, char c)
{
	if (c == 'd')
		return (ft_printf_itoa(va_arg(arg, int)));
	else if (c == 's')
		return (ft_printf_str(arg));
	else if (c == 'c')
	{
		ft_putchar(va_arg(arg, int));
		return (1);
	}
	else if (c == 'S')
		return (ft_printf_ws(arg));
	else if (c == 'C')
		return (ft_printf_wc(arg));
	else if (c == 'o')
		return (ft_printf_uitoa_base(va_arg(arg, unsigned int), 8, c));
	else if (c == 'u')
		return (ft_printf_uitoa_base(va_arg(arg, unsigned int), 10, c));
	else if (c == 'x' || c == 'X')
		return (ft_printf_uitoa_base(va_arg(arg, unsigned int), 16, c));
	else
		return (0);
}

static	int		ft_printf_resolve(char **format, va_list arg)
{
	int		len;

	if (!(ft_strchr("scdouxXSC", **format)) || !**format)
		return (0);
	len = ft_check_flag(arg, **format);
	(*format)++;
	return (len);
}

static	int		ft_read_format(char **format, va_list arg)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	while (**format)
	{
		if (!(str = ft_strchr(*format, '%')))
		{
			write(1, *format, ft_strlen(*format));
			len += ft_strlen(*format);
			break ;
		}
		write(1, *format, str - *format);
		len += str - *format;
		*format = str + 1;
		len += ft_printf_resolve(format, arg);
	}
	return (len);
}

int				ft_printf(const char *format, ...)
{
	int		len;
	char	*str;
	va_list	arg;

	va_start(arg, format);
	str = (char*)format;
	len = ft_read_format(&str, arg);
	va_end(arg);
	return (len);
}
