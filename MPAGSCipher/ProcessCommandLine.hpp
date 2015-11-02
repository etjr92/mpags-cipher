#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>

//! Transliterate char to string
void processCommandLine(int argc, char *argv[], std::string& input_file_name, std::string& output_file_name, bool& decrypt, long& key);

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
