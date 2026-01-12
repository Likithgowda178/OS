#include<stdio.h>
#include<stdlib.h>

int main(){
    int rq[100],i,j,n,headmovement=0;
    int initial,size,move;

    printf("Enter the number of requests:");
    scanf("%d",&n);

    printf("Enter the request sequence:");
    for(i=0;i<n;i++){
        scanf("%d",&rq[i]);
    }

    printf("Enter the initial head:");
    scanf("%d",&initial);

    printf("Enter the disk size:");
    scanf("%d",&size);

    printf("Enter the move if its hight 1 or low 0");
    scanf("%d",&move);

    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(rq[j]>rq[j+1]){
                int temp;
                temp=rq[j];
                rq[j]=rq[j+1];
                rq[j+1]=temp;
            }
        }
    }

    int index;
    for(i=0;i<n;i++){
        if(initial<rq[i]){
            index=i;
            break;
        }
    }

    if(move==1){
        for(i=index;i<n;i++){
            headmovement=headmovement+abs(rq[i]-initial);
             initial=rq[i];
        }
        headmovement=headmovement+abs(size-rq[i-1]-1);
        initial=size-1;

        for(i=index-1;i>=0;i--){
            headmovement=headmovement+abs(rq[i]-initial);
            initial=rq[i];
        }
    }
    else
    {
        for (i = index - 1; i >= 0; i--)
        {
            headmovement = headmovement + abs(rq[i] - initial);
            initial = rq[i];
        }

        headmovement = headmovement + abs(rq[i + 1] - 0);
        initial = 0;

        for (i = index; i < n; i++)
        {
            headmovement =  headmovement + abs(rq[i] - initial);
            initial = rq[i];
        }
    }

    printf("Total head movement is %d",  headmovement);
    return 0;
}