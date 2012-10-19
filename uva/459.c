#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	long i,j,k,t,tmp,tmpx,num,cnt,sum,n[30],clr,a,b,p,q;
	char read[100];
	scanf("%ld",&num);
	for(p=0;p<num;p++)
	{
		scanf("%s",&read);

		cnt=read[0]-65+1;
		for(i=0;i<cnt;i++)
			n[i]=-1;
		clr=0;
		gets(read);
		while(gets(read)!=NULL)
		{
			k=strlen(read);
			if(k==0)
				break;
			else
			{
				a=read[0]-65;
				b=read[1]-65;
				if(n[a]!=n[b])
				{
					if(n[a]==-1&&n[b]!=-1)
						n[a]=n[b];
					else if(n[a]!=-1&&n[b]==-1)
						n[b]=n[a];
					else
					{
						q=n[a];
						t=n[b];
						for(i=0;i<cnt;i++)
							if(n[i]==q)
								n[i]=t;
					}
				}
				else
				{
					if(n[a]==-1&&n[b]==-1)
					{
						n[a]=clr;
						n[b]=clr;
						clr++;
					}
				}
			}
		}
		sum=0;
		for(i=0;i<cnt;i++)
		{
			if(n[i]==-1)
			{
				n[i]=-2;
				sum++;
			}
			else if(n[i]>-1)
			{
				k=n[i];
				for(j=0;j<cnt;j++)
					if(n[j]==k)
						n[j]=-2;
				sum++;
			}
		}
		printf("%ld\n",sum);
				if(p!= num-1)
			printf("\n");
	}
}
