#include <string>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;

    struct tScore
    {
        int score;
        int times; // 1, 2, 3
        int opt;   // 0:none, 1:*, 2:#

        tScore(string str)
        {
            score = 0;
            times = 0;
            opt = 0;

            int nTimesIndex = 1;
            if('0' <= str[1] && str[1] <= '9')
            {
                score = atoi(str.substr(0, 2).c_str());
                nTimesIndex = 2;
            }
            else
            {
                score = atoi(str.substr(0, 1).c_str());
            }

            if(str[nTimesIndex] == 'S') times = 1;
            else if(str[nTimesIndex] == 'D') times = 2;
            else if(str[nTimesIndex] == 'T') times = 3;

            if(str.length() > nTimesIndex)
            {
                if(str[nTimesIndex + 1] == '*') opt = 1;
                else if(str[nTimesIndex + 1] == '#') opt = 2;
            }
        }
        int GetScore(bool bStar)
        {
            int nResult = score;
            if(times == 2) nResult = score * score;
            else if(times == 3) nResult = score * score * score;

            if(bStar)
            {
                if(opt == 1) nResult *= 4;
                else if(opt == 2) nResult *= -2;
                else if(opt == 0) nResult *= 2;
            }
            else
            {
                if(opt == 1) nResult *= 2;
                else if(opt == 2) nResult *= -1;
            }
            return nResult;
        }
    };

    vector<tScore> scores;

    int nSubStr = 0;
    for(int i = 2 ; i < dartResult.length(); i++)
    {
        if('0' <= dartResult[i] && dartResult[i] <= '9')
        {
            scores.push_back(tScore(dartResult.substr(nSubStr, i - nSubStr)));

            nSubStr = i;

            if('0' <= dartResult[i+1] && dartResult[i+1] <= '9')
            {
                i++;                
            }
        }
    }
    scores.push_back(tScore(dartResult.substr(nSubStr, dartResult.length() - nSubStr)));

    if(scores.size() != 3) return answer;

    answer = scores[0].GetScore(scores[1].opt == 1);
    answer += scores[1].GetScore(scores[2].opt == 1);
    answer += scores[2].GetScore(false);
    
    return answer;
}




int main()
{
    int nRet;
    nRet = solution("10S*10S*10S*");
    nRet = solution("0S#0S#0S#");
    nRet = solution("1S#1S#1S#");
    nRet = solution("1S2D*3T");
    nRet = solution("1D2S#10S");
    nRet = solution("1D2S0T");
    nRet = solution("1S*2T*3S");
    nRet = solution("1D#2S*3S");

    return 0;
}