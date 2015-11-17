#ifndef MPAGSCIPHER_PLAYFAIRCIPHER_HPP
#define MPAGSCIPHER_PLAYFAIRCIPHER_HPP

#include <algorithm>
#include <iterator>
#include <vector>
#include <map>

#include "ProcessCommandLine.hpp"

/**
 * This is the doxygen labelling system
 *
 * CaesarCipher object encodes a string
 * use it by creating an object and then calling the caeserCipher function
 */
class PlayfairCipher
{
public:
  /**
   * Create a new cipher with a specific cipher key
   * \param cipher_key the key to be used in the cipher
   */
  PlayfairCipher(std::string cipher_key);
  /**
   * Inacts the cipher on code
   * \param code the string to be encoded
   */
  std::string encrypt(std::string in);

  void setKey(std::string key);
  void processKey();
private:
  /// The key
  std::string key_;
  using Letter2PairMap = std::map<char, std::pair<int, int>>;
  Letter2PairMap l2pmap;
  using Pair2LetterMap = std::map<std::pair<int, int>, char>;
  Pair2LetterMap p2lmap;
};

// Define the Caesar cipher
//void caesarCipher(bool decrypt, int key, std::string& code);

#endif // MPAGSCIPHER_CAESARCIPHER_HPP
