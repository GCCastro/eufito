#include "Opt.h"
#include "fstream"

using namespace std;
//merdas

//Construtor
Opt::Opt(string fparam, string fdados)
{
  ficheiro = fparam;
  dados = fdados;
  ifstream det(fparam.c_str());
  if (det.is_open())
  {
    det.ignore(256,':');
    getline(det,opcao);
  }
  det.close();
  cout << "O ficheiro de parametros e " << ficheiro << " e a opcao e " << opcao << endl;
}


//Decide, baseado na opcao, que grafico fazer; Chama funcao adequada
string Opt::Escolher()
{
  if (opcao!="fit" & opcao!="grafico" & opcao!="histograma")
  {
    opcao.clear();
    cout << "opcao invalida. adeus" << endl;
  }

  return opcao;
}


//Faz um ajuste
TGraphErrors* Opt::Ajuste()
{
  cout << "Eu quero fazer um ajuste e nao me deixam." << endl;
}


//Faz um grafico
TGraphErrors* Opt::Grafico()
{
  cout << "Eu quero fazer um grafico e ja consigo!" << endl;

  TGraphErrors *gr1 = new TGraphErrors(dados.c_str(),"%lg %lg %lg %lg");
  gr1->SetName("gr1");
  gr1->SetTitle("graph 1");
  gr1->SetMarkerStyle(20);
  gr1->SetMarkerColor(kRed);

  return gr1;
}


//Faz um histograma
TH1F* Opt::Histograma()
{
  cout << "Eu quero fazer um histograma e nao me deixam." << endl;
}
