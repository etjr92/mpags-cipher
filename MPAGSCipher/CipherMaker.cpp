#include <memory>
#include "CipherMaker.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"

std::unique_ptr<Cipher> cipherMaker(const CipherTypes type, const std::string& key){
  switch (type){
  case CipherTypes::CAESAR :
    return std::make_unique<CaesarCipher>(key);
  case CipherTypes::PLAYFAIR :
    return std::make_unique<PlayfairCipher>(key);
  }

  return std::unique_ptr<Cipher>(nullptr);
}
