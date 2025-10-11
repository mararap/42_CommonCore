/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:37:49 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/11 17:26:18 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *c, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putint(int n);
int		ft_putusint(unsigned int u);
int		ft_puthex(unsigned int x, int c);
int		ft_putptr(void *ptr);

#endif // !LIBFTPRINTF_H
