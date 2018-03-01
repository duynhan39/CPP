// File: morse.cpp
//
// ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
// Class: CS 215		Instructor: Dr. Deborah Hwang
// Assignment: Project 7 	Date assigned: Nov 20
// Programmer: Duy Nhan Cao	Date completed: Dec 4

#include "morse.h"
#include <algorithm>
#include <iomanip>
using namespace std;

// Explicit-value constructor
MorseTree::MorseTree(std::istream & code_file)
{
    int n;
    root = new MorseTree::TreeNode;
    code_file>>n;
    for(int i = 0; i < n; i++)
    {
        char let;
        code_file>>let;
        string path;
        code_file>>path;
        TreeNode *r = root;
        for(int j = 0; j < path.size(); j++)
        {
            if(path[j] == '.')
            {
                if(r->lchild == nullptr)
                    r->lchild = new TreeNode;
                r=r->lchild;
            } else
            {
                if(r->rchild == nullptr)
                    r->rchild = new TreeNode;
                r=r->rchild;
            }
        }
        r->letter=let;
    }
}

// Copy constructor
MorseTree::MorseTree(const MorseTree &source)
{
    this->root = copy_tree(source.root);
}

// Helper function: copy_tree
MorseTree::TreeNode* MorseTree::copy_tree(MorseTree::TreeNode *source_root)
{
    TreeNode *copy_root = new MorseTree::TreeNode(source_root->letter);
    if(source_root->lchild != nullptr)
        copy_root->lchild = copy_tree(source_root->lchild);
    if(source_root->rchild != nullptr)
        copy_root->rchild = copy_tree(source_root->rchild);
    return copy_root;
}

// Destructor
MorseTree::~MorseTree()
{
    delete_tree(root);
}

// Helper function: delete_tree
void MorseTree::delete_tree(MorseTree::TreeNode *source_root)
{
    if(source_root->lchild != nullptr)
        delete_tree(source_root->lchild);
    if(source_root->rchild != nullptr)
        delete_tree(source_root->rchild);
    delete source_root;
}

// Operator =
MorseTree MorseTree::operator= (const MorseTree &source)
{
    MorseTree copy(source);
    swap(copy.root, root);
    return *this;
}

// Function: write
void MorseTree::write(std::ostream &out)
{
    write_tree(out, root, 0);
}

// Helper function: write_tree
void MorseTree::write_tree(std::ostream &out, TreeNode *local_root, int depth)
{
    if(local_root->rchild != nullptr)
        write_tree(out, local_root->rchild, depth+1);
    
    for(int i=0; i<depth; i++)
        out<<setw(8)<<" ";
    out<<local_root->letter<<endl;
    
    if(local_root->lchild != nullptr)
        write_tree(out, local_root->lchild, depth+1);
}

// Function: encode
void MorseTree::encode(std::istream &message_file, std::ostream &out)
{
    char c;
    string path;
    message_file.get(c);
    if(c==' ')
        out<<'|';
    else if(c=='\n')
        out<<"||";
    else
    {
        path = char_to_code(c, root, "");
        if(path == "")
            out<<"\nCharacter "<<c<<" is ignored\n";
        else
            out<<path;
    }
    while(message_file.get(c))
    {
        out<<' ';
        if(c==' ')
            out<<'|';
        else if(c=='\n')
            out<<"||";
        else
        {
            path = char_to_code(c, root, "");
            if(path == "")
                out<<"character "<<c<<" is ignored\n";
            else
                out<<path;
        }
    }
    out<<endl;
}

// Helper function: char_to_code
std::string MorseTree::char_to_code(char ch, TreeNode *t, string path_so_far)
{
    string code;
    if(t == nullptr)
        return "";
    if(t->letter == ch)
        return path_so_far;
    
    if(char_to_code(ch, t->lchild, path_so_far+".") != "")
        code = char_to_code(ch, t->lchild, path_so_far+".");
    else if(char_to_code(ch, t->rchild, path_so_far+"-") != "")
        code = char_to_code(ch, t->rchild, path_so_far+"-");
    
    return code;
}

// Function: decode
void MorseTree::decode(std::istream &message_file, std::ostream &out)
{
    string path;
    while(message_file>>path)
    {
        if(path == "|")
        {
            out<<" ";
            continue;
        }
        if(path == "||")
        {
            out<<endl;
            continue;
        }
        MorseTree::TreeNode *r=root;
        for(int i=0; i<path.size(); i++)
            if(path[i] == '.')
            {
                if(r->lchild == nullptr)
                    break;
                r=r->lchild;
            } else
            {
                if(r->rchild == nullptr)
                    break;
                r=r->rchild;
            }
        out<<r->letter;
    }
}
