PHONY_TARGETS := git run
.PHONY: $(PHONY_TARGETS)

all:
	# @printf '%s\n' $(PHONY_TARGETS) | fzf | xargs -r make
	@SRC=$$(find . -name '*.cpp' -type f -printf '%T@ %p\n' | sort -n | tail -1 | cut -d' ' -f2); \
	echo "building $$SRC..."; \
	g++ -std=c++17 -O2 "$$SRC" -o a.out; \
	echo "run that shit"; \
	./a.out

git:
	git add .
	git commit
	git push

# build & run latest cpp recursively
run:
	@SRC=$$(find . -name '*.cpp' -type f -printf '%T@ %p\n' | sort -n | tail -1 | cut -d' ' -f2); \
	echo "building $$SRC..."; \
	g++ -std=c++17 -O2 "$$SRC" -o a.out; \
	./a.out

