/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:25:31 by noctis            #+#    #+#             */
/*   Updated: 2025/03/11 03:36:23 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// --------------------------------------------------------
// int	close_window(t_list2 *data)
// {
// 	mlx_destroy_image(data->ptr, data->ptr_img);
// 	mlx_destroy_window(data->ptr, data->ptr_win);
// 	mlx_destroy_display(data->ptr); // Required for Linux
// 	free(data->ptr);
// 	exit(0);
// 	return (0);
// }
// int	key_press(int keycode, t_list2 *data)
// {
// 	if (keycode == 65307) // ESC key on Linux
// 		close_window(data);
// 	return (0);
// }
// --------------------------------------------------------

int	ft_check(char *t1, char *t2)
{
	if ((ft_strnstr(t1, t2, ft_strlen(t2)) != NULL)
		&& (ft_strlen(t1) == ft_strlen(t2)))
		return (1);
	return (0);
}

void	ft_put_error(void)
{
	ft_printf("-----------------------------------------------\n");
	ft_printf("-                                             -\n");
	ft_printf("-    Allowed arguments are :                  -\n");
	ft_printf("-                                             -\n");
	ft_printf("-         ./fractol mandelbrot                -\n");
	ft_printf("-         ./fractol julia 'Width' 'Hight'     -\n");
	ft_printf("-                                             -\n");
	ft_printf("-----------------------------------------------\n");
	exit(1);
}
