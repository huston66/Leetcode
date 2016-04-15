#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 1050

using namespace std;

int sum[320][320];
int num[320][320];

void inity(int s1,int s2,int l,int r,int t,int b){
    if(t==b)
    {
        if(l==r)
        {
            sum[s1][s2]=num[l][t];
        }
        else
        {
            sum[s1][s2]=sum[s1<<1][s2]+sum[s1<<1|1][s2];
        }
        return;
    }

    int mid=(t+b)>>1;
    inity(s1,s2<<1,l,r,t,mid);
    inity(s1,s2<<1|1,l,r,mid+1,b);
    sum[s1][s2]=sum[s1][s2<<1]+sum[s1][s2<<1|1];
}

void initx(int s1,int s2,int l,int r,int t,int b){
    if(l!=r)
    {
        int mid=(l+r)>>1;
        initx(s1<<1,s2,l,mid,t,b);
        initx(s1<<1|1,s2,mid+1,r,t,b);
    }

    inity(s1,s2,l,r,t,b);
}

int queryy(int s1,int s2,int L,int R,int T,int B,int l,int r,int t,int b){
    if(T==t&&B==b){
        return sum[s1][s2];
    }

    int mid=(T+B)>>1;
    if(b<=mid)
    {
        return queryy(s1,s2<<1,L,R,T,mid,l,r,t,b);
    }
    else if(t>mid)
    {
        return queryy(s1,s2<<1|1,L,R,mid+1,B,l,r,t,b);
    }


    int t1=queryy(s1,s2<<1,L,R,T,mid,l,r,t,mid);
    int t2=queryy(s1,s2<<1|1,L,R,mid+1,B,l,r,mid+1,b);

    return t1+t2;
}

int queryx(int s1,int s2,int L,int R,int T,int B,int l,int r,int t,int b){
    if(L==R){
        return queryy(s1,s2,L,R,T,B,l,r,t,b);
    }

    int mid=(L+R)>>1;
    if(r<=mid)
        return queryx(s1<<1,s2,L,mid,T,B,l,r,t,b);
    else if(l>mid)
        return queryx(s1<<1|1,s2,mid+1,R,T,B,l,r,t,b);

    int t1=queryx(s1<<1,s2,L,mid,T,B,l,mid,t,b);
    int t2=queryx(s1<<1|1,s2,mid+1,R,T,B,mid+1,r,t,b);
    return t1+t2;
}

void updatey(int s1,int s2,int L,int R,int T,int B,int x,int y,int val){
    if(T==y&&B==y){
        sum[s1][s2]=val;
        return;
    }

    int mid=(T+B)>>1;
    if(y<=mid)
    {
        updatey(s1,s2<<1,L,R,T,mid,x,y,val);
    }
    else if(y>mid)
    {
        updatey(s1,s2<<1|1,L,R,mid+1,B,x,y,val);
    }

    sum[s1][s2]=sum[s1][s2<<1]+sum[s1][s2<<1|1];
}

void updatex(int s1,int s2,int L,int R,int T,int B,int x,int y,int val){
    if(L==x&&R==x){
        updatey(s1,s2,L,R,T,B,x,y,val);
        return;
    }

    int mid=(L+R)>>1;
    if(x<=mid)
    {
        updatex(s1<<1,s2,L,mid,T,B,x,y,val);
    }
    else if(x>mid)
    {
        updatex(s1<<1|1,s2,mid+1,R,T,B,x,y,val);
    }

    sum[s1][s2]=sum[s1<<1][s2]+sum[s1<<1|1][s2];
}
