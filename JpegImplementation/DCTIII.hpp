#ifndef DCTIII_HPP
#define DCTIII_HPP

#define PI 3.14159265358979323846

#include "HuffmanEncoding.hpp"
#include <cmath>

class DCTIII {
  double M[DIMENTION][DIMENTION]; // DCTII Matrix
  double T[DIMENTION][DIMENTION]; // Normal
  void copyMatrix(int m[DIMENTION][DIMENTION]);
  double f(int i, int j);
  int F(int i, int j);
  void generateTransform();
public:
  DCTIII (int m[DIMENTION][DIMENTION]);
  double getT(int i, int j);
  void printF();
};

#endif
