//Keith Flagg
//COSC 350

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *Sum(void *n){
	int i;
	int sum = (int) n;

	for(i = sum - 1; i > 0; i--){
		sum += i;
	}
	
	n = (void *) sum;

	return n;

}

void *Fact(void *n){
	int i;
	int fact = (int) n;
	
	for(i = fact - 1; i > 0; i--){
		fact *= i;
	}
	
	n = (void *) fact;
	
	return n;
}

int myatoi(char *str){
	int num = 0;
	int i = 0;

	while(str[i] != '\0'){
		num = (num * 10) + (str[i] - 48);
		i++;
	}

	return num;
}

int main(int argc, char* argv[]){

	pthread_t sumThread, prodThread;
	int r;

	if(argc != 2){
		puts("Please Type: ./Task1 [integer]");
		exit(1);
	}
	
	int n = myatoi(argv[1]);

	// Creates a thread to find the sum of all numbers from 1 - n
	r = pthread_create(&sumThread, NULL, Sum, (void*) n);

	if(r){
		puts("Pthread Error!");

		exit(-1);
	}

	// creates a thread to find the product of all numbers from 1 - n
	r = pthread_create(&prodThread, NULL, Fact, (void*) n);
		if(r){

		puts("Pthread Error!");

		exit(-1);
	}

	void* sum;
	void* prod;

	pthread_join(sumThread, &sum);
	pthread_join(prodThread, &prod);

	printf("∑n = %d \n", (int) sum);
	printf("n! = %d \n", (int) prod);

	pthread_exit(NULL);
    
    exit(0);
}
