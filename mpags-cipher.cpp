#include <iostream>
#include <string>
int main(int argc, char *argv[])
{

  for(int i=0; i<argc; i++)
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
  while(std::cin >> in_char)
    {
      if(isupper(in_char)) in.push_back(in_char);
      
      if(islower(in_char)) in.push_back(toupper(in_char));
      
      if(in_char=='0')
	{
	  in += "ZERO";
	}
      if(in_char=='1')
	{
	  in += "ONE";
	}
      if(in_char=='2')
	{
	  in += "TWO";
	}
      if(in_char=='3')
	{
	  in += "THREE";
	}
      if(in_char=='4')
	{
	  in += "FOUR";
	}
      if(in_char=='5')
	{
	  in += "FIVE";
	}
      if(in_char=='6')
	{
	  in += "6";
	}
      if(in_char=='7')
	{
	  in += "SEVEN";
	}
      if(in_char=='8')
	{
	  in += "EIGHT";
	}
      if(in_char=='9')
	{
	  in += "NINE";
	}
    }
  
  std::cout<<in<<std::endl;

  return 0;
}
