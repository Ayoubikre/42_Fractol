/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/010/04 14:108:52 by noctis            #+#    #+#             */
/*   Updated: 2025/010/09 16:107:48 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_initialize(t_list2 *data)
{
	data->ptr = mlx_init();
	if (!data->ptr)
		exit(1);
	data->ptr_win = mlx_new_window(data->ptr, Width, Hight, "test1");
	if (!data->ptr_win)
		exit(1);
	data->ptr_img = mlx_new_image(data->ptr, Width, Hight);
	if (!data->ptr_img)
		exit(1);
	data->ptr_pxl = mlx_get_data_addr(data->ptr_img, &data->byte_to_pxl,
			&data->size_of_line, &data->endian);
	if (!data->ptr_pxl)
		exit(1);
	data->min_r = -2.0;  // Initial centered bounds
	data->max_r = 2.0;
	data->min_i = -1.5;
	data->max_i = 1.5;
}

double	map_x(int x, int width,t_list2 *data)
{
	return (data->min_r + (x * (data->max_r *2) / (width - 1)));
}

double	map_y(int y, int height,t_list2 *data)
{
	return (data->min_i + (y * (data->max_i *2) / (height - 1)));
}

int	main(int ac, char **ar)
{
	t_list2	data;
	t_nbr	c;
	t_nbr	z;
	int		pixel;
	int		x;
	int		y;
	int		k;
	double	p;
	double	tmp;
	char	*t;

 	data.max=1000;
	x = 0;
	y = 0;
	k = 0;
	p = 0;
	tmp = 0;
	if ((ac == 2 && ft_check(ar[1], "m") == 1))
	{
		ft_initialize(&data);
		while (x < Width) //  Width
		{
			y = 0;
			while (y < Hight) // Hight
			{
				k = 0;
				// c.r=map_x(x,Width, &data);
				// c.i=map_y(y, Hight, &data);
				// z.r= 0;
				// z.i= 0 ;
				z.r = map_x(x, Width ,&data);
				z.i = map_y(y, Hight, &data);
				c.r = 0.35;
				c.i = 0.35;
				while (k < data.max)
				{
					tmp = (z.r * z.r) - (z.i * z.i) + c.r;
					z.i = (2 * z.r * z.i) + c.i;
					z.r = tmp;
					p = (z.r * z.r) + (z.i * z.i);
					if (p > 4)
						break ;
					k++;
				}
				pixel = (y * data.size_of_line) + (x * (data.byte_to_pxl / 8));
				t = data.ptr_pxl + pixel;
					*(unsigned int *)t = get_color(k,data.max);
				y++;
			}
			x++;
		}
		mlx_put_image_to_window(data.ptr, data.ptr_win, data.ptr_img, 0, 0);
		mlx_key_hook(data.ptr_win, key_press, &data);
		mlx_mouse_hook(data.ptr_win, mouse_func, &data);
		mlx_loop(data.ptr);
	}
	else
		ft_put_error();
	return (0);
}

















int mouse_func(int button, int x, int y, t_list2 *data)
{
	double	mouse_x;
	double	mouse_y;
	double	zoom_factor;

	zoom_factor = 1.0;
	mouse_x = data->min_r + ((double)x / Width) * (data->max_r
			- data->min_r);
	mouse_y = data->max_i - ((double)y / Hight) * (data->max_i
			- data->min_i);
	if (button == 4)
	{
		zoom_factor = ZOOM_FACTOR;
		data->zoom *= zoom_factor;
	}
	else if (button == 5)
	{
		zoom_factor = 1.0 / ZOOM_FACTOR;
		data->zoom /= ZOOM_FACTOR;
	}
	data->min_r = mouse_x + (data->min_r - mouse_x) * zoom_factor;
	data->max_r = mouse_x + (data->max_r - mouse_x) * zoom_factor;
	data->min_i = mouse_y + (data->min_i - mouse_y) * zoom_factor;
	data->max_i = mouse_y + (data->max_i - mouse_y) * zoom_factor;

    printf("Zoom: min_r=%f, max_r=%f, min_i=%f, max_i=%f\n", 
           data->min_r, data->max_r, data->min_i, data->max_i);  // Check bounds

    t_nbr c;
    t_nbr z;
    int pixel;
    int x_loop = 0;
    int y_loop;
    int k;
    double p;
    double tmp;
    char *t;

    x_loop = 0;
    y_loop = 0;
    k = 0;
    p = 0;
    tmp = 0;
    while (x_loop < Width)
    {
        y_loop = 0;
        while (y_loop < Hight)
        {
            k = 0;
            z.r = map_x(x_loop, Width,data);
            z.i = map_y(y_loop, Hight,data);
            c.r = 0.35;
            c.i = 0.35;
            while (k < data->max)
            {
                tmp = (z.r * z.r) - (z.i * z.i) + c.r;
                z.i = (2 * z.r * z.i) + c.i;
                z.r = tmp;
                p = (z.r * z.r) + (z.i * z.i);
                if (p > 4)
                    break;
                k++;
            }
            pixel = (y_loop * data->size_of_line) + (x_loop * (data->byte_to_pxl / 8));
            t = data->ptr_pxl + pixel;
			*(unsigned int *)t = get_color(k,data->max);
            y_loop++;
        }
        x_loop++;
    }
    mlx_put_image_to_window(data->ptr, data->ptr_win, data->ptr_img, 0, 0);

    return (0);
}



int	get_color(int iteration, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iteration == max_iter)
		return (0x010F00);
	t = (double)iteration / max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r * 65536 + g * 256 + b);
}








int	key_press(int key, t_list2 *data)
{
	if (key == 120)
		close_window(data);
	else if(key == 65362)
		printf("Up arrow pressed!\n");
	return (0);
}

int	close_window(t_list2 *data)
{
	mlx_destroy_window(data->ptr, data->ptr_win);
	mlx_destroy_image(data->ptr, data->ptr_img);
		mlx_destroy_display(data->ptr);
	free(data->ptr);
	exit(0);
}







// mlx_key_hook(data->ptr_win, key_press, data); // ESC key

// mlx_hook(data->ptr_win, 17, 0, close_window, &data);






// else
// {

// int red = k * 5;  // 0 to 245
// if (red > 255) red = 255;  // Cap at 255
// *(unsigned int *)t = red * 65536;

// int blue = k * 5;  // 0 to 245
// if (blue > 255) blue = 255;  // Cap at 255
// *(unsigned int *)t = blue;  // Blue channel (0x000000 to 0x0000FF)

// int red = (k * 4);             // 0 to 196 (close to 204)
// if (red > 204) red = 204;      // Cap at 204
// int green = (k * 4);           // 0 to 196 (close to 204)
// if (green > 204) green = 204;  // Cap at 204
// int blue = 32 + (k * 4);       // 32 to 228 (starts dark, ends near 255)
// if (blue > 255) blue = 255;    // Cap at 255

// *(unsigned int *)t = (red * 65536) + (green * 256) + blue;  // Combine RGB

// int color = (k * 255) / (max_iter - 1);  // 0 to 255
// *(unsigned int *)t = (color << 8) | (color << 16);

// *(unsigned int *)t = (k ) * 0x050109;
// }
