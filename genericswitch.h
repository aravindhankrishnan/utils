#pragma once

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

#include <iostream>
using namespace std;

#define BEGIN_GENERIC_SWITCH_(type, obj) type _i_n_p_u_t_ = obj; if (0) {
#define CASE_(val) } else if (_i_n_p_u_t_ == val) {
#define DEFAULT  } else {
#define END_GENERIC_SWITCH }
