#include<iostream>
using namespace std;
int main(){
    int a[]={2,1,2};
    int n=sizeof(a)/sizeof(a[0]);

    int curr=a[0];
    int count=1;
    for(int i=1;i<n;i++){
        if(a[i]==curr){
            count++;
        }
        else{
            count--;
        }

        if(count==0){
            curr=a[i];
            count=1;
        }
    }

    count=0;
    for(auto x:a){
        if(x==curr){
            count++;
        }
    }

    if(count>n/2){
        cout<<"Majority element is : "<<curr<<endl;
    }
    else{
        cout<<"There is no majority element in this array\n";
    }
}