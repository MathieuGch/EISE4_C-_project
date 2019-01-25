#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>
#include "region.hh"
using namespace std;

/*
La classe Pays (qui dérive de région) créer un pays avec une zone qui lui est
définie
La surchage du constructeur permet de créer des éléments avec une photo où
juste un pays sans zone
*/

class Pays : public Region {
 public:
   Pays(string n, string nRegion, int x, int y, int w, int h);
   Pays(string nPays, string nRegion, string path);
   Pays(string nPays, string nRegion):Region(nRegion), nomPays(nPays){}
   Pays():Region(){}
   ~Pays(){}
   string getNom(){
     return this->nomPays;
   }
   void setNom(string s){
     this->nomPays = s;
   }
protected:
  string nomPays;

 };
