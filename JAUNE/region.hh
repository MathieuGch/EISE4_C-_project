#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <string>
#include "zone.hh"
#include "photo.hh"
using namespace std;

/*
La classe région permet de créer une région avec une photo et une zone qui lui
sont propres.
La surcharge de constructeur permet également à un pays d'avoir une zone, où
un élément d'avoir une photo, ou bien d'avoir seulement un nom.
*/

class Region{
public:
  Region(string n, string path, int x, int y, int w, int h);
  Region(int x, int y, int w, int h, string n);
  Region(string nRegion, string path);
  Region(string nRegion):nomRegion(nRegion){}
  Region(){}
  virtual ~Region();
  Zone *getZone(void){
    return this->zone;
  }
  Photo *getPhoto(void){
    return this->photo;
  }
  string getNomRegion(void){
    return this->nomRegion;
  }
  virtual string getNom(void){
    return this->nomRegion;
  }
protected:
  string nomRegion;
  Photo *photo;
  Zone *zone;



};
