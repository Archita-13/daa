#include<iostream>
using namespace std;
void quicksort(int a[],int lb,int ub);
int partition(int a[],int lb,int ub);

int main(){
    int n;
    cout<<"Enter the number of elements : ";
    cin>>n;
    int a[n];

    //input
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<"Array before sorting --> ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    quicksort(a,0,n-1);
    cout<<"Array after sorting --> ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void quicksort(int a[],int lb,int ub){
    if(ub>lb){
        int p=partition(a,lb,ub);
        quicksort(a,lb,p-1);
        quicksort(a,p+1,ub);
    }
}

int partition(int a[],int lb,int ub){
    int pindex=lb, pivot=a[ub];
    for(int i=lb;i<ub;i++){
        if(a[i]<pivot){
            swap(a[i],a[pindex]);
            pindex++;
        }
    }
    swap(a[pindex],a[ub]);
    return pindex;
}