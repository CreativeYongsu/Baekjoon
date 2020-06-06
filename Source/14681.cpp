#include <iostream>

using namespace std;
int main()
{
    int x,y;
    cin>>x>>y;
    int ret = 0;
    if(x > 0)
    {
        if(y > 0) ret = 1;
        else ret = 4;
    }
    else
    {
        if(y>0) ret = 2;
        else ret = 3;
    }
    cout<<ret<<std::endl;

    return 0;
}
