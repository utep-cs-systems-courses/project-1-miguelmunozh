tokenizer_test: main.o functions.o
	cc -o tokenizer main.o functions.o

clean:
	rm -f *.o *.*~ *~ tokenizer

main.o: tester.c tokenizer.h functions.c
