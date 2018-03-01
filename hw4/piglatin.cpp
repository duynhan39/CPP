//Duy Nhan Cao
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
void translate_sentence(string eng_sen, string & pig_sen);
void translate_word(const string eng_word, string & pig_word);

int main(int argc, char * argv[])
{
    // 1. Check for correct number of arguments
    if(argc!=3)
    {
        cout << "Usage: " <<argv[0]<<"<input file><outfile>" <<endl;
        exit(1);
    }
    // 2. Open files 
    ifstream inFile(argv[1]);
    ofstream outFile(argv[2]);
    // 3. Check for successful opens
    if(!inFile)
    {
        cout<<"Error opening input file" << argv[1]<<endl;
        exit(1);
    }
    if(!outFile)
    {
        cout<< "Error opening output file" << argv[2]<<endl;
        exit(1);
    }

    //4. Get english sentence and compute piglatin sentence
    string input;
    while(getline(inFile, input))
    {
      string output;
      translate_sentence(input, output);
      outFile << output << endl;
    }
    
    //Close files
    inFile.close();
    outFile.close();
    return 0;
}

//Receive an english sentence and pass back a piglatin sentence
void translate_sentence(string eng_sen, string & pig_sen)
{

  string eng_word, pig_word;
  size_t stIndex=0, endIndex;
  eng_sen.append(" ");
  while(eng_sen.find(' ', stIndex)!=string::npos)
  {
    endIndex=eng_sen.find(' ', stIndex);
    eng_word = eng_sen.substr(stIndex, endIndex-stIndex);
    stIndex = endIndex+1;
    translate_word(eng_word, pig_word);
    pig_sen.append(pig_word);
    pig_sen+=" ";
  }
  pig_sen.pop_back();
}

//Receive an english word and pass back a piglatin word
void translate_word(const string eng_word, string& pig_word)
{
  string vowel="ueoai";
  pig_word = eng_word;
  if(vowel.find(eng_word[0])==string::npos)
  {
    pig_word.erase(pig_word.begin());
    pig_word.append(eng_word, 0, 1);
  }
  pig_word.append("ay");
}
