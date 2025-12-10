/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 23:50:36 by netrunner         #+#    #+#             */
/*   Updated: 2025/10/02 20:02:58 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int	match_space(FILE *f)
{
	int	c;
	int	skipped;

	skipped = 0;
	c = fgetc(f);

	while ((c = fgetc(f))!= EOF)
	{
		if (isspace((unsigned char) c))
		{
			skipped = 1;
			continue;
		}
		ungetc(c, f);
		break ;
	}
	if (c == EOF)
		return -1;
	if (!skipped)
		return 0;
	return (1);
}

int match_char(FILE *f, char expected)
{
	int c;
	c = fgetc(f);
	if (c == EOF)
		return -1;
	if (expected == (char) c)
		return (1);
	ungetc(c, f);
    return (0);
}

int	scan_char(FILE *f, va_list ap)
{
	int c = fgetc(f);
	if (c == EOF)
		return -1;
	char *p = va_arg(ap, char *);
	*p = (char) c;
	return (1);
}

int scan_int(FILE *f, va_list ap)
{
	int minus;
	int value;
	int c;
	int digits;

	digits = 0;
	minus = 1;
	value = 0;
	while ((c = fgetc(f)) != EOF && isspace((unsigned char) c))
		;
	if (c == '-')
	{
		minus = -1;
		c = fgetc(f);
	}
	else if (c == '+')
		c = fgetc(f);

	while (c != EOF && isdigit((unsigned char)c))
	{
		value = value * 10 + (c - '0');
		digits++;
		c = fgetc(f);
	}
	if (c != EOF)
		ungetc(c, f);
	if (!digits)
		return 0;
	int *p = va_arg(ap, int *);
	*p = value * minus;
    return (1);
}

int scan_string(FILE *f, va_list ap)
{
	int c;
	char *p = va_arg(ap, char *);
	int read;

	read = 0;
	c = 0;
	while ((c = fgetc(f)) != EOF && isspace((unsigned char) c))
        ;
    if (c == EOF)
        return -1;
	while (c != EOF && !isspace((unsigned char) c))
	{
		*p++ = (char) c;
		read = 1;
		c = fgetc(f);
	}
	if (c != EOF)
		ungetc(c, f);

	if (!read)
		return 0;
	*p = '\0';
	return (1);
}


int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);
			return scan_int(f, ap);
		case 's':
			match_space(f);
			return scan_string(f, ap);
		case '\0':
			return -1;
		default:
			return -1;
	}
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int nconv = 0;

	int c = fgetc(f);
	if (c == EOF)
		return EOF;
	ungetc(c, f);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
			{

				break;
			}
			format++;
			nconv++;
			continue ;
		}
		else if (isspace((unsigned char) *format))
		{
			if (match_space(f) == -1)
			{
				break;
			}
		}
		else if (match_char(f, *format) != 1)
		{
			break;
		}
		format++;
	}

	if (ferror(f))
		return EOF;
	return nconv;
}


int ft_scanf(const char *format, ...)
{
	va_list	ap;

	if (!format)
		return (-1);
	va_start(ap, format);
	int ret = ft_vfscanf(stdin, format, ap);
	va_end(ap);

	return ret;
}

int main(void)
{
    int d;
    char c;
    char s[128];

    int n = ft_scanf("%d%c%s", &d, &c, s);
    printf("n=%d d=%d c=%c s=\"%s\"\n", n, d, c, s);
    return 0;
}


