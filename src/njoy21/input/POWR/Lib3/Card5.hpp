class Card5{
public:

#include "njoy21/input/POWR/Lib3/Card5/Nina.hpp"
#include "njoy21/input/POWR/Lib3/Card5/Ntemp.hpp"
#include "njoy21/input/POWR/Lib3/Card5/Nsigz.hpp"
#include "njoy21/input/POWR/Lib3/Card5/Sgref.hpp"
#include "njoy21/input/POWR/Lib3/Card5/Ires.hpp"
#include "njoy21/input/POWR/Lib3/Card5/Sigp.hpp"
#include "njoy21/input/POWR/Lib3/Card5/Mti.hpp"
#include "njoy21/input/POWR/Lib3/Card5/Mtc.hpp"
#include "njoy21/input/POWR/Lib3/Card5/Ip1opt.hpp"
#include "njoy21/input/POWR/Lib3/Card5/Inorf.hpp"
#include "njoy21/input/POWR/Lib3/Card5/Pos.hpp"
#include "njoy21/input/POWR/Lib3/Card5/Posr.hpp"

#include "njoy21/input/POWR/Lib3/Card5/src/readNina03.hpp"
#include "njoy21/input/POWR/Lib3/Card5/src/readNtapea0.hpp"
#include "njoy21/input/POWR/Lib3/Card5/src/readMode0.hpp"

Argument< Nina > nina;
Argument< Ntemp > ntemp;
Argument< Nsigz > nsigz;
Argument< Sgref > sgref;
optional< std::pair< Argument< Ires >, Argument< Sigp > > > nina03;
optional< std::tuple< Argument< Mti >, Argument< Mtc >, Argument< Ip1opt >,
                                                  Argument< Inorf > > > ntapea0;
optional< std::pair< Argument< Pos >, Argument< Posr > > > mode0;

template< typename Istream >
Card5( Istream& is, const int mode )
try:
  nina( argument::extract< POWR::Lib3::Card5::Nina >( is ) ),
  ntemp( argument::extract< POWR::Lib3::Card5::Ntemp >( is ) ),
  nsigz( argument::extract< POWR::Lib3::Card5::Nsigz >( is ) ),
  sgref( argument::extract< POWR::Lib3::Card5::Sgref >( is ) ),
  nina03( readNina03( is, this->nina.value ) ),
  ntapea0( readNtapea0( is, 0 ) ),
  mode0( readMode0( is, mode ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card 5." );
  throw e;
}
};
