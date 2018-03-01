// File: term.h
//
// ----------------------------------------------------------
// Class: CS 215               Instructor: Dr. Deborah Hwang
// Assignment: Project 5       Date assigned:
// Programmer: Duy Nhan Cao    Date completed:

#ifndef TERM
#define TERM
#include<iostream>
struct Term {
    Term(int init_coef=0, int init_expo=0)
    {
        coef=init_coef;
        expo=init_expo;
        next=nullptr;
    }
    friend std::ostream & operator<< (std::ostream & out, const Term & a_term)
    {
        if(a_term.expo==0)
            out<<a_term.coef;
        else {
            if(a_term.coef==-1 && a_term.expo!=0)
                out<<'-';
            else if(a_term.coef*a_term.coef!=1 || a_term.expo==0)
                out<<a_term.coef;
            if(a_term.expo!=0)
                out<<'x';
            if(a_term.expo>1)
                out<<'^'<<a_term.expo;
        }
        return out;
    }
    int coef;
    int expo;
    Term* next;
};

#endif
