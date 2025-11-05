#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Structure to represent a job
typedef struct Job {
    char id[10];
    int deadline;
    int profit;
} Job;

// Comparator function to sort jobs by descending profit
int compare(const void *a, const void *b) {
    return ((Job *)b)->profit - ((Job *)a)->profit;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

void jobSequencing(Job jobs[], int n) {
    // Sort jobs by profit
    qsort(jobs, n, sizeof(Job), compare);

    // Find max deadline to size the slot array
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;

    int slot[MAX] = {0};        // slot[i] = 1 if occupied
    char result[MAX][10];       // job id at each slot
    int totalProfit = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (from its deadline backwards)
        for (int j = min(maxDeadline, jobs[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = 1;
                strcpy(result[j], jobs[i].id);
                totalProfit += jobs[i].profit;
                count++;
                break;
            }
        }
    }

    printf("Scheduled Jobs: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i])
            printf("%s ", result[i]);
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}


int main() {
    int n;
    Job jobs[MAX];

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    printf("Enter JobID Deadline Profit:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    jobSequencing(jobs, n);
    return 0;
}
