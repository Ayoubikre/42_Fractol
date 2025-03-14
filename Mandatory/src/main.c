/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:31:44 by noctis            #+#    #+#             */
/*   Updated: 2025/03/13 08:38:53 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../main.h"

int main(int ac, char **ar)
{
    atexit(leaks);
    t_list2 data;
    
    ft_arguments(ac , ar, &data);
    ft_initialize(&data);
    mlx_event(&data);
    ft_render(&data);
    mlx_loop(data.ptr);
    return 0;
}

void leaks()
{
    system("leaks fractol");
}
