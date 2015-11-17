//! Test that Catch works
#define CATCH_CONFIG_MAIN
#include "Catch.hpp"

TEST_CASE("Addition works", "[math]"){
  REQUIRE( 1 - 1 == 0);
}
