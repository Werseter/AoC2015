#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(a,b) (((a)<(b))?(a):(b))

int min(int x,int y,int z)
    {return MIN(MIN(x,y),z);}
int perim(int x,int y)
    {return 2*(x+y);}
int shrtprm(int x, int y, int z)
    {return min(perim(x,y),perim(x,z),perim(y,z));}
int main()
{
    FILE *in;
    in=fopen("input.txt","r+");
    if (in==NULL) printf("\nFNF\n");
    else
    {
        int x[3],y=0,z,s=0;
        int i;
        char buf[4]={0,0,0,0};
        while (feof(in)==0)
        {
            i=fgetc(in);
            if(i!='\n')
            {
                if(i!='x')
                {
                    z=strlen(buf);
                    buf[z]=i;
                }
                else
                {
                    x[y]=atoi(buf);
                    y++;
                    for(z=0;z<4;z++) buf[z]=0;
                }
            }
            else
            {
                x[y]=atoi(buf);
                y=0;
                for(z=0;z<4;z++) buf[z]=0;
                s=s+shrtprm(x[0],x[1],x[2])+x[0]*x[1]*x[2];
            }
        }
        x[y]=atoi(buf);
        s=s+shrtprm(x[0],x[1],x[2])+x[0]*x[1]*x[2];
        printf("Total length of ribbon elves should order is %d feet\n",s);
    }
    return 0;
}
