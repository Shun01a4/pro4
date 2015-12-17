#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

typedef struct node{
	int data;
	struct node *next;
}LISTEL;

LISTEL *root;

int tmp[MAX];

void construct_list(){
	LISTEL *p;
	int n,y,i,k,noindex[50];
	char buf[100];

	while(1){
		fprintf(stdout,"input data : ");
		fgets(buf,sizeof(buf),stdin);
		if(buf[0]=='\n'){
			return;
		}
		i=0;
		k=0;
		if(buf[i]!=' '){
			noindex[k++]=i;
		}
		while(buf[i]!='\0'){
			i++;
			if(buf[i-1]==' ' && buf[i]!=' ' && buf[i]!='\n'){
				noindex[k++]=i;
			}
		}
		if(buf[i-1]!='\n'){
			fprintf(stderr,"Error over long");
			exit(1);
		}
		for(i=0;i<k;i++){
			n=sscanf(&buf[noindex[i]],"%d",&y);
			if(n!=1){
				fprintf(stderr,"Error no number");
				continue;
			}
			p=(LISTEL *)malloc(sizeof(LISTEL));
			p->data=y;
			p->next=root;
			root=p;
		}
	}
}

void print_list(){
	LISTEL *p;
	p=(LISTEL *)malloc(sizeof(LISTEL));
	p=root;
	if(p==NULL){
		fprintf(stderr, "no data");
		return;
	}
	while(p!=NULL){
		fprintf(stdout,"%4d",p->data);
		p=p->next;
	}
	fprintf(stdout,"\n");
}

LISTEL* merge_sort(LISTEL *Head){
	LISTEL *a,*b,*p,*q,*le,*ri,top,*ct;
	p=Head;
	b=Head;
	if(b->next==NULL){
		return b;
	}
	q=p->next->next;
	while(q!=NULL){
		p=p->next;
		if(q==NULL)
			break;
		q=q->next;
		if(q==NULL)
			break;
		q=q->next;
	}
	
	a=p->next;
	p->next=NULL;
	le=merge_sort(b);
	ri=merge_sort(a);
	
	ct=&top;
	while(le!=NULL && ri!=NULL){
		if(le->data<=ri->data){
			ct->next=le;
			ct=le;
			le=le->next;
		}
		else{
			ct->next=ri;
			ct=ri;
			ri=ri->next;
		}
	}
	if(le==NULL)
		ct->next=ri;
	else
		ct->next=le;
			
	return top.next;
}

int main(){
	root=NULL;
	construct_list();
	fprintf(stdout,"\ninput data : ");
	print_list();
	root=merge_sort(root);
	fprintf(stdout,"Output data : ");
	print_list();
	return 0;
}
