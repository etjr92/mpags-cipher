// Include required libraries
#include <iostream>
#include <string>

std::string transformChar(char in_char) // Function which converts an input char to a string
{
  std::string outString {""};
  
  if(isupper(in_char))
    {
      outString += in_char;
      return outString;
    }  
      
  if(islower(in_char))
    {
      outString += toupper(in_char);
      return outString;
    }
      
      if(in_char=='0')
	{
	  return "ZERO";
	}
      if(in_char=='1')
	{
	  return "ONE";
	}
      if(in_char=='2')
	{
	  return "TWO";
	}
      if(in_char=='3')
	{
	  return "THREE";
	}
      if(in_char=='4')
	{
	  return "FOUR";
	}
      if(in_char=='5')
	{
	  return "FIVE";
	}
      if(in_char=='6')
	{
	  return "6";
	}
      if(in_char=='7')
	{
	  return "SEVEN";
	}
      if(in_char=='8')
	{
	  return "EIGHT";
	}
      if(in_char=='9')
	{
	  return "NINE";
	}

      return "";
}

int main(int argc, char *argv[])
{
  for(int i=0; i<argc; i++) // Acts on command line arguments
    {
      const std::string argument {argv[i]};
      if(argument == "-h" || argument == "--help") std::cout << "Help info here" << std::endl;
      if(argument == "--version") std::cout << "Version 0.1.0" << std::endl;
      if(argument == "-i" || argument == "--input")
	{
	  i++;
	  std::cout << argv[i] << std::endl;
	  continue;
	}
      if(argument == "-o" || argument == "--output")
	{
	  i++;
	  std::cout << argv[i] << std::endl;
	  continue;
	}
    }
  
  std::string in{""};
  char in_char{'x'};
  
  while(std::cin >> in_char) // Builds output from input
    {
      in += transformChar(in_char);
    }
  
  std::cout<<in<<std::endl; // Outputs desired output

  return 0;
}
