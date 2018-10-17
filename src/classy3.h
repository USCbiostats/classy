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
    std::cout << "I don't want to dieee!!!\n" ;
  };

  double sum();
  int count();
  int count_if_less(double y);
  T get();


};



#endif
