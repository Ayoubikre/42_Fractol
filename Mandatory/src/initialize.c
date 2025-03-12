/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:21:10 by aakritah          #+#    #+#             */
/*   Updated: 2025/03/11 18:09:03 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	ft_initialize(t_list2 *data)
{
	data->ptr = mlx_init();
	if (!data->ptr)
		exit(1);
	data->ptr_win = mlx_new_window(data->ptr, WIDTH, HEIGHT, data->name);
	if (!data->ptr_win)
		ft_exit(data);
	data->ptr_img = mlx_new_image(data->ptr, WIDTH, HEIGHT);
	if (!data->ptr_img)
		ft_exit(data);
	data->ptr_pxl = mlx_get_data_addr(data->ptr_img, &data->byte_to_pixel,
			&data->line_size, &data->endian);
	if (!data->ptr_pxl)
		ft_exit(data);
	data->max_r = 2.0;
	data->min_r = -2.0;
	data->max_i = 1.5;
	data->min_i = -1.5;
}

double ft_atoi2()
{
	int f;
	
}