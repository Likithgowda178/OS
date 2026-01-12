#include <stdio.h>

// Structure defining a User Directory
struct  {
    char dname[10];          // Name of the User Directory
    char sdname[10][10];     // Names of Subdirectories (up to 10)
    char fname[10][10][10];  // 3D Array: [Subdir Index][File Index][Char]
    int ds;                  // Number of subdirectories for this user
    int sds[10];             // Array storing number of files in each subdirectory
} dir[10]; // Array of 10 users

// Function to handle all input logic
void inputDirectories(int n) {
    int i, j, k;
    
    // Loop 1: Iterate through each User (n users)
    for (i = 0; i < n; i++) {
        printf("enter user directory %d names:", i + 1);
        scanf("%s", dir[i].dname);

        printf("enter size of directories:"); // How many subfolders this user has
        scanf("%d", &dir[i].ds);

        // Loop 2: Iterate through each Subdirectory for the current User
        for (j = 0; j < dir[i].ds; j++) {
            printf("enter subdirectory name and size:");
            scanf("%s", dir[i].sdname[j]);    // Read Subdir Name
            scanf("%d", &dir[i].sds[j]);      // Read Number of files in this Subdir

            // Loop 3: Iterate through files inside the current Subdirectory
            for (k = 0; k < dir[i].sds[j]; k++) {
                printf("enter file name:");
                scanf("%s", dir[i].fname[j][k]); // Store file name
            }
        }
    }
}

// Function to print the structure nicely
void displayDirectories(int n) {
    int i, j, k;
    printf("\ndirname\t\tsize\tsubdirname\tsize\tfiles");
    printf("\n******************************************************\n");

    // Loop 1: Go through Users
    for (i = 0; i < n; i++) {
        printf("%s\t\t%d", dir[i].dname, dir[i].ds); // Print User Name and Subdir Count

        // Loop 2: Go through Subdirectories
        for (j = 0; j < dir[i].ds; j++) {
            // Print Subdir Name and File Count
            printf("\t%s\t\t%d\t", dir[i].sdname[j], dir[i].sds[j]);

            // Loop 3: Print all files in this Subdirectory
            for (k = 0; k < dir[i].sds[j]; k++) {
                printf("%s\t", dir[i].fname[j][k]);
            }

            printf("\n\t\t"); // Formatting to align next subdirectory rows
        }
        printf("\n"); // Spacing between users
    }
}

int main() {
    int n;
    printf("enter number of users:");
    scanf("%d", &n);

    // Call modular functions
    inputDirectories(n);
    displayDirectories(n);

    return 0;
}