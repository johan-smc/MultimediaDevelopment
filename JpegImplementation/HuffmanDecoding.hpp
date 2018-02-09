#ifndef HUFFMAN_DECODING_HPP
#define HUFFMAN_DECODING_HPP

#include "HuffmanEncoding.hpp"

class HuffmanDecoding {
  private:
    void constructIthPath(int iPath[]);
    void constructJthPath(int jPath[]);
  public:
    HuffmanDecoding(std::vector<std::pair<int,int> > v, int m[DIMENTION][DIMENTION]);

};

#endif
