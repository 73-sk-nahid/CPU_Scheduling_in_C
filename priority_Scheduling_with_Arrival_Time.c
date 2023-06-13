#include <stdio.h>
#include <conio.h>
#define max 25
int main()
{
    int n, i, j, k = 1, bt[max], wt[max], tat[max], pr[max], at[max], t, b, min, temp[max];
    float avgwt = 0, avgtat = 0;

    printf("Enter the number of process: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        /* code */
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    for (i = 0; i < n; i++)
    {
        /* code */
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &at[i]);
    }
    for (i = 0; i < n; i++)
    {
        /* code */
        printf("Enter the priority  of process %d: ", i + 1);
        scanf("%d", &pr[i]);
    }

    for (i = 0; i < n; i++)
    {
        /* code */
        for (j = 0; j < n; j++)
        {
            /* code */
            if (at[i] < at[j])
            {
                /* code */
                t = at[j]; // sorting arrival time
                at[j] = at[i];
                at[i] = t;

                t = bt[j]; // sorting burst time
                bt[j] = bt[i];
                bt[i] = t;
            }
        }
    }
    for (j = 0; j < n; j++)
    {
        /* code */
        b = b + bt[j];
        min = bt[k];
        for (i = k; i < n; i++)
        {
            /* code */
            min = pr[k];
            if (b >= at[i])
            {
                /* code */
                if (pr[i] < min)
                {
                    /* code */
                    t = at[k];
                    at[k] = at[i];
                    at[i] = t;

                    t = bt[k];
                    bt[k] = bt[i];
                    bt[i] = t;

                    t = pr[k];
                    pr[k] = pr[i];
                    pr[i] = t;
                }
            }
        }

        k++;
    }
    temp[0] = 0;
    printf("Process \t Burst Time \t Arrival Time \t Priority \t Waiting Time \t Turn Around Time \n");
    for (i = 0; i < n; i++)
    {
        /* code */
        wt[i] = 0;
        tat[i] = 0;
        temp[i + 1] = temp[i] + bt[i];
        wt[i] = temp[i] - at[i];
        tat[i] = wt[i] + bt[i];
        avgwt = avgwt + wt[i];
        avgtat = avgtat + tat[i];
        printf("%d \t\t %d \t\t %d \t\t %d \t\t %d \t\t %d \n", i + 1, bt[i], at[i], pr[i], wt[i], tat[i]);
    }
    avgwt = avgwt / n;
    avgtat = avgtat / n;

    printf("Average Waiting Time: %.2f", avgwt);
    printf("Average Turn Around Time: %.2f", avgtat);

    return 0;
}