#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "pays.hh"
using namespace std;

/*
La classe Element permet de créer un élément, autrement dit une photo associée
à son pays et sa région respective
*/

class Element : public Pays{
 public:
   Element(int i, string nP, string nR, string path);
   Element(int i, string n, string path);
   ~Element(){}
   bool operator == (Region *r);
   //bool operator == (Pays p);
   int getID(void){
     return this->id;
   }
private:
  int id;

 };
