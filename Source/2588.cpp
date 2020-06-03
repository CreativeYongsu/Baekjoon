#include <iostream>

using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<((b/1)%10) * a<<endl;
    cout<<((b/10)%10) * a<<endl;
    cout<<((b/100)%10) * a<<endl;
    cout<<a*b<<endl;

    return 0;
}
