NAME = so_long

NAME_B = so_long_bonus

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = so_long.c \
	   ./get_next_line/get_next_line.c \
	   ./get_next_line/get_next_line_utils.c \
	   ./files/ft_strchr.c \
	   ./files/ft_bzero.c \
	   ./files/ft_calloc.c \
	   ./files/ft_memset.c \
	   ./files/ft_strlen.c \
	   ./files/ft_substr.c \
	   ./files/ft_strdup.c \
	   ./files/ft_putnbr_fd.c \
	   ./files/ft_itoa.c \
	   ./files/ft_strncmp.c \
	   ./files/ft_split.c \
	   parssing.c \
	   parssing_2.c \
	   render_map.c \
	   moves.c \
	   moves_2.c \
	   error.c \
	   check_path.c

SRCS_BONUS = so_long_bonus.c \
	   ./get_next_line/get_next_line.c \
	   ./get_next_line/get_next_line_utils.c \
	   ./files/ft_strchr.c \
	   ./files/ft_bzero.c \
	   ./files/ft_calloc.c \
	   ./files/ft_memset.c \
	   ./files/ft_strlen.c \
	   ./files/ft_substr.c \
	   ./files/ft_strdup.c \
	   ./files/ft_putnbr_fd.c \
	   ./files/ft_itoa.c \
	   ./files/ft_strncmp.c \
	   ./files/ft_split.c \
	   parssing.c \
	   parssing_2.c \
	   render_map.c \
	   moves.c \
	   moves_2.c \
	   error.c \
	   check_path.c

OBJ = $(SRCS:.c=.o)

bonus_OBJ = ${SRCS_BONUS:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o:%.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(bonus_OBJ)
	$(CC) $(CFLAGS) $(bonus_OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)

clean:
	rm -rf $(OBJ) $(bonus_OBJ)

fclean: clean
	rm -rf $(NAME) $(NAME_B)

re: fclean all
