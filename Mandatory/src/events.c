/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:25:38 by aakritah          #+#    #+#             */
/*   Updated: 2025/03/11 13:50:22 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"


void mlx_event(t_list2 *data)
{
    mlx_hook(data->ptr_win,17,0,close_window,data);
}

int close_window(t_list2 *data)
{
    mlx_destroy_window(data->ptr, data->ptr_win);
    mlx_destroy_image(data->ptr, data->ptr_img);
    // if(LX==1)
    //     mlx_destroy_display(data->ptr);

    ft_exit(data);
    return(0);
}

void ft_exit(t_list2 *data)
{
    // free(data->ptr);
    exit(1);
}