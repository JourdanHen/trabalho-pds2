#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> quebra(string &s) {
  vector<string> v;
  int i = 0, j = 0;
  
  while (j < s.size()){
    if (s[j] == ' ' || s[j] == ';'|| s[j] == '.'|| s[j] == ','|| s[j] == '!'|| s[j] == '.'|| s[j] == '?'|| s[j] == '\n'){
      // palavra s[i] --- s[j]
      string sub = s.substr(i, j-i);
      v.push_back(sub);
      j++;
      i = j;
    }
    else {
      j++;
    }
  }
  
  string sub = s.substr(i, j-i);
  v.push_back(sub);
  
  for (auto s : v)
    cout << "achou palavra: " << s << "\n";
  
  return v;
}

int main(){
vector<string> g;
string busca;
int tf=0;
cout<<"Digite a palavra que quer buscar ...\n";
cin>>busca;
ifstream arquivo;
arquivo.open("d1.txt");
while (!arquivo.eof()){
  string s;
  getline(arquivo, s);
  if (arquivo.eof())
    break;
    cout << "Leu: " << s << endl;
    
    g=quebra(s);
  }
  for(int i=0;g.size()>i;i++){
    if(busca==g[i]){
      tf++;
    }
  }
  return 0;
}
