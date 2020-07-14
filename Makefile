##
## EPITECH PROJECT, 2020
## poll
## File description:
## makefile
##

SRC	=	src/Main.cpp	\
		src/Poll.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	209poll

CFLAGS	=	-Wall -Wextra -Werror

all:		$(NAME) message

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(CFLAGS) -lm -I ./include

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f *~ $(NAME)

re:		fclean all

message:
		@echo "Successfully compiled!"
