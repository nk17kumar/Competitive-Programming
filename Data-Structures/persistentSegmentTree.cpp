#include "bits/stdc++.h"
using namespace std;

const int sz = 1e5 + 1;
int A[sz],B[sz],pos[sz];

struct node {
    int cnt;
    node *left,*right;
    node* update(int lo,int hi,int idx);
    int query(int lo,int hi,int l,int r);
    node(int c,node* l,node* r)
    : cnt(c),left(l),right(r) {}
};

node *tmp = new node(0,NULL,NULL);

node* root[sz];

node* node :: update(int lo,int hi,int idx) {
    if(lo > idx or hi < idx) 
        return this;
    if(lo==hi) 
        return new node(1,NULL,NULL);
    int m = (lo+hi) >> 1;
    node *q1 = this->left->update(lo,m,idx);
    node *q2 = this->right->update(m+1,hi,idx);
    return new node(q1->cnt + q2->cnt,q1,q2);
}

int node :: query(int lo,int hi,int l,int r) {
    if(l > hi or r < lo)
        return 0;
    if(l <= lo and hi <= r)
        return this->cnt;
    int mid = (lo+hi) >> 1;
    return this->left->query(lo,mid,l,r) + this->right->query(mid+1,hi,l,r);
}

int main(int argc, char const *argv[])
{
    ios_base :: sync_with_stdio(false);
    int n,q;
    cin >> n;
    tmp->left = tmp;
    tmp->right = tmp;
    root[0] = tmp;
    for(int i=0;i<n;i++) {
        cin >> A[i];
        pos[A[i]] = i+1;
    } 
    for(int i=0;i<n;i++) {
        cin >> B[i];
        root[i+1] = root[i]->update(0,n,pos[B[i]]);
    }
    int l1,r1,l2,r2;
    cin >> q;
    while(q--) {
        cin >> l1 >> r1 >> l2 >> r2;
        cout << (root[l2-1]->query(0,n,l1,r1)) << endl;
        cout << (root[r2]->query(0,n,l1,r1)) << endl;
        int ans = (r1-l1+1) + root[l2-1]->query(0,n,l1,r1) - root[r2]->query(0,n,l1,r1);
        cout << ans << endl; 
    } 
    return 0;
}