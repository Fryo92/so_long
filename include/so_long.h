/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:38:49 by abiddane          #+#    #+#             */
/*   Updated: 2023/01/14 14:41:59 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
typedef struct s_img
{
	void	*ptr;
	char	*addr;
}t_img;
typedef struct s_data
{
	t_img	wall;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_addr;
	char	**map_tab;
	int		width;
	int		height;
	int		move;	
	size_t	x;
	size_t	y;
}				t_data;

/* event .c */
void	event_handling(t_data *data);
int		key_escape(int key, t_data *data);

/* utils.c */
int		kill_clean(t_data *data);
void	kill_error(char *msg, t_data *data);
void	kill_error_image(char *msg, t_data *data);
void	free_tab(char **tab);

/* map_error.c */
int		arg_error(int ac, char *file, t_data *data);
int		rectangular_map(t_data *data);
int		walled_map(t_data *data);
int		char_map(t_data *data);

/* check_ecp.c */
int		check_ecp(t_data *data);

/* check_path.c */
int		check_path(t_data *data);

/* parsing_utils.c */
int		find_playerx(char **tab);
int		find_playery(char **tab);
int		collectible_count(char **tab);

/* parsing.c */
int		map_isvalid(int ac, char *file, t_data *data);

/* open_file.c */
char	**open_file(char *file, t_data *data);

/* display_map.c */
int		display_map(t_data *data);

/* player_move.c */
void	move_left(t_data *data);
void	move_right(t_data *data);
void	move_down(t_data *data);
void	move_up(t_data *data);

/* main.c */
void	*ft_new_window(t_data *data);

#endif