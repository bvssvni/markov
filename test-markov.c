
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "markov.h"

void test_markov_1(void)
{
	int cols = 4;
	int states = 2;
	int rows = 2;
	
	int data[] = {
		0,0,0,0,
		1,1,1,1
	};
	
	double prob[states << 1];
	memset(prob, 0, (states << 1) * sizeof(double));
	
	int freq[states];
	memset(freq, 0, states * sizeof(int));
	
	markov_chain(cols, rows, data, states, freq, prob);
	
	assert(freq[0] == 4);
	assert(freq[1] == 0);
	
	assert(prob[0 + states * 0] == 0);
	assert(prob[1 + states * 0] == 0);
	assert(prob[0 + states * 1] == 1);
	assert(prob[1 + states * 1] == 0);
}

void test_markov_2(void)
{
	int cols = 4;
	int states = 2;
	int rows = 2;
	
	int data[] = {
		0,0,1,1,
		1,1,0,0
	};
	
	double prob[states << 1];
	memset(prob, 0, (states << 1) * sizeof(double));
	
	int freq[states];
	memset(freq, 0, states * sizeof(int));
	
	markov_chain(cols, rows, data, states, freq, prob);
	
	assert(freq[0] == 2);
	assert(freq[1] == 2);
	
	assert(prob[0 + states * 0] == 0);
	assert(prob[1 + states * 0] == 1);
	assert(prob[0 + states * 1] == 1);
	assert(prob[1 + states * 1] == 0);
}


void test_markov_3(void)
{
	int cols = 4;
	int states = 2;
	int rows = 2;
	
	int data[] = {
		0,1,1,0,
		1,1,0,0
	};
	
	double prob[states << 1];
	memset(prob, 0, (states << 1) * sizeof(double));
	
	int freq[states];
	memset(freq, 0, states * sizeof(int));
	
	markov_chain(cols, rows, data, states, freq, prob);
	
	assert(freq[0] == 2);
	assert(freq[1] == 2);
	
	assert(prob[0 + states * 0] == 0.5);
	assert(prob[1 + states * 0] == 0.5);
	assert(prob[0 + states * 1] == 0.5);
	assert(prob[1 + states * 1] == 0.5);
}

int main(int argc, char *argv[])
{
	test_markov_1();
	test_markov_2();
	test_markov_3();
	
	return 0;
}
