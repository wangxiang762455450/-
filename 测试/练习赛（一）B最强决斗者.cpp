#include <stdio.h>

struct str
{
	int s;
	int t;
	int x;
 }q[1010],k;
int main()
{
	int n,i,j;
	while (scanf("%d",&n)!=EOF)
	{
		int l1=1,l2,l=0;
		for (i=1;i<=n;i++)
		{
			scanf("%d%d",&q[i].s,&q[i].t);
			if (q[i].t<3) scanf("%d",&q[i].x);
			if (q[i].s<q[i-1].s)
			{
				l2=i-1;
				for (j=l2;j>=l1;j--)
				{
					if (q[j].t==1) l+=q[j].x;
					else if (q[j].t==2) l+=q[j].x*(j+1-l1);
					else if (q[j].t==3) break;
					else if (q[j].t==4) j--;
				}
				l1=i;
			}
		 }
		 for (j=n;j>=l1;j--)
			{
				if (q[j].t==1) l+=q[j].x;
				else if (q[j].t==2) l+=q[j].x*(j+1-l1);
				else if (q[j].t==3) break;
				else if (q[j].t==4) j--;
			}
		printf("%d\n",l);
	}
	return 0;
}
