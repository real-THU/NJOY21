class Card8{
public:

#include "njoy21/input/POWR/Lib3/Card8/Identa.hpp"
#include "njoy21/input/POWR/Lib3/Card8/Decay.hpp"
#include "njoy21/input/POWR/Lib3/Card8/Yield.hpp"

Argument< Identa > identa;
Argument< Decay > decay;
Argument< Yield > yield;

template< typename Istream >
Card8( Istream& is, const int nfis )
try:
  identa( argument::extract< POWR::Lib3::Card8::Identa >( is ) ),
  decay( argument::extract< POWR::Lib3::Card8::Decay >( is ) ),
  yield( argument::extract< POWR::Lib3::Card8::Yield >( is, nfis+2 ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card 8." );
  throw e;
}
};
