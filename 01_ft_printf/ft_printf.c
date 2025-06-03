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

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int	ft_putstr(char *s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return(i);
}

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	print_format(char type_specifier, va_list argp, int count)
{
	if (type_specifier == 'c')
		count = ft_putchar(va_arg(argp, int));
	else if (type_specifier == 's')
		count = ft_putstr(va_arg(argp, char *));
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
		...;
	else if (type_specifier == '%')
		...;*/
	else
		count = count + write(1, &type_specifier, 1);
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
		{
			count++;
			count = count + print_format(*(&format[count]), argp);
		}
		else
			count = count + write(1, &format, 1);
		count++;
	}
	va_end(argp);
	return(count);
}

#include <stdio.h>

int	main(void)
{
//	int		count;
	char	*abc;
	int	x;
	
	abc = "a string";
	x = 42;
	ft_printf("My Output: %s %d\n", abc, x);
//	printf("original function: %s %d\n", abc, x);
//	printf("%d\n", count);
	return (0);
}
