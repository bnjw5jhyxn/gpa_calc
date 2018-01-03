gpa: gpa.c
	gcc -Wall -g -o gpa gpa.c

.PHONY: clean
clean:
	rm -vf gpa
