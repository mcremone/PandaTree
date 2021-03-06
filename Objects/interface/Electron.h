#ifndef PandaTree_Objects_Electron_h
#define PandaTree_Objects_Electron_h
#include "Constants.h"
#include "Lepton.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"
#include "SuperCluster.h"

namespace panda {

  class Electron : public Lepton {
  public:
    enum TriggerObject {
      fEl23El12FirstLeg,
      fEl23El12SecondLeg,
      fEl25Tight,
      fEl27Loose,
      fEl27Tight,
      fEl35Tight,
      fPh165HE10,
      fPh175,
      fPh200,
      fPh36EBR9Iso,
      nTriggerObjects
    };

    static TString TriggerObjectName[nTriggerObjects];

    struct datastore : public Lepton::datastore {
      datastore() : Lepton::datastore() {}
      ~datastore() { deallocate(); }

      /* ParticleP
      Float_t* pt_{0};
      Float_t* eta_{0};
      Float_t* phi_{0};
      */
      /* Lepton
      Float_t* pfPt{0};
      Char_t* charge{0};
      Bool_t* loose{0};
      Bool_t* medium{0};
      Bool_t* tight{0};
      Bool_t* hltsafe{0};
      Float_t* chIso{0};
      Float_t* nhIso{0};
      Float_t* phIso{0};
      Float_t* puIso{0};
      Float_t* dxy{0};
      Float_t* dz{0};
      ContainerBase const* matchedPFContainer_{0};
      Short_t* matchedPF_{0};
      ContainerBase const* matchedGenContainer_{0};
      Short_t* matchedGen_{0};
      ContainerBase const* vertexContainer_{0};
      Short_t* vertex_{0};
      */
      Float_t* chIsoPh{0};
      Float_t* nhIsoPh{0};
      Float_t* phIsoPh{0};
      Float_t* ecalIso{0};
      Float_t* hcalIso{0};
      Float_t* trackIso{0};
      Float_t* isoPUOffset{0};
      Float_t* sieie{0};
      Float_t* sipip{0};
      Float_t* dEtaInSeed{0};
      Float_t* dPhiIn{0};
      Float_t* eseed{0};
      Float_t* hOverE{0};
      Float_t* ecalE{0};
      Float_t* trackP{0};
      Float_t* regPt{0};
      Float_t* smearedPt{0};
      UShort_t* nMissingHits{0};
      Bool_t* veto{0};
      Bool_t* conversionVeto{0};
      Bool_t* tripleCharge{0};
      Bool_t (*triggerMatch)[nTriggerObjects]{0};
      ContainerBase const* superClusterContainer_{0};
      Short_t* superCluster_{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, utils::BranchList const&) override;
      utils::BranchList getStatus(TTree&, TString const&) const override;
      utils::BranchList getBranchNames(TString const& = "") const override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef Array<Electron> array_type;
    typedef Collection<Electron> collection_type;

    typedef Lepton base_type;

    Electron(char const* name = "");
    Electron(Electron const&);
    Electron(datastore&, UInt_t idx);
    ~Electron();
    Electron& operator=(Electron const&);

    static char const* typeName() { return "Electron"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    double m() const override { return 5.109989e-4; }
    double combIso() const override { return chIso + std::max(nhIso + phIso - isoPUOffset, Float_t(0.)); }

    /* Lepton
    Float_t& pfPt; // for E: Pt of the dR-closest PF candidate; for Mu: pfP4().pt()
    Char_t& charge;
    Bool_t& loose;
    Bool_t& medium;
    Bool_t& tight;
    Bool_t& hltsafe;
    Float_t& chIso;
    Float_t& nhIso;
    Float_t& phIso;
    Float_t& puIso;
    Float_t& dxy;
    Float_t& dz;
    Ref<PFCand> matchedPF;
    Ref<GenParticle> matchedGen;
    Ref<Vertex> vertex;
    */
    Float_t& chIsoPh;
    Float_t& nhIsoPh;
    Float_t& phIsoPh;
    Float_t& ecalIso;
    Float_t& hcalIso;
    Float_t& trackIso;
    Float_t& isoPUOffset;
    Float_t& sieie;
    Float_t& sipip;
    Float_t& dEtaInSeed;
    Float_t& dPhiIn;
    Float_t& eseed;
    Float_t& hOverE;
    Float_t& ecalE;
    Float_t& trackP;
    Float_t& regPt;
    Float_t& smearedPt;
    UShort_t& nMissingHits;
    Bool_t& veto;
    Bool_t& conversionVeto;
    Bool_t& tripleCharge;
    Bool_t (&triggerMatch)[nTriggerObjects];
    Ref<SuperCluster> superCluster;

  protected:
    /* ParticleP
    Float_t& pt_;
    Float_t& eta_;
    Float_t& phi_;
    */

  public:
    /* BEGIN CUSTOM Electron.h.classdef */
    /* END CUSTOM */

    static utils::BranchList getListOfBranches();

    void destructor(Bool_t recursive = kFALSE);

  protected:
    Electron(ArrayBase*);

    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doInit_() override;
  };

  typedef Array<Electron> ElectronArray;
  typedef Collection<Electron> ElectronCollection;
  typedef Ref<Electron> ElectronRef;
  typedef RefVector<Electron> ElectronRefVector;

  /* BEGIN CUSTOM Electron.h.global */
  /* END CUSTOM */

}

#endif
