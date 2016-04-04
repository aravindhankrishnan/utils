#include "integer_sequence.h"

namespace utils {

void IntegerSequence::operator () (const int _start, const int _end, const int _step)
{
  counter = _start;
  end = _end;
  step = _step;
}

bool IntegerSequence::operator () (int& i)
{
  if (counter > end) {
    return false;
  }

  i = counter;
  counter += step;
  return true;
}

}
