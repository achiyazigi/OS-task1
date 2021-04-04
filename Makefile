#!make -f
.PHONY: all clean
CC =gcc

all: main1_1 main1_2 main1_3

main1_1: main1_1.c hello_ariel.c hello_ariel.h
	$(CC) $^ -o $@
main1_2: main1_2.c libhello_ariel.so
	$(CC) -L. main1_2.c -lhello_ariel -o $@
	export LD_LIBRARY_PATH=.
main1_3: main1_3.c libhello_ariel.so
	$(CC) $< -fPIC -ldl -o $@
hello_ariel.o: hello_ariel.c hello_ariel.h
	$(CC) -c -fPIC $<
libhello_ariel.so: hello_ariel.o
	$(CC) -shared -fPIC -o $@ $<
clean:
	rm main1_1 main1_2 main1_3 hello_ariel.o libhello_ariel.so
