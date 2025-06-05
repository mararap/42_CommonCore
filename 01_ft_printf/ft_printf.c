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
	else if (type_specifier == 'd' or 'i')	//The  int  argument  is  converted
			  to signed decimal notation. The precision, if any, gives the
			  minimum  number  of  digits that  must appear; if the converted
			  value requires fewer dig its, it is padded on the left with zeros.
			  The default precision  is  1.  When 0 is printed with an explicit
			  precision 0, the output is empty.
		...;
	else if (type_specifier == 'i') //see 'd'
		...; 
	else if (type_specifier == 'u')	//The  unsigned int argument is  converted
			  to unsigned octal (o), unsigned decimal (u), or unsigned  hexa-
			  decimal (x  and X) notation.  The letters abcdef are used for x
              conversions; the letters ABCDEF are used for X  conversions.  The
			  precision, if any, gives the minimum number of digits that must
			  appear; if the converted value  requires  fewer digits, it is
			  padded on the left with zeros. The default precision is 1.  When
			  0  is  printed with an explicit precision 0, the output is empty.
		...;
	else if (type_specifier == 'x')	//see 'u'
		...;
	else if (type_specifier == 'X')	//see 'u'
		...;*/
	else if (type_specifier == '%')
		count += write(1, "%", 1);
//	else
//		count = count + write(1, &type_specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	argp;
	int	count;
	size_t	i;
	
	va_start(argp, format);
	count = 0;
	i = 0;
	while(format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += print_format(*(&format[i]), argp);
		}
		else
		{
			count += write(1, &format[i], 1);
		}
		i++;

	}
	va_end(argp);
	return(count);
}

#include <stdio.h>

int	main(void)
{
	int		count;
	int		count2;
//	char	*abc = "a string";
	//
	
	printf("%s\n", "my function: ");
	count = ft_printf("it's %% and %c and %s", 'M', "a string");
//	ft_printf("My output: %% and %c and %s", 'M', "a string");
//	printf("original function: %s %d\n", abc, x);
	//	it's % and M and a string
	printf("\n%d\n", count);
	printf("%s\n", "original function: ");
	count2 = printf("it's %% and %c and %s", 'M', "a string");
	printf("\n%d\n", count2);
	return (0);
}
//t's %% and %c and %s", 'M', "a string
