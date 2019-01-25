#include "IA.hh"


IA::IA():Joueur("AI"){

}

void IA::initIA(vector<Element*> element){
  ifstream file("IMG/ia.txt");
  string p,r;
  int i = 0, end = element.size();
  while(i < end){
    file >> p;
    file >> r;
    reponse.insert(make_pair(element[i]->getID(),new Pays(p, r)));
    i++;
  }
  file.close();
}
