#include "element.hh"


Element::Element(int i, string nP, string nR, string path) : Pays(nP, nR, path){
  id = i;
}

Element::Element(int i, string n, string path): Pays("", n, path){
  id = i;
}

bool Element::operator == (Region *r){
  if(this->nomRegion == r->getNom()){
    return true;
  }
  else return false;
}
/*
bool Element::operator == (Pays p){
  if(this->nomPays == p.getNom()){
    return true;
  }
  else return false;
}*/
