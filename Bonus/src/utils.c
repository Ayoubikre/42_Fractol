/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:46:56 by aakritah          #+#    #+#             */
/*   Updated: 2025/03/14 13:54:17 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

unsigned int	ft_colore(t_list2 *data)
{
	int	r;
	int	g;
	int	b;

	if (data->k == ITTER)
		return (0x000000);
	r = (data->k * 5) % 256;
	g = (data->k * 10) % 256;
	b = (data->k * 15) % 256;
	return (r << 16 | g << 8 | b);
}

void	ft_message(int f)
{
	if (f == 1)
		ft_printf("give a whidth value betwenn  -2 and 2");
	else if (f == 2)
		ft_printf("give a hight value betwenn -1.5 and 1.5");
	else
	{
		ft_printf("-----------------------------------------------\n");
		ft_printf("-                                             -\n");
		ft_printf("-    Allowed arguments are :                  -\n");
		ft_printf("-                                             -\n");
		ft_printf("-         ./fractol mandelbrot                -\n");
		ft_printf("-         ./fractol julia 'Width' 'Hight'     -\n");
		ft_printf("-         ./fractol burningship               -\n");
		ft_printf("-                                             -\n");
		ft_printf("-----------------------------------------------\n");
	}
	exit(1);
}
