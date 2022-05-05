// //task 2
// #include <numeric>

// void fill_arr(map<int, int> &arr)
// {
//     for (int i=0;i<9;i++){
//         arr[i] = i+1;
//     }
// }

// vector<bool> solution(vector<vector<int>> numbers) {
//     int hor_pos = numbers[0].size(); //n
//     vector<bool> slide_win; 
//     int slide_pos = hor_pos-2;
    
//     map<int, int> expected_arr_9;
//     map<int, int> left_arr_9;
//     fill_arr(expected_arr_9);
    
//     //loop through sliding/horizontal positions
//     for(int i =0; i< slide_pos; i++)
//     {
//         //do a loop for 3 x 3 
//         int temp_sum = 0;
//         for (int j=0; j < 3; j++){ //vertical loop 
//             for (int k=0; k < 3; k++){ //horizontal loop
//                 left_arr_9[numbers[j][k+i] - 1] = numbers[j][k+i];
//             }
//         }
        
//         if (left_arr_9.size() < expected_arr_9.size())
//             slide_win.push_back(false);
//         else slide_win.push_back(true);
        
//         left_arr_9.clear();   
//     }
    
//     return slide_win;
// }

// //task 3
#include <limits.h>
int solution(vector<vector<int>> m, int k) {
    vector<vector<int>> vect_sum;
    int max_max = 0;//maximum max
    
    int hor_pos = m[0].size(); //horizontal position
    int ver_pos = m.size(); //vertical position
    
    int slide_pos_h = hor_pos - k;
    int slide_pos_v = ver_pos - k;
    
    vector<int> vect_sum_int;
    int temp_sum = 0;
    for(int i =0; i< slide_pos_h; i++)//horizontal
    {
        for(int j =0; j< slide_pos_v; j++)//vertical
        {
            //loop for k x k matrix
            
            for (int a=0; a < k; a++){ //horizontal loop        
                for (int b=0; b < k; b++){ //vertical loop 
                    vect_sum_int.push_back(m[j+b][i+a]);
                    temp_sum += m[j+b][i+a];
                }
            }
            
            if (max_max < temp_sum ) max_max = temp_sum;
            vect_sum_int.push_back(temp_sum);//add sum to the end 
            vect_sum.push_back(vect_sum_int);
            
            vect_sum_int.clear();
            temp_sum=0;
        }
        
    }
    
    //get the max of the vectors into a map 
    map<int, int> max_map; 
    for (int i=0; i< vect_sum.size(); i++){
        if (vect_sum[i].back() == max_max){
            //add elements to map 
            for (int j=0; j < vect_sum[i].size()-1;j++)
            {
                max_map[vect_sum[i][j]]  = vect_sum[i][j];            
            }
            
        }       
        
    }
    
    int ret = 0;
    for (auto i : max_map){
        ret += i.second;
    }
    return ret;
    
//find the 
//create a vector of vector that stores all array and max at last index

}
