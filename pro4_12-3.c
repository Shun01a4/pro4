#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
int d[MAX];

void downheap(int j,int k){
	int i,v;
	v=d[j];
	while(j<=k/2){
		i=2*j;
		if(i<k && d[i]<d[i+1]){
			i++;
		}
	if(v>=d[i] || i>k){
		break;
	}
	d[j]=d[i];
	d[i]=v;
	j=i;
	}
}


void print_heap(int n){
	int i=2,x=1,j,k,y,l=1,m=1;
	int sp[10]={1,2,4,8,16,32,64,128,256,512};
	while(1){
		if(n<i && n>=i/2){
			break;
		}
		i*=2;
		x++;
	}	
	y=x;
	for(j=x;j>0;j--){
		for(k=1;k<=m;k++){
			for(i=0;i<sp[y-1]-1;i++){
				printf("  ");
			}
			printf("%2d",d[l]);
			for(i=0;i<sp[y-1]-1;i++){
				printf("  ");
			}
			printf("  ");
			l++;
			if(l>n)
				break;
		}
		m*=2;
		y--;
		printf("\n");
	}
	printf("==========\n");
}

void heap_sort(int n){
	int i,j,k,t;
	printf("---heap down---\n");
	for(j=n/2;j>=1;j--){
		print_heap(n);
		downheap(j,n);
	}
	k=n;
	printf("---sorting---\n");
	while(k>1){
		t=d[1];
		d[1]=d[k];
		d[k]=t;
		print_heap(n);
		downheap(1,--k);
	}
}

int main(){
	int n,i,seed;
	n=0;
	printf("seed : ");
	scanf("%d",&seed);
	printf("size : ");
	scanf("%d",&n);
	if(n>MAX){
		printf("size too large");
		exit(1);
	}
	srand(seed);
	for(i=1;i<=n;i++){
		d[i]=(rand()*rand()/1000)%100;
	}
	printf("input data : \n");
	for(i=1;i<=n;i++){
		printf("d[%3d] : data=%5d\n",i,d[i]);
	}
	heap_sort(n);
	printf("output data : \n");
	for(i=1;i<=n;i++){
		printf("d[%3d] : data=%5d\n",i,d[i]);
	}
	return 0;
}
