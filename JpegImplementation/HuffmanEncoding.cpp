#include "HuffmanEncoding.hpp"

HuffmanEncoding::HuffmanEncoding(int m[DIMENTION][DIMENTION]) {
  copyMatrix(m);
  int zigzag[DIMENTION * DIMENTION];
  zigzagItertion(zigzag);
  generateEncoding(zigzag);
}

void HuffmanEncoding::copyMatrix(int m[DIMENTION][DIMENTION]) {
  for(int i = 0; i < DIMENTION; ++i)
  for(int j = 0; j < DIMENTION; ++j)
  M[i][j] = m[i][j];
}

void HuffmanEncoding::zigzagItertion(int zigZagSacan[]) {
  int iIdxs[DIMENTION * DIMENTION];
  int jIdxs[DIMENTION * DIMENTION];
  constructIthPath(iIdxs);
  constructJthPath(jIdxs);
  for(int k = 0; k < DIMENTION * DIMENTION; ++k) {
    int i = iIdxs[k];
    int j = jIdxs[k];
    zigZagSacan[k] = M[i][j];
  }
}

void HuffmanEncoding::generateEncoding(int zigZagSacan[]) {
  int cont = 0;
  for(int i = 0; i < DIMENTION * DIMENTION; ++i) {
    int curr = zigZagSacan[i];
    if(curr != 0) {
      huffmanEncoding.push_back(std::make_pair(cont, curr));
      cont = 0;
    } else {
      ++cont;
    }
  }
  huffmanEncoding.push_back(std::make_pair(0, 0));
}

std::vector<std::pair<int, int> > HuffmanEncoding::getHuffmanEncoding() const {
  return huffmanEncoding;
}

std::ostream& operator<<(std::ostream& out, const HuffmanEncoding& huff) {
  std::vector<std::pair<int, int> > code = huff.getHuffmanEncoding();
  for(int i = 0; i < code.size(); ++i)
    out << '[' << code[i].first << ", " << code[i].second << ']';
  return out;
}

void HuffmanEncoding::constructIthPath(int iPath[]) {
  int index = 0;
  int iLimit = 0;
  while(iLimit < DIMENTION) {
    for(int i = 0; i < iLimit; ++i)
      iPath[index++] = i;
    for(int i = iLimit; i >= 0; --i)
      iPath[index++] = i;
    iLimit += 2;
  }
  for(int i = 0; i < DIMENTION; ++i)
    iPath[index++] = i;
  iLimit = 1;
  int upperLimit = DIMENTION - 1;
  while(iLimit < DIMENTION) {
    for(int i = upperLimit;  i > iLimit; --i)
      iPath[index++] = i;
    for(int i = iLimit; i <= upperLimit; ++i)
      iPath[index++] = i;
    iLimit += 2;
  }
}

void HuffmanEncoding::constructJthPath(int jPath[]) {
  int jLimit = 1;
  int jndex = 0;
  while(jLimit < DIMENTION) {
    for(int i = 0; i < jLimit; ++i)
      jPath[jndex++] = i;
    for(int i = jLimit; i >= 0; --i)
      jPath[jndex++] = i;
    jLimit += 2;
  }
  for(int i = 1; i < DIMENTION; ++i)
    jPath[jndex++] = i;
  jLimit = 2;
  int upperLimit = DIMENTION - 1;
  while(jLimit <= DIMENTION) {
    for(int i = upperLimit; i > jLimit; --i)
      jPath[jndex++] = i;
    for(int i = jLimit; i <= upperLimit; ++i)
      jPath[jndex++] = i;
    jLimit += 2;
  }
}
