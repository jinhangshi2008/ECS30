paint.out: main.o board.o cmd_check.o test.o
	gcc -g -Wall -Werror -o paint.out main.o board.o cmd_check.o test.o
	
board.o: board.c board.h
	gcc -g -Wall -Werror -c -o board.o board.c
	
main.o: main.c board.h cmd_check.h test.h
	gcc -g -Wall -Werror -c -o main.o main.c
	
cmd_check.o: cmd_check.c cmd_check.h board.h
	gcc -g -Wall -Werror -c -o cmd_check.o cmd_check.c
	
test.o: test.c test.h board.h
	gcc -g -Wall -Werror -c -o test.o test.c
	
clean:
	rm -f *.o *.out
