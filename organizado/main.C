//Header's de ROOT
#include "TROOT.h"  //Principal
#include "TFrame.h"  //gClient
#include "TCanvas.h"  //Ecra principal dos graficos
#include "TPad.h"  //"Subcanvas"
#include "TSystem.h"  //Nao faco ideia
#include "TApplication.h"  //Janela
#include "TAxis.h"  //Eixos dos graficos
#include "TMultiGraph.h"  //Varios graficos sobrepostos

//Header's nao de ROOT
#include <iostream>  //Porque razoes
#include <fstream>  //Ficheiros
#include "Opt.h"

using namespace std;

int main(int argc, char **argv)
{
  
  cout << "Hail Eris! All hail Discordia!" << endl;

  if (argc != 3)
  {
    cout << "Faltam argumentos. Ler manual." << endl;
    return 0;
  }

  const char* paramf = argv[1];
  const char* dadosf = argv[2];

  ifstream det(paramf);
  if(det.is_open())
    cout << "Ficheiro aberto com sucesso" << endl;
  else
    cout << "Erro. Nao foi possivel abrir o ficheiro" << endl;
  det.close();

  //faz aparecer o canvas
  TApplication theApp("App", &argc, argv);
  theApp.InitializeGraphics();

  TCanvas *c1 = new TCanvas("c1","Nome",200,10,700,500);
  c1->SetFillColor(0);
  c1->SetGrid();
  c1->GetFrame()->SetFillColor(21);
  c1->GetFrame()->SetBorderSize(12);

  TMultiGraph *mg = new TMultiGraph("mg","mg");
  //mg->SetTitle(titulo.c_str());
  mg->SetTitle("Por favor, funciona");


  Opt *Decisao = new Opt(paramf, dadosf);
  string escolha = Decisao->Escolher();  
  cout << escolha << endl;

  if (escolha == "grafico")
  {
    TGraphErrors* gr = Decisao->Grafico();
    mg->Add(gr);
  }
  else if (escolha == "histograma")
  {
    Decisao->Histograma();
  }
  else if (escolha == "Fit")
  {
    Decisao->Ajuste();
  }


  mg->Draw("AP");
  mg->GetXaxis()->SetLimits(0.0,11.0);
  mg->SetMinimum(0.);
  mg->SetMaximum(11.);
  c1->Update();

  c1->Modified();
  c1->Print("plot.pdf");
  getchar();

  theApp.Terminate();

  return 0;
}
