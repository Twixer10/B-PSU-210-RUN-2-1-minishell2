##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make all my lib
##

SRC1	=	$(shell find .-type f -name'*.c')

SRC2	=	*.h*

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

$(NAME):	$(OBJ)
	gcc -c *.c
	ar rc $(NAME) *.o
	cp -r $(NAME) ../
	rm -f *.o

all: $(NAME)

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f *.o

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all

reset:
	rm -rf ../../include
	rm -rf ../$(NAME)
	rm -rf libmy.a
