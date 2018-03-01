// File: morse.h
//
// ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
// Class: CS 215		Instructor: Dr. Deborah Hwang
// Assignment: Project 7 	Date assigned: Nov 20
// Programmer: Duy Nhan Cao	Date completed: Dec 4

#ifndef NODE
#define NODE

#include<iostream>
#include<string>

class MorseTree {
 public:
  MorseTree(std::istream &code_file);
  MorseTree(const MorseTree &source);
  ~MorseTree();
  MorseTree operator= (const MorseTree &source);
  void write(std::ostream &out);
  void encode(std::istream &message_file, std::ostream &out);
  void decode(std::istream &message_file, std::ostream &out);
  
 private:
  struct TreeNode {
    TreeNode(char initial_letter='*', TreeNode *initial_lchild=nullptr, TreeNode *initial_rchild=nullptr) {
      letter=initial_letter;
      lchild=initial_lchild;
      rchild=initial_rchild;
    }
    char letter;
    TreeNode *lchild;
    TreeNode *rchild; 
  };
  
  TreeNode *copy_tree(TreeNode *source_root);
  void delete_tree(TreeNode *source_root);
  void write_tree(std::ostream &out, TreeNode *local_root, int depth);
  std::string char_to_code(char ch, TreeNode *t, std::string path_so_far);
  
  TreeNode *root;
};

#endif
