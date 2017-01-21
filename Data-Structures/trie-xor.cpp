#include "bits/stdc++.h"
using namespace std;

int level;
int p2[32];

struct node{
	node* zero;
	node* one;
	node(){};
};
node* root;

void run(){
	p2[0] = 1;
	for(int i=1;i<32;i++)
		p2[i] = p2[i-1]*2;
}

// insertion for binary numbers
void insert(node* root,int val){
	node* tmp = root;
	for(int i=level;i>=0;i--){
		if(val & (1<<i)){
			if(tmp->one == NULL) tmp->one = new node();
			tmp = tmp->one; 
		}else{
			if(tmp->zero == NULL) tmp->zero = new node();
			tmp = tmp->zero;
		}
	}
}

// gives maximum subarray Xor
int getVal(node* root,int val){
	int ret = 0; node* tmp = root;
	for(int i=level;i>=0;i--){
		if(val & (1<<i)){
			if(tmp->zero != NULL) {
				tmp = tmp->zero;
				ret+=p2[i];
			}else tmp = tmp->one;
		}
		else
		{
			if(tmp->one != NULL){
				tmp = tmp->one;
				ret+=p2[i];
			}else tmp = tmp->zero;
		}
	}
	return ret;
}
