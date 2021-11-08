NAME		=	cub3D

SRC			=	src
INC			=	include
OBJ			=	obj

LIB			=	lib
LIBFT		=	$(LIB)/libft
MLX_GL		=	$(LIB)/mlx_opengl
MLX_MAC		=	$(LIB)/mlx_mac
MLX_LINUX	=	$(LIB)/mlx_linux

CC			=	clang
CFLAGS		=	-Wall -Werror -Wextra -Wconversion -Wpedantic

RM			=	rm -rf
MK			=	mkdir -p
NM			=	norminette

MAKE_DIR	= $(MAKE) --no-print-directory -C

CFILES		=	main.c
HFILES		=
OFILES		=	$(CFILES:.c=.o)

SRCS		=	$(addprefix $(SRC)/, $(CFILES))
HEADERS		=	$(addprefix $(INC)/, $(HFILES))
OBJS		=	$(addprefix $(OBJ)/, $(OFILES))

VPATH		=	$(SRC)

$(OBJ)/%.o:	%.c
			$(CC) $(CFLAGS) -I$(INC) -I$(LIBFT) -c $< -o $@

all:		CFLAGS += -O2 -DNDEBUG
all:		$(NAME)

$(NAME):	$(OBJ) $(OBJS)
			@$(MAKE_DIR) $(LIBFT)
			@$(MAKE_DIR) $(MLX_GL)
			$(CC) $(OBJS) -L$(LIBFT) -lft -L$(MLX_GL) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJ):
			$(MK) $(OBJ)

debug:		CFLAGS += -Og
debug:		$(NAME)

linux:		CFLAGS += -Og
linux:		$(OBJ) $(OBJS)
			@$(MAKE_DIR) $(LIBFT)
			@$(MAKE_DIR) $(MLX_LINUX)
			$(CC) $(OBJS) -L$(LIBFT) -lft -L$(MLX_LINUX) -lmlx -lXext -lX11 -o $(NAME)

clean:
			@$(MAKE_DIR) $(LIBFT) clean
			@$(MAKE_DIR) $(MLX_GL) clean
			@$(MAKE_DIR) $(MLX_MAC) clean
			@$(MAKE_DIR) $(MLX_LINUX) clean
			@$(RM) $(OBJS)

fclean:		clean
			@$(MAKE_DIR) $(LIBFT) fclean
			@$(RM) $(NAME)

re:			fclean all

norme:
			$(MAKE_DIR) $(LIBFT) norme
			$(NM) $(SRCS) $(HEADERS)

.PHONY:		all debug clean fclean re norme linux
