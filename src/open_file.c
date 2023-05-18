/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:08:56 by abiddane          #+#    #+#             */
/*   Updated: 2023/01/14 14:04:03 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Check if their is a new line in the map */
int	check_new_line(char *str, t_data *data)
{
	int	i;

	i = 0;
	data->map_tab = NULL;
	if (str[0] == '\n')
	{
		free(str);
		kill_error("Empty line before the map", data);
	}
	while (str[i])
	{
		if (str[i] == '\n' && str[i - 1] == '\n')
		{
			free(str);
			kill_error("Empty line in the map", data);
		}
		i++;
	}
	if (str[i - 1] == '\n')
	{
		free(str);
		kill_error("Empty line after the map", data);
	}	
	return (1);
}

/* Open the file and stock it into a table */
char	**open_file(char *file, t_data *data)
{
	char	**tab;
	char	*str;
	char	*buf;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		kill_error("Fail opening file", data);
	str = get_next_line(fd);
	while (1)
	{
		buf = get_next_line(fd);
		if (!buf)
			break ;
		str = ft_strjoin(str, buf);
		free(buf);
	}
	close(fd);
	check_new_line(str, data);
	tab = ft_split(str, '\n');
	free(str);
	return (tab);
}
