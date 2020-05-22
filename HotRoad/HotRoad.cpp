#include <bits/stdc++.h>
#include "Solution.cpp"
using namespace std;

// DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE

void testRegNumberToInteger() {
    assert(regNumberToInteger("KA01AA0001") == 1);
    assert(regNumberToInteger("KA01AA0002") == 2);
    assert(regNumberToInteger("KA01AB0001") == 10000);
    assert(regNumberToInteger("KA01BA0001") == 26 * 9999 + 1);
    assert(regNumberToInteger("KA01BA0001") == 259975);
    assert(regNumberToInteger("KA02AA0001") == 6759325);
}

void findMaximumNumberOfPeopleAccomodated() {
    // normal case
    vector< pair<string , int > > broken = {{"KA01MQ1012", 2}, {"KA01MQ1045", 4}};
    vector<pair<string , pair<int, int > > > good = {{"KA01MQ1002", {2, 4}}, {"KA01MQ1050", {4, 10}}};

    assert(findMaximumNumberOfPeopleAccomodated(broken, good, 10) == 6);
    // normal case
    broken = {{"KA01MQ1012", 2}, {"KA01MQ1045", 4}};
    good = {{"KA01MQ1002", {2, 4}}, {"KA01MQ1050", {4, 10}}};

    assert(findMaximumNumberOfPeopleAccomodated(broken, good, 5) == 4);

    // no good car in range
    broken = {{"KA01MQ1012", 2}, {"KA01MQ1045", 4}};
    good = {{"KA01MQ1002", {2, 4}}, {"KA01MQ1055", {4, 10}}};

    assert(findMaximumNumberOfPeopleAccomodated(broken, good, 9) == 0);

    // large broke car accomodated by multiple good cars
    broken = {{"KA01MQ1012", 6}};
    good = {{"KA01MQ1002", {2, 4}}, {"KA01MQ1021", {3, 4}}};

    assert(findMaximumNumberOfPeopleAccomodated(broken, good, 10) == 3);

    // car with large capacity accomodates people from multiple cars
    broken = {{"KA01MQ1002", 2}, {"KA01MQ1021", 2}};
    good = {{"KA01MQ1012", {2, 8}}};

    assert(findMaximumNumberOfPeopleAccomodated(broken, good, 10) == 4);

}

int main()
{
    testRegNumberToInteger();
    findMaximumNumberOfPeopleAccomodated();

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
