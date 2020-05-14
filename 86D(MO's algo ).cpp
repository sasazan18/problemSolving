#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define endl '\n'
#define mxn 2000000

ll n,q,bs;
ll input[mxn];
ll ans[mxn];
ll cnt[mxn];

struct query
{
    ll L,R,indx;
}arr[mxn];

bool cmp(const query &a, const query &b)
{
    ll tmp = a.L / bs;
    if(tmp != b.L / bs)
        return a.L < b.L;

    if(tmp & 1)
        return a.R < b.R;

    return a.R > b.R;
}

ll sum=0;
void add(ll i)
{
    sum-= cnt[input[i]]*cnt[input[i]]*input[i];
    cnt[input[i]]++;
    sum+=cnt[input[i]]*cnt[input[i]]*input[i];
}

void del(ll i)
{
    sum-= cnt[input[i]]*cnt[input[i]]*input[i];
    cnt[input[i]]--;
    sum+=cnt[input[i]]*cnt[input[i]]*input[i];
}


int main()
{

    scanf("%lld %lld",&n,&q);

     bs=sqrt(n);


    for(ll i=0;i<n;i++){

        scanf("%lld",&input[i]);
    }

    for(ll i=0;i<q;i++)
    {

        scanf("%lld %lld",&arr[i].L,&arr[i].R);
        --arr[i].L;
        --arr[i].R;
        arr[i].indx=i;
    }

    sort(arr,arr+q,cmp);

    ll left=0,right=-1;
    sum=0;
    for(ll i=0;i<q;i++)
    {
        ll l=arr[i].L;
        ll r=arr[i].R;
        ll in=arr[i].indx;

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

        ans[in]=sum;

    }

  for(ll i=0;i<q;i++)  printf("%lld\n",ans[i]);




    return 0;
}
