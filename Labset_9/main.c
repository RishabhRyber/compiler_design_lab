#include<stdio.h>
#include<ctype.h>
int findFirst(char prod[][10],char *first,char c,int n);
int first_count;

int main(){
  int n,i;
  printf("Enter the no of productions in grammer\n");
  scanf("%d",&n);
  char first[n];//array to store first of the given terminal
  char productions[n][10];//stores productions in form A=nD
  char c;
  //Taking input from the user
  printf("Enter the productions\n");
  for(i=0;i<n;i++)
    scanf("%s",productions[i]);
  printf("Enter the character whose first is to find\n");
  scanf("%c",&c);
  scanf("%c",&c);
  findFirst(productions,first,c,n);
  for(i=0;i<first_count;i++){
    printf("%c",first[i]);
  }
  printf("\n");
  return 0;
}
/*
  Finds first character of the production and:
    if it's a terminal it adds it to first and stops
    if it's a non terminal then it recursively finds the first of it
    if it's ephsilon($) then it adds it to first and returns -1, which is used by it's parent calling function to identify that ephsilon has been found. If recursive call returns -1 we decrese count of the first_count (cause $ was added uselessly,it's useful only when it's returning to main)
 */
int findFirst(char prod[][10], char first[],char c,int n){
  int i;
  for(i=0;i<n;i++){
    //check if the current production is of the required non terminal
    if(prod[i][0]==c){
        if(prod[i][2]=='$'){
          first[first_count++]=prod[i][2];
          return -1;
        }
        if(islower(prod[i][2]))
          first[first_count++]=prod[i][2];
      else if(isupper(prod[i][2])){
        int j=2;
        int k = findFirst(prod,first,prod[i][j++],n);
        while(k == -1 && prod[i][j]!='\0' ){
            first_count--;
            k = findFirst(prod,first,prod[i][j++],n);

        }
      }
      }
  }
  return 1;
}