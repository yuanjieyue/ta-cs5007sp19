all: play test

test: a4.h a4.c a4_test.c a4_helpers.c deck.c
	gcc a4.c deck.c a4_helpers.c a4_test.c -o test -g

play: a4.h a4.c a4_run.c deck.c a4_helpers.c
	gcc a4.c deck.c a4_helpers.c a4_run.c -o play -g

.PHONY: clean
clean:
	rm -f play
	rm -f test
