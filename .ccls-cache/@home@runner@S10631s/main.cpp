#include <cstddef>
#include <iostream>
#include <time.h>
using namespace std;
#include "lista.h"

void players(LinkedList<int> & characters){
  srand(time(0));
  for(int i = 0; i < 100; i++)
    characters.addLast(rand()%100);
}

int main() {
  
  LinkedList<int> middleEarth;
  players(middleEarth);
  for(int i = 0; i < middleEarth.size(); i++){
    int character = middleEarth.get(i);
    if( character % 2 == 0){
      middleEarth.remove(i);
    }else{
      middleEarth.insert(rand()%100, i + 1);
    }
    
    /*
      Completa lo que se pide.
    */
  }
  cout << middleEarth.size() << endl;
  /*
  Imprime si Sauron gana o pierde. No olvides calcular la complejidad total.

    */
}
