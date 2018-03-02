#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Yl output values", "[PLOTR],[Card6], [Yl]"){

  std::vector<int> itype{1,2,3,4};

  GIVEN( "valid entries" ){
  
    WHEN( "valid Yl parameters for linear scale" ){
      std::vector<double> validValues{0.0,0.1,0.5,0.8,1.0,2.0,80.0};
  
      THEN( "the returned class has the correct value" ){
        for( auto yl : validValues ){
          iRecordStream<char> issYl( 
              std::istringstream( std::to_string( yl ) ) );
  
          REQUIRE( yl == *( argument::extract< PLOTR::Card6::Yl >( 
                            issYl, itype[0] ).value ) );
        }
      }
    }
  
    WHEN( "valid Yl parameters for log scale" ){
      std::vector<double> validValues{0.1,0.5,0.8,1.0,2.0,80.0};
  
      THEN( "the returned class has the correct value" ){
        for( auto yl : validValues ){
          iRecordStream<char> issYl( 
              std::istringstream( std::to_string( yl ) ) );
  
          REQUIRE( yl == *( argument::extract< PLOTR::Card6::Yl >( 
                            issYl, itype[1] ).value ) );
        }
      }
    }
  
    WHEN( "default value is used" ){
      iRecordStream<char> issYl( std::istringstream( " /" ) );
  
      THEN( "default value is returned" ){
        REQUIRE( std::nullopt == argument::extract< PLOTR::Card6::Yl >(
                            issYl, itype[2] ).value );
      }
    }
  }

  GIVEN( "invalid Yl parameters" ){
    std::vector<double> invalidValues{ -2.0, -1.1, 0.0 };

    THEN( "the class throws an exception" ){
      for( auto yl : invalidValues ){
        iRecordStream<char> issYl( 
            std::istringstream( std::to_string( yl ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card6::Yl >(
                          issYl, itype[1] ) );
      }
    }
  } // GIVEN
} // SCENARIO
