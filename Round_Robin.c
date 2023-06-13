#include <stdio.h>
#define max 25

int main() {
    int i, j, bt[max], rem_bt[max], qt, sq = 0, wt[max], tat[max], n, count = 0, temp;
    float avgwt = 0, avgtat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }

    printf("Enter quantum time: ");
    scanf("%d", &qt);

    while (1) {
        for (i = 0, count = 0; i < n; i++) {
            temp = qt;
            if (rem_bt[i] == 0) {
                count++;
                continue;
            }
            if (rem_bt[i] > qt) {
                rem_bt[i] = rem_bt[i] - qt;
            } else {
                temp = rem_bt[i];
                rem_bt[i] = 0;
            }
            sq = sq + temp;
            tat[i] = sq;
        }
        if (n == count) {
            break;
        }
    }

    printf("Process No \t Burst Time \t Waiting Time \t Turn Around Time\n");
    for (i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
        avgwt = avgwt + wt[i];
        avgtat = avgtat + tat[i];
        printf("%d \t\t %d \t\t %d \t\t %d \n", i + 1, bt[i], wt[i], tat[i]);
    }

    avgwt = avgwt / n;
    avgtat = avgtat / n;
    printf("Average Waiting Time: %.2f\n", avgwt);
    printf("Average Turn Around Time: %.2f\n", avgtat);

    return 0;
}
