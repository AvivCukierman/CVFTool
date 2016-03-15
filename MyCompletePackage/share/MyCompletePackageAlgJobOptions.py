#Skeleton joboption for a simple analysis job

theApp.EvtMax=10                                         #says how many events to run over. Set to -1 for all events

import AthenaPoolCnvSvc.ReadAthenaPool                   #sets up reading of POOL files (e.g. xAODs)
svcMgr.EventSelector.InputCollections=["/afs/cern.ch/user/a/acukierm/Datasets/AOD.05771185._000079.pool.root.1"]   #insert your list of input files here
#ToolSvc += CfgMgr.CVFTool("MyCVFTool",InputContainer="CaloCalTopoClusters",OutputContainer="CVFClusters",doSpread=False)

include("AthAnalysisBaseComps/SuppressLogging.py")       #Optional include to suppress as much athena output as possible

UserAlgs = ["myAlg.py"]
include ("RecExCommon/RecExCommon_topOptions.py")
