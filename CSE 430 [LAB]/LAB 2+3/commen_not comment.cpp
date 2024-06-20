/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
using namespace std;
//gfghghghghghhhhhhhhhhjgggggggggggg
/* vhghjgjhjk
fghfghvhj
nbn mnm,m,m,, */

int main()
{
    char com[100];
    int i=2, a=0;
    //take input
    printf("enter the line of code \n");
    gets(com);
    if(com[0]=='/')
    {
        if(com[1]=='/')
        printf("cmment");
        else if(com[1]=='*')
        {
            for(i=2;i<=100;i++)
            {
                if(com[i]=='*' && com[i+1]=='/')
                {
                printf("comment");
                a=1;
                break;
                }

                else
                   continue;
            }
            if(a==0)
            printf("not comment");
        }
        else
        printf("not comment");
     }
     else
     printf("not comment");
return 0;
}
