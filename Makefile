SRC = get_next_line.c get_next_line_utils.c
SRCNEW = gnlnew/get_next_line.c gnlnew/get_next_line_utils.c
MESSAGE = "Commit: "


all: drun

drun:
	cd gnlnew && make -s

run:
	@gcc $(SRC) -o gnl.out
	@clear
	./gnl.out

commit-and-push:
	git add .
	git commit -m "$(MESSAGE)"
	git push

commit:
	git add .
	git commit -m "$(MESSAGE)"

push:
	git push

.PHONY: all run drun commit commit-and-push push
