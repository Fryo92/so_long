/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:15:29 by abiddane          #+#    #+#             */
/*   Updated: 2023/01/23 16:57:45 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_new_window(t_data *data)
{
	void	*win_ptr;

	data->move = 0;
	data->width = ft_strlen(data->map_tab[0]) * 64;
	data->height = ft_tablen(data->map_tab) * 64;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (0);
	if (data->width > 1930 || data->height > 1060)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		kill_error("Map too big", data);
	}	
	win_ptr = mlx_new_window(data->mlx_ptr, data->width,
			data->height, "mlx 42");
	return (win_ptr);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	if (!map_isvalid(ac, av[1], data))
		return (0);
	data->win_ptr = ft_new_window(data);
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (0);
	}
	display_map(data);
	event_handling(data);
	mlx_loop(data->mlx_ptr);
	return (1);
}
