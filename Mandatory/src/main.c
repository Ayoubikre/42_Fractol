/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:31:44 by noctis            #+#    #+#             */
/*   Updated: 2025/03/11 15:23:03 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../main.h"


int main(int ac, char **ar)
{
   
    t_list2 data;
    
    ft_arguments(ac , ar, &data);
    ft_initialize(&data);
    if(data.f==1)
        ft_render_mandelbrot(&data);
    // else
    //     ft_render_mandelbroad(&data);
    mlx_event(&data);
    mlx_loop(data.ptr);
    return 0;
}

void leaks()
{
    system("leaks fractol");
}
