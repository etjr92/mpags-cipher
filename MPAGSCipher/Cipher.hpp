#ifndef MPAGSCIPHER_CIPHER_HPP
#define MPAGSCIPHER_CIPHER_HPP

class Cipher {
public:
  // The following 6 lines define the standard functions that any class has:
  Cipher() = default;
  Cipher(const Cipher& rhs) = default;
  Cipher(Cipher&& rhs) = default;
  Cipher& operator=(const Cipher& rhs) = default;
  Cipher& operator=(Cipher&& rhs) = default;
  virtual ~Cipher() = default;

  //The following 2 lines define the Cipher-specific functions:
  virtual std::string encrypt(const std::string& input) const = 0;
  virtual std::string decrypt(const std::string& input) const = 0;
};

#endif // MPAGSCIPHER_CIPHER_HPP
