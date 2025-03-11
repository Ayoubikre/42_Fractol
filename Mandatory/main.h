/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:28:18 by noctis            #+#    #+#             */
/*   Updated: 2025/03/11 05:49:44 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include "../42_Libft/libft.h"
#include "main.h"

#include "../mlx_Linux/mlx.h"
// #include "../mlx/mlx.h"

#define Width 1200
#define Height 900 // Fixed typo from Hight

#ifdef __linux__
# define ESC_KEY 65307  // ESC on Linux
# define UP_KEY 65362   // Up arrow on Linux
# define DOWN_KEY 65364 // Down arrow on Linux
# define SPACE_KEY 32   // Spacebar on Linux
# define R_KEY 27       // 'r' on Linux
# define X_KEY 120      // 'x' on Linux

#else                // macOS
# define ESC_KEY 53   // ESC on macOS
# define UP_KEY 126   // Up arrow on macOS
# define DOWN_KEY 125 // Down arrow on macOS
# define SPACE_KEY 49 // Spacebar on macOS
# define R_KEY 15     // 'r' on macOS
# define X_KEY 7      // 'x' on macOS

#endif

typedef struct s_nbr
{
	double	r;
	double	i;
}			t_nbr;
typedef struct s_list2
{
	char	*name;
	void	*ptr;
	void	*ptr_win;
	void	*ptr_img;
	char	*ptr_pxl;
	int		byte_to_pxl;
	int		size_of_line;
	int		endian;
	double min_r; // Bounds for zoom
	double	max_r;
	double	min_i;
	double	max_i;
}			t_list2;








#endif