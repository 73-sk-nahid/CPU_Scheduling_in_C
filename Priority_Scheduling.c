#include <stdio.h>
#define max 25
int main()
{
    int i, j, n, bt[max], pr[max], wt[max], tat[max], temp, pos;
    float avgwt = 0, avgtat = 0;

    printf("Enter the process number: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        /* code */
        printf("Enter the burst time of %d no process: ", i + 1);
        scanf("%d", &bt[i]);
    }

    for (i = 0; i < n; i++)
    {
        /* code */
        printf("Enter the priority of %d no process: ", i + 1);
        scanf("%d", &pr[i]);
    }

    for (i = 0; i < n; i++)
    {
        /* code */
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (pr[j] < pr[pos])
            {
                /* code */
                pos = j;
            }
        }

        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
    }

    wt[0] = 0;
    printf("Process No \t Burst Time \t Priority \t Waiting Time \t Turn Around Time \n");
    for (i = 0; i < n; i++)
    {
        /* code */
        wt[i] = 0;
        tat[i] = 0;

        for (j = 0; j < i; j++)
        {
            wt[i] = wt[i] + bt[j];
        }
        tat[i] = wt[i] + bt[i];
        avgwt = avgwt + wt[i];
        avgtat = avgtat + tat[i];
        printf("%d \t\t %d \t\t %d \t\t %d \t\t %d \n", i + 1, bt[i], pr[i], wt[i], tat[i]);
    }

    avgwt = avgwt / n;
    avgtat = avgtat / n;

    printf("Average Waiting Time: %.2f", avgwt);
    printf("Average Turn Around Time: %.2f", avgtat);

    return 0;
}