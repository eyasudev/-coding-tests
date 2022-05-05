/**
MORSE CODE IN CPP
*/

#include <string>
#include <vector>
#include <cstdlib>


//create a tree data structure for the morse code 
typedef struct M_node{
  char letter;
  struct M_node* left;
  struct M_node* right;
}MorseNode;

MorseNode *initNode(char letter){
  MorseNode* node = (MorseNode*) calloc(1, sizeof(MorseNode));
  node->letter = letter;
  return node;
}

MorseNode *initNode_lr(char letter, MorseNode* left, MorseNode* right){
  MorseNode* node = (MorseNode*) calloc(1, sizeof(MorseNode));
  node->letter = letter;
  
  node->left = left; 
  node->right = right;
  return node;
}

//recursive function to traverse through the morse code tree 
char* interpretMorse(MorseNode* node, char* ret_str, char* m_code);


char *possibilities(const char *signals) {
  //create tree nodes
  //connect parent nodes to child nodes
  MorseNode* G = initNode('G');
  MorseNode* O = initNode('O');
  MorseNode* D = initNode('D');
  MorseNode* K = initNode('K');
  MorseNode* R = initNode('R');
  MorseNode* W = initNode('W');
  MorseNode* S = initNode('S');
  MorseNode* U = initNode('U');

  MorseNode* I = initNode_lr('I', S, U);
  MorseNode* A = initNode_lr('A', R, W);
  MorseNode* N = initNode_lr('N', D, K);
  MorseNode* M = initNode_lr('M', G, O);

  MorseNode* E = initNode_lr('E', I, A);
  MorseNode* T = initNode_lr('T', N, M);

  MorseNode* start = initNode_lr('0', E, T);

  int total_num_of_char = 15; //maximum number of possible characters
  char* ret_str = (char*)calloc(1, total_num_of_char);
  if (!ret_str) return ret_str;

  //traverse tree, searching for the last node
  interpretMorse(start, ret_str, (char*) signals);

  //pass the built string back 
  return ret_str;
}

#define null_char '\0'
char* interpretMorse(MorseNode* node, char* ret_str, char* m_code)
{
  if (!node)   return ret_str;
  
  if (*m_code == null_char){ //end of string 
    *ret_str = node->letter;
    ret_str++;
    return ret_str;
  } else if (*m_code == '.'){//left
    m_code++;
    return interpretMorse(node->left, ret_str, m_code);
  } else if (*m_code == '-'){//right
    m_code++;
    return interpretMorse(node->right, ret_str, m_code);
  } else if (*m_code == '?'){//indistinguishable
    m_code++;
    ret_str = interpretMorse(node->left, ret_str, m_code);
    return interpretMorse(node->right, ret_str, m_code);
  }
  
  return ret_str;
}




std::vector<std::string > possibilities(const std::string& word) {
  const char* c_string=word.c_str();
  char *ret_str = possibilities(c_string);
  std::vector<std::string> ret_vec; 
  
  int i = 0;
  while (ret_str[i] != '\0')
  {
    char c_[2] = {0,0};
    c_[0] = ret_str[i];
    std::string str = c_;
    ret_vec.push_back(str);
    i++;
  }
    
    return ret_vec;
}

