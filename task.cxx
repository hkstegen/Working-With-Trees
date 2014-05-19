#include <TFile.h>
#include <TTree.h>
#include <TBrowser.h>
#include <TRandom.h>
#include <TCanvas.h>
#include <TROOT.h>
#include <TH2.h>

void LearningTrees(Char_t* name = "Pi0_mc_out_250.root")
	{
		TFile *file = new TFile(name);
		TTree *tree=(TTree*)file->Get("h1");
		
		Float_t En_bm;
		
		tree->SetBranchAddress("En_bm",	&En_bm);
		
		TH1F *En_bm_Gev = new TH1F("En_bm_GeV", "Energy of Incoming Photon Beam (GeV)", 100, 0.244, 0.256);
		TH1F *En_bm_MeV = new TH1F("En_bm_MeV", "Energy of Incoming Photon Beam (MeV)", 100, 244, 256);
		
		En_bm_GeV->GetYaxis()->SetTitle("# of Counts");
		En_bm_MeV->GetYaxis()->SetTitle("# of Counts");
		
		Int_t nentries = (Int_t)tree->GetEntries();
		for (Int_t i=0;i<nentries; i++)
			{
				tree->GetEntry(i);
				
				En_bm_GeV->Fill(En_bm);
				En_bm_MeV->Fill(En_bm*1000);
				
			}
			
			canvas = new TCanvas("En_bm", "En_bm as function of GeV and MeV");
			canvas->Divide(1,2);
			
			canvas->cd(1); En_bm_GeV->Draw();
			canvas->cd(2); En_bm_MeV->Draw();
		}
		
	
