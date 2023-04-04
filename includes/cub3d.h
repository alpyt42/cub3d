/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:57:31 by ale-cont          #+#    #+#             */
/*   Updated: 2023/02/07 12:56:09 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*---------------------------------------*/

# include "../libs/libft/libft.h"
# include "../libs/mlx_linux/mlx.h"
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>

/*---------KEY----------------------*/

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126


/*----------------------------------*/

# define FALSE 0
# define TRUE 1

# define LEFT 0
# define RIGHT 1

# define C 0
# define F 1

# define N 0
# define S 1
# define E 2
# define W 3

# define NW 0
# define NE 1
# define SW 2
# define SE 3

/*------error-messages----------------------------*/

# define MLX_INIT_FAIL	"MLX init failed"
# define MLX_WIN_FAIL	"MLX couldn't create a window"
# define MLX_IMG_FAIL	"MLX couldn't create an image"
# define VALID_CHARS	"01 NSEW"
# define PLAYER_SPAWN	"NSEW"
# define FREE_SPACES	"NSEW0"
# define MALLOC_ERR		"Malloc Error"
# define NB_IDS			"The ids should include a key and a value (PARSING ERROR)"
# define TOO_MANY_IDS	"Duplicates ids (PARSING ERROR)"
# define TOO_LOW_IDS	"Not enough identifiers"
# define PARSING		"PARSING ERROR"
# define COL_ERROR		"Invalid color input"
# define MLX_IMG_ERR	"The path to the img is not working"
# define MAP_MISSING	"Map not found"
# define INVALID_MAP	"Map content cannot contain empty lines"
# define INVALID_CHARS	"Map content contains invalid characters"
# define SPAWN_COUNT_ER	"Map content has to contain (only) 1 player spawn"
# define MAP_SURR_ER	"The map has to be surrounded by walls (1)"
# define NB_ARG			"The number of arguments is wrong, provide only one map (*.cub)"
# define MAP_EXT		"The map must have the .cub extension"

/*-------COLORS---------------------------*/

# define DEFAULT "\001\033[0;39m\002"
# define GRAY "\001\033[1;90m\002"
# define RED "\001\033[1;91m\002"
# define GREEN "\001\033[1;92m\002"
# define YELLOW "\001\033[1;93m\002"
# define BLUE "\001\033[1;94m\002"
# define MAGENTA "\001\033[1;95m\002"
# define CYAN "\001\033[1;96m\002"
# define WHITE "\001\033[0;97m\002"

/*-------STRUCT---------------------------*/

typedef struct s_data		t_data;
typedef struct s_ray		t_ray;
typedef struct s_dico		t_dico;
typedef struct s_player		t_player;
typedef struct s_mlx		t_mlx;
typedef struct s_img		t_img;

struct s_img
{
	void	*ptr;
	int		bpp;
	int		width;
	int		height;
};

struct s_data
{
	int			ac;
	char		**av;
	char		**map;
	int			fd_map;
	t_list		*h_dico;
	t_img		*imgs;
	t_mlx		*mlx;
	t_player	*player;
	int			**col;
};

struct s_dico
{
	char	*key;
	char	*val;
};

struct s_ray
{
	float	x;
	float	y;
	float	raydirx;
	float	raydiry;	
	float	sidedistx;
	float	sidedisty;
	float	deltadistx;
	float	deltadisty;
	float	p_to_wall_dist;
	int		height;
	int		draw_start;
	int 	draw_end;
};

struct s_player
{
	float	x;
	float	y;
	float	dirx;
	float	diry;	
	int		mapx;
	int		mapy;
	float	planx;
	float	plany;
	char	orientation;
};

struct s_mlx
{
	void	*mlx;
	void	*win;
	int		*img;
	int		width;
	int		height;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		bpp;
};

/*--parsing---------------------------*/

void	*parse(t_data *d);
void	*get_keys(t_data *d);
void	*check_keys(t_data *d);
void	*get_map(t_data *d);
void	*check_map(t_data *d);
void	start_set(t_data *d, t_mlx *mlx);
char	*search_dico(char *search, t_data *d);
t_dico	*init_dico(void);
void	*add_dico(t_list **h_dico, char *key, char *val);
void	*check_keys(t_data *d);
void	start_player_orientation(t_data *d);
void	*set_color_img(t_data *d, int i);

/*--raycasting---------------------------*/

int floor_ceiling(t_data *d);


/*--utils---------------------------*/

void		*error(char *str);
long long	ft_get_time(void);
void		*ft_free_data(t_data *d);
void		free_dico(void *content);
void		display_dico(t_list *h_dico);
void		*check_arr_type(char **str);

#endif