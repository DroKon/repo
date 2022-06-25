#include <iostream>
#include"Pattern AbstrFactory.h";
using namespace std;

int main() {

  AbstractFactory* F = new ResidentialFactory();
  LowBilding* m;
  HighBilding* b;

  m = F->createLowBilding();
  b = F->createHighBilding();

  m->Bilding();
  b->Bilding();
  cout << m->get_status();
  cout << b->get_status();

  delete F;
  delete m; delete b;

  cout << "------------------------" << endl;

  F = new NoResidentialFactory();

  m = F->createLowBilding();
  b = F->createHighBilding();

  m->Bilding();
  b->Bilding();

  delete F;
  delete m;
  delete b;

  return 0;
}
