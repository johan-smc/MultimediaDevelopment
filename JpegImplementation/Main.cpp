#include <iostream>
#include "JPEG.hpp"


using namespace std;

int main(int argc, char const *argv[]) {
int picture[DIMENTION][DIMENTION];
  for(int i = 0; i < DIMENTION; ++i)
    for(int j = 0; j < DIMENTION; ++j)
      cin >> picture[i][j];

  cout << "Original: " << endl;
  for(int i = 0; i < DIMENTION; ++i) {
    for(int j = 0; j < DIMENTION; ++j) {
      cout << picture[i][j] << " ";
    }
    cout << endl;
  }

  int p[DIMENTION][DIMENTION];
  memset(p, 0, sizeof p);
  cout << endl << "Huffman Encoding: " << endl;
  JPEG jpeg(picture);
  jpeg.decode(jpeg.getHuffmanEncoding(), p);

  cout << endl << "JPEG Decoded: " << endl;
  for(int i = 0; i < DIMENTION; ++i) {
    for(int j = 0; j < DIMENTION; ++j) {
      cout << p[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
