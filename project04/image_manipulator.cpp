// File: image_manipulator.cpp
//
// ----------------------------------------------------------
// Class: CS 215        Instructor: Dr. Deborah Hwang
// Assignment: Project 4       Date assigned: Oct 13 2017
// Programmer: Duy Nhan Cao    Date completed: Oct 23 2017

#include "image.h"   // PGMImage Class
#include <iostream>  // operator << and >>
#include <fstream>
using namespace std;
void comList();
int main()
{
  bool quit=false;
  char cmd='\0';
  PGMImage im1, im2;
  while(!quit) {
    comList();
    cin>>cmd;
    switch (toupper(cmd)) {
      case 'L':
	try {
	  cout<<"Enter name of image file to load into current image: ";
	  string in_name;
	  cin>>in_name;
	  ifstream in_file(in_name);
	  if(!in_file) {
	    throw runtime_error ("Cannot open file.");
	  }
	  im1.load(in_file);
	  in_file.close();
	}
	catch (const runtime_error & er) {
	  cout<<er.what()<<"Try again!\n";
	}
	break;
      case 'A':
	cout<<"Creating rotated image\n";
	im2=im1.rotate_left();
	break;
      case 'B':
	cout<<"Creating rotated image\n";
	im2=im1.rotate_right();
	break;
      case 'C':
	cout<<"Creating rotated image\n";
	im2=im1.flip_horizontal();
	break;
      case 'D':
	cout<<"Creating rotated image\n";
	im2=im1.flip_vertical();
	break;
      case 'E':
	cout<<"Creating rotated image\n";
	im2=im1.invert();
	break;
      case 'W':
	try {
	  cout<<"Enter name of file to write new image: ";
	  string out_name;
	  cin>>out_name;
	  ofstream out_file(out_name);
	  if(!out_file) {
	    throw runtime_error ("Cannot open file.");
	  }
	  im2.write(out_file);
	  out_file.close();
	}
	catch (const runtime_error & er) {
	  cout<<er.what()<<"Try again!\n";
	}
	break;
      case 'Q':
	quit=true;
	cout<<"Bye!!\n";
	break;
      }
    cout<<endl;
  }
  return 0;
}

void comList() {
  cout<<"Choose from the following commands:\n";
  cout<<"   L - Load current image from file\n";
  cout<<"   A - Create new image rotated 90 degrees left\n";
  cout<<"   B - Create new image rotated 90 degrees right\n";
  cout<<"   C - Create new image flipped along horizontal axis\n";
  cout<<"   D - Create new image flipped along vertical axis\n";
  cout<<"   E - Create new inverted image\n";
  cout<<"   W - Write new image to file\n";
  cout<<"   Q - Quit the program\n";
  cout<<"\nEnter your command: ";
}

