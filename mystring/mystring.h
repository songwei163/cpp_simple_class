//
// @Author: songwei
// @Date: 2019-05-27 22:36
//

#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iostream>
#include <cstring>
using namespace std;

class mystring;
ostream& operator<< (ostream&, mystring&);

class mystring {
 public:
  mystring (const char *str = nullptr);
  mystring (const mystring&);
  mystring& operator= (const mystring&);
  ~mystring ();
 public:
  char *get_str () const;
 private:
  char *_data;
  friend ostream& operator<< (ostream&, mystring&);
};

inline mystring::mystring (const char *str)
{
  if (str != nullptr)
    {
      _data = new char[strlen (str) + 1];
      strcpy (_data, str);
    }
  else
    {
      //  未指定初值
      _data = new char[1];
      *_data = '\0';
    }
}

inline mystring::mystring (const mystring& str)
{
  _data = new char[strlen (str._data) + 1];
  strcpy (_data, str._data);
}

inline mystring& mystring::operator= (const mystring& str)
{
  //  不仅仅是效率问题，更是为了检测自我赋值
  if (this == &str)
    return *this;

  delete[] _data;
  _data = new char[strlen (str._data) + 1];
  strcpy (_data, str._data);
  return *this;
}

inline mystring::~mystring ()
{
      delete[]_data;
}

inline char *mystring::get_str () const
{
  return _data;
}

ostream& operator<< (ostream& os, mystring& str)
{
  os << str.get_str ();
  return os;
}

#endif //_MYSTRING_H_
