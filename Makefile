NAME		=	cub3D

LIB_PATH	=	libft/

LIB			=	${LIB_PATH}libft.a

SRCS		=	${wildcard *.c}

SRCS_BONUS	=	${wildcard bonus/*.c}

MLX_PATH	=	minilibx_opengl_20191021/

MLX			=	${MLX_PATH}libmlx.a

MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit

HEADER		=	-I include/
OBJDIR		=	objects
OBJS		=	${SRCS:%.c=${OBJDIR}/%.o}
OBJS_BONUS	=	${SRCS_BONUS:%.c=%.o}

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra ${HEADER}

RM			=	rm -rf

ifdef WITH_BONUS
	OBJS_FILES	=	${OBJS_BONUS}
else
	OBJS_FILES	=	${OBJS}
endif

.PHONY		:	all subsystem clean fclean re bonus

all			:	subsystem_mlx subsystem ${NAME}

bonus		:
				@make WITH_BONUS=1 all

subsystem_mlx:	
				@ # make -C ${MLX_PATH} all
				@printf "\033[0;35m🍀 File '${MLX}' is done ! ✅\033[0m\n"

subsystem	:
				@ # make -C ${LIB_PATH} all
				@printf "\033[0;33m🍀 File '${LIB}' is done ! ✅\033[0m\n"

${NAME}		:	${OBJS_FILES}
				@${CC} ${CFLAGS} ${OBJS_FILES} ${LIB} ${MLXFLAGS} ${MLX} -o ${NAME}
				@printf "\033[0;32m💬 File '${NAME}' is created ! ✅\033[0m\n"

${OBJDIR}	:	
				@mkdir -p ${OBJDIR}

${OBJDIR}/%.o:	%.c | ${OBJDIR}
				@${CC} ${CFLAGS} ${HEADER} -c $< -o $@

clean		:
				@ # make -C ${MLX_PATH} clean
				@make -C ${LIB_PATH} clean
				@${RM} ${OBJS_BONUS} ${OBJDIR}
				@printf "\033[0;34m👻 Files '${MLX}' and '${OBJS_FILES}' are deleted ! 🗑️\033[0m\n"

fclean		:	clean
				@ # make -C ${LIB_PATH} fclean
				@${RM} ${NAME}
				@printf "\033[0;31m💬 Files '${LIB}' and '${NAME}' is deleted ! 🗑️\033[0m\n"

re			:	fclean all