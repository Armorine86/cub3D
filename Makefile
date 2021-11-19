NAME		=	cub3D

SRC			=	src
INC			=	include
OBJ			=	obj

LIB			=	lib
LIBFT		=	$(LIB)/libft
MLX_LINUX	=	$(LIB)/mlx_linux

CC			=	clang
CFLAGS		=	-Wall -Werror -Wextra -Wpedantic

RM			=	rm -rf
MK			=	mkdir -p
NM			=	norminette

MAKE_DIR	= $(MAKE) --no-print-directory -C

CFILES		=	main.c buffer.c utils.c draw_line.c game.c draw_rect.c player.c\
				draw_circle.c event.c draw_ray.c fixed_map.c draw_field.c draw_view.c\
				intersection.c map_parser.c parse_utils.c textures.c validate.c\
				
HFILES		=	buffer.h utils.h draw.h game.h player.h keymap.h event.h config.h\
				intersection.h texture.h

OFILES		=	$(CFILES:.c=.o)

SRCS		=	$(addprefix $(SRC)/, $(CFILES))
HEADERS		=	$(addprefix $(INC)/, $(HFILES))
OBJS		=	$(addprefix $(OBJ)/, $(OFILES))

VPATH		=	$(SRC)

$(OBJ)/%.o:	%.c
			$(CC) $(CFLAGS) -I$(INC) -I$(LIB) -c $< -o $@

all:		CFLAGS += -O2 -DNDEBUG
all:		$(NAME)

$(NAME):	$(OBJ) $(OBJS)
			@$(MAKE_DIR) $(LIBFT)
			$(CC) $(OBJS) -L$(LIBFT) -lft -lmlx -lm -framework OpenGL -framework AppKit -o $(NAME)

$(OBJ):
			@$(MK) $(OBJ)

debug:		CFLAGS += -O0 -g
debug:		$(NAME)

linux:		CFLAGS += -O0 -g
linux:		$(OBJ) $(OBJS)
			@$(MAKE_DIR) $(LIBFT)
			@$(MAKE_DIR) $(MLX_LINUX)
			$(CC) $(OBJS) -L$(LIBFT) -lft -L$(MLX_LINUX) -lmlx -lm -lXext -lX11 -o $(NAME)

clean:
#			@$(MAKE_DIR) $(LIBFT) clean
			@$(MAKE_DIR) $(MLX_LINUX) clean
			@$(RM) $(OBJS)

fclean:		clean
#			@$(MAKE_DIR) $(LIBFT) fclean
			@$(RM) $(NAME)

re:			fclean all

norme:
			$(MAKE_DIR) $(LIBFT) norme
			$(NM) $(SRCS) $(HEADERS)

.PHONY:		all debug clean fclean re norme linux cool_evaluator
