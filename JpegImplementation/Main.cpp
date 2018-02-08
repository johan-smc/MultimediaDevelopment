#include <iostream>
#include "HuffmanEncoding.hpp"


using namespace std;

int main(int argc, char const *argv[]) {
int picture[DIMENTION][DIMENTION];
  for(int i = 0; i < DIMENTION; ++i)
    for(int j = 0; j < DIMENTION; ++j)
      cin >> picture[i][j];

  HuffmanEncoding huffEnc(picture);
  cout << huffEnc << endl;

  return 0;
}
