#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <cstring>
#include<bits/stdc++.h>
using namespace std;

map<string, string> mp;

struct number_pattern {
    string pattern;
    string type;

    number_pattern(const string & p, const string & t) : pattern(p), type(t)
    {
    }

    /*number_pattern() {}
    number_pattern(const number_pattern & other) {
    }*/


    /*bool number_matches_the_pattern(const string & number) {
    }


    string get_number_suggestion(const string & number) {

        return string("-1");
    }*/
};


struct vehicle_info{
    string number, type;
    vehicle_info(const string &num, string t = "optional") : number(num), type(t)
    {
    }
};

vector<vehicle_info> to_print;

bool check_state(vehicle_info x)
{
//cout << "Checking state ";
    set<string> state_code = {"AP","AS","AR","BR","CG","GA","GJ","HR","HP","JK","JH","KA","KL","MP","MH","ML","MN","MZ","NL",
                         "OD","PB","RJ","SK","TN","TS","TR","UK","UP","WB","AN","CH","DD","DL","LA","LD","PY"};

    string su = x.number.substr(0, 2);
    transform(su.begin(), su.end(), su.begin(), ::toupper);

    //cout << su << " ";
    if(state_code.find(su) != state_code.end()){
      //  cout << "ok\n";
        return true;
    }
    //cout << "No\n";
    return false;
}

bool check_district(vehicle_info x)
{
//cout << "Checking district ";
    if((x.number[3] >= '0' && x.number[3] <= '9') &&
            (x.number[4] >= '0' && x.number[4] <= '9') && (x.number[2] == '-' && x.number[5] == '-')){
       // cout << "ok\n";
        return true;
    }
  //  cout << "no not happen \n";
    return false;
}

bool check_mid(vehicle_info x)
{
//cout << "checking mid ";
    int n = x.number.size();
    int flag = 0, cnt = 0;
    for(int i = 6; i < n; i++)
    {
        if(x.number[i] == '-'){
            flag = 1;
            break;
        }
        cnt++;
    }

    if(flag == 0){
//        cout << " empty\n";
        return true;
    }
    if(cnt <= 3)
    {
        string su = x.number.substr(6, cnt);
       // cout << " " << su << " ";
        for(int i = 0; i < cnt; i++)
        {
            if((su[i] >= 'A' && su[i] <= 'Z') || (su[i] >= 'a' && su[i] <= 'z'))
                continue;
    //        cout << "Going from here " ;
            return false;
        }
  //      cout << "ok\n";
        return true;
    }
    else
        return false;
}

bool check_last(vehicle_info x)
{
//cout << "checking last ";
    int n = x.number.size(), cnt = 0, last_index;
    for(int i = 0; i < n; i++)
    {
        if(x.number[i] == '-'){
            last_index = i;
            cnt = 0;
            continue;
        }
        cnt++;
    }
//cout << "\nlast index = " << last_index << "cnt = " << cnt << " ";
    if(cnt == 4)
    {
        for(int i = last_index+1; i < n; i++){
           //cout << x.number[i] << " ";
            if(x.number[i] >= '0' && x.number[i] <= '9')
                continue;
    //        cout << "return ";
            return false;
        }
      //  cout << "ok\n";
        return true;

    }
    else{
      //  cout << "Retunrning ";
        return false;
    }
}

void is_pallindrome(vehicle_info x, string num)
{
//cout << "checking for " << num << "\n";
    int i = 0, j = num.size()-1;
    while(i <= j)
    {
  //  cout << i << " " << j << "\n";
        if(num[i] != num[j]){
    //        cout << "breaking at " << num[i] << " " << num[j] << "\n";
            return;
        }
        i++, j--;
    }
    to_print.push_back(x);
}

void follow_regex(vehicle_info x, vector<number_pattern> &patterns)
{
    vector<vector<char>> allow_size{ {0,9},
                                    {0,9},
                                    {0,9},
                                    {0,9}
                                };

    map<string, string>:: iterator itr;

    itr = mp.find(x.type);
    if(itr != mp.end())
    {
  //  cout << "FOund\n";
        int cnt = 0;
        string reg = itr->second;
        //cout << "regex is : " << reg << "\n";
        for(int i = 0; i < reg.size(); i++)
        {
            if(i == reg.size()-1 || (reg[i+1] >= '0' && reg[i+1] <= '9'))
            {
          //  cout << " HERE ";
                allow_size[cnt][0] = reg[i];
                allow_size[cnt][1] = reg[i];
            }
            else{
                allow_size[cnt][0] = reg[i];
                allow_size[cnt][1] = reg[i+2];
                i+=2;
            }
            cnt++;
        }
    }
    else
    {
        for(int i = 0; i < 4; i++)
        {
            allow_size[i][0] = '0';
            allow_size[i][1] = '9';
        }
    }


/*cout << "\nREGEX pattern \n";
    for(int i = 0; i < allow_size.size(); i++)
    {
        for(int j = 0; j < allow_size[i].size(); j++)
            cout << "ya " << allow_size[i][j] << " ";
        cout << "\n";
    }
*/
    int n = x.number.size(),  cnt = 4, i, flag = 0;
    string s = "";
    for(i = n-1; i >= n-4; i--)
    {
        cnt--;
        if(x.number[i] >= allow_size[cnt][0] && x.number[i] <= allow_size[cnt][1]){
            s.append(1, x.number[i]);
            continue;
        }
        s.append(1, allow_size[cnt][0]);
        flag = 1;
    }

    if(flag == 0){
        is_pallindrome(x, s);
        cout << "Good\n";
    }
    if(flag == 1)
    {
        reverse(s.begin(), s.end());
        cout << "Bad " << s << "\n";
    }
}

bool is_valid_number_pattern(vehicle_info x, vector<number_pattern> &patterns)
{
    string s = x.number;
    int n = x.number.size();
    for(int i = 0; i < n-1; i++)
        if(s[i] == '-' && s[i+1] == '-')
            return false;
            
    if(((check_state(x) && check_district(x)) && check_mid(x)) && check_last(x))
    {
        cout << "Yes ";
        follow_regex(x, patterns);
        return true;
    }
    return false;
}

void lucky_number(vector<vehicle_info> &vehicles, vector<number_pattern> &patterns)
{
    for(number_pattern pt : patterns)
        mp.insert({pt.type, pt.pattern});

    for(vehicle_info x : vehicles)
    {
        if(!is_valid_number_pattern(x, patterns))
            cout << "No\n";
    }

    if(to_print.size() >= 0){
        cout << to_print.size() << "\n";
        for(vehicle_info x : to_print)
            cout << x.number << " " << x.type << "\n";
        }
}

