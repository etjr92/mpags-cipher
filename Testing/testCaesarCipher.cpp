//! Unit Tests for MPAGSCipher CaesarCipher interface
#define CATCH_CONFIG_MAIN
#include "Catch.hpp"

#include "CaesarCipher.hpp"
#include "CaesarCipher.cpp"
#include "ProcessCommandLine.hpp"
#include "ProcessCommandLine.cpp"
#include "TransformChar.hpp"
#include "TransformChar.cpp"

TEST_CASE("Does CaesarCipher work?", "[alphanumeric]"){
  CaesarCipher cipher{"10"};
  std::string test_str{"ABC"};
  cipher.caesarCipher(CipherMode::encrypt, test_str);
  REQUIRE(test_str == "KLM");
}
