###############################################################################
#                                 VARIABLES                                   #
###############################################################################

NAME		= cub3D
CC			= cc
CFLAGS		= -g #-Wall -Wextra -Werror -g #-fsanitize=address
SRC			= ./src/
GET			= ./get_next_line/
PAR			= ./src/parser/
CUB			= ./src/cube/
FILES 		= $(GET)get_next_line.c $(GET)get_next_line_utils.c\
			  $(SRC)cub3d.c $(PAR)tools.c $(PAR)check_elements_a.c\
			  $(PAR)check_elements_b.c  $(PAR)check_elements_c.c\
			  $(PAR)check_elements_d.c $(PAR)get_scene.c $(PAR)debugs.c\
			  $(PAR)check_rgb.c $(PAR)check_map_a.c $(PAR)check_map_b.c\
			  $(PAR)parser.c $(CUB)window.c $(CUB)minimap.c $(CUB)mlx_utils.c\
			  $(CUB)ft_max_mod.c $(CUB)init_data.c $(CUB)raycasting.c\
			  $(CUB)ft_bresenham.c $(CUB)moves.c $(CUB)ray_utils.c\
			  $(CUB)render.c
OBJS		= $(FILES:.c=.o)
MLX_L		= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm
LIBFT		= ./libft/libft.a
RM			= rm -f
# INCLUDES	= -I/usr/include -Imlx

# .c.o:
#	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

.c.o:
	$(CC) -c $(CFLAGS) $< -o $@

################################################################################
#                                 COLORS                                       #
################################################################################

CLR_RESET	= \033[0m
RED		    = \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
CYAN 		= \033[1;36m
PURPLE 		= \033[0;35m

###############################################################################
#                                 SCRIPT                                      #
###############################################################################

all: $(NAME)

$(NAME): $(OBJS)
#		@make -C mlx_linux
#		@make -C libft
#		clear
		@echo "$(GREEN)Compiling of $(RED)$(NAME)...$(CLR_RESET)"
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_L) -o $(NAME)
		@echo "$(RED)$(NAME) $(GREEN)is ready!$(CLR_RESET)\n"
		@echo "$(PURPLE)====================================$(CLR_RESET)"

clean:
		$(RM) $(OBJS)
#		@make clean -C mlx_linux
#		@make clean -C libft
		clear
		@echo "$(RED)$(NAME) object $(GREEN)files have been deleted.$(CLR_RESET)\n"

fclean: clean
		$(RM) $(NAME)
#		$(RM) $(LIBFT)
		clear
		@echo "$(RED)$(NAME) $(GREEN)has been deleted.$(CLR_RESET)\n"
		@echo "$(RED)libft $(GREEN)has been deleted.$(CLR_RESET)\n"

re: fclean all
	@echo "$(RED)$(NAME) $(GREEN)has been recompiled.$(CLR_RESET)\n"
	@echo "$(PURPLE)====================================$(CLR_RESET)"

n1:
	@norminette -R CheckForbiddenSourceHeader ./src/ ./includes/

n2:
	@norminette -R CheckForbiddenSourceHeader ./get_next_line/ ./libft/

v:
	make re && clear && valgrind --leak-check=full --show-leak-kinds=all ./cub3D maps/map.cub

.PHONY: all clean fclean re
