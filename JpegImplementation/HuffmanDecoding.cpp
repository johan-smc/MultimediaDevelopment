#include "HuffmanDecoding.hpp"

HuffmanDecoding::HuffmanDecoding(std::vector<std::pair<int,int> > v, int m[DIMENTION][DIMENTION]) {
  int iIdxs[DIMENTION * DIMENTION];
  int jIdxs[DIMENTION * DIMENTION];
  constructIthPath(iIdxs);
  constructJthPath(jIdxs);
  int idx = 0;
  for(int k = 0; k < v.size(); ++k) {
    int i = iIdxs[idx], j = jIdxs[idx];
    for(int l = 0; l < v[k].first; ++l) {
      m[i][j] = 0;
      ++idx;
      i = iIdxs[idx], j = jIdxs[idx];
    }
    m[i][j] = v[k].second;
    ++idx;
  }
}

void HuffmanDecoding::constructIthPath(int iPath[]) {
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

void HuffmanDecoding::constructJthPath(int jPath[]) {
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
