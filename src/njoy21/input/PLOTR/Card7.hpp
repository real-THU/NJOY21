class Card7 {
public:
  #include "njoy21/input/PLOTR/Card7/Rbot.hpp"
  #include "njoy21/input/PLOTR/Card7/Rtop.hpp"
  #include "njoy21/input/PLOTR/Card7/Rstep.hpp"

  Argument< Rbot > rbot;
  Argument< Rtop > rtop;
  Argument< Rstep > rstep;

  template< typename Char >
  Card7 ( iRecordStream< Char >& is )
    try:
      rbot( argument::extract< Rbot >( is ) ),
      rtop( argument::extract< Rtop >( is, this->rbot.value ) ),
      rstep( argument::extract< Rstep >( is, this->rbot.value ) )
      {
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble validating Card7" );
      throw e;
    }
};
