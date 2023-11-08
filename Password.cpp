#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;

  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

bool Password::has_mixed_case(string phrase){
  int upper = 0;
  int lower = 0;
  for(int i=0;i<phrase.size();i++){
    if(phrase[i] >= 'A' && phrase[i] <= 'Z'){
      upper = 1;
    }
  }
  for(int i=0;i<phrase.size();i++){
    if(phrase[i] >= 'a' && phrase[i] <= 'z'){
      lower = 1;
    }
  }
  if(upper == 1 and lower == 1){
    return true;
  }
  return false;
}
/* kevin's implementation
bool Password::has_mixed_case(string pass){
  bool lower = false;
  bool upper = false;
  for(int i = 0; i < pass.size(); i++){
    if( pass[i] >= 'A' && pass[i] <= 'Z' ){
      upper = true;
    }
    else if( pass[i] < 'z'){
      lower = true;
    }
  }
  return upper && lower;
/

//anthony's implementation
bool Password::has_mixed_case(string phrase){
  bool upper = false;
  bool lower = false;
  int index = 0;

  while( index < phrase.length() ){
    if(isupper(phrase[index])){
      upper = true;
    }
    else if(islower(phrase[index])){
      lower = true;
    }
    index++;
  }
  if(upper == true && lower == true){
    return true;
  }
  return false;
}*/
