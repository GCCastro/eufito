#include "Opt.h"
#include "fstream"
#include "TF1.h"
#include <cstdlib>

using namespace std;
//merdas

//Construtor
Opt::Opt(string fparam, string fdados)
{
  string dim1,dim2,dim3,dim4;
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
    det.ignore(256,':');
    getline(det,dim1);
    det.ignore(256,':');
    getline(det,dim2);
    det.ignore(256,':');
    getline(det,dim3);
    det.ignore(256,':');
    getline(det,dim4);

  }
  det.close();
  dim.push_back(atof(dim1.c_str()));
  dim.push_back(atof(dim2.c_str()));
  dim.push_back(atof(dim3.c_str()));
  dim.push_back(atof(dim4.c_str()));

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
  //  f1->SetParLimits(1,0.000104,0.000107);
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
  gr1->SetMarkerStyle(1);
  gr1->SetMarkerColor(kRed);
  gr1->SetLineWidth(1);

  gr1->SetLineColor(1);
  gr1->SetLineWidth(0.1);
  gr1->SetFillStyle(0);

  gr1->GetXaxis()->SetLimits(dim[0],dim[1]);
  gr1->GetYaxis()->SetLimits(dim[2],dim[3]);
  //gr1->SetMinimum(dim[2]);
  //gr1->SetMaximum(dim[3]);


  return gr1;
}


//Faz um histograma
TH1F* Opt::Histograma()
{
  cout << "Eu quero fazer um histograma e nao me deixam." << endl;

  TH1F *hist = new TH1F("Stats",titulo.c_str(),100,-3,3);
  return hist;


}


vector<int> Opt::Return_dims()
{
  return dim;
}
