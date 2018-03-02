class Card5{
public:

#include "njoy21/input/POWR/Lib2/Card5/Xi.hpp"
#include "njoy21/input/POWR/Lib2/Card5/Alpha.hpp"
#include "njoy21/input/POWR/Lib2/Card5/Mubar.hpp"
#include "njoy21/input/POWR/Lib2/Card5/Nu.hpp"
#include "njoy21/input/POWR/Lib2/Card5/KappaFission.hpp"
#include "njoy21/input/POWR/Lib2/Card5/KappaCapture.hpp"
#include "njoy21/input/POWR/Lib2/Card5/Lambda.hpp"
#include "njoy21/input/POWR/Lib2/Card5/SigmaS.hpp"

Argument< Xi > xi;
Argument< Alpha > alpha;
Argument< Mubar > mubar;
Argument< Nu > nu;
Argument< KappaFission > kappaFission;
Argument< KappaCapture > kappaCapture;
Argument< Lambda > lambda;
Argument< SigmaS > sigmaS;

template< typename Istream >
Card5( Istream& is )
try:
  xi( argument::extract< POWR::Lib2::Card5::Xi >( is ) ),
  alpha( argument::extract< POWR::Lib2::Card5::Alpha >( is ) ),
  mubar( argument::extract< POWR::Lib2::Card5::Mubar >( is ) ),
  nu( argument::extract< POWR::Lib2::Card5::Nu >( is ) ),
  kappaFission( argument::extract< POWR::Lib2::Card5::KappaFission >( is ) ),
  kappaCapture( argument::extract< POWR::Lib2::Card5::KappaCapture >( is ) ),
  lambda( argument::extract< POWR::Lib2::Card5::Lambda >( is ) ),
  sigmaS( argument::extract< POWR::Lib2::Card5::SigmaS >( is ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card 5." );
  throw e;
}
};
