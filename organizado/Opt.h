#include "TGraphErrors.h"
#include "TH1F.h"
#include "TNamed.h"

#include <string>
#include <iostream>

using namespace std;

class Opt
{
  public:
    Opt(string, string);
    string Escolher();
    TH1F* Histograma();
    TGraphErrors* Ajuste();
    TGraphErrors* Grafico();

  private:
    string ficheiro;
    string dados;
    string opcao;

};
