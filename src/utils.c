/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:51:43 by abiddane          #+#    #+#             */
/*   Updated: 2023/01/14 14:08:56 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Send error msg and exit */
void	kill_error(char *msg, t_data *data)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(msg, 2);
	if (data->map_tab)
		free_tab(data->map_tab);
	free(data);
	exit(EXIT_FAILURE);
}

void	kill_error_image(char *msg, t_data *data)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(msg, 2);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	if (data->map_tab)
		free_tab(data->map_tab);
	free(data);
	exit(EXIT_FAILURE);
}

/* Close window and exit without error */
int	kill_clean(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	if (data->map_tab)
		free_tab(data->map_tab);
	free(data);
	exit (1);
	return (0);
}

/* Free a table */
void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
