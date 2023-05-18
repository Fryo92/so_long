/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:33:18 by abiddane          #+#    #+#             */
/*   Updated: 2023/01/13 17:07:20 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_path(char **tab, size_t x, size_t y, int comp)
{
	if (tab[y][x] == 'C' || tab[y][x] == 'E')
			comp++;
	if (tab[y][x] == 'E')
		tab[y][x] = '1';
	if (tab[y][x] != '1')
	{
		tab[y][x] = '1';
		comp = find_path(tab, x + 1, y, comp);
		comp = find_path(tab, x, y - 1, comp);
		comp = find_path(tab, x - 1, y, comp);
		comp = find_path(tab, x, y + 1, comp);
	}	
	return (comp);
}

int	check_path(t_data *data)
{
	int		comp;
	int		collectible;
	char	**tab;

	tab = ft_tabdup(data->map_tab);
	comp = 0;
	data->y = find_playery(tab);
	data->x = find_playerx(tab);
	collectible = collectible_count(tab) + 1;
	comp = find_path(tab, data->x, data->y, comp);
	free_tab(tab);
	if (comp != collectible)
		kill_error("No path found", data);
	return (1);
}
