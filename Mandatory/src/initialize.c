/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:21:10 by aakritah          #+#    #+#             */
/*   Updated: 2025/03/12 14:34:39 by aakritah         ###   ########.fr       */
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
	data->ptr_pxl = mlx_get_data_addr(data->ptr_img, &data->bytes_per_pixel, &data->bytes_per_row, &data->endian);
	if (!data->ptr_pxl)
		ft_exit(data);
	data->max_r = 2.0;
	data->min_r = -2.0;
	data->max_i = 1.5;
	data->min_i = -1.5;
	data->mouse_x = WIDTH / 2;
    data->mouse_y = HEIGHT / 2;
}
