/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:39:12 by aakritah          #+#    #+#             */
/*   Updated: 2025/03/14 15:08:55 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	ft_arguments(int ac, char **ar, t_list2 *data)
{
	if (ac == 2 && ft_check("mandelbrot", ar[1]) == 1)
	{
		data->f = 1;
		data->name = ar[1];
	}
	else if (ac == 4 && ft_check("julia", ar[1]) == 1)
	{
		data->vr[0] = ft_atof(ar[2]);
		if (2.0 < data->vr[0] || data->vr[0] < -2.0)
			ft_message(1);
		data->vr[1] = ft_atof(ar[3]);
		if (1.5 < data->vr[1] || data->vr[1] < -1.5)
			ft_message(2);
		data->f = 2;
		data->name = ar[1];
	}
	else if (ac == 2 && ft_check("burningship", ar[1]) == 1)
	{
		data->f = 3;
		data->name = ar[1];
	}
	else
		ft_message(3);
	return ;
}

double	ft_atof(char *t)
{
	double	r;
	double	n;
	int		f;
	int		i;

	r = 0.0;
	n = 1.0;
	f = 1;
	i = 0;
	while (t[i] == ' ' || (9 <= t[i] && t[i] <= 13))
		i++;
	if (t[i] == '+' || t[i] == '-')
	{
		if (t[i] == '-')
			f = -1;
		i++;
	}
	while ('0' <= t[i] && t[i] <= '9')
		r = r * 10.0 + (t[i++] - '0');
	if (t[i] == '.')
		i++;
	while ('0' <= t[i] && t[i] <= '9')
		r = r + ((t[i++] - '0') / (n *= 10.0));
	return (r * f);
}

int	ft_check(char *t, char *ar)
{
	if ((ft_strnstr(t, ar, ft_strlen(ar)) != NULL)
		&& (ft_strlen(t) == ft_strlen(ar)))
		return (1);
	return (0);
}
