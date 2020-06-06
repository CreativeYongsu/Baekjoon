#include <iostream>

using namespace std;

int main()
{
    double a,b;
    cin>>a>>b;
    if ( a > b )
        cout<<">"<<endl;
    else if(a < b)
        cout<<"<"<<endl;
    else if(a == b)
        cout<<"=="<<endl;

    return 0;
}
