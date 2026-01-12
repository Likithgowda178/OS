#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct {
    char dname[10];
    char fname[10][10];
    int fcnt;
} dir;

void createFile() {
    printf("\nEnter the name of the file -- ");
    scanf("%s", dir.fname[dir.fcnt]);
    dir.fcnt++;
}

void deleteFile() {
    char f[30];
    int i;
    printf("\nEnter the name of the file -- ");
    scanf("%s", f);

    for (i = 0; i < dir.fcnt; i++) {
        if (strcmp(f, dir.fname[i]) == 0) {
            printf("File %s is deleted ", f);
            strcpy(dir.fname[i], dir.fname[dir.fcnt - 1]);
            dir.fcnt--;
            return;
        }
    }
    printf("File %s not found", f);
}

void searchFile() {
    char f[30];
    int i;
    printf("\nEnter the name of the file -- ");
    scanf("%s", f);

    for (i = 0; i < dir.fcnt; i++) {
        if (strcmp(f, dir.fname[i]) == 0) {
            printf("File %s is found ", f);
            return;
        }
    }
    printf("File %s not found", f);
}

void displayFiles() {
    if (dir.fcnt == 0) {
        printf("\nDirectory Empty");
        return;
    }
    printf("\nThe Files are -- ");
    for (int i = 0; i < dir.fcnt; i++)
        printf("\t%s", dir.fname[i]);
}

int main() {
    int ch;
    dir.fcnt = 0;

    printf("\nEnter name of directory -- ");
    scanf("%s", dir.dname);

    while (1) {
        printf("\n\n1. Create File\t2. Delete File\t3. Search File");
        printf("\n4. Display Files\t5. Exit");
        printf("\nEnter your choice -- ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: createFile(); break;
            case 2: deleteFile(); break;
            case 3: searchFile(); break;
            case 4: displayFiles(); break;
            case 5: exit(0);
            default: printf("Invalid Choice");
        }
    }
    return 0;
}