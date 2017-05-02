#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,p,vt;
long long int sum_h[100002],sum_a_h[100002],res=-1,tmp;
pair<long long,long long> a[100002];
int solve(int x,int i,int j){
    int mid=(i+j)/2;
    if(a[mid].first<=x&&a[mid+1].first>x)
        return mid;
    if(a[mid].first>x)
        solve(x,i,mid-1);
    else
        solve(x,mid+1,j);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i].first);
    }
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i].second);
    }
    sort(a+1,a+n+1);
    a[n+1].first=10000000;
    for(int i=1;i<=n;i++){
        sum_h[i]=sum_h[i-1]+a[i].second;
        sum_a_h[i]=sum_a_h[i-1]+a[i].first*a[i].second;
    }
    for(int i=a[1].first;i<=a[n].first;i++){
        vt=solve(i,1,n);
        tmp=(sum_a_h[n]-2*sum_a_h[vt])-i*(sum_h[n]-2*sum_h[vt]);
        if(res==-1||tmp<res){
            res=tmp;
            p=i;
        }
    }
    cout<<p<<" "<<res;
}
