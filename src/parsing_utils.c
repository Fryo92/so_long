/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:58:00 by abiddane          #+#    #+#             */
/*   Updated: 2023/01/04 14:40:34 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_playery(char **tab)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (tab[y][x] == 'P')
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

int	find_playerx(char **tab)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (tab[y][x] == 'P')
				return (x);
			x++;
		}
		y++;
	}
	return (0);
}

int	collectible_count(char **tab)
{
	int	y;
	int	x;
	int	comp;

	comp = 0;
	y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (tab[y][x] == 'C')
				comp++;
			x++;
		}
		y++;
	}
	return (comp);
}
