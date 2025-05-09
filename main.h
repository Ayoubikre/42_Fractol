/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:40:02 by aakritah          #+#    #+#             */
/*   Updated: 2025/03/14 18:00:59 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "./42_Libft/libft.h"
// # include "./mlx/mlx.h"
# include "./mlx_Linux/mlx.h"
# include "main.h"
# include <math.h>
# include <unistd.h>

# define WIDTH 500
# define HEIGHT 400
# define ITTER 60

# ifdef __linux__
#  define LX 1
#  define ESC 65307
#  define LEFT 65361
#  define RIGHT 65363
#  define DOWN 65364
#  define UP 65362
# else
#  define LX 0
#  define ESC 53
#  define LEFT 123
#  define RIGHT 124
#  define DOWN 125
#  define UP 126
# endif

typedef struct s_nbr
{
	double		r;
	double		i;

}				t_nbr;

typedef struct s_list2
{
	char		*name;
	char		*t;
	int			pixel;
	int			x;
	int			y;
	int			f;
	int			k;
	double		max_r;
	double		min_r;
	double		max_i;
	double		min_i;
	double		zoom;
	double		vr[2];
	double		center_x;
	double		center_y;

	void		*ptr;
	void		*ptr_win;
	void		*ptr_img;
	char		*ptr_pxl;
	int			bytes_per_pixel;
	int			bytes_per_row;
	int			endian;
}				t_list2;

int				main(int ac, char **ar);

void			ft_arguments(int ac, char **ar, t_list2 *data);
double			ft_atof(char *t);
int				ft_check(char *t, char *ar);

void			ft_initialize(t_list2 *data);

void			ft_render(t_list2 *data);
void			ft_calcul(t_list2 *data);
void			ft_ar(t_nbr *z, t_nbr *c, t_list2 *data);
double			ft_map_x(int x, t_list2 *data);
double			ft_map_y(int y, t_list2 *data);

unsigned int	ft_colore(t_list2 *data);
void			ft_message(int f);

void			mlx_event(t_list2 *data);
int				close_window(t_list2 *data);
int				key_press(int key, t_list2 *data);
int				mouse_hook(int button, int x, int y, t_list2 *data);

int				mouse_move(int x, int y, t_list2 *data);

#endif
