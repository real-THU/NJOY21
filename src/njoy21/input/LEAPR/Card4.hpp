class Card4 {
  public:
  #include "njoy21/input/LEAPR/Card4/Mat.hpp"
  #include "njoy21/input/LEAPR/Card4/Za.hpp"

  Argument< Mat   > mat;
  Argument< Za     > za;

  template< typename Char >
  Card4( iRecordStream<Char>& is )
  try:
    mat  ( argument::extract< Mat  >( is ) ),
    za   ( argument::extract< Za   >( is ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble while validating LEAPR Card4" );
    throw e;
  }
};
