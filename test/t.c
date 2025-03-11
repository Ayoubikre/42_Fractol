#include "main.h"  // Change to "minilibx_opengl/mlx.h" for macOS

// typedef struct s_data {
//     void *ptr;
//     void *ptr_win;
//     void *ptr_img;
//     char *ptr_pxl;
//     int byte_to_pxl;        // Bits per pixel
//     int size_of_line;  // Bytes per line
//     int endian;     // Endianness
// } t_data;

// // // Function to close the window and exit
// // int close_window(t_data *data)
// // {
// //     mlx_destroy_image(data->ptr, data->ptr_img);
// //     mlx_destroy_window(data->ptr, data->ptr_win);
// //     free(data->ptr);
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
// //                 pixel = (i * data->size_of_line) + (j * (data->byte_to_pxl / 8));
// //                 dst = data->ptr_pxl + pixel;
// //                 *(unsigned int *)dst = 0x0000FF;  // Blue
// //             }
// //         }
// //         mlx_put_image_to_window(data->ptr, data->ptr_win, data->ptr_img, 350, 250);
// //     }
// //     return (0);
// // }

// int main(void)
// {
//     t_data data;

//     // Initialize MiniLibX
//     data.ptr = mlx_init();
//     if (!data.ptr)
//         return (1);

//     // Create a window
//     data.ptr_win = mlx_new_window(data.ptr, 800, 800, "MiniLibX Intro");
//     if (!data.ptr_win)
//         return (1);

//     // Create an image (100x100 pixels)
//     data.ptr_img = mlx_new_image(data.ptr, 799, 799);
//     if (!data.ptr_img)
//         return (1);

//     // Get image data address
//     data.ptr_pxl = mlx_get_data_addr(data.ptr_img, &data.byte_to_pxl, &data.size_of_line, &data.endian);

//     // Fill the image with red (0xFF0000)
//     int pixel;
//     char *dst;
//     for (int i = 0; i < 900; i++)
//     {
//         for (int j = 0; j < 900; j++)
//         {
//             pixel = (i * data.size_of_line) + (j * (data.byte_to_pxl / 8));
//             dst = data.ptr_pxl + pixel;
//             *(unsigned int *)dst = 0xFF0000;  // Red
//         }
//     }

//     // Display the image in the window (centered at 350, 250)
//     mlx_put_image_to_window(data.ptr, data.ptr_win, data.ptr_img, 350, 250);

//     // // Hook events
//     // mlx_key_hook(data.ptr_win, key_press, &data);           // ESC key
//     // mlx_mouse_hook(data.ptr_win, mouse_click, &data);       // Mouse click
//     // mlx_hook(data.ptr_win, 17, 0, close_window, &data);     // Window close button (event 17 = DestroyNotify)

//     // Start the event loop
//     mlx_loop(data.ptr);

//     return (0);
// }


typedef struct s_data {
    void *ptr;
    void *ptr_win;
    void *ptr_win2;
    void *ptr_img;
    char *ptr_pxl;
    int byte_to_pxl;        // Bits per pixel
    int size_of_line;  // Bytes per line
    int endian;     // Endianness
} t_data;

int	close_window(t_list2 *data)
{
	mlx_destroy_window(data->ptr, data->ptr_win);
	mlx_destroy_image(data->ptr, data->ptr_img);
	free(data->ptr);
	exit(0);
}

void leaks()
{
	system("leaks fractol");
}

int	main()
{
	atexit(leaks);
    t_data data;

    // Initialize MiniLibX
    data.ptr = mlx_init();
    if (!data.ptr)
        return (1);

    // Create a window
    data.ptr_win = mlx_new_window(data.ptr, 800, 600, "Fractol Image");
    if (!data.ptr_win)
        return (1);

    // Create an image (200x200 pixels)
    data.ptr_img = mlx_new_image(data.ptr, 200, 200);
    if (!data.ptr_img)
        return (1);

    // Get image data address
    data.ptr_pxl = mlx_get_data_addr(data.ptr_img, &data.byte_to_pxl, &data.size_of_line, &data.endian);

    // Draw a square (red) or triangle (blue) on the image
    int pixel;
    char *dst;


    // Square (uncomment for square, comment out triangle below)

    for (int y = 50; y < 150; y++)  // 100x100 square at (50, 50)
    {
        for (int x = 50; x < 150; x++)
        {
            pixel = (y * data.size_of_line) + (x * (data.byte_to_pxl / 8));
            dst = data.ptr_pxl + pixel;
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
            pixel = (y * data.size_of_line) + (x * (data.byte_to_pxl / 8));
            dst = data.ptr_pxl + pixel;
            *(unsigned int *)dst = 0x0000FF;  // Blue
        }
    }

    // Display the image in the window (centered at 300, 200)
    mlx_put_image_to_window(data.ptr, data.ptr_win, data.ptr_img, 300, 200);
		mlx_hook(data.ptr_win, 17, 0, close_window, &data);

    // Start the event loop (required to keep window open)
    mlx_loop(data.ptr);

    return (0);
}