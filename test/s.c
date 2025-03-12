
void mlx_event(t_list2 *data)
{
    mlx_hook(data->ptr_win, 17, 0, close_window, data);  // DestroyNotify
    mlx_hook(data->ptr_win, 2, 1L << 0, key_press, data);  // KeyPress
    mlx_hook(data->ptr_win, 6, 1L << 6, mouse_move, data);  // MotionNotify
    mlx_hook(data->ptr_win, 4, 1L << 2, mouse_click, data);  // ButtonPress
}

int close_window(t_list2 *data)
{
    ft_exit(data);
    return (0);
}

int key_press(int keycode, t_list2 *data)
{
    double r_range = data->max_r - data->min_r;
    double i_range = data->max_i - data->min_i;
    double shift = r_range * 0.1;  // 10% of view

    if (keycode == ESC)
        close_window(data);
    else if (keycode == UP)
    {
        data->max_i -= shift;
        data->min_i -= shift;
    }
    else if (keycode == DOWN)
    {
        data->max_i += shift;
        data->min_i += shift;
    }
    else if (keycode == LEFT)
    {
        data->max_r -= shift;
        data->min_r -= shift;
    }
    else if (keycode == RIGHT)
    {
        data->max_r += shift;
        data->min_r += shift;
    }
    else if (keycode == PLUS)
    {
        double new_r_range = r_range * 0.8;  // Zoom in 20%
        double new_i_range = i_range * 0.8;
        double r_center = (data->max_r + data->min_r) / 2;
        double i_center = (data->max_i + data->min_i) / 2;
        data->max_r = r_center + new_r_range / 2;
        data->min_r = r_center - new_r_range / 2;
        data->max_i = i_center + new_i_range / 2;
        data->min_i = i_center - new_i_range / 2;
    }
    else if (keycode == MINUS)
    {
        double new_r_range = r_range / 0.8;  // Zoom out 20%
        double new_i_range = i_range / 0.8;
        double r_center = (data->max_r + data->min_r) / 2;
        double i_center = (data->max_i + data->min_i) / 2;
        data->max_r = r_center + new_r_range / 2;
        data->min_r = r_center - new_r_range / 2;
        data->max_i = i_center + new_i_range / 2;
        data->min_i = i_center - new_i_range / 2;
    }
    ft_render(data);  // Redraw after each event
    return (0);
}

int mouse_move(int x, int y, t_list2 *data)
{
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
        data->mouse_x = x;
        data->mouse_y = y;
    }
    return (0);
}

int mouse_click(int button, int x, int y, t_list2 *data)
{
    double r_range = data->max_r - data->min_r;
    double i_range = data->max_i - data->min_i;
    double r_click = ft_map_x(x, data);
    double i_click = ft_map_y(y, data);

    if (button == 4)  // Scroll up - zoom in
    {
        double new_r_range = r_range * 0.8;
        double new_i_range = i_range * 0.8;
        data->max_r = r_click + new_r_range / 2;
        data->min_r = r_click - new_r_range / 2;
        data->max_i = i_click + new_i_range / 2;
        data->min_i = i_click - new_i_range / 2;
    }
    else if (button == 5)  // Scroll down - zoom out
    {
        double new_r_range = r_range / 0.8;
        double new_i_range = i_range / 0.8;
        data->max_r = r_click + new_r_range / 2;
        data->min_r = r_click - new_r_range / 2;
        data->max_i = i_click + new_i_range / 2;
        data->min_i = i_click - new_i_range / 2;
    }
    ft_render(data);  // Redraw after zoom
    return (0);
}





...........




/* Existing includes and code remain unchanged */

void mlx_event(t_list2 *data)
{
    mlx_hook(data->ptr_win, 17, 0, close_window, data); // Window close button
    mlx_hook(data->ptr_win, 2, 1L<<0, key_press, data); // Key press
    mlx_mouse_hook(data->ptr_win, mouse_wheel, data);   // Mouse wheel
}

int close_window(t_list2 *data)
{
    mlx_destroy_image(data->ptr, data->ptr_img);
    mlx_destroy_window(data->ptr, data->ptr_win);
    mlx_destroy_display(data->ptr); // Linux-specific
    free(data->ptr);
    exit(0);
    return (0);
}

int key_press(int keycode, t_list2 *data)
{
    if (keycode == ESC)
    {
        close_window(data);
    }
    return (0);
}

int mouse_wheel(int button, int x, int y, t_list2 *data)
{
    double zoom_factor = 0.1; // Adjust zoom sensitivity
    double range_r = data->max_r - data->min_r;
    double range_i = data->max_i - data->min_i;
    if (button == 4) // Scroll up (zoom in)
    {
        data->max_r -= range_r * zoom_factor;
        data->min_r += range_r * zoom_factor;
        data->max_i -= range_i * zoom_factor;
        data->min_i += range_i * zoom_factor;
    }
    else if (button == 5) // Scroll down (zoom out)
    {
        data->max_r += range_r * zoom_factor;
        data->min_r -= range_r * zoom_factor;
        data->max_i += range_i * zoom_factor;
        data->min_i -= range_i * zoom_factor;
    }
    ft_render(data); // Re-render after zooming
    return (0);
}

void ft_exit(t_list2 *data)
{
    if (data->ptr_img)
        mlx_destroy_image(data->ptr, data->ptr_img);
    if (data->ptr_win)
        mlx_destroy_window(data->ptr, data->ptr_win);
    if (data->ptr)
    {
        mlx_destroy_display(data->ptr); // Linux-specific
        free(data->ptr);
    }
    exit(1);
}