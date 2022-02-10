#include<iostream>
using namespace std;

int binarySearch(int a[],int l,int r,int ele);
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
    cout<<"Enter the elment to be searched : ";
    cin>>ele;
    int t=binarySearch(a,0,n-1,ele);
    //cout<<"t is : "<<t<<endl;
    if(t==-1){
        cout<<"Element not found in the array\n";
    }
    else{
        cout<<"Element found at position "<<t+1<<endl;
    }
}

int binarySearch(int a[],int l,int r,int ele){
    if(l<=r){
        int mid=(l+r)/2;
        //cout<<"mid : "<<mid<<endl;
        //cout<<"a[mid] == "<<a[mid]<<endl<<"l="<<l<<" r="<<r<<endl;
        if(a[mid]==ele){
            //cout<<"we are returning mid : "<<mid<<endl;
            return mid;
        }
        else if(a[mid]>ele){
            //cout<<"middle is greater\n";
            return binarySearch(a,l,mid-1,ele);
        }
        else{
            //cout<<"middle is smaller\n";
            return binarySearch(a,mid+1,r,ele);
        }
    }
    return -1;
}