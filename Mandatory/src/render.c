/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:45:57 by aakritah          #+#    #+#             */
/*   Updated: 2025/03/13 11:00:40 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	ft_calcul(t_list2 *data)
{
	// ( t_nbr z, t_nbr c, double tmp);
	t_nbr z;
	t_nbr c;
	double tmp;
	
	if (data->f == 1)
	{
		z.r = 0;
		z.i = 0;
		c.r = ft_map_x(data->x, data);
		c.i = ft_map_y(data->y, data);
	}
	else
	{
		z.r = ft_map_x(data->x, data);
		z.i = ft_map_y(data->y, data);
		c.r = data->vr[0];
		c.i = data->vr[1];
	}
	data->k = 0;
	while (data->k < ITTER)
	{
		tmp = pow(z.r, 2) - pow(z.i, 2) + c.r;
		z.i = 2 * z.r * z.i + c.i;
		z.r = tmp;
		if (pow(z.r, 2) + pow(z.i, 2) > 4)
			break ;
		data->k++;
	}
}

void	ft_render(t_list2 *data)
{
	data->x = 0;
	while (data->x < WIDTH)
	{
		data->y = 0;
		while (data->y < HEIGHT)
		{
			ft_calcul(data);
			data->pixel = (data->y * data->bytes_per_row) + (data->x
					* data->bytes_per_pixel / 8);
			data->t = data->ptr_pxl + data->pixel;
			ft_colore(data);
			data->y++;
		}
		data->x++;
	}
	mlx_put_image_to_window(data->ptr, data->ptr_win, data->ptr_img, 0, 0);
}
