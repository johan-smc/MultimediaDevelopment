#ifndef JPEG_HPP
#define JPEG_HPP

#include "HuffmanEncoding.hpp"
#include "HuffmanDecoding.hpp"
#include "DCTII.hpp"
#include "DCTIII.hpp"

#include <cstring>

using namespace std;

class JPEG {
  private:
    int  M[DIMENTION][DIMENTION];
    int  Q[DIMENTION][DIMENTION]; // Quantized Matrix
    void copyMatrix(int m[DIMENTION][DIMENTION]);
    void generateQuantized(DCTII &t);
    int getQuantization(int i, int j);
    vector<std::pair<int,int> > huffEncoding;
    void multByQuant(int m[DIMENTION][DIMENTION]);
  public:
    JPEG(int m[DIMENTION][DIMENTION]);
    void printQ();
    std::vector<std::pair<int,int> > getHuffmanEncoding();
    void decode(std::vector<std::pair<int,int> > huff, int m[DIMENTION][DIMENTION]);
};

#endif
