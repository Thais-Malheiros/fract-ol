#!----------------------------------------------------------------------------#
#                                NAME                                         #
#!----------------------------------------------------------------------------#

NAME	= fractol
NAME_BONUS = fractol_bonus
.DEFAULT_GOAL := all
.PHONY: all, clean, fclean, re
.SILENT:

#!----------------------------------------------------------------------------#
#                              COLORS                                         #
#!----------------------------------------------------------------------------#

GREEN = \033[32m
YELLOW = \033[33m
PURPLE = \033[35m
RED = \033[31m
WHITE = \033[37m
RESET = \033[0m

#!----------------------------------------------------------------------------#
#                                PATH                                         #
#!----------------------------------------------------------------------------#

SRCS_PATH = ./src/
SRCS_BONUS_PATH = ./src/bonus/
INCS_PATH = ./include/ ./lib/MLX42/include/
BUIL_DIR = ./obj/
LIBMLX = ./lib/MLX42/
MLX42_BUILD_DIR = ./lib/MLX42/build

#!----------------------------------------------------------------------------#
#                                FILES                                        #
#!----------------------------------------------------------------------------#

SRCS = $(addprefix $(SRCS_PATH), \
				main.c \
				fractal_parsing.c \
				string_handling.c \
				fractal_init.c \
				fractal_hooks.c \
				fractal_building.c \
				math_utils.c \
				fractal_colors.c)

SRCS_BONUS = $(addprefix $(SRCS_BONUS_PATH), \
				main_bonus.c \
				fractal_parsing_bonus.c \
				string_handling_bonus.c \
				fractal_init_bonus.c \
				fractal_hooks_bonus.c \
				fractal_building_bonus.c \
				math_utils_bonus.c \
				fractal_colors_bonus.c)

MLX42 = $(addprefix $(MLX42_BUILD_DIR), libmlx42.a)
LIB = ./lib/MLX42/build/libmlx42.a
OBJS = $(SRCS:%.c=$(BUIL_DIR)%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=$(BUIL_DIR)%.o)

#!----------------------------------------------------------------------------#
#                               DEFINE                                        #
#!----------------------------------------------------------------------------#

ifdef WITH_BONUS
		NAME := $(NAME_BONUS)
		OBJS := $(OBJS_BONUS)
endif

#!----------------------------------------------------------------------------#
#                             COMMANDS                                        #
#!----------------------------------------------------------------------------#

MKDIR :=mkdir -p
RM := rm -rf
CC := cc

#!----------------------------------------------------------------------------#
#                          FLAGS & COMPILATION                                #
#!----------------------------------------------------------------------------#

CFLAGS = -Wextra -Wall -Werror
LDLIB = -ldl -lglfw -pthread -lm
COMP_OBJ = $(CC) $(CFLAGS) -c $< -o $@
COMP_EXE = $(CC) $(OBJS) $(LIB) $(LDLIB) -o $(NAME)

#!----------------------------------------------------------------------------#
#                             FUNCTIONS                                       #
#!----------------------------------------------------------------------------#

define create_dir
		$(MKDIR) $(dir $@)
endef

define bonus
		$(MAKE) WITH_BONUS=TRUE
endef

define comp_objs
		$(COMP_OBJ)
endef

define comp_libmlx
		@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
endef

define comp_exe
		$(COMP_EXE)
		printf "$(GREEN) FRACTOL ->$(RESET)$(PURPLE) READY\n$(RESET)"
endef

#!----------------------------------------------------------------------------#
#                              TARGETS                                        #
#!----------------------------------------------------------------------------#

all: $(MLX42) $(NAME)

$(BUIL_DIR)%.o: %.c
		$(call create_dir)
		$(call comp_objs)

$(NAME): $(OBJS)
		printf "$(YELLOW)Compiling fractol $(RESET)\n"
		$(call comp_exe)

$(MLX42):
		$(call comp_libmlx)

clean:
		$(RM) $(BUIL_DIR)

fclean: clean
		$(RM) $(NAME)
		$(RM) $(NAME_BONUS)
		$(RM) $(MLX42_BUILD_DIR)/libmlx42.a

re: fclean all

bonus:
		printf "$(PURPLE)Compiling bonus$(RESET)\n"
		$(call bonus)


