monty:
	gcc -g -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o monty

clean:
	rm -f monty