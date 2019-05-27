//
// @Author: songwei
// @Date: 2019-05-27 22:45
//
#include "mystring.h"
//#include <cstdio>

int main ()
{
  mystring str ("hello");
  mystring& str1=str;
  //mystring str1 = str;
  str1=str;
  cout << str << endl;
  cout << str1 << endl;
  //printf("%s\n",str.get_str ());
  //printf("%s\n",str1.get_str ());
}

