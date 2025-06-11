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

static int	print_format(char type_specifier, va_list argp)
{
	int	amount;

	amount = 0;
	if (type_specifier == 'c')
		amount += ft_putchar(va_arg(argp, int));
	if (type_specifier == 's')
		amount += ft_putstr(va_arg(argp, char *));
	if (type_specifier == 'p')
		amount += ft_putptr(va_arg(argp, void *));
	if (type_specifier == 'd' || type_specifier == 'i')
		amount += ft_putint(va_arg(argp, int));
	if (type_specifier == 'u')
		amount += ft_putusint(va_arg(argp, unsigned int));
	if (type_specifier == 'x')
		amount += ft_puthex(va_arg(argp, unsigned int), type_specifier);
	if (type_specifier == 'X')
		amount += ft_puthex(va_arg(argp, unsigned int), type_specifier);
	if (type_specifier == '%')
		amount += write(1, "%", 1);
	return (amount);
}

int	ft_printf(const char *format, ...)
{
	va_list	argp;
	int		count;
	size_t	i;

	if (!format )
		return (-1);
	va_start(argp, format);
	count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += print_format(format[i], argp);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(argp);
	return (count);
}
/*
#include <stdio.h>

int main(void)
{
	int i;
	int j;
	int k = 1643216;
	char *ptr = "for_testing";

	i = printf("%p\n", ptr);
//	j = ft_printf("%x\n", k);
//	j = ft_printf("%X\n", k);
	j = ft_printf("%p\n", ptr);

	printf("ori: %i\nmine: %i\n", i, j);
}*/
