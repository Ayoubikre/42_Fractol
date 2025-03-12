/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:07:14 by aakritah          #+#    #+#             */
/*   Updated: 2025/03/11 20:01:51 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	ft_arguments(int ac, char **ar, t_list2 *data)
{
	// segfault mayby ?
	if (!ft_strncmp("mandelbrot", ar[1], ft_strlen(ar[1])) && ac == 2)
		((data->f = 1), (data->name = ar[1]));
	else if (!ft_strncmp("julia", ar[1], ft_strlen(ar[1])) && ac == 4)
	{
		data->vl[0] = ft_atoi2(ar[3]);
		if (data->r_max < data->vl[0] || data->vl[0] < data->r_min)
			ft_message(1);
		
		data->vl[1] = ft_atoi2(ar[4]);
		if (data->r_max < data->vl[1] || data->vl[1] < data->r_min)
			ft_message(2);

		data->f = 2;
		data->name = ar[1];
	}
	else
		ft_message(3);
	return ;
}

void	ft_message(int f)
{
	if(f==1)
		ft_printf("give a whidth value betwenn  2 and 2");
	else if(f==2)
		ft_printf("give a hight value betwenn -1.5 and 1.5");
	else{		
		ft_printf("-----------------------------------------------\n");
		ft_printf("-                                             -\n");
		ft_printf("-    Allowed arguments are :                  -\n");
		ft_printf("-                                             -\n");
		ft_printf("-         ./fractol mandelbrot                -\n");
		ft_printf("-         ./fractol julia 'Width' 'Hight'     -\n");
		ft_printf("-                                             -\n");
		ft_printf("-----------------------------------------------\n");
	}
	exit(1);
}

double ft_atoi2(char *t);
{
	double r;
	double i;
	double f;
	
}