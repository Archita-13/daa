#include<bits/stdc++.h>
using namespace std;
struct item{
    int profit;
    int weight;
};

bool compare(item a,item b){
    double r1=a.profit/a.weight;
    double r2=b.profit/b.weight;
    return (r1>r2);
}

int main(){
    item a[]={{1,1},{6,2},{18,3},{22,6},{28,7}};
    int n=sizeof(a)/sizeof(a[0]);
    int W=9;
    sort(a,a+n,compare);
    int currentWeight=0;
    double totalProfit=0.0;
    for(int i=0;i<n;i++){
        if(currentWeight+a[i].weight<=W){
            currentWeight+=a[i].weight;
            totalProfit+=a[i].profit;
        }
        else{
            int remain=W-currentWeight;
            totalProfit+=a[i].profit*((double)remain/(double)a[i].weight);
            break;
        }
    }
    cout<<"Total profit is : "<<totalProfit<<endl;
}