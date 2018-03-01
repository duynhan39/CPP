// File: image.h
//
// ----------------------------------------------------------
// Class: CS 215        Instructor: Dr. Deborah Hwang
// Assignment: Project 4       Date assigned: Oct 13 2017
// Programmer: Duy Nhan Cao    Date completed: Oct 23 2017

#ifndef IMA
#define IMA
#include <iostream>    // operator >> and <<
class PGMImage
{
public:
    // Constructors
    PGMImage(); // set default to a empty image
    // Member functions
    PGMImage(const PGMImage & original) noexcept; // create a copy of original
    PGMImage operator= (const PGMImage & original); // operator=
    bool empty() const; // Check if the image is empty
    int width() const; // Return width
    int height() const; // Return height
    int max_value() const; // Return max pixel value
    int& at(int row, int col); // Returns a reference to the pixel value at the given row and column indexes
    int& at(int row, int col) const; // Returns a reference to the pixel value at the given row and column indexes
    PGMImage rotate_left() const;  // Rotate left
    PGMImage rotate_right() const; // Rotate right
    PGMImage flip_horizontal() const; // Flip horizontally
    PGMImage flip_vertical() const; // Flip vertically
    PGMImage invert() const; // Invert
    void load(std::ifstream& inFile); // Load image
    void write(std::ofstream& out_file); // Write to file
    // Destructor
    ~PGMImage();
    
private:
    int wd; // width of the image
    int ht; // height of the image
    int max; // pixel max value
    int *image; // image
};

#endif
