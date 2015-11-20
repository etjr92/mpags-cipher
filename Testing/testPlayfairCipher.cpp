//! Unit Tests for MPAGSCipher PlayfairCipher interface
#define CATCH_CONFIG_MAIN
#include "Catch.hpp"

#include "CaesarCipher.hpp"
#include "CaesarCipher.cpp"
#include "ProcessCommandLine.hpp"
#include "ProcessCommandLine.cpp"
#include "TransformChar.hpp"
#include "TransformChar.cpp"
#include "PlayfairCipher.hpp"
#include "PlayfairCipher.hpp"

TEST_CASE("Does PlayfairCipher work?", "[alphanumeric]"){
  PlayfairCipher cipher{"HI"};
  std::string test_str{"ABC"};
  test_str = cipher.encrypt(test_str);
  REQUIRE(test_str == "BCKC");
}
