
#include <string>
#include <vector>
#include <iostream>

#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

map< int, set<string> > g_MapCache;

int GetMapCache(const vector<string>& gems, int nS, int nCount)
{
    int nSize = gems.size();
    set<string>& rMap = g_MapCache[nS];
    if(rMap.size() == 0)
    {
        for(int i = nS; i < nS + nCount; i++)
        {
            rMap.insert(gems[i]);
        }
    }
    else
    {
        rMap.insert(gems[nS + nCount - 1]);
    }

    return rMap.size();
}

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> setGems;
    for(vector<string>::iterator itr = gems.begin(); itr != gems.end(); itr++)
    {
        setGems.insert(*itr);
    }
    int nMinSize = setGems.size();

    int nSize = gems.size();
    int nCurSize = nMinSize;
    while(nCurSize <= nSize)
    {
        int nMinIndex = -1;
        
        map<string, int> mapCnt;
        for(int i = 0 ; i < nSize - nCurSize + 1; i++)
        {
            if(i == 0)
            {
                for(int j = i ; j < i + nCurSize ; j++)
                {
                    if(mapCnt.find(gems[j]) == mapCnt.end())
                    {
                        mapCnt[gems[j]] = 1;
                    }
                    else
                    {
                        mapCnt[gems[j]]++;
                    }
                }
            }
            else
            {
                    int& nCnt1 = mapCnt[gems[i]];
                    int& nCnt2 = mapCnt[gems[i + nCurSize - 1]];
                    nCnt1--;
                    nCnt2++;
            }

            if(mapCnt.size() >= nMinSize)
            {
                int nCnt = 0;
                for(auto itr = mapCnt.begin(); itr!=mapCnt.end(); itr++)
                {
                    if(itr->second >= 1) nCnt++;
                }
                if(nCnt >= nMinSize)
                {

                }
            }


            /*
            int nTypeCnt = GetMapCache(gems, i, nCurSize);
            if(nTypeCnt == nMinSize)
            {
                answer.push_back(i + 1);
                answer.push_back(i + nCurSize);
                return answer;
            }
            */
        }

        nCurSize++;
    }

    return answer;
}

int main()
{
    vector<string> gems;
    gems.push_back("DIA");
    gems.push_back("RUBY");
    gems.push_back("RUBY");
    gems.push_back("DIA");
    gems.push_back("DIA");
    gems.push_back("EMERALD");
    gems.push_back("SAPPHIRE");
    gems.push_back("DIA");

    solution(gems);
    
}