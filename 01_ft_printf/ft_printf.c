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
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#include <stdio.h>

int	main(void)
{
	int		count;
	char	c;

	c = 'M';
	count = ft_printf("My Output: %c", c);
//	printf("%d\n", ft_printf("My Output:", c));
	return (0);
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
		{
			count++;
			print_format(*(&format[count]), argp);
		}
		else
			count = count + write(1, &format, 1);
	}
	va_end(argp);
	return(count);
}

int	print_format(char type_specifier, va_list argp)
{
	int	count;

	count = 0;
	if (type_specifier == 'c')
		count = count + ft_putchar(va_arg(argp, int));
	else if (type_specifier == 's')
		count = count + ft_putstr(va_arg, *char);
	else if (type_specifier == 'p')
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
		...;
	else if (type_specifier == '%')
		...;*/
	else count = count + write(1, &type_specifier, 1);
	return count;
}

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

void	ft_putstr(char *s)
{
	size_t i;
	while (s[i])
	{
		write
	}
}
