/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_mlx_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:18:33 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/17 20:36:04 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*pixel;
	
	pixel = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

int	fo_mlx_main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_fractol	img;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500,
		"###########  F R A C T O L  ###########");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
