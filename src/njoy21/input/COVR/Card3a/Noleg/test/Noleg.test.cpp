#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "noleg output values",
  "[COVR], [Card3a], [Noleg]"){
  GIVEN( "valid inputs for noleg" ){
    WHEN( "the noleg value is provided" ){
      THEN( "the returned class has the correct tape value" ){
        for( auto& noleg : {-1, 0, 1} ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( noleg ) ) );
          REQUIRE( noleg == argument::extract< 
            COVR::Card3a::Noleg >( iss ).value );
        }
      } // THEN
    } // WHEN

    WHEN( "no noleg value given " ){
      THEN( "default value is substituted in" ){
        iRecordStream<char> iss( std::istringstream( "  /" ) );
        REQUIRE( 0 == argument::extract< COVR::Card3a::Noleg > ( iss ).value );
      } // THEN
    } // WHEN
  
    WHEN( "noleg tapes are out of range" ){
      THEN( "an exception is thrown" ){
        for( auto& noleg : {-2, 2} ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( noleg ) ) );
          REQUIRE_THROWS( argument::extract< COVR::Card3a::Noleg>( iss ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

