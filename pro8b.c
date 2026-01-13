#include <stdio.h>

// Structure defining a User Directory
struct  {
    char dname[10];         
    char sdname[10][10];     
    char fname[10][10][10];  
    int ds;                  
    int sds[10];             
} dir[10]; 

void inputDirectories(int n) {
    int i, j, k;
    
    
    for (i = 0; i < n; i++) {
        printf("enter user directory %d names:", i + 1);
        scanf("%s", dir[i].dname);

        printf("enter size of directories:"); 
        scanf("%d", &dir[i].ds);

        for (j = 0; j < dir[i].ds; j++) {
            printf("enter subdirectory name and size:");
            scanf("%s", dir[i].sdname[j]);    
            scanf("%d", &dir[i].sds[j]);    
    
            for (k = 0; k < dir[i].sds[j]; k++) {
                printf("enter file name:");
                scanf("%s", dir[i].fname[j][k]);
            }
        }
    }
}


void displayDirectories(int n) {
    int i, j, k;
    printf("\ndirname\t\tsize\tsubdirname\tsize\tfiles");
    printf("\n******************************************************\n");

   
    for (i = 0; i < n; i++) {
        printf("%s\t\t%d", dir[i].dname, dir[i].ds); 

       
        for (j = 0; j < dir[i].ds; j++) {
       
            printf("\t%s\t\t%d\t", dir[i].sdname[j], dir[i].sds[j]);
          
            for (k = 0; k < dir[i].sds[j]; k++) {
                printf("%s\t", dir[i].fname[j][k]);
            }

            printf("\n\t\t"); 
        }
        printf("\n"); 
    }
}

int main() {
    int n;
    printf("enter number of users:");
    scanf("%d", &n);

    
    inputDirectories(n);
    displayDirectories(n);

    return 0;
}
