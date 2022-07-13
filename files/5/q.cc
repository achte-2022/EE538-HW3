#include "q.h"

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

//-----------------------------------------------------------------------------
// Used by Google test. No need to change this!
//-----------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const Student& s) {
  return os << s.DebugString();
}
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// Implement Student class
//-----------------------------------------------------------------------------

// Parameterized constructor
Student::Student(std::string name, int grade)
{
  this->name = name;
  this->grade = grade;
}

// Non-parameterized constructor. Sets the default value for name to "NO_NAME"
// and grade to INT_MIN.
Student::Student()
{
  name = "NO_NAME";
  grade = INT_MIN;
}

// Copy constructor.
Student::Student(const Student& rhs)
{
  grade = rhs.grade;
  name = rhs.name;
}

// The following operators are overloaded. They only compare the grade part of
// the class with other objects.

// Returns true if grade is less than the grade of other Student objects and
// false otherwise.
bool Student::operator<(const Student& rhs) const
{
  return (grade < rhs.grade);
}

// Returns true if grade is greater than the grade of other Student objects
// and false otherwise.
bool Student::operator>(const Student& rhs) const
{
  return (grade > rhs.grade);
}

// Returns true if grade is equal to the grade of other Student objects and
// false otherwise.
bool Student::operator==(const Student& rhs) const
{
  return (grade == rhs.grade);
}


//-----------------------------------------------------------------------------
// Implement StudentMaxHeap class
//-----------------------------------------------------------------------------

// Parameterized constructor: creates a max heap from the given input.
StudentMaxHeap::StudentMaxHeap(std::vector<Student>& input)
{
  ConvertToHeap(input);
}

// Returns the parent of a node given its index in the tree. Returns
// Student("NO_NAME", INT_MIN) if unsuccessful.
Student StudentMaxHeap::GetParent(int i)
{
  int parent_index = GetParentIndex(i);
  if (parent_index == INT_MAX)
  {
    Student no_student;
    return no_student;
  }
  return data_[parent_index];
}

// Returns the left child of a node given its index in the tree. Returns
// Student("NO_NAME", INT_MIN) if unsuccessful.
Student StudentMaxHeap::GetLeft(int i)
{
  int left_index = GetLeftIndex(i);
  if (left_index == INT_MAX)
  {
    Student no_student;
    return no_student;
  }
  return data_[left_index];
}

// Returns the right child of a node given its index in the tree. Returns
// Student("NO_NAME", INT_MIN) if unsuccessful.
Student StudentMaxHeap::GetRight(int i)
{
  int right_index = GetRightIndex(i);
  if (right_index == INT_MAX)
  {
    Student no_student;
    return no_student;
  }
  return data_[right_index];
}

// Returns the index of the parent of a node given its index in the tree.
// Returns INT_MAX if unsuccessful.
int StudentMaxHeap::GetParentIndex(int i)
{
  if (i == 0)
  {
    return INT_MAX;
  }
  return ((i - 1) / 2);
}

// Returns the index of the left child of a node given its index in the tree.
// Returns INT_MAX if unsuccessful.
int StudentMaxHeap::GetLeftIndex(int i)
{
  if ((i * 2) + 1 > data_.size())
  {
    return INT_MAX;
  }
  return (i * 2) + 1;
}

// Returns the index of the right child of a node given its index in the tree.
// Returns INT_MAX if unsuccessful.
int StudentMaxHeap::GetRightIndex(int i)
{
  if ((i * 2) + 2 > data_.size())
  {
    return INT_MAX;
  }
  return (i * 2) + 2;   
}

// Returns the index of the largest child of a node given its index in the
// tree. Returns INT_MAX if unsuccessful.
int StudentMaxHeap::GetLargestChildIndex(int i)
{
  int left_child_index = GetLeftIndex(i);
  int right_child_index = GetRightIndex(i);
  if ((left_child_index == INT_MAX) && (right_child_index == INT_MAX))
  {
    return INT_MAX;
  }
  if (left_child_index == INT_MAX)
  {
    return right_child_index;
  }
  else if (right_child_index == INT_MAX)
  {
    return left_child_index;
  }
  else
  {
    int max_child_index = (left_child_index > right_child_index) ? left_child_index : right_child_index;
    return max_child_index;
  }
}

// Returns the top of the heap. Returns
// Student("NO_NAME", INT_MIN) if unsuccessful.
Student StudentMaxHeap::top()
{
  if (empty())
  {
    Student no_student;
    return no_student;
  }
  return data_[0];
}

// Adds a new Student to the heap.
void StudentMaxHeap::push(const Student& student)
{
  data_.push_back(student);
  TrickleUp(data_.size() - 1);
}

// Removes the top. Returns
// true if successful and false otherwise.
bool StudentMaxHeap::pop()
{
  data_[0] = data_.back();
  data_.pop_back();
  TrickleDown(0);
}

// Performs trickle up. It should use the overloaded operators of the Student
// class.
void StudentMaxHeap::TrickleUp(int i)
{
  if (i == 0)
  {
    return;
  }

  int parent_index = GetParentIndex(i);
  Student tmp;
  if (data_[i] > data_[parent_index])
  {
    std::iter_swap(data_.begin() + i, data_.begin() + parent_index);
    TrickleUp(parent_index);
  }
  return;
}

// Performs trickle up. It should use the overloaded operators of the Student
// class.
void StudentMaxHeap::TrickleDown(int i)
{
  int largest_child_index = GetLargestChildIndex(i);
  if (largest_child_index == INT_MAX)
  {
    return;
  }
  if (data_[i] < data_[largest_child_index])
  {
    std::iter_swap(data_.begin() + i, data_.begin() + largest_child_index);
    TrickleDown(largest_child_index);
  }
  return;
}

// Converts the given input into a max heap and stores that into data_.
void StudentMaxHeap::ConvertToHeap(const std::vector<Student>& input)
{
  for (const auto & element : input)
  {
    push(element);
  }
  return;
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

// Sorts the given input vector of students in place. The sort is in ascending
// order based on the grades.
void HeapSort(std::vector<Student>& input)
{
  StudentMaxHeap heap(input);
  input = heap.GetData();
}