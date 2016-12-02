#include<stdio.h>

int main()
{
    FILE *in;
    int i=0, j=0;
    char x;
    in=fopen("input.txt","r+");
    if (in==NULL) printf("\nFNF\n");
    else
    {
        while (feof(in)==0)
        {
            x=fgetc(in);
            if(x=='(')
                i++;
            if(x==')')
                i--;
            j++;
            if(i==-1)
                break;
        }
        printf("Position of the character that causes Santa to first enter the basement is %d\n",j);
    }
    return 0;
}
