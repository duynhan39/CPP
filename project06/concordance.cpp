// File: concordance.cpp
//
// ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
// Class: CS 215                Instructor: Dr. Deborah Hwang
// Assignment: Project 6        Date assigned: Nov 9
// Programmer: Duy Nhan Cao     Date completed: Nov 20

#include<iostream>
#include<vector>
#include<list>
#include<fstream>
#include<string>
using namespace std;

void insert_list(list<string> &aList, string word);

int main(int argc, char *argv[])
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
        cout<<"Error opening output file" << argv[2]<<endl;
        exit(1);
    }
    string word;
    vector<list<string>> con(26);
    while(inFile>>word)
    {
      insert_list(con[word[0]-'a'], word);
    }
    for(int i=0; i<26; i++)
      for(auto it=con[i].begin(); it!=con[i].end(); it++)
	outFile<<*it<<endl;
    inFile.close();
    outFile.close();
    return 0;
}

void insert_list(list<string> &aList, string word)
{
  for(auto it=aList.begin(); it!=aList.end(); it++)
  {
    if(word==*it)
      return;
    if(word<*it)
    {
      aList.insert(it, word);
      return;
    }
  }
  aList.push_back(word);
}
