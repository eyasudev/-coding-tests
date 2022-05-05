/**
COLUMN SORT 
*/

// Task
// In this challenge, your task is to sort the columns of a CSV file. The contents of the CSV will be provided to you as a string adhering to the description below.

// The columns are separated by commas (,)
// The rows are separated by a newline (\n)
// The first line contains the names of the columns
// A blank space counts as an empty string
// Treat every value as a string
// The CSV has a dyamic number of rows and columns
// Write a method that sorts the columns by the names of the columns alphabetically, and case-insensitive.

// Specification
// sort_csv_columns(csv_data)
// Takes comma separated values and sorts it alphabetically

// Parameters
// csv_data: std::string - Unsorted CSV

// Return Value
// std::string - Sorted CSV

// Example Input
// Raw Input:

// Beth,Charles,Danielle,Adam,Eric\n
// 17945,10091,10088,3907,10132\n
// 2,12,13,48,11
// As a Table:

// Beth	Charles	Danielle	Adam	Eric
// 17945	10091	10088	3907	10132
// 2	12	13	48	11
// Example Output
// Raw output:

// Adam,Beth,Charles,Danielle,Eric\n
// 3907,17945,10091,10088,10132\n
// 48,2,12,13,11
// As a Table:

// Adam	Beth	Charles	Danielle	Eric
// 3907	17945	10091	10088	10132
// 48	2	12	13	11
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
// #include <cstdint>
// #include <cstdbool>

bool compare_str_pair(std::pair<std::string, int> p1, std::pair<std::string, int> p2)
{  
  //convert both strings to lowercase in order to avoid case 
  //sensitive comparism 
  std::string s1 = "";
  std::string s2 = "";
  for (auto c: p1.first)
    s1 += tolower(c);
  for (auto c: p2.first)
    s2 += tolower(c);
    
  return s1 < s2;
}

std::string sort_csv_columns(const std::string& csv_data) {
  //get header 
  std::stringstream sstr(csv_data);
  std::vector<std::pair<std::string, int>> hd_vec;
  std::string hd_str;
  
  getline(sstr, hd_str, '\n');
  std::cout << hd_str << std::endl;
  
  //split header in to vector of columns string
  sstr.str(hd_str); //use the same stringstream object
  int i = 0;
  while (sstr.good()){
    //use a pair to keep the index of the unsorted header
    std::pair<std::string, int> col_index_hd;
    getline(sstr, col_index_hd.first, ',');
    col_index_hd.second = i;
    hd_vec.push_back(col_index_hd);
    std::cout << hd_vec.back().first << ": " << hd_vec.back().second << "; ";
    i++;
  }
  
  //sort vector 
  std::sort(hd_vec.begin(), hd_vec.end(), compare_str_pair);

    //DEBUGGING 
    std::cout << std::endl <<"Sorted vector: " << std::endl;
    std::vector<std::pair<std::string, int>>::iterator it;
    for (it = hd_vec.begin(); it != hd_vec.end(); ++it)
      std::cout << it->first << ": " << it->second << "; ";
    std::cout << std::endl;
  
  /** build return string (stream) */
  std::stringstream ret_sstrm;   
  //loop through each line 
  std::stringstream sstr_2(csv_data); 
  int j = 0; //used to manage the last '\n'
  while (sstr_2.good()){
    if (j){//terminate each line
      ret_sstrm << "\n";
      std::cout << "\n";
    }
    j++;
    
    std::string csv_line;
    getline(sstr_2, csv_line, '\n');

    //then loop through each column
    std::stringstream sstr_line(csv_line);
    std::vector<std::string> vec_line;
    //split the line string in vector of strings
    while(sstr_line.good()){
      std::string csv_cell;
      getline(sstr_line, csv_cell, ',');
      vec_line.push_back(csv_cell);
      
    }
    //use the index in header vector to push vec_line into string stream
    for (it = hd_vec.begin(); it != hd_vec.end(); ++it){
      ret_sstrm << vec_line[it->second] << (((it+1) == hd_vec.end())? "":","); 
      std::cout << vec_line[it->second] << (((it+1) == hd_vec.end())? "":","); 
    }
      

  }
  
  
  return ret_sstrm.str();
}