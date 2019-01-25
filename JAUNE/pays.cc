#include "pays.hh"



Pays::Pays(string n,string nRegion, int x, int y, int w, int h): Region(x,y,w,h,n){
  nomPays = n;
}

Pays::Pays(string nPays, string nRegion, string path): Region(nRegion, path){
  nomPays = nPays;
}
