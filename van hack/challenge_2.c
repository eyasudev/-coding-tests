/**
MORSE CODE IN C
*/

#include <stdlib.h>
#include <string.h>

//question 
// Overview
// Morse Code is delivered in a series signals which are referred to as dashes (-) or dots (.). To keep things simple for the purposes of this challenge we'll only decode letters with a maximum length of three signals.

// Morse Code Graph showing a perfect binary tree rooted at a node labeled Start, with two subtrees: the left subtree is labeled Dot and the right subtree is labeled Dash. In the Dot subtree, the nodes are labeled as follows: E is the left child of the Start node. E has left child I and right child A, I has left child S and right child U, A has left child R and right child W. In the Dash subtree, the nodes are labeled as follows: T is the right child of the Start node, T has left child N and right child M, N has left child D and right child K, M has left child G and right child O

// Here is the Morse Code dichotomic search table courtesy of Wikipedia

// Morse Code Examples
// -.- translates to K
// ... translates to S
// .- translates to A
// -- translates to M
// . translates to E

// Background
// You've started work as morse code translator. Unfortunately some of the signals aren't as distinguishable as others and there are times where a . seems indistinguishable from -. In these cases you write down a ? so that you can figure out what all the posibilities of that letter for that word are later.

// Task
// Write a function possibilities that will take a string signals and return an array of possible characters that the Morse code signals could represent.

// Specification
// possibilities(signals)
// Parameters
// signals: std::string - The Morse code signals that needs to be parsed. The may contain one or more unknown signals (?).

// Return Value
// std::list<std::string> - The list of possible letters for the given group of signals. Letters will always be ordered from how they appear on the chart, from left to right.

// Constraints
// There will be no more than 3 characters within signals.

// 0 - 3 unknown signals may be given.

// Examples
// signals	Return Value
// "."	["E"]
// "-"	["T"]
// "-."	["N"]
// "..."	["S"]
// "..-"	["U"]
// "?"	["E","T"]
// ".?"	["I","A"]
// "?-?"	["R","W","G","O"]



/**
 * @param const char *signals a string of up to 3 Morse
 *     code characters and/or the wildcard '?'.                   
 * @return char * a pointer to a heap-allocated null-
 *     terminated string representing all characters 
 *     `signals` could represent.
 */

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
  char* ret_str = calloc(1, total_num_of_char);
  if (!ret_str) return ret_str;

  //traverse tree, searching for the last node
  interpretMorse(start, ret_str, signals);

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
  

}


