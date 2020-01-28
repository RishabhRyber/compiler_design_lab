#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
int main()
{
    char s[30],c;
    int state=0,i;

    printf("Enter the identifier\n");
    gets(s);
    if(isalpha(s[0]) || s[0]=='_')
        state=1;
    else state=2;
    for(i=1;s[i]!='\0';i++){
        if(!(isalpha(s[i]) || s[i]=='_' || isdigit(s[i])))
            state=2;
    }
    if(state==1)
        printf("Valid Identifier\n");
    else
        printf("Invalid identifier\n");
    return 0;
}
