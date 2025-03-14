/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:46:56 by aakritah          #+#    #+#             */
/*   Updated: 2025/03/13 09:54:15 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

// double	ft_map_x(int x, t_list2 *data)
// {
// 	return (data->min_r + (x * (data->max_r - data->min_r) / (WIDTH - 1)));
// }

// double	ft_map_y(int y, t_list2 *data)
// {
// 	return (data->min_i + (y * (data->max_i - data->min_i) / (HEIGHT - 1)));
// }



unsigned int 	ft_colore2(t_list2 *data)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)data->k / ITTER;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	return (r << 16 | g << 8 | b);
}

void	ft_colore(t_list2 *data)
{
	if (data->k == ITTER)
		*(unsigned int *)data->t = 0x000000;
	else
		*(unsigned int *)data->t = ft_colore2(data);
		// *(unsigned int *)data->t = (data->k % 255) * 0x050109;
}




void ft_exit(t_list2 *data)
{
    exit(1);
}
