#include <iostream>

namespace utils {

class IntegerSequence
{
  protected:

    int counter;

    int end,
        step;

    void parameterValidityCheck (const int _start, const int _end, const int _step);

  public:

    IntegerSequence (const int _start, const int _end, const int _step = 1)
    {
      parameterValidityCheck (_start, _end, _step);

      counter = _start;
      end = _end;
      step = _step;
    }

    bool operator () (int& i);

    void operator () (const int _start, const int _end, const int _step = 1);

    ~IntegerSequence ()
    {
    }
};

}
