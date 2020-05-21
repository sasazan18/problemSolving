#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define si(n) scanf("%d",&n);
#define PI acos(-1.0)
#define sl(n) scanf("%lld",&n);
#define sf(n) scanf("%lf",&n);
#define ss(n) scanf("%s",n);
#define for0(i,n) for(ll i=0;i<n;i++)
#define for1(i,n) for(ll i=1;i<=n;i++)
#define forc(i,j,n) for(ll i=j;i<n;i++)
#define pb push_back
#define sor(n) sort(n.begin(),n.end())
#define sorcmp(n) sort(n.begin(),n.end(),cmp)
#define rev(n) reverse(n.begin(),n.end())
#define pi(x)  printf("%d",x);
#define pl(x)  printf("%lld",x);
#define pf(x)  printf("%.10lf",x);
#define ps(x)  printf("%s",x);
#define en() printf("\n");
#define random_shuffle(r...)random_shuffle(r,[](int _){return rand()%_;})
#define SQR(a) (a)*(a)
#define sp(x) fixed<<setprecision(x)
#define mod 100000007
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define bug cout<<"Here"<<endl
void fastio(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
ll powmod(ll a, ll b){ll ans = 1;while(b){if(b&1) ans = ans*a%mod;a = a*a%mod;b >>= 1;}return ans;}


vector<int> failuretable(string str)
{
    int sz=str.size();
    vector<int>lca(sz);
    for(int i=0;i<str.size();i++) lca[i]=0;
    lca[0]=0;
    int indx=0;
    for(int i=1;i<str.size();)
    {
        if(str[i]==str[indx])
        {
            lca[i]=indx+1;
            i++;
            indx++;
        }
        else
        {
            if(indx!=0)
            {
                indx=lca[indx-1];

            }
            else
            {
                lca[i]=0;
                i++;
            }
        }
    }

    return lca;
}



vector<int> kmp(string str,string pat)
{
    vector<int>lca=failuretable(pat);
    vector<int>ans;


    int i=0,j=0;
    while(i<str.size())
    {

        if(str[i]==pat[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0)
            {
                j=lca[j-1];
            }
            else
            {
                i++;
            }
        }

        if(j==pat.size())
        {

            ans.pb(i-pat.size()+1);
            if(j!=0)
            {

                j=lca[j-1];
            }
            else
            {
                i++;
            }
        }


    }
    return  ans;
}




int main(){
  fastio();

 while(1)
 {
     int n;
     cin>>n;
     if(n==0) break;
     vector<string>v;
     cin.ignore();
     for(int i=0;i<n;i++)
     {
         string pat;
         getline(cin,pat);
         v.pb(pat);

     }
     //bug;
     string str;
     vector<pair <string,int> >save;

     getline(cin,str);
     map<string,int>mp;

     for(int i=0;i<n;i++)
     {
         vector<int>temp=kmp(str,v[i]);

         save.pb({v[i],temp.size()});
     }
     int mx=0;
     vector<string>ans;
     int oc=0;
     for(auto u:save)
     {
         mx=max(mx,u.second);
     }
      for(auto u:save)
     {
         if(u.second==mx)
         {
             ans.pb(u.first);
             oc=u.second;
         }
     }

     cout<<oc<<endl;

     for(auto u:ans) cout<<u<<endl;



 }




return 0;
}


