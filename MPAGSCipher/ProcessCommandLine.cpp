#include "ProcessCommandLine.hpp"

//void processCommandLine(int argc, char *argv[], std::string& input_file_name, std::string& output_file_name, bool& decrypt, int& key)
void processCommandLine(int argc, char *argv[], Command_line& command_line)
{
  for(int i=0; i<argc; i++) // Acts on command line arguments
    {
      std::string argument {argv[i]};
      if(argument == "-h" || argument == "--help")
	{
	  std::cout << "Use -k to add key and -d to switch to decrypt mode." << std::endl;
	  return;
	}
      if(argument == "-v" || argument == "--version")
	{
	  std::cout << "Version 2.1" << std::endl;
	  return;
	}
      if(argument == "-i" || argument == "--input")
	{
	  i++;
	  //input_file_name = argv[i];
	  command_line.input_filename = argv[i];
	  continue;
	}
      if(argument == "-o" || argument == "--output")
	{
	  i++;
	  //output_file_name = argv[i];
	  command_line.output_filename = argv[i];
	  continue;
	}
      if(argument == "-d" || argument == "--decrypt") command_line.mode = CipherMode::decrypt;
      if(argument == "-k" || argument == "--key")
	{
	  i++;
	  command_line.key = argv[i];
	  continue;
	}
      if(argument == "--cipher" || argument == "-c")
	{
	  i++;
	  argument = argv[i];
	  if(argument == "caesar" || argument == "playfair")
	    {
	      command_line.cipher_type = argv[i];
	    }
	  else
	    {
	      return;
	    }
	  continue;
	}
    }
}
