#include <iostream>
#include "solution.cpp"
#include <cassert>



int main()
{
    int n;
    cin >> n;


    vector<number_pattern> patterns;
    for (int i = 0; i < n; ++i) {
        string pattern;
        string type;

        cin >> type >> pattern;

        number_pattern one_pattern(pattern, type);
        patterns.push_back(one_pattern);
    }

    int m;
    cin >> m;
    vector<vehicle_info> vehicles;
    for (int i = 0; i < m; ++i) {
        string type;
        string number;

        cin >> number >> type;

        vehicle_info info(number, type);
        vehicles.push_back(info);
    }

    lucky_number(vehicles, patterns);
    return 0;
}

