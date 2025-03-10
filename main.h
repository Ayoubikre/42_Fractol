/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:05:08 by noctis            #+#    #+#             */
/*   Updated: 2025/03/10 06:58:11 by noctis           ###   ########.fr       */
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

#include "./mlx_Linux/mlx.h"
// #include "./mlx/mlx.h"

#define Hight 1000
#define Width 1000
typedef struct s_nbr
{
    double r;
    double i;
}   t_nbr;

typedef struct s_list2
{
// normal data:    
    char *name;

// mlx data:
    void *ptr;
    void *ptr_win;
    void *ptr_img;
    char  *ptr_pxl;
    int byte_to_pxl;
    int size_of_line;
    int endian;
    
    
// img data:
    double max_real;
    
    
    
}  t_list2;

// ------
// int	main(int ac, char **ar);
// void	ft_initialize(t_list2 *data);




// // ------
// int	close_window(t_list2 *data);
// int	key_press(int keycode, t_list2 *data);
// int	ft_check(char *t1, char *t2);
// void	ft_put_error(void);


#endif