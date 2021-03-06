#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Iza01 input values", "[ACER], [Card8a], [Iza01]" ){
  GIVEN( "valid iza01 values" ){
    THEN( "the returned class has the correct value" ){
      for( auto iza01 : { 1001, 92235, 100000, 199999 } ){
        iRecordStream<char> issIza01( 
            std::istringstream( std::to_string(iza01) ) );
        auto iza01Arg = argument::extract< ACER::Card8a::Iza01 >(issIza01 );
        REQUIRE( iza01 == iza01Arg.value );
      }
    }
  }
  GIVEN( "invalid iza01 values" ){
    std::vector<int> validIza01{ 1001, 92235, 100000, 199999 };

    THEN( "an exception is thrown" ){
      for( auto iza01 : {-1001, 200000 } ){
        iRecordStream<char> issIza01( 
            std::istringstream( std::to_string(iza01) ) );
        REQUIRE_THROWS( argument::extract< ACER::Card8a::Iza01 >(issIza01 ) );
      }
    }
  }
}

