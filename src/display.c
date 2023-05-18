/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:04:41 by abiddane          #+#    #+#             */
/*   Updated: 2023/01/14 14:49:26 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_char(char c, t_data *data, size_t x, size_t y)
{
	int	size;

	size = 64;
	if (c == '1')
		data->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./img/wall.xpm",
				&size, &size);
	if (c == '0')
		data->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./img/floor.xpm",
				&size, &size);
	if (c == 'E')
		data->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./img/door.xpm",
				&size, &size);
	if (c == 'P')
		data->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
				"./img/player.xpm", &size, &size);
	if (c == 'C')
		data->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
				"./img/collectible.xpm", &size, &size);
	if (!data->img_ptr)
		kill_error_image("Image not found", data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr,
		x * 64, y * 64);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
}		

int	display_map(t_data *data)
{
	data->y = 0;
	while (data->y < ft_tablen(data->map_tab))
	{
		data->x = 0;
		while (data->x < ft_strlen(data->map_tab[0]))
		{
			display_char(data->map_tab[data->y][data->x], data,
				data->x, data->y);
			data->x++;
		}
		data->y++;
	}
	return (0);
}
