#include<iostream>
using namespace std;
void mergesort(int a[],int n);
void merge(int a[],int n,int L[],int n1,int R[],int n2);
int main(){
    int n;
    cout<<"Enter number of elements : ";
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<"Array before sorting : ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    mergesort(a,n);

    cout<<"Array after sorting : ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void mergesort(int a[],int n){
    if(n<2)
    return;

    int mid=n/2;
    int n1=mid, n2=n-mid;
    int L[n1], R[n2];

    for(int i=0;i<n1;i++){
        L[i]=a[i];
    }

    for(int i=0;i<n2;i++){
        R[i]=a[mid+i];
    }

    mergesort(L,n1);
    mergesort(R,n2);
    merge(a,n,L,n1,R,n2);
}
void merge(int a[],int n,int L[],int n1,int R[],int n2){
    int i=0,j=0,k=0;
    while(i<n1&&j<n2){
        if(L[i]<R[j]){
            a[k]=L[i];
            k++; i++;
        }
        else{
            a[k]=R[j];
            k++; j++;
        }
    }

    while(i<n1){
        a[k]=L[i];
        k++; i++;
    }

    while(j<n2){
        a[k]=R[j];
        k++; j++;
    }
}