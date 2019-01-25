#include "region.hh"
#define PHOTOX  820
#define PHOTOY  320
#define PHOTOW  280
#define PHOTOH  300


Region::Region(string n, string path, int x, int y, int w, int h): nomRegion(n){
  photo = new Photo(path,x, y, w, h, 300, 150);
  zone = new Zone(x,y,w,h,nomRegion);
 }

 Region::Region(int x, int y, int w, int h, string n){
   nomRegion = n;
   zone = new Zone(x, y, w, h, nomRegion);
 }

 Region::Region(string nRegion, string path): nomRegion(nRegion){
   photo = new Photo(path,0,0,PHOTOW ,PHOTOH, PHOTOX, PHOTOY);
 }

Region::~Region(){
  delete zone;
  delete photo;
}
