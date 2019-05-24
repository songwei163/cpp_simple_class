#include <iostream>
#include "mycomplex.h"

using namespace std;

/*not return void*/
/*not return by const reference*/
/*体现级联，向ostream丢输出，故不能为const*/
ostream&
operator << (ostream& os, const mycomplex& x)
{
  return os << '(' << real (x) << ',' << imag (x) << ')';
}

int main()
{
  mycomplex c1(2, 1);
  mycomplex c2(4, 0);

  cout << c1 << endl;
  cout << c2 << endl;

  cout << c1+c2 << endl;
  cout << c1-c2 << endl;
  cout << c1*c2 << endl;
  cout << c1 / 2 << endl;

  cout << conj(c1) << endl;
  cout << norm(c1) << endl;
  cout << polar(10,4) << endl;

  cout << (c1 += c2) << endl;

  cout << (c1 == c2) << endl;
  cout << (c1 != c2) << endl;
  cout << +c2 << endl;
  cout << -c2 << endl;

  cout << (c2 - 2) << endl;
  cout << (5 + c2) << endl;

  return 0;
}
