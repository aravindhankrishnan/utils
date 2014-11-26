#pragma once

// string str = "val3";
// BEGINSTRINGSWITCH_ (str)
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
//  ENDSTRINGSWITCH

#include <iostream>
using namespace std;

#define BEGINSTRINGSWITCH_(str) string _i_n_p_u_t_ = str; if (0) {
#define CASE_(val) } else if (_i_n_p_u_t_.compare (val) == 0) {
#define DEFAULT  } else {
#define ENDSTRINGSWITCH }
