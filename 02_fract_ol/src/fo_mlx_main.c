/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_mlx_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:18:33 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/19 21:22:24 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fo_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*pixel;
	
	pixel = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}
/*
int	fo_mlx_main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_img		img;
	int			x;
	int			y;

	x = WIDTH * 0.1;
	y = HEIGHT * 0.1;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, HEIGHT, WIDTH,
		"###########  F R A C T O L  ###########");
	img.img = mlx_new_image(mlx, HEIGHT, WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_length, &img.endian);
	while (y < HEIGHT * 0.9)
	{
		x = WIDTH * 0.1;
		while (x < WIDTH * 0.9)
		{
			my_mlx_pixel_put(&img, x, y, rand() % 0x1000000);
				x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}*/
