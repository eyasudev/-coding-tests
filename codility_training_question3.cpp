// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

//removes the array's first and set itr to the next 
int take_first(vector<int> &A, vector<int>::iterator &itr){
    itr = A.begin(); //go back to the begining 
    int first = *itr; //reassign a new first to search for it's pair
    A.erase(itr);
    itr = A.begin();
    // printf("new First: %d, new itr: %d", first, *itr);
    return first;
}

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int ans = 0;
    //check if size is > 1
    vector<int>::iterator itr;
    int first = take_first(A, itr); //9,9,3 3 9 9[ 7]
    while(itr != A.end()){

        if (*itr == first){
            A.erase(itr);//remove previous first's pair

            // printf("\nLN %d ", __LINE__);
            first = take_first(A, itr);
            continue;
        }
        //loop also ends if after searching to the end the 
        //pair can't be found

        itr++;
    }
    return first;
}


*** PermMissingElem ***

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include<numeric>


int solution_(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    int n = A.size() + 1;
    uint64_t math_sum = n*(n+1)/2; //maths: sum of consequtive nums with size n, then add the n + 1 element

    // printf("SUMS %ld \n", math_sum);
    while(!A.empty()){
        math_sum -= (uint64_t)A.back();
        A.pop_back();
    }
    // printf("SUMS %ld \n", math_sum);
    
    // return math_sum - vec_sum;
    return math_sum;
}


int solution(vector<int> &A) {
    // vector<int> B;
    // int n = 120001;
    // int missing_val = 10;
    // do{
    //     if (n == missing_val) continue;
    //     B.push_back(n);
    // }while (--n);

    // printf("%s: ret: %ld\n", __FUNCTION__, solution_(B));
    
    return solution_(A);
}


*** TapeEquilibrium ***

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <math.h>
#include<limits.h> 

int solution(vector<int> &A) {
    long sumAllElements = 0;
    int len = A.size();
    for(int i=0; i<len; i++) {
      sumAllElements += A[i];
    }
   
    int minDifference = INT_MAX;
    int currentDifference = INT_MAX;
    long sumFirstPart = 0;
    long sumSecondPart = 0;

    for(int p=0; p< len-1; p++) {
      sumFirstPart += A[p];
      sumSecondPart = sumAllElements - sumFirstPart;
      currentDifference = (int) std::abs(sumFirstPart - sumSecondPart);
      minDifference = std::min(currentDifference, minDifference);
    }
    return minDifference;

}


*** FrogRiverOne *** 
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <map>
int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    std::map<int, int> my_map; 
    int count = 0;
    for (auto i : A){
        // printf("TEST: %d %d\n", i, my_map.size());
        if (i <= X) my_map[i] = i;
        if (my_map.size() == X ) break;
        count++;     
    }

    return (count >= A.size())? -1: count;
}

*** PermCheck *** 

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <numeric>
#include <map>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    //using sum of consequtive 
    int n = A.size();
    int64_t sum = n * (n+1) /2;
    int vec_max = 0;
    int64_t vec_sum  = 0;
    std::vector<int>::iterator itr; 
    std::map<int, int> dup_hndlr_map; 
    for (itr = A.begin(); itr != A.end(); itr++){
        vec_sum += *itr;
        if (vec_max < *itr) vec_max = *itr;
        dup_hndlr_map[*itr] = *itr;
        // std::accumulate(A.begin(), A.end(), 0);
    }
    
    // printf("SUM: 1: %d, 2: %d", sum, vec_sum );
    return ( (!(sum - vec_sum)) 
    && (!(vec_max - n)) 
    && (!(dup_hndlr_map.size() - n)) );
    //just a complex operation instead of using conditions
    //the first bracket returns 1 if both sum and vec_sum are the same
    //the second bracket returns 1 if both vec_max vaue and n(size of vec) are the same
    //the third bracket returns 1 if the size of the dup handler map is the same as the vector 
    //the whole return value is a function if both are true
}


*** MaxCounters *** 77%

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> out_vec(N); 

    int out_vec_max=0;
    bool set_max = false;
    for (auto i : A){
        if (i == N+1){//if max counter is seen, only set the flag
            set_max = true;
        }
        else  {
            if (set_max) {//for improving speed, only set all max when you need to increase the value of one 
                fill(out_vec.begin(), out_vec.end(),out_vec_max);
                set_max = false;
            }
                
            out_vec[i-1] ++;//increase new index 

            //check if newly increased index is the max 
            if (out_vec_max < out_vec[i-1]) out_vec_max = out_vec[i-1];
        }
    }

    //ensure this is done one last time 
    if (set_max) {//for improving speed, only set all max when you need to increase the value of one 
        fill(out_vec.begin(), out_vec.end(),out_vec_max);
        set_max = false;
    }

    return out_vec;
}

*** Misssing Integer *** 
Find the smallest positive integer that does not occur in a given sequence.
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <map>
#include <limits.h>
#include <bits/stdc++.h>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    std::map<int, int> my_map; 
    int min_val = 1; //INT_MAX;
    std::sort(A.begin(), A.end());
    for (auto i : A){
        if (min_val < i) break;
        min_val = (i<0)? 1:i+1; 
    }
    return min_val;
}

