#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include "ProcessCommandLine.hpp"

/**
 * This is the doxygen labelling system
 *
 * CaesarCipher object encodes a string
 * use it by creating an object and then calling the caeserCipher function
 */
class CaesarCipher
{
public:
  /**
   * Create a new cipher with a specific cipher key
   * \param cipher_key the key to be used in the cipher
   */
  CaesarCipher(const int& cipher_key);
  /**
   * Inacts the cipher on code
   * \param code the string to be encoded
   */
  void caesarCipher(CipherMode mode, std::string& code) const;
private:
  /// The key
  const int key_;
};

// Define the Caesar cipher
//void caesarCipher(bool decrypt, int key, std::string& code);

#endif // MPAGSCIPHER_CAESARCIPHER_HPP
