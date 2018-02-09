#ifndef DCT_II_H
#define DCT_II_H

#define PI 3.14159265358979323846

#include "HuffmanEncoding.hpp"
#include <cmath>
#include <cstdio>

using namespace std; // TODO - Delete

class DCTII {
  private:
    double M[DIMENTION][DIMENTION];
    double T[DIMENTION][DIMENTION];
    void copyMatrix(int m[DIMENTION][DIMENTION]);
    double f(int i, int j);
    double F(int i, int j);
    void generateTransform();
  public:
    DCTII (int m[DIMENTION][DIMENTION]);
    double getT(int i, int j);
    void printF();
};

#endif
