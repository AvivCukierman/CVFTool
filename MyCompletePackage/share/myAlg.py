try:
  from eflowRec.eflowRecConf import eflowTrackCaloExtensionTool
  TrackCaloExtensionTool=eflowTrackCaloExtensionTool()
except:
  mlog.error("could not import eflowRec.eflowTrackCaloExtensionTool")
  print traceback.format_exc()
CfgMgr.MyCompletePackageAlg().TrackExtrapolatorTool = TrackCaloExtensionTool

algseq = CfgMgr.AthSequencer("AthAlgSeq")                #gets the main AthSequencer
algseq += CfgMgr.MyCompletePackageAlg()                                 #adds an instance of your alg to it

include ("RecExCommon/RecExCommon_topOptions.py")
