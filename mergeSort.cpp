#include <iostream>

using namespace std;

void merging(int *a, int s, int e)
{
    int mid = (s + e)/2;\
    int i = s;
    int j = mid + 1;
    int k = s;
    int temp[100];
    while(i<=mid&&j<=e){
        if(a[i]>a[j]){
            temp[k++] = a[j++];
        }
        else{
            temp[k++] = a[i++];
        }
    }
    while(i<=mid){
        temp[k++] = a[i++];
    }
    while(j <= e){
        temp[k++] = a[j++];
    }
    for(int m = 0; m <= e; m++){
        a[m] = temp[m];
    }
}

void mergeSort(int *a, int s, int e)
{
    if(s>=e)
        return;
    int mid = (s + e)/2;
    mergeSort(a,s,mid);
    mergeSort(a,mid+1,e);
    merging(a,s,e);
}

int main()
{
    int n,a[10];
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    mergeSort(a,0,n-1);
    for(int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
}
