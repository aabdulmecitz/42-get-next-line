SRC = getmain.c get_next_line.c get_next_line_utils.c

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

NAME = gnl.out

OBJ = $(SRC:.c=.o)

BUFFER_SIZE = 42

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -o $(NAME) $(OBJ)
	$(RM) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

clean:
	$(RM) $(OBJ) $(NAME)

re: clean all
