#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
5
1 1 3 3 1
3 1 5 3 1
1 4 3 6 1
3 4 5 6 1
0 3 6 4 2

5
5 5 6 6 22
3 4 6 5 22
6 3 7 6 22
5 6 8 7 22
4 5 5 8 22

7
0 0 4 3 1
6 2 9 7 2
6 7 10 9 3
4 0 6 3 1
0 6 6 9 3
0 3 6 6 2
7 0 8 2 2
*/

int main()
{
    int n;
    cin>>n;

    int tMap[1000000001][1000000001] = {-1, };
    int nMinX = -1;
    int nMaxX = -1;
    int nMinY = -1;
    int nMaxY = -1;

    for(int i = 0 ; i < n; i++)
    {
        int x1, y1, x2, y2, type;
        cin >> x1 >> y1 >> x2 >> y2 >> type;

        if(nMinX == -1 || nMinX > x1) nMinX = x1;
        if(nMaxX == -1 || nMaxX < x2) nMaxX = x2;

        if(nMinY == -1 || nMinY > y1) nMinY = y1;
        if(nMaxY == -1 || nMaxY < y2) nMaxY = y2;

        for(int i = x1; i <= x2; i++)
        {
            for(int j = y2; j <= y2; j++)
            {
                tMap[i][j] = type;
            }
        }
    }

    return 0;
}
