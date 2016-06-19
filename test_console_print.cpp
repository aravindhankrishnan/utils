#include <iostream>
using namespace std;

#include "console_print.h"

int main (int argc, char *argv[])
{
  utils::console_print ("info") << "Hello world " << endl;
  utils::console_print ("warn") << "It's getting very hot these days ..\n";
  utils::console_print ("error") << "Do not go out without carrying a bottle of water ..\n";
  utils::console_print << "Message without any prefix ..\n";
  return 0;
}
