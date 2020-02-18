#include <stdio.h>
#include <stdlib.h>
void restore(int *,int *,int);
void bestFit(int*,int*,int,int);
void worstFit(int*,int*,int,int);
void firstFit(int*,int*,int,int);
int main()
{
    int blockC,processC,i,j,choice;
    printf("Enter Process and memory blocks count\n");
    scanf("%d%d",&processC,&blockC);
    int process[processC];
    int blocks[blockC],tempBlock[blockC];
    printf("Enter memory block count\n");
    for(i=0;i<blockC;i++)
        scanf("%d",&blocks[i]);
    printf("Enter process memory requirement\n");
    for(i=0;i<processC;i++)
        scanf("%d",&process[i]);

    while(1){
        printf("\n\n1.First fit\n2.Best Fit\n3.Worst Fit\n\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        restore(blocks,tempBlock,blockC);
        if(choice==1)
            firstFit(tempBlock,process,blockC,processC);
        if(choice==2)
            bestFit(tempBlock,process,blockC,processC);
        if(choice==3)
            worstFit(tempBlock,process,blockC,processC);

    }
    return 0;
}
void restore(int blocks[],int tempBlock[],int n){
    int i;
    for(i=0;i<n;i++)
        tempBlock[i]=blocks[i];
}

void firstFit(int tempBlock[],int process[],int blockC,int processC){
    int n,i,j,flag;
    for(i=0;i<processC;i++){
        flag=0;
        for(j=0;j<blockC;j++){
            if(process[i]<=tempBlock[j]){
                tempBlock[j]-=process[i];
                flag=1;
                printf("%d:\t%d\n",i+1,j+1);
                break;
            }
        }
        if(!flag){
            printf("\nCan't allocate further\n");
            return;
        }
    }
}

void worstFit(int tempBlock[],int process[],int blockC,int processC){
    int i,j,high,flag;
    for(i=0;i<processC;i++){
        flag=0;
        high=0;
        for(j=1;j<blockC;j++){
            if(tempBlock[j]>=process[i] && tempBlock[j]>tempBlock[high]){
                high=j;
                flag=1;
            }
        }
        if(flag || tempBlock[0]>=process[i]){
            tempBlock[high]-=process[i];
            printf("%d:\t%d\n",i+1,high+1);
        }
        else{
            printf("Can't allocate further\n");
            return;
        }
    }
}

void bestFit(int tempBlock[],int process[],int blockC,int processC){
    int i,j,high,flag;
    for(i=0;i<processC;i++){
        flag=0;
        high=-1;
        for(j=0;j<blockC;j++)
            if(tempBlock[j]>=process[i]){
                high=j;
                break;
            }
        if(high==-1){
            printf("Can't allocate further\n");
            return;
        }
        for(j=high;j<blockC;j++){
            if(tempBlock[j]>=process[i] && tempBlock[j]<tempBlock[high]){
                high=j;
                flag=1;
            }
        }
            tempBlock[high]-=process[i];
            printf("%d:\t%d\n",i+1,high+1);
    }
}
