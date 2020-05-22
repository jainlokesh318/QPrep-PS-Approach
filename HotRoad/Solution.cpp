#include <bits/stdc++.h>
using namespace std;

// Finish this function

long long stringScore(string s)
{
    long long secA = (s[2]-'0')*10 + (s[3]-'0');
    secA = (secA-1)*26*26*9999;

    long long secB = (s[4]-64)*(s[5]-64)*9999;

    long long secC = (s[6]-'0')*1000;
    secC += (s[7]-'0')*100;
    secC += (s[8]-'0')*10;
    secC += (s[9]-'0');

    return secA + secB + secC;
}

long computePassengers(map<long long, long long> &flat,
        map<long long, long long> &fresh, long k)
{
    long ans = 0;
    map<long long, long long>:: iterator itr1;
    map<long long, long long>:: iterator itr2;

    for(itr1 = flat.begin(); itr1 != flat.end(); itr1++)
    {
        for(itr2 = fresh.begin(); itr2 != fresh.end(); itr2++)
        {
           long diff = abs(itr1->first - itr2->first);
           if(diff <= k)
           {
                ans += min(itr1->second, itr2->second);
                itr1->second -= min(itr1->second, itr2->second);
                itr2->second -= min(itr1->second, itr2->second);
           }
        }
    }

    return ans;
}

int findMaximumNumberOfPeopleAccomodated(vector< pair<string , int> >& broken, vector<pair< string ,pair<int,int > > >& good, int dist)
{
    map<long long, long long> flat;
    map<long long, long long> fresh;

    vector< pair<string , int> >:: iterator itr1;
    vector<pair< string ,pair<int,int > > >:: iterator itr2;

    for(itr1 = broken.begin(); itr1 != broken.end(); itr1++)
    {
        string s = itr1->first;
        int p = itr1->second;

        long long score = stringScore(s);
        flat.insert({score, p});
    }

    for(itr2 = good.begin(); itr2 != good.end(); itr2++)
    {
        string s = itr2->first;
        int p = itr2->second.first;
        int c = itr2->second.second;
        
        long long score = stringScore(s);
        fresh.insert({score, c-p});
    }

    cout << computePassengers(flat, fresh, dist);
}
