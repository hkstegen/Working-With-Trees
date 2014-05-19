#include <TFile.h>
#include <TTree.h>
#include <TBrowser.h>
#include <TRandom.h>
#include <TCanvas.h>
#include <TROOT.h>
#include <TH2.h>
#include <TLorentzVector.h>

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
			
		canvas1 = new TCanvas("En_bm", "En_bm as function of GeV and MeV");
		canvas1->Divide(1,2);
			
		canvas1->cd(1); En_bm_GeV->Draw();
		canvas1->cd(2); En_bm_MeV->Draw();
		
		Float_t Px_l0114, Py_l0114, Pz_l0114, Pt_l0114, En_l0114;
		Float_t Px_l0201, Py_l0201, Pz_l0201, Pt_l0201, En_l0201;
		Float_t Px_l0301, Py_l0301, Pz_l0301, Pt_l0301, En_l0301;
			
		tree->SetBranchAddress("Px_l0114", &Px_l0114);
		tree->SetBranchAddress("Py_l0114", &Py_l0114);
		tree->SetBranchAddress("Pz_l0114", &Pz_l0114);
		tree->SetBranchAddress("Pt_l0114", &Pt_l0114);
		tree->SetBranchAddress("En_l0114", &En_l0114);
		
		tree->SetBranchAddress("Px_l0201", &Px_l0201);
		tree->SetBranchAddress("Py_l0201", &Py_l0201);
		tree->SetBranchAddress("Pz_l0201", &Pz_l0201);
		tree->SetBranchAddress("Pt_l0201", &Pt_l0201);
		tree->SetBranchAddress("En_l0201", &En_l0201);
		
		tree->SetBranchAddress("Px_l0301", &Px_l0301);
		tree->SetBranchAddress("Py_l0301", &Py_l0301);
		tree->SetBranchAddress("Pz_l0301", &Pz_l0301);
		tree->SetBranchAddress("Pt_l0301", &Pt_l0301);
		tree->SetBranchAddress("En_l0301", &En_l0301);
		
		TLorentzVector v1;
		TLorentzVector v2;
		TLorentzVector v3;		
		
		Float_t Px1n, Py1n, Pz1n;
		Float_t Px2n, Py2n, Pz2n;
		Float_t Px3n, Py3n, Pz3n;
		
		Double_t theta1, phi1;
		Double_t theta2, phi2;
		Double_t theta3, phi3;
		
		TH1F *Theta2 = new TH1F("Theta2", "Theta2", 100, 0, 7);
		TH1F *Phi2 = new TH1F("Phi2", "Phi2", 100, 244, 7);
		TH1F *Theta3 = new TH1F("Theta3", "Theta3", 100, 0, 7);
		TH1F *Phi3 = new TH1F("Phi3", "Phi3", 100, 0, 7);
		
		for (Int_t i=0;i<nentries; i++)
			{
				tree->GetEntry(i);
				
				Px1n=Px_l0114*Pt_l0114;
				Py1n=Py_l0114*Pt_l0114;
				Pz1n=Pz_l0114*Pt_l0114;
				
				Px2n=Px_l0201*Pt_l0201;
				Py2n=Py_l0201*Pt_l0201;
				Pz2n=Pz_l0201*Pt_l0201;
				
				Px3n=Px_l0301*Pt_l0301;
				Py3n=Py_l0301*Pt_l0301;
				Pz3n=Pz_l0301*Pt_l0301;
				
				v1.SetPxPyPzE(Px1n,Py1n,Pz1n,En_l0114);
				v2.SetPxPyPzE(Px2n,Py2n,Pz2n,En_l0201);
				v3.SetPxPyPzE(Px3n,Py3n,Pz3n,En_l0301);
				
				Double_t theta2 = v2.Theta();
				Double_t phi2 = v2.Phi();
				Double_t theta3 = v3.Theta();
				Double_t phi3 = v3.Phi();
				
				Theta2->Fill(theta2);
				Phi2->Fill(phi2);
				Theta3->Fill(theta3);
				Phi3->Fill(phi3);
				
			}
			
			Theta2->GetYaxis()->SetTitle("# of Counts");
			Phi2->GetYaxis()->SetTitle("# of Counts");
			Theta3->GetYaxis()->SetTitle("# of Counts");
			Phi3->GetYaxis()->SetTitle("# of Counts");
			
			canvas2 = new TCanvas("Photon Angles", "Photon Angles");
			canvas2->Divide(1,4);
			
			canvas2->cd(1); Theta2->Draw();
			canvas2->cd(2); Phi2->Draw();
			canvas2->cd(3); Theta3->Draw();
			canvas2->cd(4); Phi3->Draw();
		}
		
	
