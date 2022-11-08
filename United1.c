#include<stdio.h>

int main(){	
	int k,n;
	FILE *f1;
	printf(" TOHOP.INP:\n");
    f1 = fopen ("TOHOP.INP", "ab");
    scanf ("%d %d",&n,&k);
    fscanf(f1,"%d %d",&n,&k);
    fprintf (f1,"%d %d\n",n,k);
	int i,s=1,v=1,t=1,result;
	for( i=1;i<=n;i++) 
		s=s*i;
	for(i=1;i<=k;i++) 
		v=v*i;
	for( i=1;i<=n-k;i++)  
		t=t*i;
	result=s/(v*t);
	printf("TOHOP.OUT:\n");
	
	FILE *f2;
	f2 = fopen("TOHOP.OUT","ab");
	printf("%.0d\n",result);
    fprintf(f2,"%.0d\n",result);
}
