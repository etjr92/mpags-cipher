#include "PlayfairCipher.hpp"

PlayfairCipher::PlayfairCipher(std::string cipher_key) : key_{cipher_key}
{
  processKey();
}

void PlayfairCipher::setKey(std::string key)
{
  key_ = key;
  processKey();
}


void PlayfairCipher::processKey()
{
// Append the alphabet
  key_ = key_ + "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// Make sure the key is upper case
  std::transform(key_.begin(),key_.end(),key_.begin(),::toupper);
// Remove non-alpha characters
  auto cut1 = std::remove_if(key_.begin(),key_.end(), [] (char x) {return !isalpha(x);});
  key_.erase(cut1, key_.end());
// Change J -> I
  std::transform(key_.begin(),key_.end(),key_.begin(),[&] (char y) {if(y=='J') return 'I'; else return y;});
// Remove duplicated letters
  std::vector<char> used{};
  auto match_check = [&] (char z) {
    bool matched {false};
    for(unsigned int i = 0; i<used.size(); i++){
      if(z == used[i]) matched = true;
    }
    if(matched == true) return true;
    else
      {
	used.push_back(z);
	return false;
      }
  };
  auto cut2 = std::remove_if(key_.begin(),key_.end(), match_check);
  key_.erase(cut2, key_.end());
// Store the coords of each letter
  for (unsigned int i = 0; i < key_.size(); i++){
    std::pair<int, int> coordinates {(i-i%5)/5, i%5};
    l2pmap[key_[i]] = coordinates;
    }
// Store the playfair cihper key map
  for (int i = 0; i < static_cast<int>(key_.size()); i++){
    std::pair<int, int> coordinates {(i-i%5)/5, i%5};
    p2lmap[coordinates] = key_[i];
    }
}

std::string PlayfairCipher::encrypt(std::string input)
{
// Make sure input is valid
// (Upper case, only chars and J -> I)
    for (unsigned int i=0; i<input.size(); i++){
      if(!isupper(input[i]) || input[i] == 'J') std::cout<<"ERROR!!!"<<std::endl;
    }
// Find repeated chars and add an X
    for (unsigned int i=0; i<input.size()-1; i++){
      if(input[i]==input[i+1]){
	input.insert(i+1,"X");
	if(input[i]=='X') i++;
      }
    }
// if the size is odd, add a trailing Z
    if((input.size())%2 != 0) input += "Z";
// Loop over the input in Digraphs
// Find the coords in the grid for each digraph
// For each Digraph, decide how to encrypt
    for (unsigned int i=0; i<input.size(); i+=2)
      {
	auto a = l2pmap.find(input[i]);
	auto b = l2pmap.find(input[i+1]);
	//std::cout<<a->first<<" : ("<<(a->second).first<<", "<<(a->second).second<<") :: "<<b->first<<" : ("<<(b->second).first<<", "<<(b->second).second<<")"<<std::endl;
      
	if((a->second).first==(b->second).first)
	  {
	    input[i]=(p2lmap.find({((a->second).first)%5,((a->second).second+1)%5}))->second;
	    input[i+1]=(p2lmap.find({((b->second).first)%5,((b->second).second+1)%5}))->second;
	  }
	
	if((a->second).second==(b->second).second)
	  {
	    input[i]=(p2lmap.find({((a->second).first+1)%5,((a->second).second)%5}))->second;
	    input[i+1]=(p2lmap.find({((b->second).first+1)%5,((b->second).second)%5}))->second;
	  }
	if((a->second).first!=(b->second).first && (a->second).second!=(b->second).second)
	  {
	    input[i]=(p2lmap.find({(a->second).first,(b->second).second}))->second;
	    input[i+1]=(p2lmap.find({(b->second).first,(a->second).second}))->second;
	  }
    }
// return the text
    return input;
}
