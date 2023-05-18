/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:39:09 by abiddane          #+#    #+#             */
/*   Updated: 2023/01/14 14:08:50 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Check the arguments */
int	arg_error(int ac, char *file, t_data *data)
{
	int	i;

	if (ac != 2)
	{
		ft_printf("Error\nIncorrect arguments");
		free(data);
		exit(EXIT_FAILURE);
		return (0);
	}
	i = 0;
	while (file[i])
	{
		if (file[i] == '.')
		{
			if (file[i + 1] == 'b' && file[i + 2] == 'e'
				&& file[i + 3] == 'r' && file[i + 4] == '\0')
				return (1);
		}
		i++;
	}
	ft_printf("Error\nIncorrect file");
	free(data);
	exit(EXIT_FAILURE);
	return (0);
}

/* Check if there is only "01ECP" characters */
int	char_map(t_data *data)
{
	data->y = 0;
	while (data->y < ft_tablen(data->map_tab))
	{
		data->x = 0;
		while (data->x < ft_strlen(data->map_tab[0]))
		{
			if (data->map_tab[data->y][data->x] != '1'
				&& data->map_tab[data->y][data->x] != '0'
					&& data->map_tab[data->y][data->x] != 'E'
						&& data->map_tab[data->y][data->x] != 'C'
							&& data->map_tab[data->y][data->x] != 'P')
				kill_error("Wrong character in the map", data);
			data->x++;
		}
		data->y++;
	}
	return (1);
}

/* Check if the height is > 2 and if the map is rectangular */
int	rectangular_map(t_data *data)
{
	int	i;

	if (!data->map_tab[0] || !data->map_tab[1] || !data->map_tab[2])
		kill_error("Non-compliant map", data);
	i = 1;
	while (data->map_tab[i] != NULL)
	{
		if (ft_strlen(data->map_tab[i]) != ft_strlen(data->map_tab[i - 1]))
			kill_error("Non-rectangular map", data);
		i++;
	}
	return (1);
}

/* Check that the map is surrounded by wall */
int	walled_map(t_data *data)
{
	data->x = 0;
	data->y = ft_tablen(data->map_tab) - 1;
	while (data->x < ft_strlen(data->map_tab[0]))
	{
		if (data->map_tab[0][data->x] != '1'
			|| data->map_tab[data->y][data->x] != '1')
			kill_error("Wall not closed", data);
		data->x++;
	}
	data->x = ft_strlen(data->map_tab[0]) - 1;
	data->y = 1;
	while (data->y < ft_tablen(data->map_tab) - 1)
	{
		if (data->map_tab[data->y][0] != '1'
			|| data->map_tab[data->y][data->x] != '1')
			kill_error("Wall not closed", data);
		data->y++;
	}
	return (1);
}
