#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int datatype;
typedef struct shunxubiao{
	datatype* data;
	int size;
	int neicun;
}shunxubiao;
void swap(datatype*a,datatype*b){
	datatype tmp = *a;
	*a = *b;
	*b = tmp;
}
void init(shunxubiao*head){
	head->data=NULL;
	head->neicun=head->size=0;
}
void buy(shunxubiao*head){
	assert(head);
	int new = (head->neicun==0)?4:head->neicun*2;
	int*test =(int*)realloc(head->data,sizeof(datatype)*new);
	if(test==NULL){
		perror("realloc filed");
		exit(1);
	}
	head->data = test;
	head->neicun = new;
}
void weicha(shunxubiao*head,datatype a){
	assert(head);
	if(head->size==head->neicun){
		buy(head);
	}
	head->data[head->size]=a;
	head->size++;
}
void weishan(shunxubiao*head){
	assert(head);
	head->size--;
}
void toucha(shunxubiao*head,datatype x){
	assert(head);
	if(head->neicun==head->size){
		buy(head);
	}
	for(int i = head->size;i>0;i--){
		swap(&(head->data[i]),&(head->data[i-1]));
	}
	head->data[0] = x;
	head->size++;
}
void toushan(shunxubiao*head){
	assert(head);
	for(int i = 1;i<head->size;i++){
		swap(&(head->data[i]),&(head->data[i-1]));
	}
	head->size--;
}
int find(shunxubiao*head,datatype x){
	assert(head);
	int i = 0;
	for(i;i<head->size;i++){
		if(head->data[i]==x){
			return i;
		}
	}
	return -1;
}
void print(shunxubiao*head){
	int i =0;
	for(i;i<head->size;i++){
		printf("%d ",head->data[i]);
	}
}
void charuhou(int n,shunxubiao*head,datatype x){
	assert(head);
	if(head->size==head->neicun){
		buy(head);
	}
	for(int i =head->size;i>n+1;i--){
		swap(&(head->data[i]),&(head->data[i-1]));
	}
	head->data[n+1] = x;
	head->size++;
}        
void shanchuhou(int n,shunxubiao*head){
	assert(head);
	for(int i = n+1;i<head->size-1;i++){
		swap(&(head->data[i]),&(head->data[i+1]));
	}
	head->size--;
}                                                                                                                                                                                                                                                         
int main(){
	shunxubiao a;
	init(&a);
	toucha(&a,1);
	toucha(&a,2);
	toucha(&a,3);
	toucha(&a,4);
	weicha(&a,5);
	weicha(&a,6);
	int j = find(&a,5);
	shanchuhou(j,&a);
	print(&a);
	return 0;
}

