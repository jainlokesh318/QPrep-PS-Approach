#include <bits/stdc++.h>
#include "Solution.cpp"
using namespace std;

// DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE


int main()
{

    int n, dist;
    cin >> n >> dist;
    vector< pair<string , int > > broken;
    for (int i = 0; i < n; i++)
    {
        string number;
        int people;
        cin >> number >> people;
        broken.push_back({number, people});
    }
    int m;
    cin >> m;
    vector<pair<string , pair<int, int > > > good;
    for (int i = 0; i < m; i++)
    {
        int people, capacity;
        string number;
        cin >> number >> people >> capacity;
        good.push_back({number, {people , capacity}});
    }
    int result = findMaximumNumberOfPeopleAccomodated(broken, good, dist);
    cout << result << "\n";
    return 0;
}
