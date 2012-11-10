
#include "markov.h"

void markov_chain
(int cols, int rows, const int data[], int states, int freq[], double prob[])
{
	int st = states; int n = cols;
	double p;
	int r, i, j, a, b, w;
	for (r = 0; r < rows-1; r++) {
		for (i = 0; i < n; i++) {
			a = data[i + r * cols]; b = data[i + (r+1) * cols];
			p = prob[a + st * b]; w = freq[a] + 1;
			
			// Increase floating average for that connection.
			prob[a + st * b] = p * freq[a] / w + 1.0 / w;
			
			// Decrease floating average for exclusive choices.
			for (j = st-1; j >= 0; j--) {
				if (j == b) continue;
				
				prob[a + st * j] *= (double)freq[a] / w;
			}
			
			freq[a]++;
		}
	}
}

