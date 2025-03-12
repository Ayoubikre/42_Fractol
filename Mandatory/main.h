/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:28:18 by noctis            #+#    #+#             */
/*   Updated: 2025/03/11 19:59:31 by noctis           ###   ########.fr       */
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

#define WIDTH 1200
#define HEIGHT 900 
#define ITTER 1000

#ifdef __linux__
#define LX 1
#define ESC 65307
#define up 65362
#else
#define LX 0
#define ESC 53
#define up 126
#endif 

typedef struct s_nbr
{
	double r;
	double i;
	
} t_nbr;

typedef struct s_list2
{
	// fractal:
	char *name;
	int f;
	double max_r;
	double min_r;
	double max_i;
	double min_i;
	char *t;
	int pixel;
	int k;
	int x;
	int y;
	double *vl[2];


	// mlx :
	void *ptr;
	void *ptr_win;
	void *ptr_img;
	char *ptr_pxl;
	int byte_to_pixel;
	int line_size;
	int endian;
	
	// events: 


	
}	t_list2;



// functions :

int main(int ac, char **ar);
void leaks();


void ft_arguments(int ac, char **ar, t_list2 *data);
void	ft_message(int f);


void    ft_initialize(t_list2 *data);


void	ft_render_mandelbrot(t_list2 *data);
void	ft_render_julia(t_list2 *data);


double	ft_map_x(int x,t_list2 *data);
double	ft_map_y(int y,t_list2 *data);
void ft_colore(t_list2 *data);


void mlx_event(t_list2 *data);
int close_window(t_list2 *data);
void ft_exit(t_list2 *data);



#endif