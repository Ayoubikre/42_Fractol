/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot->c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student->42->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:28:31 by aakritah          #+#    #+#             */
/*   Updated: 2025/03/11 15:36:41 by aakritah         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static void	ft_calcul(t_list2 *data)
{
	t_nbr	z;
	t_nbr	c;
	double	tmp;

	z.r = 0;
	z.i = 0;
	c.r = ft_map_x(data->x, data);
	c.i = ft_map_y(data->y, data);
	data->k = 0;
	while (data->k < ITTER)
	{
		tmp = (z.r * z.r) - (z.i * z.i) + c.r;
		z.i = (2 * z.r * z.i) + c.i;
		z.r = tmp;
		if ((z.r * z.r) + (z.i * z.i) > 4)
			break ;
		data->k++;
	}
}

void	ft_render_mandelbrot(t_list2 *data)
{
	data->x = 0;
	data->y = 0;
	while (data->x < WIDTH)
	{
		data->y = 0;
		while (data->y < HEIGHT)
		{
			ft_calcul(data);
			data->pixel = (data->x * data->byte_to_pixel / 8) + (data->y * data->line_size);
			data->t = data->ptr_pxl + data->pixel;
			ft_colore(data);
			data->y++;
		}
		data->x++;
	}
	mlx_put_image_to_window(data->ptr, data->ptr_win, data->ptr_img, 0, 0);
}
