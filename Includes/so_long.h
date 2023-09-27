/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:34:27 by chonorat          #+#    #+#             */
/*   Updated: 2023/09/27 15:00:44 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <fcntl.h>

# define KEY_PRESS 2
# define ON_DESTROY 17

typedef struct s_ennemy_list {
	int						x_pos[2];
	int						last_pos[2];
	int						dir;
	int						move_switch;
	struct s_ennemy_list	*next;
}				t_ennemy_list;

typedef struct s_img {
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_so_long {
	char			**map;
	char			**map_mask;
	int				map_height;
	int				map_width;
	int				player;
	int				player_dir;
	int				player_spawn[2];
	int				player_pos[2];
	int				collectible;
	int				exit;
	int				exit_pos[2];
	int				ennemy_count;
	t_ennemy_list	*ennemy;
	int				move_count;
	int				heart;
	char			*move_string;
	void			*mlx;
	void			*win;
	t_img			base_img;
}				t_so_long;

void			init_data(t_so_long *data);
int				init_ennemy(t_so_long *data);

t_ennemy_list	*new_ennemy(void);
void			add_back(t_so_long *data, t_ennemy_list *lst);

int				get_map(t_so_long *data, char *argv[]);
int				get_mask(t_so_long *data);
int				check_map(t_so_long *data);
void			show_error(t_so_long data, char *error);
int				is_accessible(t_so_long *data);
void			accessible_path(t_so_long *data, int x, int y);

void			new_img(t_so_long *data);
t_img			new_file_img(char *path, t_so_long *data);
void			put_img_to_img(t_so_long *data, t_img src, int x, int y);

int				mlx_window(t_so_long *data);
int				get_img(t_so_long *d, t_img *img, char *path, int error);
void			print_assets(t_so_long *data);
int				print_move(t_so_long *data);
int				print_player(t_so_long *data);
int				print_hearts(t_so_long *data);
int				print_exit(t_so_long *data);
int				print_ennemy(t_so_long *data);
int				print_tree(t_so_long *data);

int				top_walls(t_so_long *data, int i);
int				down_walls(t_so_long *data, int i);
int				left_walls(t_so_long *data, int i);
int				right_walls(t_so_long *data, int i, int j);
int				is_water(t_so_long *data, int x, int y);
int				is_tree(t_so_long *data, int x, int y);

int				get_hook(int keycode, t_so_long *data);
void			move_player(int keycode, t_so_long *data);
void			ennemy_movement(t_so_long *data);
void			ennemy_position(t_so_long *data);

void			free_data(t_so_long *data);
void			exit_message(t_so_long *data);
int				exit_program(t_so_long *data, int exit_code);
int				exit_success(t_so_long *data);

#endif