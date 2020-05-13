#include<bits/stdc++.h>
using namespace std;
#define mxn 1000005

int bs,n,q,distinct;
int input[mxn];
int cnt[mxn];
int ans[mxn];

struct node{

int L,R,indx;

bool operator < ( const node & second )
{
   return L/bs<second.L/bs || (L/bs==second.L/bs  && R<second.R );
}

}arr[mxn] ;


void add(int indx)
{
    cnt[input[indx]]++;
    if(cnt[input[indx]]==1) distinct++;

}

void del(int indx)
{
    cnt[input[indx]]--;
    if(cnt[input[indx]]==0) distinct--;
}


int main(){



  scanf("%d",&n);
  bs=sqrt(n);


  for(int i=0;i<n;i++)
  {
     scanf("%d",&input[i]);
  }


  scanf("%d",&q);
  for(int i=0;i<q;i++)
  {
      scanf("%d",&arr[i].L);
      scanf("%d",&arr[i].R);
      --arr[i].L;
      --arr[i].R;
      arr[i].indx=i;
  }

  sort(arr,arr+q);

  int left=0,right=-1;
  distinct=0;

  for(int i=0;i<q;i++)
  {
      int l,r,in;
      l=arr[i].L;
      r=arr[i].R;
      in=arr[i].indx;

      while(l>left)
      {
          del(left++);
      }
      while(l<left)
      {
          add(--left);
      }
      while(r>right)
      {
          add(++right);
      }
      while(r<right)
      {
          del(right--);
      }

      ans[in]=distinct;



  }


  for(int i=0;i<q;i++)
  {
       printf("%d\n",ans[i]);

  }





















return 0;
}
