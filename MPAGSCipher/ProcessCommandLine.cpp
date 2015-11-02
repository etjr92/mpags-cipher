#include <iostream>
#include <string>

void processCommandLine(int argc, char *argv[], std::string& input_file_name, std::string& output_file_name, bool& decrypt, long& key)
{
  for(int i=0; i<argc; i++) // Acts on command line arguments
    {
      const std::string argument {argv[i]};
      if(argument == "-h" || argument == "--help") std::cout << "Use -k to add key and -d to switch to decrypt mode." << std::endl;
      if(argument == "-v" || argument == "--version") std::cout << "Version 2.1" << std::endl;
      if(argument == "-i" || argument == "--input")
	{
	  i++;
	  input_file_name = argv[i];
	  continue;
	}
      if(argument == "-o" || argument == "--output")
	{
	  i++;
	  output_file_name = argv[i];
	  continue;
	}
      if(argument == "-d" || argument == "--decrypt") decrypt = true;
      if(argument == "-k" || argument == "--key")
	{
	  i++;
	  key = std::stoi(argv[i]);
	  continue;
	}
    }
}
