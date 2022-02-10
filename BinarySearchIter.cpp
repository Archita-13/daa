#include<iostream>
using namespace std;
int binarySearchIter(int a[],int n,int ele);
int main(){
    int n;
    cout<<"Enter the number of elements : ";
    cin>>n;
    int a[n];

    //input
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int ele;
    cout<<"Enter the element to be searched : ";
    cin>>ele;
    int t=binarySearchIter(a,n,ele);
    if(t==-1){
        cout<<"Element not found\n";
    }
    else{
        cout<<"Element was found at position : "<<t+1<<endl;
    }
}

int binarySearchIter(int a[],int n,int ele){
    int l=0, r=n-1,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(a[mid]==ele){
            return mid;
        }
        else if(a[mid]>ele){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
        return -1;
}