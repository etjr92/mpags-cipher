#include "CaesarCipher.hpp"

CaesarCipher::CaesarCipher(const int& cipher_key) : key_{cipher_key}
{
}

void CaesarCipher::caesarCipher(CipherMode mode, std::string& code)const
{
  if (key_ < 0) return;
  char alphabet[26] {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  if(mode == CipherMode::decrypt)
     {char alphabet_inverted[26] {'Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M','L','K','J','I','H','G','F','E','D','C','B','A'};
       for(short i=0; i<26;i++)
	 {alphabet[i] = alphabet_inverted[i];}
    }
 
  for (unsigned int i=0; i<code.length(); i++)
    {
      for (unsigned int j=0; j<26; j++)
	{
	  if (code[i] == alphabet[j])
	    {
	      code[i] = alphabet[(j+key_)%26];
	      break;
	    }
	}
    }
}
