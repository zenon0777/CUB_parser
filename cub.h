#ifndef CUB_H
# define CUB_H
#include<stdio.h>
# include <unistd.h>
# include <math.h>
#include<stdbool.h>
#include<stdlib.h>
# include <fcntl.h>
# include"libft/libft.h"


#define TILE 20

typedef struct s_color
{
	int red;
	int green;
	int blue;
}	t_color;

typedef struct s_map
{
	int         file;
	const char  *file_name;
	char        *N_texture;
	char        *S_texture;
	char        *W_texture;
	char        *E_texture;
	char        **map_input;
	size_t      map_width;
	int         map_length;
	int         first;
	int         end;
	int flagofdragon;
	bool F_status;
	int NO;
	int SO;
	int EA;
	int WE;
	int C;
	int F;
	int index;
	t_color    *F_color;
	t_color    *C_color;
}t_map;

typedef struct player
{
	double	p_x;
	double	p_y;
	double	rotation_angle;
	double	rotation_speed;
	double	walking_dir;
	double	angle_dir;
	double	move_speed;
}	t_player;

typedef struct data
{
	void *mlx;
	void *mlx_win;
	void *mlx_img;
	char *mlx_addr;
	int		img_width;
	int		img_height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	x;
	double	y;
	int		key;
	int		screen_width;
	int		screen_height;
	int		flag_dir;
	t_player player;
	t_map	*map;
}t_data;

bool	check_textures(t_map *map);
bool	check_map(t_map *map);
bool	check_extension(const char* file, int flag);
void	*ft_memmove(void *dst, const void *src, size_t n);
char	*get_next_line(int fd);
char	*ft_strjoin_freed(char const *s1, char const *s2);
size_t	ft_strlen(const char	*str);
void	rendering(t_map *map);
void	draw(t_map *map, t_data *data);
void	draw_line_dir(t_data *data, t_player *player);
#endif
