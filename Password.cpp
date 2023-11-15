#include "Password.h"
#include <string>

using std::string;
Password::Password(){
  pass_history.push_back("ChicoCA-95929");
}
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

  /*
  receives a password and sets the latest in pass_history to it if and only
  if it meets all criteria:
    1. The password is at least 8 letters long
    2. It has no more than 3 of the same leading characters
    3. It has mixed case (at least one upper case and at least one lower case)
    4. It was not a previous password in the history
  */
  void Password::set(string phrase){
    if(phrase.size()>7){
      if(count_leading_characters(phrase)<=3){
        if(has_mixed_case(phrase)==1){
          for(int i = 0; i< pass_history.size();i++){
            if(pass_history[i]==phrase)
              return;
          }  
          pass_history.push_back(phrase);
          return;
        }
      }
    }
    return;
  }

  /*
  receives a string and authenticates it against the latest password in the
  pass_history, returning true for an exact match or false when it does not match
  or if a password has not been set.
  */
  bool Password::authenticate(string phrase){
    if(pass_history.back()==phrase)
      return true;
    else
      return false;
  }

