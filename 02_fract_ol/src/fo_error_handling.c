/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_error_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:40:24 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/20 18:39:47 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fo_cleanup(t_clean *data)
{
	if (data->init && data->img.ptr)
	{
		mlx_destroy_image(data->init, data->img.ptr);
		if (data->window)
			mlx_destroy_window(data->init, data->window);
	}
	if (data->init)
		mlx_destroy_display(data->init);
}

void	fo_error_exit(t_clean *data)
{
	fo_cleanup(data);	
	write (2, "Error\n", 6);
	exit(1);
}
