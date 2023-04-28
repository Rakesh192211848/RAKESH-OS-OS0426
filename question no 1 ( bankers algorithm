#include <stdio.h>
#include <stdbool.h>

#define N 4   // number of processes
#define M 3   // number of resources

int available[M] = {9, 3, 6};

int allocation[N][M] = {
    {1, 0, 0},
    {6, 1, 2},
    {2, 1, 1},
    {0, 0, 2}
};

int claim[N][M] = {
    {3, 2, 2},
    {6, 1, 3},
    {3, 1, 4},
    {4, 2, 2}
};

bool finish[N] = {false};

int main() {
    int work[M];
    int i, j;

    // initialize work vector to available vector
    for (i = 0; i < M; i++) {
        work[i] = available[i];
    }

    int count = 0;
    while (count < N) {
        bool found = false;
        for (i = 0; i < N; i++) {
            if (!finish[i]) {
                bool can_allocate = true;
                for (j = 0; j < M; j++) {
                    if (claim[i][j] - allocation[i][j] > work[j]) {
                        can_allocate = false;
                        break;
                    }
                }
                if (can_allocate) {
                    found = true;
                    finish[i] = true;
                    count++;
                    for (j = 0; j < M; j++) {
                        work[j] += allocation[i][j];
                    }
                    printf("Process %d is safe.\n", i);
                }
            }
        }
        if (!found) {
            printf("The system is in an unsafe state.\n");
            return 1;
        }
    }
    printf("The system is in a safe state.\n");
    return 0;
}
