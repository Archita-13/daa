#include<iostream>
using namespace std;
void mergesort(int a[],int n);
void merge(int a[],int l,int mid,int r);
int main(){
    int n;
    cout<<"Enter the number of elements : ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    mergesort(a,n);

    cout<<"After sorting ------------------>\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void mergesort(int a[],int n){
    int mid,r;
    for(int p=1;p<n;p=p*2){
        for(int l=0;l<n-1;l+=2*p){
            mid=p+l-1;
            r=min(l+(2*p)-1,n-1);
            merge(a,l,mid,r);
        }
    }
}

void merge(int a[],int l,int mid,int r){
    int n1=mid-l+1;
    int n2=r-mid;
    int left[n1], right[n2];

    for(int i=0;i<n1;i++){
        left[i]=a[i+l];
    }

    for(int i=0;i<n2;i++){
        right[i]=a[mid+1+i];
    }

    int i=0,j=0,k=l;
    while(i<n1&&j<n2){
        if(left[i]<right[j]){
            a[k]=left[i];
            k++; i++;
        }
        else{
            a[k]=right[j];
            k++; j++;
        }
    }

    while(i<n1){
        a[k]=left[i];
        k++; i++;
    }

    while(j<n2){
        a[k]=right[j];
        k++; j++;
    }
}
