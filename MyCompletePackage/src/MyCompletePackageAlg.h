#ifndef MYCOMPLETEPACKAGE_MYCOMPLETEPACKAGEALG_H
#define MYCOMPLETEPACKAGE_MYCOMPLETEPACKAGEALG_H 1

#include "AthAnalysisBaseComps/AthAnalysisAlgorithm.h"
//#include "JetRecTools/JetRecTools/CVFTool.h"
//#include "JetRecTools/JetRecTools/JetTrackSelectionTool.h"
#include "eflowRec/eflowTrackCaloExtensionTool.h"
#include "eflowRec/eflowTrackExtrapolatorBaseAlgTool.h"
#include "RecoToolInterfaces/IParticleCaloExtensionTool.h"

#include "xAODTracking/TrackParticle.h"
#include "xAODTracking/TrackParticleContainer.h"

/*namespace Trk {
  //class IParticleCaloExtensionTool;
  class TrackParametersIdHelper;
}*/


class MyCompletePackageAlg: public ::AthAnalysisAlgorithm { 
 public: 
  MyCompletePackageAlg( const std::string& name, ISvcLocator* pSvcLocator );
  virtual ~MyCompletePackageAlg(); 

  virtual StatusCode  initialize();
  virtual StatusCode  execute();
  virtual StatusCode  finalize();
  
  virtual StatusCode beginInputFile();

 private: 
  //ToolHandle<IJetExecuteTool> m_CVFTool;
  //ToolHandle<eflowTrackExtrapolatorBaseAlgTool> m_TrackCaloExtensionTool;
  ToolHandle<eflowTrackExtrapolatorBaseAlgTool> m_theTrackExtrapolatorTool;
  //ToolHandle<Trk::IParticleCaloExtensionTool> m_theTrackExtrapolatorTool;

}; 

#endif //> !MYCOMPLETEPACKAGE_MYCOMPLETEPACKAGEALG_H
