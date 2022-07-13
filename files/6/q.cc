#include "q.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// Already implemented. No need to change!
void DeleteMemory(BinaryTreeNode *root) {
  if (root == nullptr) {
    return;
  }

  DeleteMemory(root->left);
  DeleteMemory(root->right);
  delete root;
}



std::vector<int> BinaryTree::PreOrder()
{
  std::vector<int> result;
  PreOrder_Helper(root_, result);
  return result;
}

// A helper function for Preorder.
void BinaryTree::PreOrder_Helper(BinaryTreeNode *root, std::vector<int> &v)
{
  if (root->left == nullptr)
  {
    int node_val = root->val;
    v.push_back(node_val);
    return;
  }

  int node_val = root->val;
  v.push_back(node_val);
  PreOrder_Helper(root->left, v);
  PreOrder_Helper(root->right, v);
  return;
}

// Returns the number of nodes in the tree. It uses size_helper.
int BinaryTree::size()
{
  int counter = 0;
  size_helper(root_, counter);
  return counter;
}

// A helper function for size()
void BinaryTree::size_helper(BinaryTreeNode *root, int &counter)
{
  if (root->left == nullptr)
  {
    counter++;
    return;
  }

  counter++;
  size_helper(root->left, counter);
  size_helper(root->right, counter);
  return;
}

// Returns the height of the tree. It uses GetHeight_Helper.
int BinaryTree::GetHeight()
{
  int max_height = 0;
  int current_level = 0;
  GetHeight_Helper(root_, current_level, max_height);
  return max_height;
}

void BinaryTree::GetHeight_Helper(BinaryTreeNode *root, int current_level,
                      int &max_height)
                      {

                      }

std::vector<Direction> BinaryTree::GetPathToIthElement(int i)
{
  std::vector<Direction> result;
  if ((i < 0) || (i > size()))
  {
    return result;
  }
  int current_index = i;
  std::vector<int> node_index;
  while (current_index >= 1)
  {
    node_index.push_back(current_index);
    current_index /= 2;
  }
  std::reverse(node_index.begin(), node_index.end());
  int left_child, right_child;
  for (int i = 0, n = node_index.size(); i < (n - 1); i++)
  {
    left_child = node_index[i] * 2;
    right_child = node_index[i] * 2 + 1;
    if (node_index[i + 1] == left_child)
    {
      result.push_back(Direction::kLeft);
    }
    else
    {
      result.push_back(Direction::kRight);
    }
  }
  return result;
}

//-----------------------------------------------------------------------------

bool IsBST(BinaryTreeNode *root)
{
  std::vector<int> node_vector = InOrder(root);
  if (node_vector.size() <= 1)
  {
    return true;
  }
  for (int i = 1, n = node_vector.size(); i < n; i++)
  {
    if (node_vector[i - 1] > node_vector[i])
    {
      return false;
    }
  }
  return true;
}

std::vector<int> InOrder(BinaryTreeNode *root)
{
  std::vector<int> result;
  InOrder_Helper(root, result);
  return result;
}

// A helper function for Preorder.
void  InOrder_Helper(BinaryTreeNode *root, std::vector<int> &v)
{
  if (root->left == nullptr)
  {
    int node_val = root->val;
    v.push_back(node_val);
    return;
  }

  InOrder_Helper(root->left, v);
  int node_val = root->val;
  v.push_back(node_val);
  InOrder_Helper(root->right, v);
  return;
}