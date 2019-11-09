/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:06:06 by asultanb          #+#    #+#             */
/*   Updated: 2019/11/08 13:45:54 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		i;
	int		num;
	va_list	argp;
	
	va_start(argp, format);
	i = 0;
	num = 0;
	while (format[i])
	{
		if (format[i] == '%')
			process_format(&argp, (char*)format, &i, &num);
		else
		{
			ft_putchar(format[i++]);
			num++;
		}
	}
	va_end(argp);
	return (num);
}
