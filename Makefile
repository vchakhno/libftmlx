# **************************************************************************** #
# 	Makefile based on clemedon's Makefile tutorial							   #
# **************************************************************************** #

NAME		:= libmlxft.a

# **************************************************************************** #
# 	SOURCES																	   #
# **************************************************************************** #

include src/math/Makefile
include src/input/Makefile
include src/drawing/Makefile

SRC_DIR		:= src
SRCS		:= \
	$(addprefix /math/,$(MATH_SRCS)) \
	$(addprefix /input/,$(INPUT_SRCS)) \
	$(addprefix /drawing/,$(DRAWING_SRCS)) \
	ft_image.c \
	ft_color_rgb.c \
	ft_color_hsv.c \
	ft_mlx_context.c \
	ft_renderer.c \
	ft_window_handlers.c \
	ft_window.c
SRCS		:= $(addprefix $(SRC_DIR)/,$(SRCS))

INCS		:= include \
		lib/minilibx

BUILD_DIR	:= .build
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

# **************************************************************************** #
# 	COMPILATION																   #
# **************************************************************************** #

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
CPPFLAGS	:= $(addprefix -I,$(INCS)) -MMD -MP
AR			= ar -rcs

# **************************************************************************** #
# 	UTILITIES																   #
# **************************************************************************** #

RM			:= rm -rf
MAKEFLAGS   += --no-print-directory
DIR_DUP		= mkdir -p $(@D)

# **************************************************************************** #
# 	RECIPIES :D																   #
# **************************************************************************** #

all: $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re