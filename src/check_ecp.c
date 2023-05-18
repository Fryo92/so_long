/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ecp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:11:23 by abiddane          #+#    #+#             */
/*   Updated: 2023/01/06 15:46:48 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_e(char **tab, t_data *data)
{
	int	comp;

	comp = 0;
	data->y = 1;
	while (data->y < ft_tablen(tab) - 1)
	{
		data->x = 1;
		while (data->x < ft_strlen(tab[0]) - 1)
		{
			if (tab[data->y][data->x] == 'E')
				comp++;
			data->x++;
		}
		data->y++;
	}
	if (comp == 0)
		kill_error("No exit found", data);
	if (comp > 1)
		kill_error("More than 1 exit found", data);
	return (1);
}

int	check_p(char **tab, t_data *data)
{
	int	comp;

	comp = 0;
	data->y = 1;
	while (data->y < ft_tablen(tab) - 1)
	{
		data->x = 1;
		while (data->x < ft_strlen(tab[0]) - 1)
		{
			if (tab[data->y][data->x] == 'P')
				comp++;
			data->x++;
		}
		data->y++;
	}
	if (comp == 0)
		kill_error("No player found", data);
	if (comp > 1)
		kill_error("More than 1 player found", data);
	return (1);
}

int	check_c(char **tab, t_data *data)
{
	int	comp;

	comp = 0;
	data->y = 1;
	while (data->y < ft_tablen(tab))
	{
		data->x = 1;
		while (data->x < ft_strlen(tab[0]))
		{
			if (tab[data->y][data->x] == 'C')
				comp++;
			data->x++;
		}
		data->y++;
	}
	if (comp == 0)
		kill_error("No collectible found", data);
	return (1);
}

int	check_ecp(t_data *data)
{
	if (!check_c(data->map_tab, data))
		return (0);
	if (!check_e(data->map_tab, data))
		return (0);
	if (!check_p(data->map_tab, data))
		return (0);
	return (1);
}
