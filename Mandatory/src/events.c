/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:25:38 by aakritah          #+#    #+#             */
/*   Updated: 2025/03/12 15:52:27 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"


void mlx_event(t_list2 *data)
{
    mlx_hook(data->ptr_win,17,0,close_window,data);
    mlx_hook(data->ptr_win,2, 1,key_press,data);
    mlx_mouse_hook(data->ptr_win,mouse_wheel,data);
}

int close_window(t_list2 *data)
{
    mlx_destroy_window(data->ptr, data->ptr_win);
    mlx_destroy_image(data->ptr, data->ptr_img);
    // mlx_destroy_display(data->ptr)
    ft_exit(data);
    return(0);
}

int key_press(int button, t_list2 *data)
{
    if(button == ESC)
        close_window(data);
    return 0;
}
int mouse_wheel(int button, int x, int y, t_list2 *data)
{
    data->zoom=0.1;
    data->range_x=data->max_r - data->min_r;
    data->range_y=data->max_i - data->min_i;
    if(button== 4)
    {
        data->max_r -= data->range_x * data->zoom;
        data->max_r += data->range_x * data->zoom;
        data->max_i -= data->range_y * data->zoom;
        data->max_i += data->range_y * data->zoom;     
    }
    else if(button == 5)
    {
        data->max_r += data->range_x * data->zoom;
        data->max_r -= data->range_x * data->zoom;
        data->max_i += data->range_y * data->zoom;
        data->max_i -= data->range_y * data->zoom;    
    }
    ft_render(data);
    return 0;
}
