#include<stdio.h>

int main()
{
    FILE *in;
    int i=0;
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
        }
        printf("Instructions take Santa to floor number %d\n",i);
    }
    return 0;
}
