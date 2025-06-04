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
		count += ft_putchar(va_arg(argp, int));
	else if (type_specifier == 's')
		count += ft_putstr(va_arg(argp, char *));
/*	else if (type_specifier == 'p')
		...;
	else if (type_specifier == 'd')
		...;
	else if (type_specifier == 'i')
		...;
	else if (type_specifier == 'u')
		...;
	else if (type_specifier == 'x')
		...;
	else if (type_specifier == 'X')
		...;*/
	else if (type_specifier == '%')
		write(1, "%", 1);
//	else
//		count = count + write(1, &type_specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	argp;
	int	count;
	
	va_start(argp, format);
	count = 0;
	while(format[count] != '\0')
	{
		if (format[count] == '%')
			count += print_format(*(&format[count + 1]), argp);
		else
			write(1, &format[count], 1);
		count++;
	}
	va_end(argp);
	return(count);
}
/*
#include <stdio.h>

int	main(void)
{
//	int		count;
//	char	*abc;
	
//	abc = "a string";
	ft_printf("My Output: %% and %c and %s", 'M', "a string");
//	printf("original function: %s %d\n", abc, x);
//	printf("%d\n", count);
	return (0);
}*/
