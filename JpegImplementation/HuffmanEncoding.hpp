#ifndef HUFFMAN_ENCODING_H
#define HUFFMAN_ENCODING_H
#define DIMENTION 8

#include <iostream>
#include <vector>
#include <utility>


class HuffmanEncoding {
  private:
    int M[DIMENTION][DIMENTION];
    std::vector<std::pair<int,int> > huffmanEncoding;
    void copyMatrix(int m[DIMENTION][DIMENTION]);
    void constructIthPath(int iPath[]);
    void constructJthPath(int jPath[]);
    void zigzagItertion(int zigZagSacan[]);
    void generateEncoding(int zigZagSacan[]);
  public:
    HuffmanEncoding(int m[DIMENTION][DIMENTION]);
    std::vector<std::pair<int,int> > getHuffmanEncoding() const;
};

std::ostream& operator<<(std::ostream& os, const HuffmanEncoding& huff);

#endif
