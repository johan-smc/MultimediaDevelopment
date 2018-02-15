#include "DCTIII.hpp"

DCTIII::DCTIII(int m[DIMENTION][DIMENTION]) {
  copyMatrix(m);
  generateTransform();
}

double DCTIII::f(int i, int j) {
  return M[i][j];
}

int DCTIII::F(int u, int v) {
  double ans = 0.0;
  for(int i = 0; i < DIMENTION; i++) {
    for(int j = 0; j < DIMENTION; j++) {
      double c1 = (i == 0 ? (1.0 / sqrt(2.0)) : 1.0);
      double c2 = (j == 0 ? (1.0 / sqrt(2.0)) : 1.0);
      // double p = (PI / (double) DIMENTION) * ((double) u + 0.5) * (double) i;
      // double q = (PI / (double) DIMENTION) * ((double) v + 0.5) * (double) j;
      double p = ((2.0*u + 1.0)*(double)i*PI) / 16.0;
      double q = ((2.0*v + 1.0)*(double)j*PI) / 16.0;
      ans += ((cos(p)*cos(q)*f(i,j)) * c1 * c2);
    }
  }
  // return (ans / 4.0);
  return (((ans) / 4.0) + 128.0);
}

void DCTIII::copyMatrix(int m[DIMENTION][DIMENTION]) {
  for(int i = 0; i < DIMENTION; ++i)
  for(int j = 0; j < DIMENTION; ++j)
  M[i][j] = ((double) m[i][j]);
}

void DCTIII::generateTransform() {
  for(int i = 0; i < DIMENTION; ++i)
    for(int j = 0; j < DIMENTION; ++j)
      T[i][j] = F(i, j);
}

void DCTIII::printF() {
  for(int i = 0; i < DIMENTION; ++i) {
    for(int j = 0; j < DIMENTION; ++j) {
      printf("%.2lf ", T[i][j]);
    }
    std::cout << '\n';
  }
}

double DCTIII::getT(int i, int j) {
  return T[i][j];
}
