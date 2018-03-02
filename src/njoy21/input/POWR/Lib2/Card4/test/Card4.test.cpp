#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib2, Card4",
          "[POWR] [Lib2] [Card4]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0 1 2 /" ) );

      POWR::Lib2::Card4 card4( iss );

      THEN( "the values can be verified" ){
        REQUIRE( 0 == card4.itrc.value );
        REQUIRE( 1 == card4.mti.value );
        REQUIRE( 2 == card4.mtc.value );
      }
    } // WHEN

    WHEN( "all defaults are used" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      POWR::Lib2::Card4 card4( iss );

      THEN( "the default values can be verified" ){
        REQUIRE( 0 == card4.itrc.value );
        REQUIRE( 0 == card4.mti.value );
        REQUIRE( 0 == card4.mtc.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an extra value is given" ){
      iRecordStream<char> iss( std::istringstream( " 0 1 2 3 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib2::Card4( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is given" ){
      iRecordStream<char> iss( std::istringstream( " -1 1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib2::Card4( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
