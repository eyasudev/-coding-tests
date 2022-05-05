#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'countGroups' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY related as parameter.
 */

// BETACan’t read the text? 
// Switch
//  theme
// 2. Gifting Groups (example question)
// At Audible, a subscriber can gift an audiobook from his/her library to any other non-subscriber to kick start their audiobook journey. The first time subscriber can receive up to a maximum of N audiobooks from their friends/relatives. When a non-subscriber receives an audiobook, we can infer that the two may be related. Similarly, if the non-subscriber receives gifted books from two other subscribers, we can infer that all of them are related and the three of them form a group. More formally, a group is composed of all of the people who know one another, whether directly or transitively. Audible would like your help finding out the number of such distinct groups from the input data.

 

// Example

// Consider the following input matrix M:

// 110

// 110

// 001



// Every row corresponds to a subscriber and the value M[i][j] determines if j was gifted a book by i. In the above example, user 0 has gifted a book to user 1 and so they are connected [0][1], while person 2 has not received a book from anyone or gifted book to anyone. Therefore, there are 2 groups.

// M[i][j] = 1 if i == j (Each of the people is known to self)

 

// Determine the number of groups represented in a matrix.

 

// Note: The method signatures may vary slightly depending on the requirements of the chosen language. For example, C language will have an argument that represents the number of rows and columns in the matrix. Also, Java will receive a list rather than an array.

 

// Function Description

// Complete the function countGroups in the editor below.

 

// countGroups has the following parameter(s):

//     int related[n]:  an array of strings of binary digits related[i] that represent connections of people

 

// Returns:

//     int: an integer that represents the number of groups of people

 

// Constraints

// 1 ≤ n ≤ 300
// 0 ≤ i < n
// |related| = n
// Each related[i] contains a binary string of n zeros and ones. related is a square matrix.
// Input Format for Custom Testing
// Input from stdin will be processed as follows and passed to the function.

 

// The first line contains an integer n, the size of the square association matrix, related.

// The next n lines each contain a binary string of length n that represents a row in the matrix, related[i] where 0 ≤ i < n.

// Sample Case 0
// Sample Input

// STDIN     Function
// -----     -----
// 4      →  size of related[] n = 4
// 1100   →  related = ['1100', '1110', '0110', '0001']
// 1110
// 0110
// 0001
 

// Sample Output

// 2
 

// Explanation

// Squares highlighting a connection between two people are highlighted in green. Each of the people is known to self, so they are highlighted in gray.



// There are n = 4 people numbered related[0] through related[3].

// There are 2 pairs who directly know each another: (related[0], related[1]) and (related[1],related[2]). Because a relation is transitive, the set of people {related[0], related[1], related[2]} is considered a single group.

// The remaining person, related[3], does not know any other people and is a separate group: {related[3]}.

// There are a total of 2 groups.

// Sample Case 1
// Sample Input

// STDIN     Function
// -----     -----
// 5      →  size of related[] n = 5
// 10000  →  related = ['10000', '01000', '00100', '00010', '00001']
// 01000
// 00100
// 00010
// 00001
 

// Sample Output

// 5
 

// Explanation



// No direct relationships are shown so there are 5 groups: {related[0]}, {related[1]}, {related[2]}, {related[3]}, and {related[4]}.


int countGroups(vector<string> related) {
    //create a vector to store group number
    vector<int> related_grp(related.size(), -1);
    
    //create a total group number variable 
    int total_num_of_grps = 0;
    
    //loop through vector and change the group number of other people who are related. i.e. add them to your group if you have one, or first create your own group if you don't 
    int i = 0;
    for (i=0; i < related.size(); i++)
    {
        //check if the current number has a group yet
        if (related_grp[i] == -1){
            total_num_of_grps++;
            related_grp[i] = total_num_of_grps;
        }
        std::cout << "P"<<i << ": " << related[i] << ", grp: " << related_grp[i] << std::endl;
        //loop through all its character to see who he has a relationship with it
        int j = 0;
        std::string people = related[i];
        for (j=0; j<people.size(); j++){
            // if (j == i) continue;//ignore if its your index
            if (people[j] == '1') related_grp[j] = related_grp[i];
        }
        
    }
    std::cout << "Total groups: " << total_num_of_grps << std::endl;
    return total_num_of_grps;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string related_count_temp;
    getline(cin, related_count_temp);

    int related_count = stoi(ltrim(rtrim(related_count_temp)));

    vector<string> related(related_count);

    for (int i = 0; i < related_count; i++) {
        string related_item;
        getline(cin, related_item);

        related[i] = related_item;
    }

    int result = countGroups(related);

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
