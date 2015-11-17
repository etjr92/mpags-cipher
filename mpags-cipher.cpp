// Include required libraries
#include <iostream>
#include <string>
#include <fstream>

// My function headers
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"

int main(int argc, char *argv[])
{
  Command_line command_line {"","",CipherMode::encrypt,"",""};
  processCommandLine(argc,argv,command_line);
  
  
  std::string in{""};
  char in_char{'x'};

  if(command_line.input_filename == "")
    {
      while(std::cin >> in_char) // Builds output from input
	{
	  in += transformChar(in_char);
	}
    }
  else
    {
      // Read input from file
      std::ifstream in_file {command_line.input_filename};
      if(in_file.good())
	{
	  while(in_file >> in_char) // Builds output from input
	    {
	      in += transformChar(in_char);
	    }
	}
      else
	{
	  std::cout<<"ERROR READING INPUT FILE!!!"<<std::endl;
	  return 1;
	}
      in_file.close();
    }
  
  if(command_line.cipher_type == "caesar")
    {
      CaesarCipher cipher{command_line.key};
      cipher.caesarCipher(command_line.mode, in);
    }

  if(command_line.cipher_type == "playfair")
    {
      PlayfairCipher cipher{command_line.key};
      in = cipher.encrypt(in);
    }

  if(command_line.output_filename == "")
    {
      std::cout<<in<<std::endl; // Outputs desired output
    }
  else
    {
      std::ofstream out_file {command_line.output_filename};
      if(out_file.good()) out_file << in;
      else std::cout<<"ERROR WRITING TO OUTPUT FILE!!!"<<std::endl;
      out_file.close();
    }

  return 0;
}
