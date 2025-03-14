/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:21:10 by aakritah          #+#    #+#             */
/*   Updated: 2025/03/13 10:50:37 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	ft_initialize(t_list2 *data)
{
	data->ptr = mlx_init();
	if (!data->ptr)
		close_window(data);
	data->ptr_win = mlx_new_window(data->ptr, WIDTH, HEIGHT, data->name);
	if (!data->ptr_win)
		close_window(data);
	data->ptr_img = mlx_new_image(data->ptr, WIDTH, HEIGHT);
	if (!data->ptr_img)
		close_window(data);
	data->ptr_pxl = mlx_get_data_addr(data->ptr_img, &data->bytes_per_pixel, &data->bytes_per_row, &data->endian);
	if (!data->ptr_pxl)
		close_window(data);
	data->max_r = 2.0;
	data->min_r = -2.0;
	data->max_i = 1.5;
	data->min_i = -1.5;
	// data->mouse_x = WIDTH / 2;
    // data->mouse_y = HEIGHT / 2;
	// data->offset_x=0;
    // data->offset_y=0;
	
    // Initial zoom factor
    data->zoom = 1.0;

    // Initial center of the fractal (center of the viewing window)
    data->center_x = 0.0;
    data->center_y = 0.0;

}
