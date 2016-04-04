#include "integer_sequence.h"

namespace utils {

bool IntegerSequence::operator () (int& i)
{
  i = counter;
  counter += step;

  if (i > end) {
    return false;
  }

  return true;
}

}
