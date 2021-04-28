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
    // printf("killing classy1...\n");
  };

  double sum();
  int count();
  int count_if_less(double y);
  std::vector< double > get();
  void get_address() const;


};

#endif
