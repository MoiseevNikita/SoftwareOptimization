#include <iostream>
#include <time.h>

using namespace std;

const size_t N = 512;
typedef int32_t type;

type A[N * N];
type B[N * N];
type C[N * N];

clock_t start, stop;
double secs;

int main(int argc, char* argv[]) {
	if (argc != 2 || (atoi(argv[1]) != 0 && atoi(argv[1]) != 1)) {
		printf("Usage: %s <option>\n", argv[0]);
		printf(" option:\n");
		printf(" 1 = performance problem is present\n");
		printf(" 0 = no performance problem (optimized code is called)\n");
		fflush(stdout);
		return 1;
	}
	int user_option = atoi(argv[1]);

    for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			A[i * N + j] = 0;
			B[i * N + j] = i;
			C[i * N + j] = j;
		}

    start = clock();
    if (user_option == 1) {
		int i, j, k;
		for (int z = 0; z < 100; z++)
			for (i = 0; i < N; i++)
				for (j = 0; j < N; j++)
					for (k = 0; k < N; k++)
						A[i * N + j] += B[i * N + k] * C[k * N + j];

	}
	else {
		int i, j, k;
		for (int z = 0; z < 100; z++)
			for (i = 0; i < N; i++)
				for (k = 0; k < N; k++)
					for (j = 0; j < N; j++)
						A[i * N + j] += B[i * N + k] * C[k * N + j];

	}
	stop = clock();

	secs = ((double)(stop - start)) / CLOCKS_PER_SEC;
	printf("Execution time = %2.3lf seconds\n", secs); fflush(stdout);

    return 0;
}
