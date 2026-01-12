#include<stdio.h>
#include<stdlib.h>

void fifo(char ref[],int frames[],int n,int f);
void lru(char ref[],int frames[],int n,int f);
void initial(int frames[],int f);

int main(){
    int n,f;
    int choice,again=1;
    int frames[50];
    char ref[20];
    
    printf("Enter the total number of frames:");
    scanf("%d",&f);
    
    printf("Enter the length of the reference string:");
    scanf("%d",&n);
    
    printf("Enter the reference string(No Space):");
    scanf("%s",ref);
    
    do{
        printf("=========memory managment menu=========");
        printf("1.FIFO\n2.LRU\n3.EXIT");
        printf("Enter your choice:");
        scanf("%d",&choice);
        
        initial(frames,f);
        
        switch(choice){
            case 1:fifo(ref,frames,n,f);
                break;
            case 2:lru(ref,frames,n,f);
                break;
            case 3:exit(0);
                break;
            default:printf("Invalid Input:");
        }
        printf("Do you want to continue (1=YES || 0=NO):");
        scanf("%d",&again);
    }while(again==1);
}

void initial(int frames[],int f){
    for(int i=0;i<f;i++){
        frames[i]=-1;
    }
}

void fifo(char ref[],int frames[],int n,int f){
    int front=0;
    int faultcnt=1;
    
    printf("Page\tFrames\tStatus\n");
    
    for(int i=0;i<n;i++){
        int page=ref[i];
        int found=0;
        for(int j=0;j<f;j++){
            if(frames[j]==page){
                found=1;
            }
        }
        
        printf("%c\t",page);
        
        if(!found){
            frames[front]=page;
            front=(front+1)%f;
            
            for(int j=0;j<f;j++){
                printf("%c ",(frames[j]==-1 ? '-':frames[j]));
            }
            printf("\t Fault %d",faultcnt);
            faultcnt++;
        }
        else{
            for(int j=0;j<f;j++){
                printf("%c ",(frames[j]==-1 ? '-':frames[j]));
            }
            printf("\tHIT\n");
        }
    }
}


void lru(char ref[],int frames[],int n,int f){
    int top=-1;
    int faultcnt=1;
    
    printf("Page\tFrames\tStatus\n");
    
    for(int i=0;i<n;i++){
        int page=ref[i];
        int found=0;
        int pos=0;
        for(int j=0;j<f;j++){
            if(frames[j]==page){
                found=1;
                pos=j;
            }
        }
        printf("%c\t",page);
        
        if(!found){
            if(top<f-1){
                frames[++top]=page;
            }
            else{
                for(int j=0;j<f-1;j++){
                    frames[j]=frames[j+1];
                    frames[f-1]=page;
                }
            }
            for(int j=0;j<f;j++){
                printf("%c ",(frames[j]==-1 ? '-':frames[j]));
            }
            printf("\tFault%d",faultcnt);
            faultcnt++;
        }
        else{
            for(int j=pos;j<top;j++){
                frames[j]=frames[j+1];
                frames[top]=page;
            }
            for(int j=0;j<f;j++){
                printf("%c ",(frames[j]==-1 ? '-':frames[j]));
            }
            printf("\tHIT");
        }
    }
}
