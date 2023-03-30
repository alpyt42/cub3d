# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 19:17:58 by ale-cont          #+#    #+#              #
#    Updated: 2023/03/30 14:41:37 by ale-cont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--variables-------------------------------------------------------------------#

NAME		=	cub3d
DEBUG		=	no
OS			=	$(shell uname)

#--includes & libraries--------------------------------------------------------#

INC_DIR		=	includes/
HEADERS		= 	includes/cub3d.h
LIB_DIR		=	libs
LIBFT_DIR	=	$(LIB_DIR)/libft

#--sources & objects-----------------------------------------------------------#

SRC_DIR		=	srcs/
OBJ_DIR		=	.objects

#--mlx-------------------------------------------------------------------------#

ifeq ($(OS), Darwin)
MLX_DIR 	=	$(LIB_DIR)/mlx_mac
else ifeq ($(OS), Linux)
MLX_DIR 	=	$(LIB_DIR)/mlx_linux
endif

#--flags-----------------------------------------------------------------------#

CFLAGS		=	-Wall -Wextra -Werror -I $(LIBFT_DIR) -I $(MLX_DIR) -I $(INC_DIR)
DFLAGS		=	-g3 -fsanitize=address
MLX_FLAGS 	= 	-L $(MLX_DIR)

#--mlx flags-------------------------------------------------------------------#

ifeq ($(OS), Darwin)
MLX_FLAGS 	+= -framework OpenGL -framework AppKit
else ifeq ($(OS), Linux)
MLX_FLAGS 	+= -l m -l Xext -l X11 -I $(MLX_DIR)
endif

#--Sources-----------------------------------------------------------------------#

MAIN = main
PARSING = parse

SOURCES =	$(addsuffix .c, $(addprefix srcs/main/, $(MAIN)))			\
			$(addsuffix .c, $(addprefix srcs/parsing/, $(PARSING)))		\


#--debug & define flags--------------------------------------------------------#

ifeq ($(DEBUG), yes)
CFLAGS 		+=	$(DFLAGS)
endif

ifeq ($(OS), Darwin)
CFLAGS 		+=	-DMACOS
endif

#--libs------------------------------------------------------------------------#

LIBFT	=	$(LIBFT_DIR)/libft.a
MLX		=	$(MLX_DIR)/libmlx.a

#--objects---------------------------------------------------------------------#

OBJECTS	=	$(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

#--global rules----------------------------------------------------------------#

.DEFAULT_GOAL = all

#--compilation rules-----------------------------------------------------------#

all:
	$(MAKE) libs 
	$(MAKE) $(NAME)

$(NAME): $(OBJECTS)
	@echo "\n\033[0;32mCompiling cub3d...\033[0m"
	$(CC) $^ $(CFLAGS) $(MLX) $(LIBFT) -o $@ $(MLX_FLAGS)
	@echo "\n\033[0;32mcub3d is up to date !\033[0m"

$(OBJ_DIR)/%.o: %.c $(HEADERS) $(LIBFT) $(MLX)
	@ mkdir -p $(dir $@)
	$(CC) $(MLX) $(CFLAGS) -c $< -o $@

#--libs, debugs & bonus--------------------------------------------------------#

libs:
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)

debug:
	$(MAKE) re DEBUG=yes

#--re, clean & fclean----------------------------------------------------------#

re:
	$(MAKE) fclean
	$(MAKE) all

clean:
	@echo "\033[0;31mCleaning libft..."
	$(MAKE) -C $(LIBFT_DIR) clean
	@echo "\033[0;31mCleaning mlx..."
	$(MAKE) -C $(MLX_DIR) clean
	@echo "\nRemoving binaries..."
	@$(RM) -rf $(OBJECTS)
	@echo "\033[0m"

fclean:
	@echo "\nDeleting objects..."
	@$(MAKE) clean
	@echo "\033[0;31mCleaning libft..."
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "\nDeleting executable..."
	@$(RM) $(NAME)
	@echo "\033[0m"

#--PHONY-----------------------------------------------------------------------#

.PHONY: all libs debug re clean fclean
 