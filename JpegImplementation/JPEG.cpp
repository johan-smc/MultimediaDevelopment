#include "JPEG.hpp"

JPEG::JPEG(int m[DIMENTION][DIMENTION]) {
  copyMatrix(m);
  DCTII transformed(m);
  generateQuantized(transformed);
  HuffmanEncoding huff(Q);
  huffEncoding = huff.getHuffmanEncoding();
  std::cout << huff << '\n';
}

void JPEG::generateQuantized(DCTII &t) {
  for(int i = 0; i < DIMENTION; i++)
    for(int j = 0; j < DIMENTION; j++)
      Q[i][j] = t.getT(i, j) / getQuantization(i, j);
}

void JPEG::printQ() {
  for(int i = 0; i < DIMENTION; ++i){
    for(int j = 0;  j< DIMENTION; ++j){
      std::cout << Q[i][j] << " ";
    }
    std::cout << '\n';
  }
}

int JPEG::getQuantization(int i, int j) {
  int QUANTIZATION[DIMENTION][DIMENTION] = { {16, 12, 14, 14, 18, 24, 49, 72},
                                  {11, 12, 13, 17, 22, 35, 64, 92},
                                  {10, 14, 16, 22, 37, 55, 78, 95},
                                  {16, 19, 24, 29, 56, 64, 87, 98},
                                  {24, 26, 40, 51, 68, 81, 103, 112},
                                  {40, 58, 57, 87, 109, 104, 121, 100},
                                  {51, 60, 69, 80, 103, 113, 120, 103},
                                  {61, 55, 56, 62, 77, 92, 101, 99}
                                };
  return QUANTIZATION[i][j];
}

void JPEG::copyMatrix(int m[DIMENTION][DIMENTION]) {
  for(int i = 0; i < DIMENTION; ++i)
  for(int j = 0; j < DIMENTION; ++j)
  M[i][j] = m[i][j];
}

std::vector<std::pair<int,int> > JPEG::getHuffmanEncoding() {
  return huffEncoding;
}

void JPEG::multByQuant(int m[DIMENTION][DIMENTION]) {
  int QUANTIZATION[DIMENTION][DIMENTION] = { {16, 12, 14, 14, 18, 24, 49, 72},
                                  {11, 12, 13, 17, 22, 35, 64, 92},
                                  {10, 14, 16, 22, 37, 55, 78, 95},
                                  {16, 19, 24, 29, 56, 64, 87, 98},
                                  {24, 26, 40, 51, 68, 81, 103, 112},
                                  {40, 58, 57, 87, 109, 104, 121, 100},
                                  {51, 60, 69, 80, 103, 113, 120, 103},
                                  {61, 55, 56, 62, 77, 92, 101, 99}
                                };
  for(int i = 0; i < DIMENTION; ++i)
    for(int j = 0; j < DIMENTION; ++j)
      m[i][j] *= QUANTIZATION[i][j];
}

void JPEG::decode(std::vector<std::pair<int,int> > huff, int m[DIMENTION][DIMENTION]) {
  //memset(m, 0, sizeof m);
  HuffmanDecoding huffDec(huff, m);
  multByQuant(m);
  DCTIII dct3(m);
  for(int i = 0; i < DIMENTION; ++i)
    for(int j = 0; j < DIMENTION; ++j)
      m[i][j] = dct3.getT(i, j);
}
