#include "bits/stdc++.h"
using namespace std;

int a[100001];
int segtree[100001*3];

void build(int node,int low,int high)
{
	if(low == high)
	{
	 segtree[node] = a[low];
	 return;
	}
	int mid = (low+high)>>1;
	build(2*node,low,mid);
	build(2*node+1,mid+1,high);
	segtree[node]=min(segtree[2*node],segtree[2*node+1]);
}

void update(int node,int low,int high,int idx,long long val)
{
	if(low>high)
		return;
	if(low == high)
	{
		segtree[node] = val;
		return;
	}
	int mid = (low+high)>>1;
	 if(low<=idx&& idx<=mid)
	update(2*node,low,mid,idx,val);
    else
	update(2*node+1,mid+1,high,idx,val);

	segtree[node]=min(segtree[2*node],segtree[2*node+1]);
}

int query(int node,int low,int high,int l,int r)
{
	if(l<=low && r>=high)
	  {
	     return segtree[node];
	  }  	
	       int mid=(low+high)>>1;
	        if(r<=mid)
			return query(2*node,low,mid,l,r);
		   else if(l>mid)
			return query(2*node+1,mid+1,high,l,r);
 
      int p1=query(2*node,low,mid,l,r);
      int p2=query(2*node+1,mid+1,high,l,r);
      return min(p1,p2);
}


int main(int argc, char const *argv[])
{
	
	return 0;
}