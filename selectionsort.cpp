//Write a program to implement selection sort.
#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int a[5],k,j,pos,small,temp;
    cout << "Enter the elements of the array: " << endl;
    for(k=0; k<5; k++)
    {
        cin >> a[k];
    }

    for(k=0; k<5; k++)
    {
        small=a[k];
        pos=k;
        for(j=k+1; j<=4; j++)
        {
            if(small>a[j])
            {
                small=a[j];
                pos=j;
            }
        }
        temp=a[k];
        a[k]=a[pos];
        a[pos]=temp;
    }

    cout << "The sorted array: ";
    for(k=0; k<5; k++)
    {
        cout << a[k] << " ";
    }
    return 0;
}

