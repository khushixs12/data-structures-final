//Write a program to implement merge sort.
#include <iostream>
#include <conio.h>
using namespace std;


void merge(int a[], int beg, int mid, int end)
{
    int i=beg, j=mid+1, index=0, temp[100], k;
    while((i<=mid) && (j<=end))
    {
        if(a[i]<a[j])
        {
            temp[index]=a[i];
            i++;
        }
        else
        {
            temp[index]=a[j];
            j++;
        }
        index++;
    }

    if(i>mid)
    {
        while(j<=end)
        {
            temp[index]=a[j];
            j++;
            index++;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[index]=a[i];
            i++;
            index++;
        }
    }

    k=0;
    while(k<index)
    {
        a[beg+k]=temp[k];
        k++;
    }
}

void merge_sort(int a[], int beg, int end)
{
    int mid;
    if(beg<end)
    {
        mid=(beg+end)/2;
        merge_sort(a, beg, mid);
        merge_sort(a, mid+1, end);
        merge(a, beg, mid, end);
    }
}

int main()
{
    int a[100],i, n;
    cout << "How many elements do you want to enter in the array: ";
    cin >> n;
    cout << "Enter the elements in the array: ";
    for(i=0; i<n; i++)
    {
        cin >> a[i];
    }

    merge_sort(a, 0, n-1);

    cout << "The sorted array is: ";
    for(i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
