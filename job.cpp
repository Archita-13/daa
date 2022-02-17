#include<bits/stdc++.h>
using namespace std;
struct job{
    char job_id;
    int dline;
    int profit;
};

bool compare(job a1,job a2){
    return (a1.profit>a2.profit);

}
int main(){
    job a[]={{'a', 2, 100},{'b', 1, 19},{'c', 2, 27},{'d', 1, 25},{'e', 3, 15}};
    int n=sizeof(a)/sizeof(a[0]);

    //sorting according to profit
    sort(a,a+n,compare);

    int sol[n], flag[n];
    for(int i=0;i<n;i++){
        flag[i]=0;
    }

    for(int i=0;i<n;i++){
        for(int j=min(n,a[i].dline)-1;j>=0;j--){
            if(flag[j]==0){
                sol[j]=i;
                flag[j]=1;
                break;
            }        
        }
    }

    for(int i=0;i<n;i++){
        if(flag[i]==1){
            cout<<a[sol[i]].job_id<<" ";
        }
    }
}