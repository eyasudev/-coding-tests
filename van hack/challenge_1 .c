/**
BASE 64 converter in C 
*/

#include <stdlib.h>
#include <string.h>

static const char base64_map[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                               "abcdefghijklmnopqrstuvwxyz"
                               "0123456789+/";


char* to_base64( char* str )
{
  //allocate memory for the str to write out 
  char* ret_str = calloc(2, strlen(str));
  int ret_str_len = 2 * strlen(str);
  printf("str in len: %d, out len: %d, str out ptr: %x", strlen(str), ret_str_len, ret_str);
  
  if (!ret_str) return ret_str; //return null pointer if 
  
  //loop through the string to convert 
  char* ret_str_head = ret_str;
  int i=0;
  int j = 0;
  char char_array_3[3];
  char char_array_4[4];
  while(*str != '\0'){
    char_array_3[i++] = *(str++);
    if (i == 3){
      char_array_4[0] = (char_array_3[0] & 0xfc) >> 2; 
      char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4); 
      char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
      char_array_4[3] = (char_array_3[2] & 0x3f) ; 
      
      for (i=0; (i<4); i++) *(ret_str++) = base64_map[char_array_4[i]];
      i=0;
    }
  }
  
  if (i){
    for (j = i; j<3; j++)
      char_array_3[j] = '\0';
    
    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2; 
    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4); 
    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
    
    for (j = 0; (j<i+1); j++)
      *(ret_str++) = base64_map[char_array_4[j]];
    
    while(i++<3)
      *(ret_str++) = '=';
    
  }
    
  return ret_str_head;
}