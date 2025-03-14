/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:25:38 by aakritah          #+#    #+#             */
/*   Updated: 2025/03/13 15:32:37 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"


void mlx_event(t_list2 *data)
{
    mlx_hook(data->ptr_win,17,0,close_window,data);
    mlx_hook(data->ptr_win,2, 1,key_press,data);
    mlx_mouse_hook(data->ptr_win,mouse_hook,data);
}

int close_window(t_list2 *data)
{
    if (data->ptr_img)
        mlx_destroy_image(data->ptr, data->ptr_img);
    if (data->ptr_win)
        mlx_destroy_window(data->ptr, data->ptr_win);  
    mlx_destroy_display(data->ptr);
    ft_exit(data);
    return(0);
}

int key_press(int button, t_list2 *data)
{
    if(button == ESC)
        close_window(data);
    return 0;
}



double ft_map_x(int x, t_list2 *data)
{
    return ((x - WIDTH / 2.0) / (0.25 * data->zoom * WIDTH) + data->center_x);
}

double ft_map_y(int y, t_list2 *data)
{
    return ( (y - HEIGHT / 2.0) / (0.25 * data->zoom * HEIGHT) +data->center_x );
}



int mouse_hook(int button, int x, int y, t_list2 *data)
{
    if (button == 4) // Zoom in
        data->zoom *= 1.1;
    else if (button == 5) // Zoom out
        data->zoom *= 0.9;
    ft_render(data);
    return 0;
}

// int mouse_wheel(int button, int x, int y, t_list2 *data)
// {

//     double zoom_factor = 1.0;

//     if (button == 4) // Zoom in
//         zoom_factor = 1.2;
//     else if (button == 5) // Zoom out
//         zoom_factor = 0.8;

//     // Adjust zoom factor
//     data->zoom*= zoom_factor;

//     // Adjust the center of the fractal (so zoom happens around the mouse cursor)
//     double real_coord = ft_map_x(x, data);  // Get the real coordinate at the mouse position
//     double imag_coord = ft_map_y(y, data);  // Get the imaginary coordinate at the mouse position

//     // Update the center of the fractal to zoom in on the mouse cursor
//     data->center_x = real_coord;
//     data->center_y = imag_coord;

//     // Update the real and imaginary ranges based on the new zoom factor
//     data->max_r = data->center_x + (data->max_r - data->center_x) * zoom_factor;
//     data->min_r = data->center_x + (data->min_r - data->center_x) * zoom_factor;
//     data->max_i = data->center_y + (data->max_i - data->center_y) * zoom_factor;
//     data->min_i = data->center_y + (data->min_i - data->center_y) * zoom_factor;

//     ft_render(data); // Re-render after zooming
//     return (0);
// }


// double	ft_map_x(int x, t_list2 *data)
// {
// 	return (data->min_r + (x * (data->max_r - data->min_r) / (WIDTH - 1)));
// }

// double	ft_map_y(int y, t_list2 *data)
// {
// 	return (data->min_i + (y * (data->max_i - data->min_i) / (HEIGHT - 1)));
// }

// int mouse_wheel(int button, int x, int y, t_list2 *data)
// {
    
//     data->range_x=data->max_r - data->min_r;
//     data->range_y=data->max_i - data->min_i;
//     if (button == 4)
//     {
//         data->zoom=0.1;
//         data->max_r -= data->range_x * data->zoom;
//         data->min_r += data->range_x * data->zoom;
//         data->max_i -= data->range_y * data->zoom;
//         data->min_i += data->range_y * data->zoom;
//     }
//     else 
//     if (button == 5) 
//     {
//         data->zoom=0.9;
//         data->max_r += data->range_x * data->zoom;
//         data->min_r -= data->range_x * data->zoom;
//         data->max_i += data->range_y * data->zoom;
//         data->min_i -= data->range_y * data->zoom;
//     }
//     ft_render(data);
//     return (0);
// }




// void zoom_set(int x, int y, t_list2 *data, double zoom_factor) {
//     double real, imag;
    
//     real = (x - WIDTH / 2.0) / (0.5 * data->zoom * WIDTH) + data->x;
//     imag = (y - HEIGHT / 2.0) / (0.5 * data->zoom * HEIGHT) + data->y;

//     data->zoom *= zoom_factor;
//     data->x = real - (x - WIDTH / 2.0) / (0.5 * data->zoom * WIDTH);
//     data->y = imag - (y - HEIGHT / 2.0) / (0.5 * data->zoom * HEIGHT);
// }

// int mouse_wheel(int button, int x, int y, t_list2 *data)
// {
//     if (button == 4) // Scroll up (Zoom in)
//         data->zoom=1.1;
//     else if (button == 5) // Scroll down (Zoom out)
//         data->zoom=0.9;
//     printf("%f",data->zoom);
//     ft_render(data);
//     return (0);
// }

