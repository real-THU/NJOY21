#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card6a, Identa",
          "[WIMSR] [Card6a] [Identa]" ){
  GIVEN( "valid inputs" ){
    for( auto i : {1, 10, 100, 1000, 9999} ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE(i == argument::extract< WIMSR::Card6a::Identa >( iss ).value);
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    for( auto i : {0, 10000} ){
      std::string situ( "invalid value " + std::to_string(i) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< WIMSR::Card6a::Identa >( iss ) );
        }
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< WIMSR::Card6a::Identa >( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
