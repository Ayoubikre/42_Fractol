/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:07:14 by aakritah          #+#    #+#             */
/*   Updated: 2025/03/11 15:17:56 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void ft_arguments(int ac, char **ar, t_list2 *data)
{
    if(!ft_strncmp("mandelbrot" , ar[1], ft_strlen(ar[1])) && ac == 2)
        ((data->f=1),(data->name=ar[1]));
    else if(!ft_strncmp("julia", ar[1], ft_strlen(ar[1])) && ac == 4)
        ((data->f=2),(data->name=ar[1]));
    else
        ft_message();
    return;
}

void	ft_message(void)
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
