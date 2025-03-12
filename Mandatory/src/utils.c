/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:46:56 by aakritah          #+#    #+#             */
/*   Updated: 2025/03/12 14:19:14 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

double	ft_map_x(int x, t_list2 *data)
{
	return (data->min_r + (x * (data->max_r - data->min_r) / (WIDTH - 1)));
}

double	ft_map_y(int y, t_list2 *data)
{
	return (data->min_i + (y * (data->max_i - data->min_i) / (HEIGHT - 1)));
}

void	ft_colore(t_list2 *data)
{
	if (data->k == ITTER)
		*(unsigned int *)data->t = 0x000000;
	else
		*(unsigned int *)data->t = (data->k % 255) * 0x050109;
}


void ft_exit(t_list2 *data)
{
    exit(1);
}
