#include<iostream>
using namespace std;
void merge(int *a,int si,int ei)
{
    int mid=(si+ei)/2;
    int i=si,j=mid+1,k=si;
    int temp[100];
    while(i<=mid && j<=ei)
    {
        if(a[i]<a[j])
        {
        temp[k++]=a[i++];
        }
        
        else{
            temp[k++]=a[j++];
        }
    }
    
    while(i<=mid)
    {
        temp[k++]=a[i++];
    }
    while(j<=ei)
    {
        temp[k++]=a[j++];
    }
   //we need to copy all element to original array 
    for(int i=si;i<=ei;i++)
    {
        a[i]=temp[i];
    }
    
}
void mergeSort(int a[],int si,int ei)
{
    //base case
    if(si>=ei)return;
    
    //follow 3 steps
    //1 divide
    int mid=(si+ei)/2;
    
    //recursively the array - si,mid & mid+1,ei
    mergeSort(a,si,mid);
    
    mergeSort(a,mid+1,ei);
    
    //merge two parts
    merge(a,si,ei);

}

int main()
{
    int size;
    cout<<"Enter size";
    cin>>size;
    int *a=new int[size];
    cout<<"Enter array";
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    mergeSort(a,0,size-1);
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}

//Code Contributed By Aryan Modi