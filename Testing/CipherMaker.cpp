#include <memory>
#include "CipherMaker.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"

std::unique_ptr<Cipher>cipherMaker(const CipherTypes type){
  switch (type){
  case CipherTypes::CAESAR :
    return std::make_unique<CaesarCipher>();
  case CipherTypes::PLAYFAIR :
    return std::make_unique<PlayfairCipher>();
  }
}
