// Write a program to implement binary search.
#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int a[5],i;
    cout << "Enter 5 values in the array: " << endl;
    for(i=0;i<5;i++)
    {
        cin >> a[i];
    }
    int val;
    cout << "Enter the value that is to be searched: " << endl;
    cin >> val;
    int beg=0, end=4, pos=-1, mid;
    while(beg<=end)
    {
        mid=(beg+end)/2;
        if(a[mid]==val)
        {
            pos=mid;
            cout << pos << endl;
            break;
        }
        else if(a[mid]>val)
        {
            end=mid-1;
        }
        else
        {
            beg=mid+1;
        }
    }
    if(pos==-1)
    {
        cout << "Value Not Found";
    }
    return 0;
}

