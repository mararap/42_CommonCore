/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:34:28 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/23 21:42:17 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static long	fo_isvalid_sign(char *str, ssize_t i)
{
	if (str[i] == '-' || str[i] == '+')
	{
		if (ft_isdigit(str[i + 1]))
		{
			if (str[i] == '-')
				return (-1);
		}
		else
			return ((long)INT_MIN - 1);
	}
	return (1);
}

static ssize_t	fo_skip_spaces(char *str)
{
	ssize_t	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	return (i);
}

static void	fo_parse_int(t_atof *st, char *str)
{
	while (ft_isdigit((int)str[st->i]))
	{
		st->result = st->result * 10.0 + (double)(str[st->i] - '0');
		st->i++;
	}
}

static void	fo_parse_fract(t_atof *st, char *str)
{
	st->i++;
	st->div = 10.0;
	while (ft_isdigit((int)str[st->i]))
	{
		st->result = st->result + (double)(str[st->i] - '0') / st->div;
		st->div = st->div * 10.0;
		st->i++;
	}
}

double	fo_atof(char *str)
{
	t_atof	st;

	st.result = 0.0;
	st.div = 1.0;
	st.sign = 1;
	st.i = 0;
	if (!str || !str[0])
		return ((long)INT_MIN - 1);
	st.i = fo_skip_spaces(str);
	st.sign = fo_isvalid_sign(str, st.i);
	if (st.sign == ((long)INT_MIN - 1))
		return ((long)INT_MIN - 1);
	if (str[st.i] == '-' || str[st.i] == '+')
		st.i++;
	fo_parse_int(&st, str);
	if (str[st.i] == '.')
		fo_parse_fract(&st, str);
	if ((str[st.i] != '\0') && (!((str[st.i] == ' ')
				|| ((str[st.i] >= '\t') && (str[st.i] <= '\r')))))
		return ((long)INT_MIN - 1);
	if ((st.result * st.sign) > INT_MAX || (st.result * st.sign) < INT_MIN)
		return ((long)INT_MIN - 1);
	return (st.result * st.sign);
}
/*
#include <stdio.h>

int	main (int ac, char **av)
{
	int	i;
	double	d;

	i = 0;
	while (i < ac)
	{
		d = fo_atof(av[i]);
		printf("%d\n", d);
		i++;
	}
	return (0);
}*/