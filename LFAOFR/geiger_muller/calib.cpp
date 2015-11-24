#include "TGraphErrors.h"
#include <iostream>

using namespace std;

void calib()
{
  TGraphErrors *gr = new TGraphErrors ("dados_patamar.txt","%lg %lg %lg %lg");
  gr->Draw();

}
