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

# define N 1
# define E 2
# define S 3
# define W 4

/*------error-messages----------------------------*/

# define MLX_INIT_FAIL	"MLX init failed"
# define MLX_WIN_FAIL	"MLX couldn't create a window"
# define MLX_IMG_FAIL	"MLX couldn't create an image"
# define VALID_CHARS	"01 NSEW"
# define PLAYER_SPAWN	"NSEW"
# define FREE_SPACES	"NSEW0"
# define MALLOC_ERROR	"Malloc Error"
# define PARSING_ERROR	"Couldn't parse map identifiers"
# define RGB_ERROR		"Invalid RGB input"
# define IMG_ERROR		"Path to texture not valid or has the wrong extension"
# define MISSING_IDS	"Some map identifiers are missing"
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

struct s_data
{
	int		ac;
	char	**av;
	char	**map;
	int		fd_map;
	t_list	*dico;
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

};

struct s_player
{
	float	x;
	float	y;
	char	orientation;

};

/*--parsing---------------------------*/

void		*parse(t_data *d);
void	*get_keys(t_data *d);
void	*check_keys(t_data *d);
void	*get_map(t_data *d);
void	*check_map(t_data *d);

/*--raycasting---------------------------*/


/*--utils---------------------------*/

void		*error(char *str);
long long	ft_get_time(void);

#endif