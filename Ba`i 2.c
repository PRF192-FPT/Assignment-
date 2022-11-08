#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dovat{
	char name[50];
	int tl,gt;
	double tigia;
	int soluong;
};

int main(){
	int i,n,m,j;
	FILE *fptr;
	
	if((fptr=fopen("BAG.INP","r"))== NULL){
		printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
	}
	
	fscanf(fptr,"%d%d",&n,&m);
	struct dovat dv[n];
	
	for(i=0;i<n;i++){
		fscanf(fptr,"%d",&dv[i].tl);
		fscanf(fptr,"%d",&dv[i].gt);
		fscanf(fptr,"%s",&dv[i].name);
		dv[i].tigia = dv[i].gt*1.0/dv[i].tl;
		dv[i].soluong = 0;
	}
	fclose(fptr);
	struct dovat dv2[n];
	for(i = 0;i<n;i++){
		dv2[i] = dv[i];
	}
	
	for(i = 0;i<n-1;i++){
		for(j = i+1;j<n;j++){
			if(dv[i].tigia < dv[j].tigia){
				struct dovat temp = dv[i];
				dv[i] = dv[j];
				dv[j] = temp;
			}
		}
	}
	int maxans = 0;
	for(i = 0;i<n;i++){
		int cnt = m / dv[i].tl;
		m -= cnt*dv[i].tl;
		maxans +=cnt*dv[i].gt;
		dv[i].soluong = cnt;
		if(m == 0)break;
	}
	
	for(i = 0;i<n;i++){
		for(j = 0;j<n;j++){
			if(strcmp(dv2[i].name,dv[j].name) == 0){
				dv2[i].soluong = dv[j].soluong;
			}
		}
	}
	
	
	printf("%d\n",maxans);
	
	for(i = 0;i<n;i++){
		if(dv2[i].soluong != 0)
		printf("%s %d\n",dv2[i].name,dv2[i].soluong);
	}	
}
