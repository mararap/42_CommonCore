/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_mlx_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:18:33 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/20 19:41:53 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fo_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;
	
	offset = (y * img->line_len + (x * (img->bits_per_pixel / 8)));
	*(unsigned int *)(img->addr + offset) = color;
}

/*
void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->window,
			KeyPress,
			KeyPressMask,
			key_handle,
			fractal);

	mlx_hook(fractal->window,
			ButtonPress,
			ButtonPressMask,
			mouse_handle,
			fractal);
			
	mlx_hook(fractal->window,
			DestroyNotify,
			StructureNotifyMask,
			clese_handle,
			fractal);
}*/
/*
int	fo_mlx_main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_img		img;
	int			x;
	int			y;

	x = WIDTH;
	y = HEIGHT;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, HEIGHT, WIDTH,
		"###########  F R A C T O L  ###########");
	img.ptr = mlx_new_image(mlx, HEIGHT, WIDTH);
	img.addr = mlx_get_data_addr(img.ptr, &img.bits_per_pixel,
		&img.line_len, &img.endian);
	while (y < HEIGHT)
	{
		x = WIDTH * 0.1;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(&img, x, y, rand() % 0x1000000);
				x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.ptr, 0, 0);
	mlx_loop(mlx);
	return (0);
}*/
