/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:39:36 by abiddane          #+#    #+#             */
/*   Updated: 2023/01/14 12:26:19 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_data *data)
{
	data->x = find_playerx(data->map_tab);
	data->y = find_playery(data->map_tab);
	if ((data->map_tab[data->y][data->x - 1] == 'E'
		&& collectible_count(data->map_tab) == 0))
	{
		data->move++;
		ft_printf("Move = %i\n", data->move);
		ft_printf("YOU WIN\n");
		kill_clean(data);
	}	
	else if (data->map_tab[data->y][data->x - 1] == '1'
		|| data->map_tab[data->y][data->x - 1] == 'E')
		return ;
	data->map_tab[data->y][data->x] = '0';
	data->map_tab[data->y][data->x - 1] = 'P';
	data->move++;
	display_map(data);
	ft_printf("Move = %i\n", data->move);
}

void	move_right(t_data *data)
{
	data->x = find_playerx(data->map_tab);
	data->y = find_playery(data->map_tab);
	if ((data->map_tab[data->y][data->x + 1] == 'E'
		&& collectible_count(data->map_tab) == 0))
	{
		data->move++;
		ft_printf("Move = %i\n", data->move);
		ft_printf("YOU WIN\n");
		kill_clean(data);
	}	
	else if (data->map_tab[data->y][data->x + 1] == '1'
		|| data->map_tab[data->y][data->x + 1] == 'E')
		return ;
	data->map_tab[data->y][data->x] = '0';
	data->map_tab[data->y][data->x + 1] = 'P';
	data->move++;
	display_map(data);
	ft_printf("Move = %i\n", data->move);
}

void	move_up(t_data *data)
{
	data->x = find_playerx(data->map_tab);
	data->y = find_playery(data->map_tab);
	if ((data->map_tab[data->y - 1][data->x] == 'E'
		&& collectible_count(data->map_tab) == 0))
	{
		data->move++;
		ft_printf("Move = %i\n", data->move);
		ft_printf("YOU WIN\n");
		kill_clean(data);
	}	
	else if (data->map_tab[data->y - 1][data->x] == '1'
		|| data->map_tab[data->y - 1][data->x] == 'E')
		return ;
	data->map_tab[data->y][data->x] = '0';
	data->map_tab[data->y - 1][data->x] = 'P';
	data->move++;
	display_map(data);
	ft_printf("Move = %i\n", data->move);
}

void	move_down(t_data *data)
{
	data->x = find_playerx(data->map_tab);
	data->y = find_playery(data->map_tab);
	if ((data->map_tab[data->y + 1][data->x] == 'E'
		&& collectible_count(data->map_tab) == 0))
	{
		data->move++;
		ft_printf("Move = %i\n", data->move);
		ft_printf("YOU WIN\n");
		kill_clean(data);
	}	
	else if (data->map_tab[data->y + 1][data->x] == '1'
		|| data->map_tab[data->y + 1][data->x] == 'E')
		return ;
	data->map_tab[data->y][data->x] = '0';
	data->map_tab[data->y + 1][data->x] = 'P';
	data->move++;
	display_map(data);
	ft_printf("Move = %i\n", data->move);
}
