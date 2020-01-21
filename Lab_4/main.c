#include <stdio.h>
#include <stdlib.h>

int n,m,i,j,next;
int allocation[50][50];
int need[50][50];
int max[50][50];
int available[50];
int order[50];
int safeSequence[50];


void showAll(){
    int i,j;

    printf("Allocatin \t Max \t\t Need \t Order\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            printf("%d ",allocation[i][j]);
        printf("\t\t");
        for(j=0;j<m;j++)
            printf("%d ",max[i][j]);
        printf("\t\t");
        for(j=0;j<m;j++)
            printf("%d ",need[i][j]);
        printf("\t\t");

            printf("%d ",order[i]);
        printf("\n");



    }

    printf("Safe sequence is:\t");
    for(j=0;j<n;j++)
        printf("%d\t",safeSequence[j]);


}


int nextOne(){
    int i,j,flag=1;
    for(i=0;i<n;i++){
        if(order[i]==0){
            printf("lol %d\n",i);
            flag=1;
            for(j=0;j<m;j++){
                if(need[i][j]>available[j]){
                    printf("%d\t%d\n",need[i][j],available[j]);
                    flag=0;
                    break;
                }
            }
            if(flag==1){

                printf("ewturning %d\n",i);
                return i;
            }
        }
    }
    return -1;
}

int main()
{


    printf("Enter the no of processes\n");
    scanf("%d",&n);
    printf("Enter the no of resources\n");
    scanf("%d",&m);
    printf("Enter the allocation matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&allocation[i][j]);
    printf("Enter the max need matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            scanf("%d",&max[i][j]);
            need[i][j]=max[i][j]-allocation[i][j];
            order[i]=0;
        }

    printf("Enter the available resources count\n");
    for(i=0;i<m;i++)
        scanf("%d",&available[i]);


    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            need[i][j]=max[i][j]-allocation[i][j];

    printf("Need matrix is\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }

    for(i=0 ; i<n; i++){
        next = nextOne();
        safeSequence[i]=next+1;
        if(next==-1){
            printf("breaking at i = %d\n",i);
            break;
        }
        order[next] = i+1;
        for(j=0;j<m;j++)
            available[j]+=need[next][j];
    }

    showAll();


    return 0;
}
