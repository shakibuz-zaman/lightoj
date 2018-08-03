#include <bits/stdc++.h>
using namespace std;
 
#define pi 2*acos(0.0)
#define all(v) v.begin(),v.end()
#define coff ios_base::sync_with_stdio(0);
 
#define ff first
#define se second
#define pb push_back
#define sz(a) ((int)a.size())
#define ST(v) sort(all(v))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define cover(a,d) memset(a,d,sizeof(a))
#define popcount(i) __builtin_popcount(i)      //count one. in long long use __builtin_popcountll(i)
#define parity(i)   __builtin_parity(i)       //evenparity 0 and odd parity 1
#define btz(a)   __builtin_ctz(a)            //count binary trailling zero
#define un(v) ST(v), (v).erase(unique(all(v)),v.end())
#define common(a,b) ST(a), ST(b), a.erase(set_intersection(all(a),all(b),a.begin()),a.end())
#define uncommon(a,b) ST(a), ST(b), a.erase(set_symmetric_difference(all(a),all(b),a.begin()),a.end())
 
typedef  long long ll;
typedef  unsigned long long ull;
 
template <typename T>string toString( T Number ){stringstream st;st << Number;return st.str();}
int stringconvert(string s){int p; istringstream st(s); st>>p ; return p;}
 
//upper bound and lower bound
#define LB(a,value) (lower_bound(all(a),value)-a.begin())
#define UB(a,value) (upper_bound(all(a),value)-a.begin())
 
//Debug
#define dbg(x) cout<<#x<<'='<<x<<endl;
#define dbgarr(i,a) cout<<#a<<"["<<i<<"] = "<<a[i]<<" "<<endl;
#define nl puts("")
 
//File input/output
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
 
ll bigmod(ll a,ll b, ll m) { ll res = 1; while(b) { if(b & 1) { res = ( (res % m) * (a % m) ) %m ; } a= ((a%m) * (a%m)) %m; b >>= 1; } return res; }
ll modInverse(ll a, ll m){return bigmod(a,m-2,m);}
 
////============ CONSTANT ===============////
#define inf   1<<30                                           //infinity value
#define eps   1e-9
#define mx    100009
#define mod   1000000007
////=====================================////
 
struct info //for combine single update segment tree and range update segment tree
{
    int zero,one,two;
}tree[6*mx];
int lazy[6*mx];
 
void uptree(int i){
    int tmp=tree[i].zero;
    tree[i].zero=tree[i].two;tree[i].two=tree[i].one;tree[i].one=tmp;
}
 
void upftree(int node){
    int left=node<<1,right=left+1;
    lazy[left]+=lazy[node];lazy[right]+=lazy[node];
    int count=lazy[node]%3;
    while(count){
        uptree(left);uptree(right);
        count--;
    }
    lazy[node]=0;
}
 
void marge(int node, int left, int right)
{
    tree[node].zero= tree[left].zero + tree[right].zero;
    tree[node].one= tree[left].one + tree[right].one;
    tree[node].two= tree[left].two + tree[right].two;
}
 
void make(int node, int s, int e)
{
 
   if(s==e)
   {
        lazy[node]=0;
        tree[node].one=0;
        tree[node].two=0;
        tree[node].zero=1;
       return;
   }
 
   int left=node<<1;
   int mid=(s+e)>>1;
 
    make(left,s,mid);
    make(left+1,mid+1,e);
 
    marge(node,left,left+1);
}
 
void update(int node, int s, int e, int i, int j)
{
    if(e<i||s>j)
        return;
    if(s>=i&&e<=j){
        lazy[node]++;
        uptree(node);
        return;
    }
   int left=node<<1,right=left+1;
   int mid=(s+e)>>1;
 
    if(lazy[node]){
        upftree(node);
    }
 
    update(left,s,mid,i,j);
    update(right,mid+1,e,i,j);
    marge(node,left,right);
}
 
int query(int node, int s, int e, int i,int j)
{
    if(e<i||s>j)
        return 0;
    if(s>=i&&e<=j){
        return tree[node].zero;
    }
    int left=node<<1,right=(node<<1)+1,mid=(s+e)/2;
    if(lazy[node]){
        upftree(node);
    }
 
    int qq=query(left,s,mid,i,j);
    int qqq=query(right,mid+1,e,i,j);
    return qq+qqq;
}
 
int main()
{
    int t,no=0;
    scanf("%d",&t);
 
    while(t--)
    {
        int n,q,a;
        scanf("%d %d",&n,&q);
 
        cover(tree,0);
        memset(lazy,0,sizeof(lazy));
        make(1,1,n);
 
        printf("Case %d:\n",++no);
        while(q--)
        {
            int type,l,r;
            scanf("%d %d %d",&type,&l,&r);
            l++;
            r++;
 
            if(type == 0)
            {
                update(1,1,n,l,r);
            }
            else
            {
                printf("%d\n",query(1,1,n,l,r));
            }
        }
    }
 
    return 0;
}