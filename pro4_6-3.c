#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}TREEEL;

TREEEL *root;

void construct_tree(){
	TREEEL *p,*q;
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
		if(buf[i]!='\0'){
			noindex[k++]=i;
		}
		while(buf[i]!='\0'){
			i++;
			if(buf[i-1]==' ' && buf[i]!=' ' && buf[i]!='\n'){
				noindex[k++]=i;
			}
		}
		if(buf[i-1]!='\n'){
			fprintf(stderr,"Error no input data\n");
			exit(1);
		}
		for(i=0;i<k;i++){
			n=sscanf(&buf[noindex[i]],"%d",&y);
			if(n!=1){
				fprintf(stderr,"Error no number input\n");
				continue;
			}
			if(i==0){
				q=(TREEEL *)malloc(sizeof(TREEEL));
				q->data=y;
				q->left=NULL;
				q->right=NULL;
				root=q;
			}
			else{
				p=root;
				while(p!=NULL){
					if(y<p->data){
						if(p->left!=NULL){
							p=p->left;
						}
						else{
							q=(TREEEL *)malloc(sizeof(TREEEL));
							q->data=y;
							q->left=NULL;
							q->right=NULL;
							p->left=q;
							break;
						}
					}
					else if(y>p->data){
						if(p->right!=NULL){
							p=p->right;
						}
						else{
							q=(TREEEL *)malloc(sizeof(TREEEL));
							q->data=y;
							q->left=NULL;
							q->right=NULL;
							p->right=q;
							break;
						}
					}
				}
			}
		}
	}
}

void print_tree(int depth,TREEEL *p){
	int i;
	if(p==NULL)
		return;
	print_tree(depth+1,p->right);
	for(i=0;i<depth;i++){
		fprintf(stdout,"	");
	}
	fprintf(stdout,"%4d\n",p->data);
	print_tree(depth+1,p->left);
}

void insert_node(int y, TREEEL *p){
	TREEEL *q;
	if(root==NULL){
		fprintf(stderr,"Error no data");
		return;
	}
	q=(TREEEL *)malloc(sizeof(TREEEL));
	q->data=y;
	q->left=NULL;
	q->right=NULL;
	
	while(p!=NULL){
		if(y<p->data){
			if(p->left!=NULL){
				p=p->left;
			}
			else{
				p->left=q;
				break;
			}
		}
		else if(y>p->data){
			if(p->right!=NULL){
				p=p->right;
			}
			else{
				p->right=q;
				break;
			}
		}
	}
}

int delete_node(int y){
	TREEEL *n,*p_n,*l_b;
	int d;
	n=root;
	p_n=NULL;
	d=0;
	if(n==NULL){
		fprintf(stderr,"Error no data");
		return 0;
	}
	while(n!=NULL && n->data!=y){
		if(n->data>y){
			p_n=n;
			n=n->left;
			d=-1;
		}
		else{
			p_n=n;
			n=n->right;
			d=1;
		}
	}
	if(n==NULL){
		fprintf(stderr,"Error no data");
		return;
	}
	if(n->left==NULL && n->right==NULL){
		if(d==-1){
			p_n->left=NULL;
		}
		else if(d==1){
			p_n->right=NULL;
		}
	}
	else if(n->left==NULL){
		if(d==-1){
			p_n->left=n->right;
		}
		else if(d==1){
			p_n->right=n->right;
		}
	}		
	else if(n->right==NULL){
		if(d==-1){
			p_n->left=n->left;
		}
		else if(d==1){
			p_n->right=n->left;
		}
	}		
	else{
		l_b=n;
		n=n->left;
		if(n->right==NULL){
			l_b->data=n->data;
			l_b->left=NULL;
		}
			
		else{
			while(n->right!=NULL){
				p_n=n;
				n=n->right;
			}
			l_b->data=n->data;
			p_n->right=NULL;
		}
	}
	return 1;
}	
		


int main(){
	int y;
	root=NULL;
	construct_tree();
	print_tree(0,root);
	
	fprintf(stdout,"---insert---\n");
	fprintf(stdout,"input insert data : ");
	scanf("%d",&y);
	insert_node(y,root);
	print_tree(0,root);
	
	fprintf(stdout,"---delete---\n");
	fprintf(stdout,"input delete data : ");
	scanf("%d",&y);
	delete_node(y);
	print_tree(0,root);
	
	return 0;
}	
