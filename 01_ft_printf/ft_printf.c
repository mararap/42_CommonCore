/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:10:30 by marapovi          #+#    #+#             */
/*   Updated: 2025/05/28 17:10:33 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_format(char type_specifier, va_list argp)
{
	int	count;

	count = 0;
	if (type_specifier == 'c')
		count = count + ft_putchar(va_arg(argp, int));
//	else if...
//	else if...
//	...
//	else ...
	return count;
}

int	ft_printf(const char *format, ...)
{
	va_list	argp;
	int	count;
	
	va_start(argp, format);
	count = 0;
	while(!format)
	{
		if (*format == '%')
			count = count + print_format(*(format), argp);
		else
			count = count + write(1, format, 1);
		format++;
	}
	va_end(argp);
	return(count);
}

#include <stdio.h>

int	main(void)
{
	int count;

	count = ft_printf("My Output: %c");
	return count;
}
