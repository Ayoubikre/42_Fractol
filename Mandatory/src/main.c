/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:31:44 by noctis            #+#    #+#             */
/*   Updated: 2025/03/12 13:51:02 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../main.h"


int main(int ac, char **ar)
{
    atexit(leaks);
    t_list2 data;
    
    ft_arguments(ac , ar, &data);
    ft_initialize(&data);
    ft_render(&data);
    mlx_event(&data);
    mlx_loop(data.ptr);
    return 0;
}

void leaks()
{
    system("leaks fractol");
}
