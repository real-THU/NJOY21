#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Normal, Card7, Legord",
          "[ERRORR] [Normal] [Card7] [Legord]" ){
  GIVEN( "valid inputs" ){
    WHEN( "a valid input is provided" ){
      const int mfcov = 34;
      iRecordStream<char> iss( std::istringstream( " 1 /" ) );

      THEN( "the value can be verified" ){
        REQUIRE( 1 == argument::extract< ERRORR::Normal::Card7::Legord >(
                                                           iss, mfcov ).value );
      }
    } // WHEN

    WHEN( "no input is provided" ){
      const int mfcov = 34;
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value is provided" ){
        REQUIRE( 1 == argument::extract< ERRORR::Normal::Card7::Legord >(
                                                           iss, mfcov ).value );
      }
    } // WHEN

    for( auto i : {31, 33, 35, 40} ){
      for( auto j : {-1, 0, 1, 2, 3} ){
        std::string situ( "mfcov == " + std::to_string( i ) + " and legord == "
                        + std::to_string( j ) );
        WHEN( situ.c_str() ){
          iRecordStream<char> iss( std::istringstream( std::to_string( j ) ) );

          THEN( "the value doesn't matter" ){
            REQUIRE( j == argument::extract< ERRORR::Normal::Card7::Legord >(
                                                               iss, i ).value );
          }
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    for( auto i : {0, 2} ){
      std::string situ( "invalid input " + std::to_string(i) + " is provided.");
      WHEN( situ.c_str() ){
        const int mfcov = 34;
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS(
             argument::extract< ERRORR::Normal::Card7::Legord >( iss, mfcov ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
