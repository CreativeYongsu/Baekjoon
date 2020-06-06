#include <iostream>
#include <vector>
#include <map>

/*
2
-5 1 12 1
7
1 1 8
-3 -1 1
2 2 2
5 5 1
-4 5 1
12 1 1
12 1 2
-5 1 5 1
1
0 0 2 
*/

// 문제를 보고 이해하길 이건 트리문제다.
// 그래서 그냥 트리를 죽 생성하고 트리간의 뎁스를 출력하였음.

using namespace std;
struct T_PT
{
    int x;
    int y;
};

struct T_NODE
{
    int parent;
    T_PT point;
    int r;
    vector<int> childs;

    bool HasPoint(const T_PT& pt)
        {
        double sqR = (double)r * (double)(r);
        double sqD = 
        ( (point.x - pt.x) * (point.x - pt.x) ) +
        ( (point.y - pt.y) * (point.y - pt.y) );

        return sqR > sqD;
    }
};

T_PT g_s, g_e;
vector<T_NODE> g_nodes;

bool GetDistanceNodeSub(int ncur, int target, int& nDepth);

map<int, bool> g_mapChecked;
int GetDistanceNode(int n1, int n2)
{
    g_mapChecked.clear();

    int nDepth = 0;
    GetDistanceNodeSub(n1, n2, nDepth);

    return nDepth;
}

bool GetDistanceNodeSub(int ncur, int target, int& nDepth)
{
    if(ncur == target)
    {
        return true;
    }
    if(g_mapChecked.find(ncur) != g_mapChecked.end())
    {
        nDepth--;
        return false;
    }
    
    g_mapChecked[ncur] = true;
    T_NODE& node = g_nodes[ncur];

    if(node.parent != -1)
    {
        if(GetDistanceNodeSub(node.parent, target, ++nDepth))
            return true;
    }

    for(auto& id : node.childs)
    {
        if(GetDistanceNodeSub(id, target, ++nDepth))
        {
            return true;
        }
    }

    nDepth--;
    return false;
}

using namespace std;
int main()
{
    int t;
    cin>>t;

    for(int i = 0 ; i < t; i++)
    {
        cin>>g_s.x>>g_s.y>>g_e.x>>g_e.y;

        int cnt;
        cin>>cnt;
        
        g_nodes.clear();
        g_nodes.resize(cnt);

        map<int, vector<int> > radius;

        for(int j = 0 ; j < cnt; j++)
        {
            g_nodes[j].parent = -1;
            cin>>g_nodes[j].point.x>>g_nodes[j].point.y>>g_nodes[j].r;

            if(radius.find(g_nodes[j].r) == radius.end())
            {
                radius[g_nodes[j].r] = vector<int>();
            }
            radius[g_nodes[j].r].push_back(j);            
        }

        // sort
        vector<int> sortedIdx;
        sortedIdx.reserve(cnt);
        for(auto& itr : radius)
        {
            for(auto& itr2 : itr.second)
            {
                sortedIdx.push_back(itr2);
            }
        }

        int nSIdx = cnt;
        int nEIdx = cnt;
        for(int j = 0 ; j < cnt; j++)
        {
            int& nSrtIdx = sortedIdx[j];
            if(nSIdx == cnt)
            {
                if(g_nodes[nSrtIdx].HasPoint(g_s))
                {
                    nSIdx = nSrtIdx;
                }
            }

            if(nEIdx == cnt)
            {
                if(g_nodes[nSrtIdx].HasPoint(g_e))
                {
                    nEIdx = nSrtIdx;
                }
            }
        }

        for(int j = 0 ; j < cnt - 1; j++)
        {
            T_NODE& nodeTest = g_nodes[sortedIdx[j]];
            T_PT ptTest = nodeTest.point;
            ptTest.x += nodeTest.r;

            for(int k = j + 1; k < cnt; k++)
            {
                if(nodeTest.r >= g_nodes[sortedIdx[k]].r) continue;

                if(g_nodes[sortedIdx[k]].HasPoint(ptTest))
                {
                    nodeTest.parent = sortedIdx[k];
                    g_nodes[sortedIdx[k]].childs.push_back(sortedIdx[j]);
                    break;
                }
            }
        }
        T_NODE root;
        root.parent = -1;
        for(int j = 0 ; j < cnt; j++)
        {
            if(g_nodes[j].parent != -1) continue;

            g_nodes[j].parent = cnt;
            root.childs.push_back(j);
        }
        g_nodes.push_back(root);

        cout<<GetDistanceNode(nSIdx, nEIdx)<<endl;
    }

    return 0;
}