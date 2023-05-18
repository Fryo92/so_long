/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:50:57 by abiddane          #+#    #+#             */
/*   Updated: 2023/01/14 14:08:40 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_isvalid(int ac, char *file, t_data *data)
{
	if (open(file, O_DIRECTORY) != -1)
	{
		ft_printf("Error\nTrying to open directory");
		free(data);
		exit(EXIT_FAILURE);
		return (0);
	}
	if (!arg_error(ac, file, data))
		return (0);
	data->map_tab = open_file(file, data);
	if (!rectangular_map(data))
		return (0);
	if (!char_map(data))
		return (0);
	if (!walled_map(data))
		return (0);
	if (!check_ecp(data))
		return (0);
	if (!check_path(data))
		return (0);
	return (1);
}
