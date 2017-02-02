all: Our_algo

Our_algo:	Our_algo_main.o Our_algo_fun.o
	gcc Our_algo_main.c Our_algo_fun.c -o Our_algo

Our_algo_main.o:	Our_algo_main.c
	gcc -c Our_algo_main.c

Our_Modified_algo_fun.o:	Our_algo_fun.c
	gcc -c Our_algo_fun.c

clean:	
	rm -rf *o Our_algo 
