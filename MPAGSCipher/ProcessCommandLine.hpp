#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <iostream>

enum class CipherMode // Creates types of modes for the cipher
{
  encrypt,
  decrypt
};

struct Command_line
{
  std::string input_filename;
  std::string output_filename;
  CipherMode mode;
  int key;
};

//! Transliterate char to string
//void processCommandLine(int argc, char *argv[], std::string& input_file_name, std::string& output_file_name, bool& decrypt, int& key);

void processCommandLine(int argc, char *argv[], Command_line& command_line);

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
