all: runMatrix

buildMatrix: a5.h a5_matrix.c a5_helper.c
	gcc a5_matrix.c a5_helper.c -o matrix

runMatrix: buildMatrix
	./matrix

buildList: 

runList:

memcheck: buildMatrix
	valgrind --leak-check=full ./matrix

stylecheck: a5_matrix.c a5_helper.c
	clint.py a5_matrix.c 
	clint.py a5_helper.c

.PHONY: clean

clean: 
	rm -f matrix
	rm -f list

