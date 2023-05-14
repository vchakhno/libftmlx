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
	$(addprefix math/,$(MATH_SRCS)) \
	$(addprefix input/,$(INPUT_SRCS)) \
	$(addprefix drawing/,$(DRAWING_SRCS)) \
	ft_image.c \
	ft_color_rgb.c \
	ft_color_hsv.c \
	ft_renderer.c \
	ft_window_handlers.c \
	ft_window.c
SRCS		:= $(addprefix $(SRC_DIR)/,$(SRCS))

INCS		:= include

LIB_DIR		?= $(dir $(abspath $(firstword $(MAKEFILE_LIST))))lib
LIB_TARGETS	:= \
				minilibx/libmlx.a \
				libft/libft.a
LIB_TARGETS	:= $(addprefix $(LIB_DIR)/,$(LIB_TARGETS))
LIB_INCS	:= \
				minilibx/ \
				libft/include/
INCS		+= $(addprefix $(LIB_DIR)/,$(LIB_INCS))

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
DIR_DUP		= @mkdir -p $(@D)

# **************************************************************************** #
# 	RECIPIES :D																   #
# **************************************************************************** #

all: $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(LIB_TARGETS) $(OBJS)
	$(AR) $(NAME) $(OBJS)

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
# 	DEPENDENCIES :3															   #
# **************************************************************************** #

$(LIB_DIR):
	@mkdir -p $(LIB_DIR)

$(LIB_DIR)/minilibx/: | $(LIB_DIR)
	git clone git@github.com:42Paris/minilibx-linux.git $(LIB_DIR)/minilibx

$(LIB_DIR)/libft/: | $(LIB_DIR)
	git clone git@github.com:vchakhno/libft.git $(LIB_DIR)/libft

$(LIB_DIR)/mlxft/: | $(LIB_DIR)
	git clone git@github.com:vchakhno/mlxft.git $(LIB_DIR)/mlxft

.SECONDEXPANSION:
$(LIB_TARGETS): $(LIB_DIR)/%.a: | $(LIB_DIR)/$$(dir %.a)
	make LIB_DIR=$(LIB_DIR) -C $(dir $@)
