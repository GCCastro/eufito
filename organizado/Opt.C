#include "Opt.h"
#include "fstream"
#include "TF1.h"

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
    det.ignore(256,':');
    getline(det,titulo);
    det.ignore(256,':');
    getline(det,func);
    
  }
  det.close();
  cout << "O ficheiro de parametros e " << ficheiro << " e a opcao e " << opcao << endl;
}


//Decide, baseado na opcao, que grafico fazer; Chama funcao adequada
vector<string> Opt::Escolher()
{
  if ( (opcao!="fit") & (opcao!="grafico") & (opcao!="histograma") )
  {
    opcao.clear();
    cout << "opcao invalida. adeus" << endl;
  }

  mainsender.push_back(opcao);
  mainsender.push_back(titulo);
  return mainsender;
}


//Faz um ajuste
TGraphErrors* Opt::Ajuste(TGraphErrors* gr1)
{
  cout << "Eu quero fazer um ajuste e jame deixam." << endl;

  TF1 *f1 = new TF1("f1",func.c_str());
  //  f1->SetParLimits(0,7,9);
  f1->SetLineColor(kBlue);
  gr1->Fit("f1","EMF");
 
 
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

  gr1->SetLineColor(1);
  gr1->SetLineWidth(1);
  gr1->SetFillStyle(0);

  return gr1;
}


//Faz um histograma
TH1F* Opt::Histograma()
{
  cout << "Eu quero fazer um histograma e nao me deixam." << endl;
}
