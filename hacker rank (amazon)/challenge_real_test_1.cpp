#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'countFamilyLogins' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY logins as parameter.
 */
char getRotateCharUp(char c){
    if (c == 'z')return 'a';
    return ++c; 
}

char getRotateCharDown(char c){
    if (c == 'a')return 'z';
    return --c; 
}

std::string getRotateStringUp(std::string s){
    std::string ret_str;
    for (char i: s){
        ret_str += getRotateCharUp(i);
    }
    return ret_str;
}

std::string getRotateStringDown(std::string s){
    std::string ret_str;
    for (char i: s){
        ret_str += getRotateCharDown(i);
    }
    return ret_str;
}

int countFamilyLogins(vector<string> logins) {
    
    //if all other string are the same as this increase pair count 
    long unsigned i = 0;
    long unsigned j = 0;
    long unsigned total_fam = 0;
    //loop through vector 
    for (i =0; i< logins.size(); i++)
    {
        //get copy of 
        std::string famUp = getRotateStringUp(logins[i]);
        std::string famDown = getRotateStringDown(logins[i]);
        //debug 
        // std::cout << "login: "<< logins[i] << ", fam: " << fam << std::endl;
        
        //loop through all the elements (from the beginning to find current login family)
        for (j = i+1; j < logins.size(); j++){
            if (logins[j] == famUp || logins[j] == famDown)
                total_fam++;
        }
    }
    std::cout << "total: " <<total_fam << std::endl;
    return total_fam;
}

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>
/*
 * Complete the 'findTotalPower' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY power as parameter.
 */
//  long unsigned powerCalc(vector<int> &vec, int i, int j){
     

//  }

int findTotalPower(vector<int> power) {
    long long unsigned overallSum = 0;
    
    int i = 0;
    int j = 0;
    int min_ = INT_MAX;
    int sum_ = 0;
    for (i=0; i < power.size(); i++)
    {
        min_ = INT_MAX;
        sum_ = 0;
        for (j=i; j < power.size(); j++){
            min_ = (power[j] < min_ )? power[j]: min_;
            sum_ += power[j];
            // std::cout << "min: " << min_ << ", sum: " << sum_;

            overallSum+=min_ * sum_;
            // std::cout << ", overall: " << overallSum << ", " << i << " " << j << std::endl;
        }
        
    }
    return (int) overallSum % (int)(pow(10, 9) +7);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string power_count_temp;
    getline(cin, power_count_temp);

    int power_count = stoi(ltrim(rtrim(power_count_temp)));

    vector<int> power(power_count);

    for (int i = 0; i < power_count; i++) {
        string power_item_temp;
        getline(cin, power_item_temp);

        int power_item = stoi(ltrim(rtrim(power_item_temp)));

        power[i] = power_item;
    }

    int result = findTotalPower(power);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

//bag cbh

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string logins_count_temp;
    getline(cin, logins_count_temp);

    int logins_count = stoi(ltrim(rtrim(logins_count_temp)));

    vector<string> logins(logins_count);

    for (int i = 0; i < logins_count; i++) {
        string logins_item;
        getline(cin, logins_item);

        logins[i] = logins_item;
    }

    int result = countFamilyLogins(logins);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
