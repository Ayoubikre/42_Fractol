

// #endif

// // Initialize MiniLibX and set default Julia parameters
// void init_fractol(t_data *data)
// {
//     data->mlx = mlx_init();
//     if (!data->mlx)
//         exit(1);
//     data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Julia Fractal");
//     if (!data->win)
//         exit(1);
//     data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
//     if (!data->img)
//         exit(1);
//     data->img_data = mlx_get_data_addr(data->img, &data->bits_per_pixel,
// &data->size_line, &data->endian);
//     data->zoom = 1.0;         // Initial zoom level
//     data->c_real = -0.7;      // Default Julia constant
//     data->c_imag = 0.27015;
//     data->offset_x = 0.0;     // Center of complex plane
//     data->offset_y = 0.0;
// }

// // Put pixel color into image buffer
// void put_pixel(t_data *data, int x, int y, int color)
// {
//     if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
//     {
//         char *dst = data->img_data + (y * data->size_line) + (x
// * (data->bits_per_pixel / 8));
//         *(unsigned int *)dst = color;
//     }
// }

// // Render Julia fractal
// void render_julia(t_data *data)
// {
//     int x, y, iter;
//     double z_r, z_i, c_r, c_i, tmp;

//     y = 0;
//     while (y < HEIGHT)
//     {
//         x = 0;
//         while (x < WIDTH)
//         {
//             // Map pixel to complex plane with zoom and offset
//             z_r = (x - WIDTH / 2.0) / (0.25 * data->zoom * WIDTH)
// + data->offset_x;
//             z_i = (y - HEIGHT / 2.0) / (0.25 * data->zoom * HEIGHT)
// + data->offset_y;
//             c_r = data->c_real;
//             c_i = data->c_imag;

//             // Julia iteration
//             iter = 0;
//             while (z_r * z_r + z_i * z_i <= 4.0 && iter < MAX_ITER)
//             {
//                 tmp = z_r * z_r - z_i * z_i + c_r;
//                 z_i = 2 * z_r * z_i + c_i;
//                 z_r = tmp;
//                 iter++;
//             }

//             // Color based on iterations
//             if (iter == MAX_ITER)
//                 put_pixel(data, x, y, 0x000000); // Black for inside set
//             else
//                 put_pixel(data, x, y, iter * 0x10101);
// Grayscale for outside
//             x++;
//         }
//         y++;
//     }
//     mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
// }

// // Mouse hook for zooming
// int mouse_hook(int button, int x, int y, t_data *data)
// {
//     if (button == 4) // Zoom in
//         data->zoom *= 1.1;
//     else if (button == 5) // Zoom out
//         data->zoom *= 0.9;
//     render_julia(data);
//     return (0);
// }

// // Key hook for exit
// int key_hook(int keycode, t_data *data)
// {
//     if (keycode == 53) // ESC key (macOS keycode)
//     {
//         mlx_destroy_image(data->mlx, data->img);
//         mlx_destroy_window(data->mlx, data->win);
//         exit(0);
//     }
//     return (0);
// }

// // Main function
// int main(void)
// {
//     t_data data;

//     init_fractol(&data);
//     render_julia(&data);
//     mlx_mouse_hook(data.win, mouse_hook, &data);
//     mlx_key_hook(data.win, key_hook, &data);
//     mlx_loop(data.mlx);
//     return (0);
// }

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

double	ft_atof(char *t)
{

}

#include <stdio.h>

int main()
{
    printf("%f\n", ft_atof(""));     // Expected: 42.195
    printf("%f\n", ft_atof("  -3.14"));    // Expected: -3.140000
    printf("%f\n", ft_atof("0.00123"));    // Expected: 0.001230
    printf("%f\n", ft_atof("123"));        // Expected: 123.000000
    printf("%f\n", ft_atof("+12.0"));      // Expected: 12.000000
    return 0;
}
