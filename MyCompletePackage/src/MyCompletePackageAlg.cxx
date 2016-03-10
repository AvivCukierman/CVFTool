// MyCompletePackage includes
#include "MyCompletePackageAlg.h"



MyCompletePackageAlg::MyCompletePackageAlg( const std::string& name, ISvcLocator* pSvcLocator ) :
  AthAnalysisAlgorithm( name, pSvcLocator ),
  m_theTrackExtrapolatorTool("Trk::ParticleCaloExtensionTool",this)
{
  declareProperty("TrackExtrapolatorTool", m_theTrackExtrapolatorTool, "AlgTool to use for track extrapolation");
}


MyCompletePackageAlg::~MyCompletePackageAlg() {}


StatusCode MyCompletePackageAlg::initialize() {
  ATH_MSG_INFO ("Initializing " << name() << "...");
  //m_CVFTool.setTypeAndName("CVFTool/MyCVFTool");
  //m_theTrackExtrapolatorTool.setTypeAndName("Trk::ParticleCaloExtensionTool/TrackCaloExtensionTool");
  //m_TrackCaloExtensionTool.setTypeAndName("eflowTrackCaloExtensionTool/MyTrackCaloExtensionTool");
  //m_TrackCaloExtensionTool.setProperty("TrackCaloExtensionTool",m_theTrackExtrapolatorTool);

  StatusCode sc;
  // tool service
  IToolSvc* myToolSvc;
  sc = service("ToolSvc", myToolSvc);
  if (sc.isFailure()) {
    msg(MSG::WARNING) << " Tool Service Not Found" << endreq;
    return StatusCode::SUCCESS;
  }
  sc = m_theTrackExtrapolatorTool.retrieve();
  if (sc.isFailure()) {
    msg(MSG::WARNING) << "Cannot find eflowTrackToCaloExtrapolatorTool " << endreq;
    return StatusCode::SUCCESS;
  }

  return sc;
}

StatusCode MyCompletePackageAlg::finalize() {
  ATH_MSG_INFO ("Finalizing " << name() << "...");

  return StatusCode::SUCCESS;
}

StatusCode MyCompletePackageAlg::execute() {  
  ATH_MSG_DEBUG ("Executing " << name() << "...");

  std::string m_trackContainer = "InDetForwardTrackParticles";
  const xAOD::TrackParticleContainer* tracks(nullptr);
  if(evtStore()->retrieve(tracks,m_trackContainer).isFailure()) ATH_MSG_ERROR("Could not retrieve the tracks.");
  std::cout << "Tracks" << std::endl;
  for(auto track: *tracks){
    std::cout << "t: " << track->pt() << std::endl;
    //m_theTrackExtrapolatorTool->execute(track);
  }
  /*m_CVFTool->execute();

  std::string m_outputContainer = "CVFClusters";
  const xAOD::CaloClusterContainer*             CVF_clusters   (nullptr);
  if(evtStore()->retrieve(CVF_clusters,m_outputContainer).isFailure()) ATH_MSG_ERROR("Could not retrieve the CVF cluster container");
  for(auto clust: *CVF_clusters) std::cout << "v: " << clust->pt() << std::endl;*/

  /*std::string m_inputContainer = "CaloCalTopoClusters";
  const xAOD::CaloClusterContainer*             in_clusters   (nullptr);
  if(evtStore()->retrieve(in_clusters,m_inputContainer).isFailure()) ATH_MSG_ERROR("Could not retrieve the input cluster container");
  for(auto clust: *in_clusters) std::cout << "i: " << clust->pt() << std::endl;*/

  return StatusCode::SUCCESS;
}

StatusCode MyCompletePackageAlg::beginInputFile() {  
  //example of metadata retrieval:
  //float beamEnergy(0); CHECK( retrieveMetadata("/TagInfo","beam_energy",beamEnergy) );
  //std::vector<float> bunchPattern; CHECK( retrieveMetadata("/Digitiation/Parameters","BeamIntensityPattern",bunchPattern) );

  return StatusCode::SUCCESS;
}


