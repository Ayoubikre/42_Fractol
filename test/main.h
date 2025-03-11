/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:05:08 by noctis            #+#    #+#             */
/*   Updated: 2025/03/11 08:58:53 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../42_Libft/libft.h"
# include "../mlx_Linux/mlx.h"
# include "main.h"
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
// #include "./mlx/mlx.h"

# ifndef __linux__
#  define ESC_KEY 65307
#  define UP_KEY 65362
#  define f 1
# else
#  define ESC_KEY 53
#  define UP_KEY  126
#  define f 0
# endif
// #define Width 3200
// #define Hight 2400
# define Width 1200
# define Hight 900
# define MAX_ITER 500
# define ZOOM_FACTOR 1.0

typedef struct s_nbr
{
	double	r;
	double	i;
}			t_nbr;

typedef struct s_list2
{
	// normal data:
	char	*name;

	// mlx data:
	void	*ptr;
	void	*ptr_win;
	void	*ptr_img;
	char	*ptr_pxl;
	int		byte_to_pxl;
	int		size_of_line;
	int		endian;

	// img data:
	double	max_real;
	int		color;
    
	double min_r ;
	double max_r ;
	double min_i ;
	double max_i ;
    double zoom;
    int max ;
}			t_list2;

// // ------
// int			main(int ac, char **ar);
// void		ft_initialize(t_list2 *data);

// // ------
// int			close_window(t_list2 *data);
// int			key_press(int keycode, t_list2 *data);
// int			ft_check(char *t1, char *t2);
// void		ft_put_error(void);
// int mouse_func(int button, int x, int y, t_list2 *data);
// void render_fractal(t_list2 *data);

// int	get_color(int iteration, int max_iter);

#endif