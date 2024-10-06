//Write a program to implement insertion sort.
#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int a[5],k,j,temp;
    cout << "Enter the elements of the array: " << endl;
    for(k=0; k<5; k++)
    {
        cin >> a[k];
    }

    for(k=1; k<=4; k++)
    {
       temp=a[k];
       j=k-1;
       while(temp<a[j] && j>=0)
       {
           a[j+1]=a[j];
           j--;
       }
       a[j+1]=temp;
    }

    cout << "The sorted array: ";
    for(k=0; k<5; k++)
    {
        cout << a[k] << " ";
    }
    return 0;
}

