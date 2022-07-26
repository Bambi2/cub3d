/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <fdonetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:34:06 by fdonetta          #+#    #+#             */
/*   Updated: 2022/07/24 20:34:11 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <get_next_line.h>
# include <../mlx/mlx.h>
# include <math.h>

# define UP_KEY 126
# define DOWN_KEY 125
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define ESC 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2

typedef struct s_map_line
{
	int		len;
	char	*string;
}	t_map_line;

typedef struct s_map
{
	int			count_of_string;
	t_map_line	*lines;
}	t_map;

typedef struct s_texture
{
	void	*img;
	void	*addr;
	int		bpp;
	int		ll;
	int		endian;
	int		height;
	int		width;
}	t_texture;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*image;
	void	*addr;
	int		bpp;
	int		ll;
	int		end;
}	t_mlx;

typedef struct s_cub
{
	t_list		*tab_map;
	t_map		*map;
	int			x;
	int			y;
	float		hero_x;
	float		hero_y;
	int			win_w;
	int			win_h;
	char		**params;
	int			floor[3];
	int			celling[3];
	int			error;
	int			p_count;
	t_texture	*textures;
	t_mlx		mlx;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	char		dir;
}	t_cub;

typedef struct s_rcst
{
	int		i;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		map_x;
	int		map_y;
	double	perp_wall_distance;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
}	t_rcst;

void			cub_init(t_cub **cub);
int				is_valid_char(char c);

void			ft_exit(char *str, int fd);
int				close_window(void *p);
void			ft_freeall(t_cub *cub);
int				is_nl(char *str);
void			free_params(char **params);

void			get_params(t_cub *cub, t_list **lst, t_list *head);
void			get_map(char *map_name, t_cub *cub);
void			get_notab_map(t_cub *cub);
int				check_elems(t_map *map, int i, int j);
void			look_left(t_cub *cub);
void			look_right(t_cub *cub);
void			draw(t_cub *cub, t_mlx mlx);

void			cub3d(t_cub *cub);
int				fkey(int key, t_cub *cub);
void			drop_ray(t_cub *cub);
void			draw_texture(t_rcst rcst, t_cub *cub);
void			ft_put_pixel(t_mlx *mlx, int x, int y, int color);
unsigned int	get_color(t_texture *texture, int x, int y);
int				set_colors_util(char *str, t_cub *cub, int num, int i);
int				check_start(t_map *map, t_cub *cub);

char			*get_next_line(int fd);
#endif