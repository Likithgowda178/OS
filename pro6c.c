#include <stdio.h>

int main()
{
    int nb, nf;

    printf("\nMemory Management Scheme - First Fit\n");

    printf("Enter number of blocks: ");
    scanf("%d", &nb);

    printf("Enter number of files: ");
    scanf("%d", &nf);

    int blocks[nb], files[nf];
    int allocation[nf], fragment[nf];
    int blockUsed[nb];

    // Initialize block usage and allocation
    for (int i = 0; i < nb; i++)
        blockUsed[i] = 0;

    for (int i = 0; i < nf; i++)
        allocation[i] = -1;

    // Input block sizes
    printf("\nEnter block sizes:\n");
    for (int i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blocks[i]);
    }

    // Input file sizes
    printf("\nEnter file sizes:\n");
    for (int i = 0; i < nf; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &files[i]);
    }

    // --- FIRST FIT LOGIC WITHOUT 'allocated' ---
    for (int i = 0; i < nf; i++) {

        fragment[i] = 0;   // default if not allocated

        for (int j = 0; j < nb; j++) {

            if (blockUsed[j] == 0 && blocks[j] >= files[i]) {

                allocation[i] = j;
                fragment[i] = blocks[j] - files[i];
                blockUsed[j] = 1;
                break;  // stop, because first fit
            }
        }
    }

    // Output
    printf("\nFile_no\tFile_size\tBlock_no\tBlock_size\tFragment\n");

    for (int i = 0; i < nf; i++) {

        printf("%d\t\t%d\t\t", i + 1, files[i]);

        if (allocation[i] != -1) {
            int b = allocation[i];
            printf("%d\t\t%d\t\t%d\n", b + 1, blocks[b], fragment[i]);
        }
        else {
            printf("Not Allocated\n");
        }
    }

    return 0;
}
