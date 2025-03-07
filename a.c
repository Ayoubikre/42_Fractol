/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:38:52 by noctis            #+#    #+#             */
/*   Updated: 2025/03/07 12:36:26 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(int ac, char ** ar)
{
    t_fr data;
    t_win win;
    if((ac ==2 && ft_check(ar[1], "m") == 1))
    {
        ft_initialize(&data, &win, ar);
        ft_draw_mandlbroad(&data, &win, ar);
            



        mlx_loop(win.ptr);
    }
    else
        ft_put_error();
    return 0;
}

void ft_draw_mandlbroad(t_fr *data, t_win *win , char ** ar)
{
    t_nbr z;
    
    z.r=0;
    z.i=0;
    while(x<)
    
    
}

void ft_initialize(t_fr *data, t_win *win , char ** ar)
{
    data->name=ar[1];
    
    data->r_max=2;
    data->r_min=-2;
    data->i_max=1.5;
    data->i_min=-1.5;

    win->ptr=mlx_init();
    if(!win->ptr)
        exit(1);
    win->ptr_win=mlx_new_window(win->ptr,800,600,data->name);
    if(!win->ptr_win)
        exit(1);
    win->ptr_img=mlx_new_image(win->ptr,300,300);
    if(!win->ptr_img)
        exit(1);
    win->ptr_data=mlx_get_data_addr(win->ptr_img,&win->bite_per_pixel,&win->size_of_line,&win->endian);
    if(!win->ptr_data)
        exit(1);
}


int ft_check(char *t1, char* t2)
{
    if((ft_strnstr(t1, t2, ft_strlen(t2)) !=NULL) &&  (ft_strlen(t1) == ft_strlen(t2)))
        return 1;
    return 0;
}

void ft_put_error()
{
    ft_printf("-----------------------------------------------\n");
    ft_printf("-                                             -\n");
    ft_printf("-    Allowed arguments are :                  -\n");
    ft_printf("-                                             -\n");
    ft_printf("-         ./fractol mandelbrot                -\n");
    ft_printf("-         ./fractol julia 'Width' 'Hight'     -\n");
    ft_printf("-                                             -\n");
    ft_printf("-----------------------------------------------\n");
    exit(1);    
}
