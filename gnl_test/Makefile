SRCGNL = ../gnl/get_next_line.c ../gnl/get_next_line_utils.c

run:
	gcc main.c $(SRCGNL) -g -o gnl.out -D BUFFER_SIZE=-1
	clear
	./gnl.out | cat -e

paco:
	cd ../gnl/ && francinette

--strict:
	francinette --strict
.PHONY: all run drun commit commit-and-push push