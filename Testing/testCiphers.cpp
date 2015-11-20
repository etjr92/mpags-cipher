//! Unit Tests for MPAGSCipher CaesarCipher interface
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
#include "Cipher.hpp"
#include "CipherMaker.hpp"
#include <memory>

TEST_CASE("Do the Ciphers work?", "[alphanumeric]"){

  std::vector<std::unique_ptr<Cipher>> ciphers;
ciphers.push_back(cipherMaker(CipherTypes::CAESAR,"10"));
ciphers.push_back(cipherMaker(CipherTypes::PLAYFAIR,"HI"));
std::vector<std::string> in;
in.push_back("ABC");
in.push_back("ABC");
std::vector<std::string> out;
out.push_back("KLM");
out.push_back("BCKC");



  for (unsigned int i; i<ciphers.size(); i++){
    in[i] = (ciphers[i])->encrypt(in[i]);
    REQUIRE(in[i] == out[i]);
  }
}
