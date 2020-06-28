tokenizer_test: main.o functions.o history.o
	cc -o tokenizer main.o functions.o history.o

clean:
	rm -f *.o *.*~ *~ tokenizer

main.o: tester.c tokenizer.h functions.c history.c
