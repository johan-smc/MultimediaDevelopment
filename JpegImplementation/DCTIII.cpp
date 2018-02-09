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
      double p = (PI / (double) DIMENTION) * ((double) u + 0.5) * (double) i;
      double q = (PI / (double) DIMENTION) * ((double) v + 0.5) * (double) j;
      ans += (cos(p)*cos(q)*f(i,j));
    }
  }
  // return (ans / 4.0);
  return (ans / ((double)DIMENTION * DIMENTION) + 128.0);
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
