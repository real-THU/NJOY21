#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Wght input values", "[Card8b], [Wght]" ){
  GIVEN( "Valid pseudo-TAB1 input" ){
    THEN( "the returned TAB1 has the correct values" ){
      iRecordStream<char>
        iss( std::istringstream
             (" 0. 0. 0 0 1 6\n"
              "6 5\n"
              "1.00000E-05 8.00000E-20 1.00000E+03 9.13415E-10 1.00000E+04 6.13955E-08\n"
              "1.00925E+04 6.17490E-08 1.01859E+04 6.09190E-08 1.02802E+04 6.19874E-08\n" ) );

      njoy::ENDFtk::TAB1 tab1 =
        argument::extract< GROUPR::Card8b::Wght >( iss ).value;

      REQUIRE( 1 == tab1.NR() );
      REQUIRE( 6 == tab1.NP() );

      std::vector<double> x{1.00000E-05, 1.00000E+03, 1.00000E+04,
                            1.00925E+04, 1.01859E+04, 1.02802E+04};
      std::vector<double> y{8.00000E-20, 9.13415E-10, 6.13955E-08,
                            6.17490E-08, 6.09190E-08, 6.19874E-08};

      REQUIRE( ranges::equal(x, tab1.x()) );
      REQUIRE( ranges::equal(y, tab1.y()) );
    }
  }

  GIVEN( "invalid pseudo-TAB1 input" ){
    WHEN( "energy value is negative" ){
      THEN( "an exception is thrown" ){
        iRecordStream<char>
          iss( std::istringstream
               ( " 0. 0. 0 0 1 6\n"
                 "6 5\n"
                 "1.00000E-05 8.00000E-20 -1.00000E+03 9.13415E-10 1.00000E+04 6.13955E-08\n"
                 "1.00925E+04 6.17490E-08 1.01859E+04  6.09190E-08 1.02802E+04 6.19874E-08\n" ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card8b::Wght >( iss ) );
      }
    } // WHEN

    WHEN( "wrong number of regions" ){
      THEN( "an exception is thrown" ){
        iRecordStream<char>
          iss( std::istringstream
               ( " 0. 0. 0 0 2 6\n"
                 "6 5\n"
                 "1.00000E-05 8.00000E-20 1.00000E+03  9.13415E-10 1.00000E+04 6.13955E-08\n"
                 "1.00925E+04 6.17490E-08 1.01859E+04  6.09190E-08 1.02802E+04 6.19874E-08\n" ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card8b::Wght >( iss ) );
      }
    } // WHEN

    WHEN( "wrong number of values" ){
      THEN( "an exception is thrown" ){
        iRecordStream<char>
          iss( std::istringstream
               ( " 0. 0. 0 0 1 6\n"
                 "6 5\n"
                 "1.00000E-05 8.00000E-20 1.00000E+03  9.13415E-10 1.00000E+04 6.13955E-08\n"
                 "1.00925E+04 6.17490E-08 1.01859E+04 \n" ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card8b::Wght >( iss ) );
      }
    } // WHEN

    WHEN( "weight value is negative" ){
      THEN( "an exception is thrown" ){
        iRecordStream<char>
          iss( std::istringstream
               ( " 0. 0. 0 0 1 6\n"
                 "6 5\n"
                 "1.00000E-05 8.00000E-20 1.00000E+03 -9.13415E-10 1.00000E+04 6.13955E-08\n"
                 "1.00925E+04 6.17490E-08 1.01859E+04  6.09190E-08 1.02802E+04 6.19874E-08\n" ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card8b::Wght >( iss ) );
      }
    } // WHEN
  }
} // SCENARIO
