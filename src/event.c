/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:23:28 by abiddane          #+#    #+#             */
/*   Updated: 2023/01/14 12:13:34 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* All key press event */
int	key_press(int key, t_data *data)
{
	key_escape(key, data);
	if (key == XK_a)
		move_left(data);
	if (key == XK_d)
		move_right(data);
	if (key == XK_s)
		move_down(data);
	if (key == XK_w)
		move_up(data);
	return (1);
}

int	key_escape(int key, t_data *data)
{
	if (key == XK_Escape)
		kill_clean(data);
	return (1);
}

void	event_handling(t_data *data)
{
	mlx_hook(data->win_ptr, 2, 1L << 0, &key_press, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, &kill_clean, data);
}
