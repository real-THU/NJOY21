class DummyMF33 {
public:

#include "njoy21/input/ERRORR/DummyMF33/Card2.hpp"
#include "njoy21/input/ERRORR/DummyMF33/Card3.hpp"

#include "njoy21/input/ERRORR/DummyMF33/src/readCard3List.hpp"

Card2 card2;
std::vector< Card3 > card3List;

template< typename Istream >
DummyMF33( Istream& is )
try:
  card2( is ),
  card3List( readCard3List( is ) )
{
}
catch( std::exception& e ){
  Log::info( "Trouble reading ERRORR dummy mf33 input." );
  throw e;
}
};
