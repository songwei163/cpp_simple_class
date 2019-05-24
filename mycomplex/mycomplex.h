//
// @Author: songwei
// @Date: 2019-05-24 14:25
//

#ifndef _MYCOMPLEX_H_
#define _MYCOMPLEX_H_

class mycomplex;
mycomplex&
__doapl (mycomplex *ths, const mycomplex& r);
mycomplex&
__doami (mycomplex *ths, const mycomplex& r);
mycomplex&
__doaml (mycomplex *ths, const mycomplex& r);

class mycomplex {
 public:
  mycomplex (double r = 0, double i = 0)
      : re (r), im (i)
  { }

 public:
  //成员函数操作符重载，return by reference
  mycomplex& operator+= (const mycomplex&);
  mycomplex& operator-= (const mycomplex&);
  mycomplex& operator*= (const mycomplex&);
  //mycomplex& operator/= (const mycomplex&);

 public:
  double real () const
  { return re; }
  double imag () const
  { return im; }
 private:
  double re, im;

  //友元函数，访问私有数据成员
  //1-->返回值为什么不设计为void
  //  答： 体现级联
  //2-->return value by reference
  //  答： 优先以引用方式返回的，原因：函数参数列表第一个参数接收this指针，返回*this
  //  另一个版本，第一个参数以引用方式接收*this，直接以引用方式返回ths,此时ths就是*this的别名
  friend mycomplex& __doapl (mycomplex *ths, const mycomplex& r);
  friend mycomplex& __doami (mycomplex *ths, const mycomplex& r);
  friend mycomplex& __doaml (mycomplex *ths, const mycomplex& r);
};

/*另一种写法*/
#if 0

inline mycomplex& __doapl (mycomplex& ths, const mycomplex& r)
{
  ths.re += r.re;
  ths.im += r.im;
  return ths;
}

inline mycomplex&
mycomplex::operator+= (const mycomplex& r)
{
  return __doapl (*this, r);
}

#endif

inline mycomplex&
__doapl (mycomplex *ths, const mycomplex& r)
{
  ths->re += r.re;
  ths->im += r.im;
  return *ths;
}

inline mycomplex&
mycomplex::operator+= (const mycomplex& r)
{
  return __doapl (this, r);
}

inline mycomplex&
__doami (mycomplex *ths, const mycomplex& r)
{
  ths->re -= r.re;
  ths->im -= r.im;
  return *ths;

}

inline mycomplex&
mycomplex::operator-= (const mycomplex& r)
{
  return __doami (this, r);
}

inline mycomplex&
__doaml (mycomplex *ths, const mycomplex& r)
{
  double f = ths->re * r.re - ths->im * r.im;
  ths->im = ths->re * r.im + ths->im * r.re;
  ths->re = f;
  return *ths;
}

inline mycomplex&
mycomplex::operator*= (const mycomplex& r)
{
  return __doaml (this, r);
}

/*采用公有接口访问*/
inline double
imag (const mycomplex& x)
{
  return x.imag ();
}

inline double
real (const mycomplex& x)
{
  return x.real ();
}


/*非成员函数运算符重载*/
/*return  by value */
/*无名临时对象，体现表达式是有结果的*/
inline mycomplex
operator+ (const mycomplex& x, const mycomplex& y)
{
  return mycomplex (real (x) + real (y), imag (x) + imag (y));
}

inline mycomplex
operator+ (const mycomplex& x, double y)
{
  return mycomplex (real (x) + y, imag (x));
}

inline mycomplex
operator+ (double x, const mycomplex& y)
{
  return mycomplex (x + real (y), imag (y));
}

inline mycomplex
operator- (const mycomplex& x, const mycomplex& y)
{
  return mycomplex (real (x) - real (y), imag (x) - imag (y));
}

inline mycomplex
operator- (const mycomplex& x, double y)
{
  return mycomplex (real (x) - y, imag (x));
}

inline mycomplex
operator- (double x, const mycomplex& y)
{
  return mycomplex (x - real (y), -imag (y));
}

inline mycomplex
operator* (const mycomplex& x, const mycomplex& y)
{
  return mycomplex (real (x) * real (y) - imag (x) * imag (y),
                    real (x) * imag (y) + imag (x) * real (y));
}

inline mycomplex
operator* (const mycomplex& x, double y)
{
  return mycomplex (real (x) * y, imag (x) * y);
}

inline mycomplex
operator* (double x, const mycomplex& y)
{
  return mycomplex (x * real (y), x * imag (y));
}

mycomplex
operator/ (const mycomplex& x, double y)
{
  return mycomplex (real (x) / y, imag (x) / y);
}

inline mycomplex
operator+ (const mycomplex& x)
{
  return x;
}

inline mycomplex
operator- (const mycomplex& x)
{
  return mycomplex (-real (x), -imag (x));
}

inline bool
operator== (const mycomplex& x, const mycomplex& y)
{
  return real (x) == real (y) && imag (x) == imag (y);
}

inline bool
operator== (const mycomplex& x, double y)
{
  return real (x) == y && imag (x) == 0;
}

inline bool
operator== (double x, const mycomplex& y)
{
  return x == real (y) && imag (y) == 0;
}

inline bool
operator!= (const mycomplex& x, const mycomplex& y)
{
  return real (x) != real (y) || imag (x) != imag (y);
}

inline bool
operator!= (const mycomplex& x, double y)
{
  return real (x) != y || imag (x) != 0;
}

inline bool
operator!= (double x, const mycomplex& y)
{
  return x != real (y) || imag (y) != 0;
}

#include <cmath>

inline mycomplex
polar (double r, double t)
{
  return mycomplex (r * cos (t), r * sin (t));
}

inline mycomplex
conj (const mycomplex& x)
{
  return mycomplex (real (x), -imag (x));
}

inline double
norm (const mycomplex& x)
{
  return real (x) * real (x) + imag (x) * imag (x);
}

#endif //_MYCOMPLEX_H_
