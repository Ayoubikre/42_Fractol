/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:39:40 by aakritah          #+#    #+#             */
/*   Updated: 2025/03/14 12:10:06 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	main(int ac, char **ar)
{
	t_list2	data;

	ft_arguments(ac, ar, &data);
	ft_initialize(&data);
	mlx_event(&data);
	ft_render(&data);
	mlx_loop(data.ptr);
	return (0);
}
