#ifndef MPAGSCIPHER_CIPHERMAKER_HPP
#define MPAGSCIPHER_CIPHERMAKER_HPP

enum class CipherTypes {CAESAR, PLAYFAIR};
#include "Cipher.hpp"
#include <memory>

std::unique_ptr<Cipher> cipherMaker(const CipherTypes type, const std::string& key);

#endif
