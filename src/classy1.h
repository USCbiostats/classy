#include <stdlib.h>
#include <iostream>
#include <vector>
#include <numeric>

#ifndef CLASSY1_H
#define CLASSY1_H

class classy1 {

private:
  std::vector< double > x;

public:
  classy1(std::vector< double > x_): x(x_) {};
  ~classy1() {
    std::cout << "I don't want to dieee!!!\n" ;
  };

  double sum();
  int count();
  int count_if_less(double y);
  std::vector< double > get();


};

#endif
