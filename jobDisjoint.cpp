#include<bits/stdc++.h>
using namespace std;
struct job{
    char id;
    int deadline, profit;
};

bool compare(job a,job b){
return (a.profit>b.profit);
}

struct DisjointSet{
    int *parent;
    DisjointSet(int n){
        parent=new int[n+1];
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }


int find(int s){
    if(s==parent[s])
    return s;
    return parent[s]=find(parent[s]);
}

void merge(int u,int v){
    parent[v]=u;
}

};

int findMaxDeadline(struct job a[],int n){
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,a[i].deadline);
    }
    return ans;
}


int main(){
    job a[]={{'a',2,100},{'b',1,19},{'c',2,27},{'d',1,25},{'e',3,15}};
    int n=sizeof(a)/sizeof(a[0]);

    sort(a,a+n,compare);

    int maxdeadline=findMaxDeadline(a,n);
    DisjointSet ds(maxdeadline);

    for(int i=0;i<n;i++){
        int availableslot=ds.find(a[i].deadline);

        if(availableslot>0){
            ds.merge(ds.find(availableslot-1),availableslot);
            cout<<a[i].id<<" ";
        }
    }
}