#include "main.h"  // Change to "minilibx_opengl/mlx.h" for macOS

// typedef struct s_data {
//     void *mlx_ptr;
//     void *win_ptr;
//     void *img_ptr;
//     char *img_data;
//     int bpp;        // Bits per pixel
//     int size_line;  // Bytes per line
//     int endian;     // Endianness
// } t_data;

// // // Function to close the window and exit
// // int close_window(t_data *data)
// // {
// //     mlx_destroy_image(data->mlx_ptr, data->img_ptr);
// //     mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// //     free(data->mlx_ptr);
// //     exit(0);
// //     return (0);
// // }

// // // Function to handle key presses (ESC to close)
// // int key_press(int keycode, t_data *data)
// // {
// //     if (keycode == 65307)  // ESC key (Linux X11 keycode; 53 for macOS)
// //         close_window(data);
// //     return (0);
// // }

// // // Function to handle mouse clicks (left-click changes color)
// // int mouse_click(int button, int x, int y, t_data *data)
// // {
// //     if (button == 1)  // Left mouse button
// //     {
// //         int pixel;
// //         char *dst;

// //         // Fill the image with blue (0x0000FF)
// //         for (int i = 0; i < 100; i++)
// //         {
// //             for (int j = 0; j < 100; j++)
// //             {
// //                 pixel = (i * data->size_line) + (j * (data->bpp / 8));
// //                 dst = data->img_data + pixel;
// //                 *(unsigned int *)dst = 0x0000FF;  // Blue
// //             }
// //         }
// //         mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 350, 250);
// //     }
// //     return (0);
// // }

// int main(void)
// {
//     t_data data;

//     // Initialize MiniLibX
//     data.mlx_ptr = mlx_init();
//     if (!data.mlx_ptr)
//         return (1);

//     // Create a window
//     data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 800, "MiniLibX Intro");
//     if (!data.win_ptr)
//         return (1);

//     // Create an image (100x100 pixels)
//     data.img_ptr = mlx_new_image(data.mlx_ptr, 799, 799);
//     if (!data.img_ptr)
//         return (1);

//     // Get image data address
//     data.img_data = mlx_get_data_addr(data.img_ptr, &data.bpp, &data.size_line, &data.endian);

//     // Fill the image with red (0xFF0000)
//     int pixel;
//     char *dst;
//     for (int i = 0; i < 900; i++)
//     {
//         for (int j = 0; j < 900; j++)
//         {
//             pixel = (i * data.size_line) + (j * (data.bpp / 8));
//             dst = data.img_data + pixel;
//             *(unsigned int *)dst = 0xFF0000;  // Red
//         }
//     }

//     // Display the image in the window (centered at 350, 250)
//     mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 350, 250);

//     // // Hook events
//     // mlx_key_hook(data.win_ptr, key_press, &data);           // ESC key
//     // mlx_mouse_hook(data.win_ptr, mouse_click, &data);       // Mouse click
//     // mlx_hook(data.win_ptr, 17, 0, close_window, &data);     // Window close button (event 17 = DestroyNotify)

//     // Start the event loop
//     mlx_loop(data.mlx_ptr);

//     return (0);
// }


typedef struct s_data {
    void *mlx_ptr;
    void *win_ptr;
    void *win_ptr2;
    void *img_ptr;
    char *img_data;
    int bpp;        // Bits per pixel
    int size_line;  // Bytes per line
    int endian;     // Endianness
} t_data;

int main(void)
{
    t_data data;

    // Initialize MiniLibX
    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
        return (1);

    // Create a window
    data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "Fractol Image");
    if (!data.win_ptr)
        return (1);
    data.win_ptr2 = mlx_new_window(data.mlx_ptr, 800, 600, "Fractol Image22");
    if (!data.win_ptr2)
        return (1);

    // Create an image (200x200 pixels)
    data.img_ptr = mlx_new_image(data.mlx_ptr, 200, 200);
    if (!data.img_ptr)
        return (1);

    // Get image data address
    data.img_data = mlx_get_data_addr(data.img_ptr, &data.bpp, &data.size_line, &data.endian);

    // Draw a square (red) or triangle (blue) on the image
    int pixel;
    char *dst;


    // Square (uncomment for square, comment out triangle below)

    for (int y = 50; y < 150; y++)  // 100x100 square at (50, 50)
    {
        for (int x = 50; x < 150; x++)
        {
            pixel = (y * data.size_line) + (x * (data.bpp / 8));
            dst = data.img_data + pixel;
            *(unsigned int *)dst = 0xFF0000;  // Red
        }
    }


    // Triangle (blue, base at y=150, apex at (100, 50))
    for (int y = 50; y <= 150; y++)  // Height from 50 to 150
    {
        int width = (150 - y) / 2;   // Width decreases as y increases
        int start_x = 100 - width;   // Center at x=100, shift left
        int end_x = 100 + width;     // Shift right
        for (int x = start_x; x <= end_x; x++)
        {
            pixel = (y * data.size_line) + (x * (data.bpp / 8));
            dst = data.img_data + pixel;
            *(unsigned int *)dst = 0x0000FF;  // Blue
        }
    }

    // Display the image in the window (centered at 300, 200)
    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 300, 200);
    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr2, data.img_ptr, 300, 200);

    // Start the event loop (required to keep window open)
    mlx_loop(data.mlx_ptr);

    return (0);
}