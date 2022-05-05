#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'minimalHeaviestSetA' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
 
//   read the text? 
// Switch
//  theme
// 1. Optimizing Box Weights (example question)
// An Amazon Fulfillment Associate has a set of items that need to be packed into two boxes. Given an integer array of the item weights (arr) to be packed, divide the item weights into two subsets, A and B, for packing into the associated boxes, while respecting the following conditions: 

 

// The intersection of A and B is null.
// The union A and B is equal to the original array.
// The number of elements in subset A is minimal.
// The sum of A's weights is greater than the sum of B's weights.
 

// Return the subset A in increasing order where the sum of A's weights is greater than the sum of B's weights. If more than one subset A exists, return the one with the maximal total weight.

 

// Example

// n = 5

// arr = [3, 7, 5, 6, 2]

 

// The 2 subsets in arr that satisfy the conditions for A are [5, 7] and [6, 7] :

// A is minimal (size 2)
// Sum(A) = (5 + 7) = 12 > Sum(B) = (2 + 3 + 6) = 11
// Sum(A) = (6 + 7) = 13 > Sum(B) = (2 + 3 + 5) = 10
// The intersection of A and B is null and their union is equal to arr.
// The subset A where the sum of its weight is maximal is [6, 7].
 

// Function Description

// Complete the minimalHeaviestSetA function in the editor below.

 

// minimalHeaviestSetA has the following parameter(s):

//     int arr[]: an integer array of the weights of each item in the set

 

// Returns:

//     int[] : an integer array with the values of subset A

 

// Constraints

// 1 ≤ n ≤ 105 
// 1 ≤ arr[i] ≤ 105 (where 0 ≤ i < n)
 

// Input Format For Custom Testing
// The first line contains an integer, n, denoting the number of elements in the array.

// Each line i of the n subsequent lines contains an integer, which is an element of arr.

 

// Sample Case 0
// Sample Input For Custom Testing

// STDIN     Function 
// -----     --------
// 6     →   arr[] size n = 6
// 5     →   arr[] = [5, 3, 2, 4, 1, 2]
// 3
// 2
// 4
// 1
// 2
// Sample Output

// 4
// 5
// Explanation

// n = 6

// arr = [5, 3, 2, 4, 1, 2]

 

// The subset of A that satisfies the conditions is [4, 5] :

// A is minimal (size 2)
// Sum(A) = (4 + 5) = 9 > Sum(B) = (1 + 2 + 2 +  3) = 8
// The intersection of A and B is null and their union is equal to arr.
// The subset A with the maximal sum is [4, 5].
 
 
#include <algorithm>

vector<int> minimalHeaviestSetA(vector<int> arr) {
    
    //SOrt the array in descending order (biggest first)
    sort(arr.begin(),arr.end(), greater<int>());
    
    //Calculate the sum of the input array 
    long long signed arr_sum = 0;
    vector<int>::iterator it;
    for (it = arr.begin(); it != arr.end(); ++it){
        arr_sum += *it;
        // std::cout << *it << ", ";
    }
    std::cout << std::endl << "sum: " << arr_sum << std::endl;
    
    //add the elements of input array to return array if the 
    //sum of return array is less than the rest of the weights
    long long signed A_sum = 0;
    vector<int> ret_vec; 
    for (it = arr.begin(); it != arr.end(); ++it){
        if (A_sum > (arr_sum - A_sum)) break;
        ret_vec.insert(ret_vec.begin(),*it); //inside at the beginning to change the order
        A_sum += *it;
    }
    return ret_vec;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    vector<int> result = minimalHeaviestSetA(arr);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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

