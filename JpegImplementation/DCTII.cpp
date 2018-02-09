#include "DCTII.hpp"

DCTII::DCTII(int m[DIMENTION][DIMENTION]) {
  copyMatrix(m);
  generateTransform();
}

double DCTII::f(int i, int j) {
  return M[i][j];
}

double DCTII::F(int u, int v) {
  double ans = 0.0;
  for(int i = 0; i < DIMENTION; i++) {
    for(int j = 0; j < DIMENTION; j++) {
      double p = (PI / (double) DIMENTION) * ((double) i + 0.5) * (double) u;
      double q = (PI / (double) DIMENTION) * ((double) j + 0.5) * (double) v;
      ans += cos(p)*cos(q)*f(i,j);
    }
  }
  // return (ans / 4.0);
  return ans;
}

void DCTII::copyMatrix(int m[DIMENTION][DIMENTION]) {
  for(int i = 0; i < DIMENTION; ++i)
  for(int j = 0; j < DIMENTION; ++j)
  M[i][j] = ((double) m[i][j] - 128.0);
}

void DCTII::generateTransform() {
  for(int i = 0; i < DIMENTION; ++i)
    for(int j = 0; j < DIMENTION; ++j)
      T[i][j] = F(i, j);
}

void DCTII::printF() {
  for(int i = 0; i < DIMENTION; ++i) {
    for(int j = 0; j < DIMENTION; ++j) {
      printf("%.2lf ", T[i][j]);
    }
    cout << '\n';
  }
}

double DCTII::getT(int i, int j) {
  return T[i][j];
}
