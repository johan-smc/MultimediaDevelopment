#include <iostream>
#include <vector>
#include <utility>
#include <sstream>

// cabracadabrarrarrad 13 6
// cabracadabrarrarrad 12 7
// abracadabrarray 14 6


using namespace std;

struct Token {
  int o, l;
  char n;

  Token(int of, int len, char m) {
    o = of;
    l = len;
    n = m;
  }

  bool operator < (const Token &t) {
    if(l == t.l) return o > t.o;
    return l < t.l;
  }

  bool operator > (const Token &t) {
    if(l == t.l) return o < t.o;
    return l > t.l;
  }

  bool operator >= (const Token &t) {
    if(l == t.l) return o < t.o;
    return l >= t.l;
  }

};

ostream& operator << (ostream &o, const Token t) {
  o << t.o << "," << t.l << "," << t.n << ";";
  return o;
}

Token codingHelper(vector<char> w, int lb) {
  Token t(0,0,w[lb]);
  for(int i = 0; i < w.size(); ++i) {
    if(w[i] == w[lb] && i < lb) {
      Token temp(0,0,'-');
      int j = i, k = lb;
      while(w[j] == w[k]) {
        ++j;
        ++k;
        temp.l++;
      }
      temp.n = w[k];
      temp.o = (lb - i);
      if(temp >= t) t = temp;
    }
  }
  return t;
}
// 0,0,a;0,0,b;0,0,r;3,1,c;2,1,d;7,4,r;3,2,y;
void codificar() {
  cout << "Ingrese [String] [Ventana] [Tamanio Del Lookahead Buffer]" << endl;
  string s;
  int w, la;
  cin >> s >> w >> la;
  //la = w - la;
  vector<Token> v;
  vector<char> window(w,'-');
  for(int i = w - la, j = 0; i < s.size(); ++i) window[i] = s[j++];
  int i = la;
  while (true) {
    if(window.size() - la > w) break;
    Token t = codingHelper(window, window.size() - la);
    cout << t;
    window.erase(window.begin() + t.l);
    for(int j = 0; j < t.l + 1; ++j)
      window.push_back(s[i++]);
  }
  cout << endl;

}

int strToInt(string n) {
  int ans;
  stringstream ss(n);
  ss >> ans;
  return ans;
}

Token strToToken(string str) {
  stringstream ss(str);
  string l;
  Token t(0,0,'-');
  getline(ss, l,',');
  t.o = strToInt(l);
  getline(ss, l,',');
  t.l = strToInt(l);
  getline(ss, l,',');
  t.n = l[0];
  return t;

}

vector<Token> stringToVecToks(string s) {
  stringstream ss(s);
  vector<Token> v;
  string l;
  while(getline(ss, l, ';')) {
    v.push_back(strToToken(l));
  }
  return v;
}

void decode() {
  cout << "Ingrese el codigo: (Ej: 0,0,c;0,0,a;)" << endl;
  string c;
  cin >> c;
  vector<Token> v = stringToVecToks(c);
  string ans = "";
  int pointer = 0;
  int p2 = 0;
  for(int i = 0; i < v.size(); ++i) {
    Token t = v[i];
    p2 = pointer;
    pointer -= t.o;
    for(int i = 0; i < t.l; ++i) {
      ans += ans[pointer++];
    }
    ans+=t.n;
    pointer = p2 + 1 + t.l;
  }
  cout << ans << endl;
}


int main(int argc, char const *argv[]) {
  int opt;
  do {
    cout << "Codificar............. 1" << endl;
    cout << "Decodificar........... 2" << endl;
    cout << "Salir................. 0" << endl;
    cout << "Opcion: ";
    cin >> opt;
    if(opt == 1) codificar();
    if(opt == 2) decode();
    cout << endl;
  } while(opt != 0);

  return 0;
}
