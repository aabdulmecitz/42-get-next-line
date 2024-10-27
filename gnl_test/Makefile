SRC = get_next_line.c get_next_line_utils.c
SRCNEW = gnlnew/get_next_line.c gnlnew/get_next_line_utils.c
SRCGNL = gnl/get_next_line.c gnl/get_next_line_utils.c
MESSAGE = "Commit: "

run:
	@gcc gnl_test/main.c $(SRCGNL) -o gnl.out
	@clear
	./gnl.out

all: drun

drun:
	cd gnlnew && make -s


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
