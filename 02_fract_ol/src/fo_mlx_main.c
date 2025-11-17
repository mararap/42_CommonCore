/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_mlx_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:18:33 by marapovi          #+#    #+#             */
/*   Updated: 2025/11/17 12:34:49 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	fo_mlx_main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "######  F R A C T O L  ######");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
