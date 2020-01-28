#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
int main()
{
    char s[30],c;
    int state=0,i;

    printf("Enter the string\n");
    scanf("%s",s);
    if(strlen(s)==0){
        printf("Accpted under a*");
        return 0;
    }
    for(i=0;s[i]!='\0';i++){
        c=s[i];
        switch(state){
            case 0:
                if(c=='a')
                    state=1;
                else if(c=='b')
                    state=5;
                else
                    state = 6;
                break;
            case 1:
                if(c=='a')
                    state=2;
                else if(c=='b')
                    state=3;
                else
                    state = 6;
                break;
            case 2:
                if(c=='a');
                else if(c=='b')
                    state=5;
                else
                    state = 6;
                break;
            case 3:
                if(c=='b')
                    state=4;
                else
                    state = 6;
                break;
            case 4:
                if(c=='b')
                    state=5;
                else
                    state = 6;
                break;
            case 5:
                if(c=='b')
                    state=5;
                else
                    state = 6;
                break;
            case 6:
                break;
        }
    }

    if(state==4)
        printf("Accepted under abb\n");
    else if (state==1||state==2)
        printf("Accepted under a*\n");
    else if (state==3||state==5)
        printf("Accepted under a*b+\n");
    else if (state==6)
        printf("Not Accepted\n");
    return 0;
}
