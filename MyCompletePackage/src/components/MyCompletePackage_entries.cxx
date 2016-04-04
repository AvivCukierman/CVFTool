
#include "GaudiKernel/DeclareFactoryEntries.h"

#include "../MyCompletePackageAlg.h"

DECLARE_ALGORITHM_FACTORY( MyCompletePackageAlg )

DECLARE_FACTORY_ENTRIES( MyCompletePackage ) 
{
  DECLARE_ALGORITHM( MyCompletePackageAlg );
}
