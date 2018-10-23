#ifndef PROJETO_SO_2_DEBUG
#define PROJETO_SO_2_DEBUG

#include <iostream> // std::cout

#ifdef DEBUG
#  define debug_message(message) \
  do { std::cout << "[DEBUG] " << message << std::endl; } \
  while (0);
#else
#  define debug_message(...)
#endif

#endif // PROJETO_SO_2_DEBUG
