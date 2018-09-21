/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-
* Author: Roberto Bradley
* Class: CST 426
* Assignment: Lab 01
* Due Date: 20 - September - 2018
* Comments:
* 
=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

#include <iostream>
#include <string>
#include <list>
#include <stdlib.h>
#include <vector>

using namespace std;


/* 1)The game has 3 different dragon types, but
2) each actual dragon instance has some specific characteristics, such as size, random color of skin and eyes, health level, experience points etc.
*/



struct dragonMesh
{
  string shape = "A dragon"; //the overall shape
  
};

struct DragMemento
{
  string skinColor;
  string eyeColor;

  int size;
  int health;
  int eyeNum;
  int exPoints;
  int skinNum;
};

class Dragon
{
  public:
  dragonMesh* mesh;
  string skinColor;
  string eyeColor;

  int size;
  int health;
  int eyeNum;
  int exPoints;
  int skinNum;

  void genDragon()
  {
    size = rand() % 100 + 1; //the overall size per dragon
    health =  rand() % 1000 + 1; // the health
    eyeNum = rand() % 6 + 1; // the eye choice
    skinNum =  rand() % 3 + 1; // the skin color choice
    exPoints = rand() %500 + 1000;
    EyeColor();
    SkinColor();
  }
  void EyeColor()
  {
    switch(eyeNum)
    {
      case 1: eyeColor = "red";
        break;
      case 2: eyeColor = "brown";
        break;
      case 3: eyeColor = "black";
        break;
      case 4: eyeColor = "green";
        break;
      case 5: eyeColor = "blue";
        break;
      case 6: eyeColor = "grey";
        break;
      default:
        break;
    }
  }

  void SkinColor()
  {
    switch(skinNum){
      case 1: skinColor = "red";
      break;
      case 2: skinColor = "green";
      break;
      case 3: skinColor = "green";
      break;
    }
  }

  void displayDrag()
  {
    cout << mesh->shape << " with these values \n" << "size: " << size <<"\n" << "health: " << health << "\n" << "Eye Color: " << eyeColor << "\n" << "Skin Color: " << skinColor << "\n" <<"Experience for this dragon: "<< exPoints << "\n\n\n";
  }

  DragMemento createMemento()
  {
    DragMemento* save = new DragMemento;
    save->skinColor = skinColor;
    save->eyeColor = eyeColor;
    save->health = health;
    save->exPoints = exPoints;
    save->size = size;
    return* save;
  }

};

class saveFile
{
  public:

  list <DragMemento> saving;
   list<DragMemento> saveDrag(list<Dragon*> listofDrags)
  {
    for(Dragon* d : listofDrags)
    {
      saving.push_back(d->createMemento());
      
    }
   return saving; 
  }

};

list<Dragon*>flyweight()
{
  list<Dragon*>spawner;
  dragonMesh* DM = new dragonMesh;

  for(int i = 0; i < 10; i++)
  {
    Dragon* D = new Dragon();
    D->mesh = DM;
    D->genDragon();
    spawner.push_front(D);
    D->displayDrag();
  }
  return spawner;
}

int main() {
  saveFile saver;
  srand (time(NULL));
  list<Dragon*> dog;
  dog = flyweight();
  saver.saveDrag(dog);
 
  return 0;
}