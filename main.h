/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:05:08 by noctis            #+#    #+#             */
/*   Updated: 2025/03/07 12:34:09 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include "./42_Libft/libft.h"
#include "main.h"

// #include "./mlx_Linux/mlx.h"
#include "./mlx/mlx.h"

typedef struct s_nbr
{
    double r;
    double i;
}   t_nbr;

typedef struct s_fractal
{
    char *name;
    double r_max;
    double r_min;
    double i_max;
    double i_min;
    
} t_fr;

typedef struct s_win
{
    void *ptr;
    void *ptr_win;
    void *ptr_img;
    void *ptr_data;
    int  bite_per_pixel;
    int size_of_line;
    int endian;
    
}   t_win;

int main(int ac, char ** ar);
int ft_check(char *t1, char* t2);
void ft_put_error();
void ft_initialize(t_fr *data, t_win *win, char ** ar);
void ft_draw_mandlbroad(t_fr *data, t_win *win , char ** ar);

#endif