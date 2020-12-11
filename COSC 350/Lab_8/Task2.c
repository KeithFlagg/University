//Keith Flagg 
//COSC 350

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void enterScore(int* scores) {
	int i, j, n, score;
	int acceptable = 1;

	puts("Please enter up to 20 test scores, enter -1 to quit");

	for(i = 0; i < 20 && acceptable; i++) {
		printf("Enter test score %d: ", i + 1);
		scanf("%d", &score);
		while(score < -1) {
			puts("Please enter a positive score!");
			scanf("%d", &score);
		}

		scores[i] = score;

		if(score == -1) {
			acceptable = 0;
		}
	}

	i--;

	// Sorts the array using selection sort
	for(j = 0; j < i - 1; j++) {
		int min = j;
		for(n = j + 1; n < i; n++) {
			if(scores[n] < scores[min]) {
				min = n;
			}
		}
		int temp = scores[j];
		scores[j] = scores[min];
		scores[min] = temp;
	}

	pthread_exit(NULL);
}

void calcAvg(int* scores) {
	int i;
	int total = 0;
	float avg, median;

	for(i = 0; scores[i] != -1; i++) {
		total += scores[i];
	}

	if(i == 0) {
		puts("No entrires :(, average: 0");
		pthread_exit(NULL);
	}

	avg = (float) total / i;

	if(i % 2 == 0) {
		int rhs = (i / 2) - 1;
		int lhs = i / 2;
		median = (float) (scores[rhs] + scores[lhs]) / 2;
	}
	else {
		median = scores[i / 2];
	}

	printf("Average: %2.2f, Median: %2.2f \n", avg, median);

	pthread_exit(NULL);
}

void calcMinMax(int* scores) {
	int i, max;
	// minimum found in thread 1
	int min = scores[0];

	for(i = 0; scores[i] != -1; i++) {
		max = scores[i];
	}

	if(i == 0) {
		puts("Low: 0 High: 0, no entries.");
		pthread_exit(NULL);
	}

	printf("Low: %d, High: %d \n", min, max);

	pthread_exit(NULL);
}

void clearBuffer(int* scores) {
	int i;

	puts("Clearing Buffer...");
	for(i = 0; i < 20; i++) {
		scores[i] = 0;
		printf("%d ", scores[i]);
	}
	puts("");

	pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
	pthread_t THREAD[4];
	int rc, i;

	int* scores = malloc(20 * sizeof(int));

	//sets all scores to -1
	for(i = 0; i < 20; i++) {
		scores[i] = -1;
	}

	rc = pthread_create(&THREAD[0], NULL, enterScore, (void *) scores);
	if(rc) {
		puts("Error ocurred when creating the pthread for reading your test scores.");
		exit(-1);
	}

	pthread_join(THREAD[0], NULL);

	rc = pthread_create(&THREAD[1], NULL, calcAvg, (void *) scores);
	if(rc) {
		puts("Error ocurred when creating the pthread for reading your test scores.");
		exit(-1);
	}

	rc = pthread_create(&THREAD[2], NULL, calcMinMax, (void *) scores);
	if(rc) {
		puts("Error ocurred when creating the pthread for reading your test scores.");
		exit(-1);
	}

	pthread_join(THREAD[1], NULL);
	pthread_join(THREAD[2], NULL);

	rc = pthread_create(&THREAD[3], NULL, clearBuffer, (void *) scores);
	if(rc) {
		puts("Error ocurred when creating the pthread for reading your test scores.");
		exit(-1);
	}

	pthread_join(THREAD[3], NULL);

	pthread_exit(NULL);

    return 0;
}
