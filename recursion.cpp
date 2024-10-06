#include <iostream>
#include <conio.h>
using namespace std;
int fact(int n)
{
    if(n==1 || n==0)
        return 1;
    else
        return n*fact(n-1);
}
int main()
{
    int n;
    cout << "Enter number to find factorial using recursion: ";
    cin >> n;
    cout << "Factorial = " << fact(n) << endl;
    getch();
    return 0;
}

