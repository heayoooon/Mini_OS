CC = cc
CFLAGS = -Wall -Wextra -Wno-deprecated-declarations
LDFLAGS = -lpthread
NAME = mini_os
INCLUDES = ./includes
SRCS = ./srcs/
HEADER = bases.h commands.h mkdir_.h grep_.h chmod_.h cp_.h touch_.h find_.h
SRC = $(SRCS)mini_os.c $(SRCS)bases.c ${SRCS}mkdir_.c ${SRCS}grep_.c ${SRCS}chmod_.c ${SRCS}cp_.c ${SRCS}touch_.c ${SRCS}find_.c ${SRCS}cd_.c ${SRCS}cat_.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -I $(INCLUDES) -o $@ 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: make clean fclean re all
