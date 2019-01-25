#include <iostream>
#include <string>
#include <vector>
#include "time.h"
#include <fstream>
#include "fenetre.hh"
#include "photo.hh"
#include "zone.hh"
#include "joueur.hh"
#include "IA.hh"
#include "region.hh"
#include "pays.hh"
#include "element.hh"
using namespace std;

#define WIDTH 1370
#define HEIGHT  720
#define NBREGION  100
#define NBELEMENTS 11
#define NBPAYS  11
#define POSX  1075
#define POSYNOM 600
#define POSYSCORE 630

/*
La classe Jeu gère le déroulement de l'application via sa méthode "jouer()".
Celle-ci fait appel à la méthode "handleEvent()" pour gérer les évenements
et la méthode "affichage()" pour réaliser l'affichage (qui fait bien sûr appel
à la classe Fenêtre).
*/

class Jeu{
public:
  Jeu(Joueur j);
  ~Jeu();
  int jouer();
private:
  Joueur joueur;
  IA ia;
  Fenetre fenetre;
  Photo world;
  Photo coeur;
  Bouton NAP;
  vector<vector<Region*> > region;
  vector<Element*> element;
  void initRegion();
  void initElement();
  void handleEvent(int *regionSelected, int random, bool *foundRegion, bool *foundPays, bool *loose, bool *wrong);
  void affichage(int regionSelected, int random, bool wrong);

};
