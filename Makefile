MESSAGE = Commit:

cap: 
	git add .
	git commit -m "$(MESSAGE)" 
	git push

commit:
	git add .
	git commit -m "$(MESSAGE)"

push:
	git push

.PHONY: commit cap push
