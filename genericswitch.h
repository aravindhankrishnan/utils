#pragma once

#include <iostream>

#define BEGIN_GENERIC_SWITCH_(type, obj) type& _i_n_p_u_t_ = obj; if (0) {
#define CASE_(val) } else if (_i_n_p_u_t_ == val) {
#define DEFAULT_  } else {
#define END_GENERIC_SWITCH_ }

// -------------- EXAMPLE 1 ----------
// string str = "val3";
// BEGIN_GENERIC_SWITCH_(string, str)
//      CASE_("val1")
//         
//
//      CASE_("val2")
//
//
//      CASE_("val3")
//
//      DEFAULT
//
//  END_GENERIC_SWITCH


//#include <iostream>
//using namespace std;
//
// -------------- EXAMPLE 2 ----------
//
//class MyClass
//{
//  protected:
//    int x,
//        y;
//
//  public:
//
//    MyClass ()
//    {
//      x = 0;
//      y = 0;
//    }
//
//    MyClass (int x_, int y_)
//    {
//      x = x_;
//      y = y_;
//    }
//
//    bool operator == (const MyClass& obj) 
//    {
//      return (obj.x == this->x) and (obj.y == this->y);
//    }
//
//    ~MyClass ()
//    {
//    }
//
//  private:
//};
//
//int main (int argc, char *argv[])
//{
//  MyClass obj (7, 7);
//
//  BEGIN_GENERIC_SWITCH_(MyClass, obj)
//
//    CASE_(MyClass (5, 7))
//        cout << "First ..\n";
//
//    CASE_(MyClass (7, 7))
//        cout << "Second ..\n";
//
//    DEFAULT_
//        cout << "None ..\n";
//
//  END_GENERIC_SWITCH_
//
//  return 0;
//}
