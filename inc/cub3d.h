/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:04:32 by ccur              #+#    #+#             */
/*   Updated: 2024/05/02 20:59:27 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>

#  include "../lib/libmlx/Darwin/mlx.h"
#  define W_KEY 13
#  define S_KEY 1
#  define D_KEY 2
#  define A_KEY 0
#  define LEFT_KEY 123
#  define RIGHT_KEY 124
#  define ESC_KEY 53
#  define DEL_KEY 51
#  define BACK_KEY 51


# define HEIGHT 768
# define WIDTH 1280
# define TRUE 1
# define FALSE 0
# define VALUE_MOV 0.05

typedef struct s_cub
{
	int		ret;
	int		tmp0_0;
	int		tmp0_1;
	int		fd_path;
	char	*tmp1_0;
	char	*tmp1_1;
	char	*tmp1_2;
	char	*tmp1_3;
	char	**tmp2_0;
	char	**tmp2_1;
	char	**map;
	size_t	count_path[4];
	int		fd_path_texture[4];
	size_t	count_color[2];
	int		color[6];
	int		color_final[2];
	int		**texture_no;
	int		**texture_so;
	int		**texture_we;
	int		**texture_ea;
	int		bpp;
	int		llength;
	int		endian;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	old_dir_x;
	double	plane_x;
	double	plane_y;
	double	old_plane_x;
	double	camera_wall;
	double	camera_x;
	double	step_x;
	double	step_y;
	double	side_x;
	double	side_y;
	double	raydir_x;
	double	raydir_y;
	double	delta_x;
	double	delta_y;
	double	rotation;
	double	step;
	double	tex_pos;
	double	wall_x;
	int		map_x;
	int		map_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	int		tex_y;
	int		ver_walk;
	int		hor_walk;
	int		turn_dir;
}			t_cub;

/* --- build_texture_2.c --- */
void		get_pixel_color(t_cub *cub, const size_t i);
int			**convert_texture(t_cub *cub);
void		build_pixels(t_cub *cub, size_t i, size_t j[], char *tmp);
int			**converting_texture(t_cub *cub, int **tmp, size_t i);

/* --- build_texture.c --- */
void		build_texture(t_cub *cub);
void		get_pixel_texture(t_cub *cub, const size_t i);
void		tmp_verification(t_cub *cub, size_t i);
void		getting_p_texture(t_cub *cub, size_t j[], size_t i, char *tmp);

/* --- cub3d.c --- */
void		cub3d(t_cub *cub);
int			play(t_cub *cub);
int			key_pressed(int key, t_cub *cub);
int			key_unpressed(int key, t_cub *cub);

/* --- draw_wall.c --- */
void		draw_wall(t_cub *cub, size_t x);
void		cub_side_exist(t_cub *cub, size_t x);
void		draw_ver(int x, t_cub *cub, int **text);
void		ft_mlx_pixel_put(t_cub *cub, int x, int y, int pixel);

/* --- error.c --- */
void		error(const t_cub *cub);
void		error_00(const t_cub *cub, const int fd);
void		error_01(const t_cub *cub, const int fd);

/* --- free.c --- */
void		ft_close_fd(int *fd);
void		ft_free_single(void **ptr);
void		ft_free_double(char ***ptr);
void		ft_free_double_int(int ***ptr, size_t size);
int			quit(t_cub *cub);

/* --- ft_atoi_base.c --- */
int			ft_atoi_base(const char *str, int str_base);
int			ft_strchr_int(const char *s, int c);

/* --- get_next_line.c --- */
char		*get_next_line(int fd);

/* --- load_file.c --- */
void		load_file(t_cub *cub);
void		load_texture(t_cub *cub, const int i, const int index);
void		load_color(t_cub *cub, const int i, const int index);
void		load_color_aux_00(t_cub *cub, const int index);
void		load_map(t_cub *cub, int *i);

/* --- mlx.c --- */
void		init_mlx(t_cub *cub);
int			destruct_mlx(t_cub *cub);

/* --- movement.c --- */
void		movement(t_cub *cub);
void		movement_vertical(t_cub *cub);
void		movement_horizontal(t_cub *cub);
void		movement_player(t_cub *cub);

/* --- raycasting.c --- */
void		raycasting(t_cub *cub);
void		init_raycasting_var(t_cub *cub, size_t x);
void		step_and_side(t_cub *cub);
void		dda(t_cub *cub);
void		get_line_height(t_cub *cub);

/* --- read_file.c --- */
void		read_file(t_cub *cub);
void		read_file_aux_00(t_cub *cub);

/* --- struct.c --- */
void		init_struct(t_cub *cub);
void		init_struct_aux_00(t_cub *cub);
void		init_struct_aux_01(t_cub *cub);
int			destroy_struct(t_cub *cub);
void		destroy_struct_aux_00(t_cub *cub);

/* --- valid_map.c --- */
void		valid_map(t_cub *cub);
void		valid_map_is_last(t_cub *cub);
void		valid_map_characteres(t_cub *cub);
void		map_tmp(t_cub *cub);
void		valid_map_is_valid(t_cub *cub);

/* --- valid_path.c --- */
void		valid_path(const char *path, t_cub *cub);
void		valid_len_path(const char *path, t_cub *cub);
void		valid_file_extension(const char *path, t_cub *cub);
void		valid_file_path(const char *path, t_cub *cub);

/* --- main.c --- */
void		valid_and_build_structs(char *path, t_cub *cub);
void		build_color(t_cub *cub);
void		get_player_position(t_cub *cub);
void		set_player_position(t_cub *cub, const char c);

#endif
