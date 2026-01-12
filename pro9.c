#include <stdio.h>
#include <stdlib.h>

void main()
{
    int f[50], i, p, a, st, len, j, k, c;

    for (i = 0; i < 50; i++)
        f[i] = 0;

    printf("Enter how many blocks already allocated: ");
    scanf("%d", &p);

    printf("Enter the allocated block numbers: ");
    for (i = 0; i < p; i++)
    {
        scanf("%d", &a);
        f[a] = 1;
    }

start:
    printf("\nEnter starting block and length of the file: ");
    scanf("%d%d", &st, &len);

    k = len;

    if (f[st] == 0)
    {
        for (j = st; j < st + k; j++)
        {
            if (f[j] == 0)
            {
                f[j] = 1;
                printf("%d ---> allocated\n", j);
            }
            else
            {
                printf("%d is already allocated\n", j);
                k++;
            }
        }
    }
    else
    {
        printf("Starting block %d is already allocated!\n", st);
    }

    printf("\nDo you want to allocate another file? (1-Yes / 0-No): ");
    scanf("%d", &c);

    if (c == 1)
        goto start;
    else
        exit(0);
}
