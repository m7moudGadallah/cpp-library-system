#ifndef LIBRARY_SYSTEM_HPP_
#define LIBARY_SYSTEM_HPP_

#include "../include/system-action-handler.hpp"

class LibrarySystem {
  private:
    SystemActionHandler actionHandler;
  public:
    void run();
};

#endif // LIBRARY_SYSTEM_HPP_