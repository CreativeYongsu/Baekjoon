#include <iostream>

using namespace std;
int main()
{
    int a;
    cin>>a;
    bool bDiv4 = a%4==0;
    bool bMult100 = a%100 == 0;
    bool bMult400 = a%400 == 0;
    
    if(bDiv4 && (!bMult100 || bMult400))
        cout<<1<<endl;
    else
    {
        cout<<0<<endl;
    }
    
    
    return 0;
}
