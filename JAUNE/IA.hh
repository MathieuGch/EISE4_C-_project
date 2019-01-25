#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include "joueur.hh"
#include "region.hh"
#include "pays.hh"
#include "element.hh"
using namespace std;

/*
La classe IA (qui dérive de la classe Joueur) permet de créer une "IA" avec les
mêmes attribues qu'un joueur mais possédant en plus une map lui permettant
de stocker ce qu'elle pense être la réponse.
Elle est initialisé grâce à un fichier "ia.txt" se trouvant dans le répertoire
IMG
*/

class IA : public Joueur{
public:
  IA();
  ~IA(){}
  void initIA(vector<Element*> element);
  string getRegion(int i){
    return reponse[i]->getNomRegion();
  }
  string getPays(int i){
    return reponse[i]->getNom();
  }
private:
  map<int, Pays *> reponse;

};
