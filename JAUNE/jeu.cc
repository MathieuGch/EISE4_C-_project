#include "jeu.hh"


Jeu::Jeu(Joueur j):joueur(j),
                   ia(),
                   fenetre(WIDTH, HEIGHT, "JAUNE"),
                   world("IMG/world.png",0, 0, WIDTH, HEIGHT,0,0),
                   coeur("IMG/coeur.png",5, 0, 50, 40, 500, 650),
                   NAP(500,600,140,50,"Not a person", sf::Color::Yellow, sf::Color::Black){
}

Jeu::~Jeu(){/*
  for(unsigned int i = 0 ; i < region.size(); i++){
    for(unsigned int j =0; j < region[i].size(); j++){
      delete region[i][j];
    }
  }*/
}
/* Les différentes régions et pays sont stockés dans le vecteur deux dimensions
region*/
void Jeu::initRegion(){

  vector<Region *> v;
  v.push_back(new Region("North_America", "IMG/world.png",100,50,300,250));
  v.push_back(new Pays("Canada", "North_America", 350, 150, 250, 100));
  v.push_back(new Pays("USA", "North_America", 350, 250, 200, 75));
  v.push_back(new Pays("Mexico", "North_America", 350, 325, 100, 70));
  region.push_back(v);
  v.clear();

  v.push_back(new Region("South_America", "IMG/world.png",280,310,190,300));
  v.push_back(new Pays("Brasil", "South_America", 350, 210, 140, 90));
  v.push_back(new Pays("Argentina", "South_America", 350, 300, 65, 140));
  region.push_back(v);
  v.clear();

  v.push_back(new Region("Europe", "IMG/world.png",550,50,270,150));
  v.push_back(new Pays("Iceland", "Europe", 300, 165, 30, 25));
  v.push_back(new Pays("UK", "Europe", 330, 200, 45, 40));
  v.push_back(new Pays("France", "Europe", 350, 240, 45, 30));
  v.push_back(new Pays("Spain", "Europe", 330, 270, 45, 30));
  v.push_back(new Pays("Italy", "Europe", 390, 255, 40, 50));
  v.push_back(new  Pays("Germany", "Europe", 390, 220, 35, 20));
  v.push_back(new Pays("East Europe", "Europe", 425, 220, 60, 40));
  v.push_back(new Pays("North Europe", "Europe", 390, 150, 80, 70));
  v.push_back(new Pays("Russia", "Europe", 485, 160, 100, 90));
  v.push_back(new Pays("South Europe", "Europe", 440, 260, 100, 50));
  region.push_back(v);
  v.clear();

  v.push_back(new Region("Africa", "IMG/world.png",545,200,295,325));
  v.push_back(new Pays("North_Africa", "Africa", 300, 150, 200, 140));
  v.push_back(new Pays("Middle_East", "Africa", 510, 150, 100, 110));
  v.push_back(new Pays("Central_Africa", "Africa", 400, 290, 150, 110));
  v.push_back(new Pays("South_Africa", "Africa", 420, 400, 70, 75));
  v.push_back(new Pays("Madagascar", "Africa", 550, 370, 25, 60));
  region.push_back(v);
  v.clear();

  v.push_back(new Region("Asia", "IMG/world.png",850,50,340,350));
  v.push_back(new Pays("India", "Asia", 350, 350, 70, 75));
  v.push_back(new Pays("Mongolia", "Asia", 390, 235, 100, 30));
  v.push_back(new Pays("China", "Asia", 380, 265, 170, 85));
  v.push_back(new Pays("South_Korea", "Asia", 555, 290, 20, 15));
  v.push_back(new Pays("Japan", "Asia", 575, 260, 45, 60));
  v.push_back(new Pays("South_Asia", "Asia",425, 350, 70, 75));
  v.push_back(new Pays("South_East_Asia", "Asia", 455, 425, 190, 75));
  region.push_back(v);
  v.clear();

  v.push_back(new Region("Oceania", "IMG/world.png",1070,420,250,150));
  v.push_back(new Pays("Australia", "Oceania",300, 150, 155, 120));
  v.push_back(new Pays("New_Zealand", "Oceania",470, 250, 55, 50));
  region.push_back(v);
  v.clear();

}

/*Les éléments sont stockés dans le vecteur element*/
void Jeu::initElement(){
  ifstream file("IMG/elements.txt");
  int i = 0;
  string pays, region, path;
  while(file >> path){
    file >> pays;
    file >> region;
    element.push_back(new Element(i, pays, region, path));
    i++;
  }
  file.close();
}

void Jeu::handleEvent(int *regionSelected, int random, bool *foundRegion, bool *foundPays, bool *end, bool *wrong){
  sf::Event event;
  while (fenetre.pollEvent(event)){
    if (event.type == sf::Event::Closed){
      fenetre.close();
      exit(0);
    }else{
      int mouseX = fenetre.getPosMouseX();
      int mouseY = fenetre.getPosMouseY();
      //Si on cherche la région
      if(*regionSelected == -1) {
          for(unsigned int i = 0; i < region.size(); i++){
              if(region[i][0]->getZone()->isSelected(mouseX, mouseY)){
                  if(*element[random] == region[i][0]){
                    *regionSelected = i;
                    *foundRegion = true;
                   }else{
                     *wrong = true;
                     if(element[random]->getNom() == "NAP")element[random]->setNom("Not a Person");
                     if(joueur.perdVie())   *end = true;
                  }
              }
            }
            if(NAP.isSelected(mouseX, mouseY)){
              if(element[random]->getNom() == "NAP"){
              *regionSelected = -1;
              *foundPays = true;
              joueur.addScore(-1);
              }else{
                *wrong = true;
                if(joueur.perdVie()) *end = true;
              }
            }
        //Si on cherche le pays
        }else{
            for(unsigned int i = 1; i < region[*regionSelected].size(); i++){
              if(region[*regionSelected][i]->getZone()->isSelected(mouseX, mouseY)){
                if(element[random]->getNom() == region[*regionSelected][i]->getNom()){
                  *foundPays = true;
                }else{
                  *wrong = true;
                  if(joueur.perdVie()) *end = true;
                }
              }
            }
          }
        }
      }
}

int Jeu::jouer(){
  bool end = false;
  bool foundPays = false;
  bool foundRegion = false;
  bool wrong = false;
  int cpt = 500;
  int random;
  int regionSelected = -1;
  initRegion();
  initElement();
  ia.initIA(element);
  random = rand() % element.size();
  while(fenetre.isOpen() && (end == false)){
    fenetre.majAffichage();
    if(foundRegion){
      foundRegion = false;
      joueur.addScore(1);
      if(element[random]->getNomRegion() == ia.getRegion(element[random]->getID())){
        ia.addScore(1);
      }else if(ia.perdVie()){
        end = true;
      }
      region[regionSelected][0]->getZone()->setText("");
    }
    if(foundPays){
      joueur.addScore(2);
      if(element[random]->getNom() == ia.getPays(element[random]->getID())){
        ia.addScore(2);
      }else if(ia.perdVie()){
        end = true;
      }
      //Si ce n'est pas le dernier élément
      if(element.size() > 1){
        foundPays = false;
        regionSelected = -1;
        //On supprime l'élément qu'on vient d'utiliser
        element.erase(element.begin()+random);
        //On met à jour random pour obtenir un nouvel élément parmi ceux restant
        random = rand() % element.size();
      // Sinon, il n'y a plus d'élément donc on termine le jeu
      }else{
        end = true;
      }
    }
    if(wrong){
    // Pour afficher le message pendant un certain temps on utilise un compteur
    // (voir fin méthode affichage)
      cpt--;
      if(cpt == 0){
        cpt = 500;
        wrong = false;
        if(element[random]->getNomRegion() == ia.getRegion(element[random]->getID())){
          ia.addScore(1);
          if(element[random]->getNom() == ia.getPays(element[random]->getID())){
            ia.addScore(2);
          }else if(ia.perdVie()){
            end = true;
          }
        }else if(ia.perdVie()){
          end = true;
        }
        regionSelected = -1;
        //Si ce n'est pas le dernier élément
        if(element.size() > 1){
          //On supprime l'élément qu'on vient d'utiliser
          element.erase(element.begin()+random);
          //On met à jour random pour obtenir un nouvel élément parmi ceux restant
          random = rand() % element.size();
        // Sinon, il n'y a plus d'élément donc on termine le jeu
        }else{
          end = true;
        }
      }
    }
    handleEvent(&regionSelected, random, &foundRegion, &foundPays, &end, &wrong);
    affichage(regionSelected, random, wrong);
  }
  fenetre.close();

  if(joueur > ia) return joueur.getScore() + 1000;
  else return joueur.getScore();
}

void Jeu::affichage(int regionSelected,int random, bool wrong){
  if(regionSelected == -1) {
      fenetre.photo(&world);
      fenetre.bouton(NAP);
      element[random]->getPhoto()->resize(820,320);
      for(unsigned int i = 0; i < region.size(); i++){
          fenetre.text(region[i][0]->getZone()->getposX() - 40 + region[i][0]->getZone()->getWidth()/2, (region[i][0]->getZone()->getposY() + region[i][0]->getZone()->getHeight()/2),region[i][0]->getZone()->getText());
      }
  }
  else{
    element[random]->getPhoto()->resize(750,150);
    fenetre.photo(region[regionSelected][0]->getPhoto());
    for(unsigned int i = 0; i < region[regionSelected].size(); i++){
      fenetre.text(region[regionSelected][i]->getZone()->getposX() - 40 + region[regionSelected][i]->getZone()->getWidth()/2, (region[regionSelected][i]->getZone()->getposY() + region[regionSelected][i]->getZone()->getHeight()/2),region[regionSelected][i]->getZone()->getText());
    }
  }
  fenetre.photo(element[random]->getPhoto());
  fenetre.box(POSX,600,300,200);
  fenetre.text(POSX + 5,POSYNOM,joueur.getNom());
  fenetre.text(POSX + 5,POSYSCORE,joueur.getTextScore());
  for(int i = 0; i < joueur.getVie(); i++){
    coeur.resize(POSX + 60 * i, 665);
    fenetre.photo(&coeur);
  }
  fenetre.box(0,600,300,200);
  fenetre.text(5,POSYNOM,ia.getNom());
  fenetre.text(5,POSYSCORE,ia.getTextScore());
  for(int i = 0; i < ia.getVie(); i++){
    coeur.resize(5 + 60 * i, 665);
    fenetre.photo(&coeur);
  }
  if(wrong){
    string s = "WRONG, the correct answer was " + element[random]->getNom() + ", " + element[random]->getNomRegion();
    fenetre.text(300,400, s);
    string t = "the AI answered " + ia.getPays(element[random]->getID()) + ", " + ia.getRegion(element[random]->getID());
    fenetre.text(300,440, t);
  }
}
