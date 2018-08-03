#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
using namespace std;
 
 
int minPrime[1006];
void siv_he(){
    lli n=1001;
    for (int i = 2; i * i <= n; ++i) {
        if (minPrime[i] == 0) {         //If i is prime
            for (int j = i * i; j <= n; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }
}
vector<int> factorize(int n) {
    vector<int> res;
    if(minPrime[n]==n)return res;
    while (n != 1) {
        //if(minPrime[n]==n)break;
        if(!res.empty() &&minPrime[n]!=res[res.size()-1] )
            res.push_back(minPrime[n]);
        if(res.empty()) res.pb(minPrime[n]);
        n /= minPrime[n];
    }
    return res;
}
int bfs(int src,int des){
    queue<int> Q;
    int vis[1002],dist[10001];
    memset(vis,0,sizeof(vis));
    Q.push(src);
    dist[src]=0;
    vis[src]=1;
    int trans=0;
    while(!Q.empty()){
        int u=Q.front();
        if(u==des) return dist[u];
        vector<int> vf=factorize(u);
        for(int i=0;i<vf.size();i++){
            int v=vf[i]+u;
            if(!vis[v] && v<=des){
                dist[v]=dist[u]+1;
                Q.push(v);
                vis[v]=1;
            }
        }
        Q.pop();
    }
    return -1;
}
 
void print1d(vector<int>a){
    cout<<endl;
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    cout<<endl;
 
}
int main(){
    int sr,de,t;
    siv_he();
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>sr>>de;
        int rr=bfs(sr,de);
        printf("Case %d: %d\n",i,rr);
    }
    return 0;
}