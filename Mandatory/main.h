/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:28:18 by noctis            #+#    #+#             */
/*   Updated: 2025/03/13 15:34:23 by noctis           ###   ########.fr       */
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
// #include "../mlx/mlx.h"

// # define WIDTH 1200
// # define HEIGHT 900
# define WIDTH 800
# define HEIGHT 600

# define ITTER 50

# ifdef __linux__
#  define LX 1
#  define ESC 65307
#  define UP 65362
#  define DOWN 65364
#  define LEFT 65361
#  define RIGHT 65363
#  define PLUS 61 
#  define MINUS 45  
# else
#  define LX 0
#  define ESC 53
#  define UP 126
#  define DOWN 125
#  define LEFT 123
#  define RIGHT 124
#  define PLUS 24 
#  define MINUS 27 
# endif

typedef struct s_nbr
{
	double	r;
	double	i;

}			t_nbr;

typedef struct s_list2
{
	// fractal:
	char	*name;
	char	*t;
	int		pixel;
	int		k;
	int		x;
	int		y;
	int		f;
	int 	offset_x;
	int 	offset_y;
	double	max_r;
	double	min_r;
	double	max_i;
	double	min_i;

	double	vr[2];

	// mlx :
	void	*ptr;
	void	*ptr_win;
	void	*ptr_img;
	char	*ptr_pxl;
	int		bytes_per_pixel;
	int		bytes_per_row;
	int		endian;

	// events:
	double zoom;
	double	center_x;
	double	center_y;
	double range_x;
	double range_y;
	
}			t_list2;

// functions :

int			main(int ac, char **ar);
void		leaks(void);

void		ft_arguments(int ac, char **ar, t_list2 *data);
void		ft_message(int f);
int			ft_check(char *t, char *ar);
double		ft_atof(char *t);

void		ft_initialize(t_list2 *data);

void	ft_render(t_list2 *data);
void	ft_calcul(t_list2 *data);

double		ft_map_x(int x, t_list2 *data);
double		ft_map_y(int y, t_list2 *data);
void		ft_colore(t_list2 *data);
void		ft_exit(t_list2 *data);

void mlx_event(t_list2 *data);
int close_window(t_list2 *data);
int key_press(int key, t_list2 *data);
int mouse_hook(int button, int x, int y , t_list2* data);

#endif
