#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input::argument::primitive;

SCENARIO( "Argument is present" ){
  int sink = 0;
  std::istringstream iss("   101");
  REQUIRE( Required< Type<int> >::read( iss, sink ) );
  REQUIRE( sink == 101 );
}

SCENARIO( "Argument is not present" ){
  int sink = 0;
  std::istringstream iss("");
  REQUIRE_THROWS( Required< Type<int> >::read( iss, sink ) );
}

SCENARIO( "Argument is wrong type" ){
  int sink = 0;
  std::istringstream iss(" alphabet ");
  REQUIRE_THROWS( Required< Type<int> >::read( iss, sink ) );
}
