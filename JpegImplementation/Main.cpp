#include <iostream>
#include <cmath>
#include "JPEG.hpp"


using namespace std;

int main(int argc, char const *argv[]) {
int picture[DIMENTION][DIMENTION];
  for(int i = 0; i < DIMENTION; ++i)
    for(int j = 0; j < DIMENTION; ++j)
      cin >> picture[i][j];

  cout << "Matriz Luminancia: " << endl;
  for(int i = 0; i < DIMENTION; ++i) {
    for(int j = 0; j < DIMENTION; ++j) {
      cout << picture[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl << "Matriz Luminancia -128: " << endl;
  for(int i = 0; i < DIMENTION; ++i) {
    for(int j = 0; j < DIMENTION; ++j) {
      cout << picture[i][j] - 128 << " "; // It's actualy done in JPEG.cpp
    }
    cout << endl;
  }



  int p[DIMENTION][DIMENTION];
  memset(p, 0, sizeof p);
  JPEG jpeg(picture);
  jpeg.decode(jpeg.getHuffmanEncoding(), p);

  cout << endl << "JPEG Decoded: " << endl;
  for(int i = 0; i < DIMENTION; ++i) {
    for(int j = 0; j < DIMENTION; ++j) {
      cout << p[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl << "Diferencias (abs(original - compressed)): " << endl;
  for(int i = 0; i < DIMENTION; ++i) {
    for(int j = 0; j < DIMENTION; ++j) {
      cout << abs(p[i][j] - picture[i][j]) << " ";
    }
    cout << endl;
  }
  return 0;
}
