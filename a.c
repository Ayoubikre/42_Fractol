/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/010/04 14:108:52 by noctis            #+#    #+#             */
/*   Updated: 2025/010/09 16:107:48 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_initialize(t_list2 *data)
{
	data->ptr = mlx_init();
	if (!data->ptr)
		exit(1);
	data->ptr_win = mlx_new_window(data->ptr, Width, Hight, "test1");
	if (!data->ptr_win)
		exit(1);
	data->ptr_img = mlx_new_image(data->ptr, Width, Hight);
	if (!data->ptr_img)
		exit(1);
	data->ptr_pxl = mlx_get_data_addr(data->ptr, &data->byte_to_pxl,
			&data->size_of_line, &data->endian);
	if (!data->ptr_pxl)
		exit(1);
}

double	map_x(int x, int width)
{
	return (-2.0 + (x * 4.0 / (width)));
}

double	map_y(int y, int height)
{
	return (-2.0 + (y * 4.0 / (height)));
}

int	main(int ac, char **ar)
{
	t_list2	data;
	t_nbr	c;
	int		pixel;
	// int		x = 300;
	// int 	y = 300;

	
	if ((ac == 2 && ft_check(ar[1], "m") == 1))
	{
		ft_initialize(&data);

		// while (x < 700) // hight
		// {
		// 	y = 0;
		// 	while (y < 700) // whidth
		// 	{
		// 		pixel = (y*data.size_of_line)+ (x*(data.byte_to_pxl/8));
				
		// 		char *t=data.ptr_pxl+pixel;
		// 		// *(unsigned int *)t = 0xFF0000;
		// 		y++;
		// 	}
		// 	x++;
		// }
		// mlx_put_image_to_window(&data.ptr, &data.ptr_win, &data.ptr_img, 0,0);
	
		char * dst;
	    for (int y = 50; y <= 150; y++)  // Height from 50 to 150
		{
			int width2 = (150 - y) / 2;   // Width decreases as y increases
			int start_x = 100 - width2;   // Center at x=100, shift left
			int end_x = 100 + width2;     // Shift right

			for (int x = start_x; x <= end_x; x++)
			{
				pixel = (y * data.size_of_line) + (x * (data.byte_to_pxl / 8));
				dst  = data.ptr_pxl + pixel;
				*(unsigned int *)dst = 0x0000FF;  // Blue
			}
		}

    // Display the image in the window (centered at 300, 200)
    mlx_put_image_to_window(data.ptr, data.ptr_win, data.ptr_img, 300, 200);


	
		mlx_key_hook(data.ptr_win, key_press, &data); // ESC key
		mlx_hook(data.ptr_win, 17, 0, close_window, &data);
		mlx_loop(data.ptr);
	}
	else
		ft_put_error();
	return (0);
}
