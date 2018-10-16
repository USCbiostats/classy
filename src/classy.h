#include <stdlib.h>
#include <iostream>
#include <vector>
#include <numeric>

#ifndef CLASSY_H
#define CLASSY_H

class classy {

private:
  std::vector< double > x;

public:
  classy(std::vector< double > x_): x(x_) {};
  ~classy() {
    std::cout << "I don't want to dieee!!!\n" ;
  };

  double sum();
  int count();
  int count_if_less(double y);
  std::vector< double > get();


};

#endif
