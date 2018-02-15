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
  double c1 = (u == 0 ? (1.0 / sqrt(2.0)) : 1.0);
  double c2 = (v == 0 ? (1.0 / sqrt(2.0)) : 1.0);
  for(int i = 0; i < DIMENTION; i++) {
    for(int j = 0; j < DIMENTION; j++) {
      // double p = (PI / (double) DIMENTION) * ((double) i + 0.5) * (double) u;
      // double q = (PI / (double) DIMENTION) * ((double) j + 0.5) * (double) v;
      double p = ((2.0*i + 1.0)*(double)u*PI) / 16.0;
      double q = ((2.0*j + 1.0)*(double)v*PI) / 16.0;
      ans += cos(p)*cos(q)*f(i,j);
    }
  }
  // return (ans / 4.0);
  return ((ans*c1*c2) / 4.0);
}

void DCTII::copyMatrix(int m[DIMENTION][DIMENTION]) {
  for(int i = 0; i < DIMENTION; ++i)
  for(int j = 0; j < DIMENTION; ++j)
  M[i][j] = ((double) m[i][j] - 128.0);
}

void DCTII::generateTransform() {
  cout << endl <<"Transformada Coseno II: " << endl;
  for(int i = 0; i < DIMENTION; ++i) {
    for(int j = 0; j < DIMENTION; ++j) {
      T[i][j] = F(i, j);
      printf("%.2lf ", T[i][j]);
    }
    cout << endl;
  }
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
