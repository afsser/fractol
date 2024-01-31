NAME	= fractol
CFLAGS	:= -Wunreachable-code -Ofast -g3 # -Wextra -Wall -Werror
LIBMLX	:= ./.lib/MLX42
BIN		:= bin

FILES	= fractal_selection.c colors.c utils.c \
			main.c mandelbrot.c mouse_hook.c julia.c

M_PATH	= src

HEADERS	= -I ./include -I $(LIBMLX)/include
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	= $(addprefix  $(M_PATH)/, $(FILES))
OBJS	= $(patsubst %, $(BIN)/%, $(notdir $(SRCS:.c=.o)))

all: $(BIN) $(LIBS) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)


$(LIBS):
ifeq ($(wildcard $(LIBMLX)/build/ ), )
	@cd ./.lib/MLX42/ && cmake -B build
	@cd ./.lib/MLX42/ && cmake --build build -j4
endif

$(BIN):
	@mkdir -p $(BIN)
	@echo "bin foi criado\n"

$(BIN)/%.o: $(M_PATH)/%.c | $(BIN)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@printf "Compiling: $(notdir $<)\n"

clean:
	@rm -rf $(BIN)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re