/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:25:38 by aakritah          #+#    #+#             */
/*   Updated: 2025/03/14 15:09:59 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	mlx_event(t_list2 *data)
{
	mlx_hook(data->ptr_win, 17, 0, close_window, data);
	mlx_hook(data->ptr_win, 2, 1, key_press, data);
	mlx_mouse_hook(data->ptr_win, mouse_hook, data);
}

int	close_window(t_list2 *data)
{
	if (data->ptr_img)
		mlx_destroy_image(data->ptr, data->ptr_img);
	if (data->ptr_win)
		mlx_destroy_window(data->ptr, data->ptr_win);
	exit(1);
	return (0);
}

int	key_press(int button, t_list2 *data)
{
	if (button == ESC)
		close_window(data);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_list2 *data)
{
	(void)x;
	(void)y;
	if (button == 4)
		data->zoom *= 1.2;
	else if (button == 5)
		data->zoom *= 0.8;
	ft_render(data);
	return (0);
}
