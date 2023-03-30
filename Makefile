# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 19:17:58 by ale-cont          #+#    #+#              #
#    Updated: 2023/03/30 11:16:45 by ale-cont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--variables-------------------------------------------------------------------#

NAME		=	cub3d
DEBUG		=	no

#--includes & libraries--------------------------------------------------------#

INC_DIR		=	includes/
HEADERS		= 	includes/cub3d.h
LIBFT_DIR	=	libft/

#--sources & objects-----------------------------------------------------------#

SRC_DIR		=	srcs/
OBJ_DIR		=	.objects

#--flags-----------------------------------------------------------------------#

CFLAGS		=	-Wall -Wextra -Werror -I $(LIBFT_DIR) -I $(INC_DIR)
DFLAGS		=	-g3 #-fsanitize=address
PRFLAGS 	= 	

#--Sources-----------------------------------------------------------------------#

SOURCES =	$(addsuffix .c, $(addprefix srcs/main/, $(MAIN)))			\

#--debug & define flags--------------------------------------------------------#

ifeq ($(DEBUG), yes)
CFLAGS 		+=	$(DFLAGS)
endif

#--libs------------------------------------------------------------------------#

LIBFT	=	$(LIBFT_DIR)/libft.a

#--objects---------------------------------------------------------------------#

OBJECTS	=	$(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

#--global rules----------------------------------------------------------------#

.DEFAULT_GOAL = all

#--compilation rules-----------------------------------------------------------#

all:
	$(MAKE) lib 
	$(MAKE) $(NAME)

$(NAME): $(OBJECTS)
	@echo "\n\033[0;32mCompiling cub3d...\033[0m"
	$(CC) $^ $(CFLAGS) $(PRFLAGS) $(LIBFT) -lreadline -o $@
	@echo "\n\033[0;32mcub3d is up to date !\033[0m"

$(OBJ_DIR)/%.o: %.c $(HEADERS) $(LIBFT)
	@ mkdir -p $(dir $@)
	$(CC) $(PRFLAGS) $(CFLAGS) -c $< -o $@

#--libs, debugs & bonus--------------------------------------------------------#

lib:
	$(MAKE) -C $(LIBFT_DIR)

debug:
	$(MAKE) re DEBUG=yes

#--re, clean & fclean----------------------------------------------------------#

re:
	$(MAKE) fclean
	$(MAKE) all

clean:
	@echo "\033[0;31mCleaning libft..."
	$(MAKE) -C $(LIBFT_DIR) clean
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
 