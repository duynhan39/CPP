// File: polynomial2.cpp
//
// ----------------------------------------------------------
// Class: CS 215               Instructor: Dr. Deborah Hwang
// Assignment: Project 5       Date assigned: Oct 25
// Programmer: Duy Nhan Cao    Date completed: Nov 8

#include<iostream>       // operator << and >>
#include"polynomial2.h"  
#include<algorithm>      // swap
#include<math.h>         // pow

using namespace std;

// Function: removeZero
// Removing element with zero coef
void removeZero(Polynomial::Term *&first) {
    Polynomial::Term *previous=nullptr, *curr=first;
    while(curr!=nullptr) {
        if(curr->coef==0 && previous!=nullptr) {
            previous->next=curr->next;
            delete curr;
            curr=previous->next;
        }
        else if(curr->coef==0 && previous==nullptr) {
            first=first->next;
            delete curr;
            curr=first;
        }
        else {
            previous=curr;
            curr=curr->next;
        }
    }
    if(first==nullptr)
        first=new Polynomial::Term;
}

// Function: insert_in_order
// Putting new element in a polynomial in the correct order
void insert_in_order(Polynomial::Term *&first, Polynomial::Term *curr) {
    Polynomial::Term *ptr=first, *previous=nullptr;
    while(ptr!=nullptr && ptr->expo>curr->expo) {
        previous=ptr;
        ptr=ptr->next;
    }
    if(ptr==nullptr)
    {
        ptr=new Polynomial::Term(curr->coef, curr->expo);
    } else if(ptr->expo==curr->expo) {
        ptr->coef+=curr->coef;
    } else if(previous==nullptr) {
        first = new Polynomial::Term(curr->coef, curr->expo);
        first->next=ptr;
        
    } else {
        previous->next = new Polynomial::Term(curr->coef, curr->expo);
        previous->next->next = ptr;
    }
}

// Default constructor
Polynomial::Polynomial()
{
    head=new Term;
}

// Explicit-value constructor
Polynomial::Polynomial(vector<int> initial_coefficients, vector<int> initial_exponents) {
    Polynomial::Term *curr=new Polynomial::Term(initial_coefficients[0], initial_exponents[0]);
    head=curr;
    for(auto i=1; i<initial_exponents.size(); i++) {
        curr->next=new Term(initial_coefficients[i], initial_exponents[i]);
        curr=curr->next;
    }
    curr=curr->next;
}

// Copy constructor
Polynomial::Polynomial(const Polynomial &original) noexcept {
    Polynomial::Term *copy=original.head;
    Polynomial::Term *newHead=new Polynomial::Term(copy->coef, copy->expo);
    head=newHead;
    copy=copy->next;
    while(copy!=nullptr)
    {
        newHead->next=new Polynomial::Term(copy->coef, copy->expo);
        newHead=newHead->next;
        copy=copy->next;
    }
}

// Destructor
Polynomial::~Polynomial()
{
    Term *curr;
    while(head!=nullptr)
    {
        curr=head;
        head=head->next;
        delete curr;
    }
}

// Overloaded operator=
Polynomial Polynomial::operator= (const Polynomial & source) {
    Polynomial copy(source);
    swap(head, copy.head);
    return *this;
}

// Function: degree
// Returning the degree of the polynomial
int Polynomial::degree() const {
    return head->expo;
}

// Function: evaluate
// evaluate the polynomial at a particular point, return result
int Polynomial::evaluate(const int x) const {
    Polynomial::Term *curr=head;
    int result=0;
    while(curr!=nullptr) {
        result+=curr->coef*pow(x, curr->expo);
        curr=curr->next;
    }
    return result;
}

// Friend operator+
Polynomial operator+ (const Polynomial & left_poly, const Polynomial & right_poly) {
    Polynomial sum_poly(left_poly);
    Polynomial::Term *curr=right_poly.head;
    while(curr!=nullptr) {
        insert_in_order(sum_poly.head, curr);
        curr=curr->next;
    }
    removeZero(sum_poly.head);
    return sum_poly;
}

// Friend operator*
Polynomial operator* (const Polynomial & left_poly, const Polynomial & right_poly) {
    Polynomial prod_poly;
    Polynomial::Term *currL=left_poly.head;
    while(currL!=nullptr) {
        Polynomial::Term *currR=right_poly.head;
        while(currR!=nullptr) {
            if(currR->coef*currL->coef!=0) {
                Polynomial::Term *curr=new Polynomial::Term(currR->coef*currL->coef, currR->expo+currL->expo);
                insert_in_order(prod_poly.head, curr);
                delete curr;
            }
            currR=currR->next;
        }
        currL=currL->next;
    }
    removeZero(prod_poly.head);
    return prod_poly;
}

// Friend operator<<
std::ostream & operator<< (std::ostream & out_stream, const Polynomial & a_poly) {
    Polynomial::Term *curr=a_poly.head;
    bool no1=true;
    while(curr!=nullptr) {
        if(!no1 && curr->coef>0)
            out_stream<<"+";
        out_stream<<*curr;
        no1=false;
        curr=curr->next;
    }
    return out_stream;
}

// Friend operator>>
std::istream & operator>> (std::istream & in_stream, Polynomial & a_poly) {
    int num=1;
    char sign;
    Polynomial::Term *currTerm;
    while(a_poly.head!=nullptr)
    {
        currTerm=a_poly.head;
        a_poly.head=a_poly.head->next;
        delete currTerm;
    }
    a_poly.head=new Polynomial::Term;
    Polynomial::Term *curr=a_poly.head;
    in_stream>>sign;
    in_stream.putback(sign);
    bool no1=true, last=false;
    while(1)
    {
        if(in_stream.peek()!='+' && in_stream.peek()!='-' && !no1)
            break;
        sign='+';
        bool neg=false;
        num=1;
        if((no1 && in_stream.peek()=='-') || !no1)
            in_stream>>sign;
        if(in_stream.fail())
            return in_stream;
        if(!no1) {
            curr->next=new Polynomial::Term;
            curr=curr->next;
        }
        no1=false;
        if(sign=='-') {
            neg=true;
            num=-1;
        }
        if(in_stream.peek()!='x') {
            if(neg)
                in_stream.putback(sign);
            in_stream>>num;
            if(in_stream.fail())
                return in_stream;
            if(in_stream.peek()!='x') {
                last=true;
                curr->expo=0;
            }
        }
        if(!last){
            in_stream.ignore();
            if(in_stream.peek()=='^') {
                in_stream.ignore();
                in_stream>>curr->expo;
                if(in_stream.fail())
                    return in_stream;
            }
            else
                curr->expo=1;
        }
        curr->coef=num;
    } // end while loop of reading terms by terms
    return in_stream;
}
