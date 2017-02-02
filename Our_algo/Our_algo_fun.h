#ifndef _MEMORY_H_
#define _MEMORY_H_

#define k 64			//key size
#define size 256		//state size
#define no_of_time 100	//How many number of colliding key pairs you need.

typedef unsigned char UC;

UC iSwap(UC *a, UC *b);
UC MaxcolStep( UC *Key5 );
void Print_key(UC *arr);
void Print_Statevector();
UC Round(UC q);
UC Search( UC Key1[] );
UC pass_second_round(UC Key1[]);
UC KSA(UC Key1[]);
void key_generation();
void Number_of_round();
void avg_time();

#endif
