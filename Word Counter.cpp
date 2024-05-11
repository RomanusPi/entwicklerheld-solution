#include "WordCounter.hpp"

string WordCounter::read_file(const string &filepath)
{
  ifstream myfile(filepath);
  document="";
  char c;
  
  if (myfile.is_open())
  { 
    while ( myfile.get(c))
    {
        
        document = document + c; 
    }
    myfile.close();
  }
  else cout << "Unable to open file"; 
  return  document;
}

map<string, int> WordCounter::count_words()
{
  map<string, int> Words; 
  string takeWord = "";
  for(int i = 0; i <= document.length(); i++)
  {
 
    if(((document[i] == ' ')  || (document[i] == '\n') || (document[i]=='\r')  
    || (document[i] == ',')|| (document[i] == '.') || i == document.length() ))
    {  

      if  (takeWord != "" )
      {
        if (Words.find(takeWord) != Words.end()   )
        {
          Words[takeWord] = Words[takeWord] + 1;
        }
        else    
        {
          Words[takeWord] = 1;
        }  
      }
      
      takeWord = "";
      continue;
  
    }
  takeWord += document[i];
  }   
  
  this->words_counted = Words;

  return Words;
}

string WordCounter::format_output()
{
  string formWords; 
  int counter = 0;
  for(const auto & fpair: words_counted )
  {
    formWords = formWords + '\t' + fpair.first+": " + std::to_string(fpair.second) + ","+'\n'; 
    counter = counter + fpair.second;
  }
  formWords = formWords + "--------------------------\n"
  + "Total Words: " + std::to_string(counter);
 
  return formWords;  
 }
