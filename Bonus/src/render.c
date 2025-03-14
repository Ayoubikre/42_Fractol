/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:45:57 by aakritah          #+#    #+#             */
/*   Updated: 2025/03/14 13:59:33 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

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
			*(unsigned int *)data->t = ft_colore(data);
			data->y++;
		}
		data->x++;
	}
	mlx_put_image_to_window(data->ptr, data->ptr_win, data->ptr_img, 0, 0);
}

void	ft_calcul(t_list2 *data)
{
	t_nbr	z;
	t_nbr	c;
	double	tmp;

	ft_ar(&z, &c, data);
	data->k = 0;
	while (data->k < ITTER)
	{
		if (data->f == 3)
		{
			z.r = fabs(z.r);
			z.i = fabs(z.i);
		}
		tmp = pow(z.r, 2) - pow(z.i, 2) + c.r;
		z.i = 2 * z.r * z.i + c.i;
		z.r = tmp;
		if (pow(z.r, 2) + pow(z.i, 2) > 4)
			break ;
		data->k++;
	}
}

void	ft_ar(t_nbr *z, t_nbr *c, t_list2 *data)
{
	if (data->f == 1 || data->f == 3)
	{
		z->r = 0;
		z->i = 0;
		c->r = ft_map_x(data->x, data);
		c->i = ft_map_y(data->y, data);
	}
	else
	{
		z->r = ft_map_x(data->x, data);
		z->i = ft_map_y(data->y, data);
		c->r = data->vr[0];
		c->i = data->vr[1];
	}
}

double	ft_map_x(int x, t_list2 *data)
{
	return (((x - WIDTH / 2.0) / (data->zoom * WIDTH)) + data->center_x);
}

double	ft_map_y(int y, t_list2 *data)
{
	return (((y - HEIGHT / 2.0) / (data->zoom * HEIGHT)) + data->center_y);
}
