# **************************************************************************** #
# 	Makefile based on clemedon's Makefile tutorial							   #
# **************************************************************************** #

NAME		:= a.out

# **************************************************************************** #
# 	SOURCES																	   #
# **************************************************************************** #

SRC_DIR		:= .
SRCS		:= main.c
SRCS		:= $(addprefix $(SRC_DIR)/,$(SRCS))

INCS		:=

LIB_DIR		?= $(dir $(abspath $(firstword $(MAKEFILE_LIST))))../../lib
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
LDFLAGS		:= $(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS		:= $(addprefix -l,$(LIBS))

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
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re