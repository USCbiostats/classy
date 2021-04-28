#include <stdlib.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <memory>

#ifndef CLASSY3_H
#define CLASSY3H

template<typename T>
class classy3 {

private:
  std::shared_ptr< T > x;

public:
  classy3(std::shared_ptr< T > x_): x(x_) {};
  ~classy3() {
    // printf("killing classy3...\n");
  };

  double sum();
  int count();
  int count_if_less(double y);
  T get();
  void get_address() const;

};



#endif
