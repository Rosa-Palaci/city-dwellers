#include <cstddef>
#include <iostream>
#include <time.h>
using namespace std;
#include "lista.h"



int main() {
  Stack<int> stack;
  for(int i = 0; i < 10; i++)
      stack.push(rand()%100);

  cout << stack.peek() << endl;

  for(int i = 0; i < stack.size(); i++)
    cout << stack.pop()<< endl;
  stack.print();
  
  
}
