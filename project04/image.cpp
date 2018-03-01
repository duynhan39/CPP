// File: image.cpp
//
// ----------------------------------------------------------
// Class: CS 215        Instructor: Dr. Deborah Hwang
// Assignment: Project 4       Date assigned: Oct 13 2017
// Programmer: Duy Nhan Cao    Date completed: Oct 23 2017

#include "image.h"     // PGMImage Class
#include <iostream>    // operator >> and <<
#include <stdexcept>   // runtime_error
#include <algorithm>   // std::swap
#include <iomanip>     // std::setw
#include <fstream>     // ifstream and ofstream
using namespace std;

// Explicit value constructor
PGMImage::PGMImage()
{
  wd=0;
  ht=0;
  max=0;
  image=nullptr;
}

// Copy constructor
PGMImage::PGMImage(const PGMImage & original) noexcept
{
    wd=original.wd;
    ht=original.ht;
    max=original.max;
    image=new int[wd*ht];
    ::copy(original.image, original.image+ht*wd, image);
}

// Destructor
PGMImage::~PGMImage()
{ delete [] image; }

// Operator =
PGMImage PGMImage::operator=(const PGMImage & original)
{
    PGMImage c(original);
    swap(max, c.max);
    swap(wd, c.wd);
    swap(ht, c.ht);
    swap(image, c.image);
    return *this;
}

// Function: empty
bool PGMImage::empty() const
{ return image==nullptr; }

// Function: width
int PGMImage::width() const
{ return wd; }

// Function: height
int PGMImage::height() const
{ return ht; }

// Function: max_value
int PGMImage::max_value() const
{ return max; }

// Function: at
int& PGMImage::at(int row, int col)
{
    if(row>ht-1 || col>wd-1)
        throw runtime_error ("PGMImage::at(): index out of range"); //Terminate when index is out of range
    // If everything is good
    return image[row*wd+col];
}

// Function: at const
int& PGMImage::at(int row, int col) const
{
    if(row>ht-1 || col>wd-1)
        throw runtime_error ("PGMImage::at(): index out of range"); //Terminate when index is out of range
    // If everything is good
    return image[row*wd+col];
}

// Function: rotate_left
PGMImage PGMImage::rotate_left() const
{
    PGMImage new_image;
    new_image.wd=ht;
    new_image.ht=wd;
    new_image.max=max;
    new_image.image = new int[wd*ht];
    for(int i=0; i<ht; i++)
        for(int j=0; j<wd; j++)
            new_image.at(wd-1-j,i)=at(i,j);
    return new_image;
}

// Function: rotate_right
PGMImage PGMImage::rotate_right() const
{
    PGMImage new_image;
    new_image.wd=ht;
    new_image.ht=wd;
    new_image.max=max;
    new_image.image = new int[wd*ht];
    for(int i=0; i<ht; i++)
        for(int j=0; j<wd; j++)
            new_image.at(j,ht-1-i)=at(i,j);
    return new_image;
}

// Function: flip_horizontal
PGMImage PGMImage::flip_horizontal() const
{
    PGMImage new_image;
    new_image.wd=wd;
    new_image.ht=ht;
    new_image.max=max;
    new_image.image = new int[wd*ht];
    for(int i=0; i<ht; i++)
        for(int j=0; j<wd; j++)
	    new_image.at(ht-1-i,j)=at(i,j);
    return new_image;
}

// Function: flip_vertical
PGMImage PGMImage::flip_vertical() const
{
    PGMImage new_image;
    new_image.wd=wd;
    new_image.ht=ht;
    new_image.max=max;
    new_image.image = new int[wd*ht];
    for(int i=0; i<ht; i++)
        for(int j=0; j<wd; j++)
            new_image.at(i,wd-1-j)=at(i,j);
    return new_image;
}

// Function: invert
PGMImage PGMImage::invert() const
{
    PGMImage new_image;
    new_image.wd=wd;
    new_image.ht=ht;
    new_image.max=max;
    new_image.image = new int[wd*ht];
    for(int i=0; i<ht; i++)
        for(int j=0; j<wd; j++)
            new_image.at(i,j)=max-at(i,j);
    return new_image;
}

// Function: load
void PGMImage::load(std::ifstream& in_file)
{
    string name;
    in_file>>name;
    if(name!="P2")
        throw runtime_error ("PGMImage::load(): not PGM file"); //Terminate when file is not PGM
    delete [] image;
    in_file>>wd;
    in_file>>ht;
    in_file>>max;
    image = new int[wd*ht];
    for(int i=0; i<wd*ht; i++ )
        in_file>>image[i];
}

// Function: write
void PGMImage::write(ofstream& out_file)
{
    if(image!=nullptr)
    {
        out_file<<"P2\n"<<wd<<" "<<ht<<"\n"<<max<<endl;
        for(int i=0; i<ht; i++ )
        {
            for(int j=0; j<wd; j++)
                out_file<<setw(4)<<at(i,j);
            out_file<<"\n";
        }
    }
}
