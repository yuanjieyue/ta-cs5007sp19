runbenchmark: runslow runfast	
	
runslow: slowsort
	./slowsort

slowsort: slowsort.c
	gcc slowsort.c -o slowsort

runfast: fastsort
	./fastsort 

fastsort: fastsort.c
	gcc fastsort.c -o fastsort

.PHONY: clean


clean: 
	rm -f slowsort fastsort
