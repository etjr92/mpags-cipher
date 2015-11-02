#include <iostream>

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
	  return "SIX";
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
