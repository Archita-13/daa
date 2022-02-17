#include<bits/stdc++.h>
using namespace std;
struct activity{
    int start;
    int finish;
};

bool compare(activity a1, activity a2){
    return (a1.finish<a2.finish);
}

int main(){
    activity a[]={{1,2},{3,4},{0,6},{5,7},{8,9},{5,9}};
    int n=sizeof(a)/sizeof(a[0]);

    //sorting activities acc to finish time 
    sort(a,a+n,compare);

    //select activities from sorted array
    int i=0,k=1;
    int sol[n];
    sol[0]=i;
    
    cout<<"Activities selected : "<<endl;
    //cout<<a[0].start<<" "<<a[0].finish<<endl;
    for(int j=1;j<n;j++){

        if(a[j].start>=a[i].finish){
            //cout<<a[j].start<<" "<<a[j].finish<<endl;
            i=j;
            sol[k]=i;
            k++;
            //cout<<"i="<<i<<" sol "<<sol[k]<<" k= "<<k<<endl;
        }
    }

    //cout<<n2<<endl<<sizeof(sol)<<endl;
    for(int i=0;i<k;i++){
        cout<<sol[i]<<" ";
    }
    cout<<endl;

}