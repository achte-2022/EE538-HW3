#include "q.h"

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
// Implement each function of `q.h` here.

// Write a new parameterized constructor that takes a vector as an input and
// crates a linked list based on that. Note that your constructor should
// assign a valid value for head_. Example:
// Input:  v = {1, 4, 5, 6, 10}
// The created list: 1->4->5->6->10, and head_ will point to the first node
// with value 1.
SinglyLinkedList::SinglyLinkedList(const std::vector<int> &v)
{
    for (const auto &element : v)
    {
        push_back(element);
    }
}

// Copy constructor.
SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList &rhs)
{
    for (int i = 0, n = rhs.size_; i < n; i++)
    {
        push_back(rhs[i]);
    }
}

// Destructor
SinglyLinkedList::~SinglyLinkedList()
{
    while (size() != 0)
    {
        pop_back();
    }
}

// Returns true if the list is empty, false otherwise.
bool SinglyLinkedList::empty() const
{
    return (size() == 0);
}

// Returns the current size of the list.
int SinglyLinkedList::size() const
{
    return size_;
}

// Returns a pointer to the head of the list.
ListNode* SinglyLinkedList::head() const
{
    return head_;
}

// Insert i at the back of the list.
void SinglyLinkedList::push_back(int i)
{
    ListNode* back_ptr = GetBackPointer();
    ListNode* new_node_ptr = new ListNode(i);
    back_ptr->next = new_node_ptr;
    size_++;
    return;
}

// Removes an item from the back of the list. Returns true if it was
// successfull.
bool SinglyLinkedList::pop_back()
{
    ListNode* tmp_ptr = head();
    ListNode* back_ptr = GetBackPointer();
    for(int i = 0, n = size(); i < (n - 1); i++)
    {
        tmp_ptr = tmp_ptr->next;
    }
    if ((tmp_ptr == nullptr) || (back_ptr == nullptr))
    {
        return false;
    }
    delete back_ptr;
    tmp_ptr->next = nullptr;
    size_--;
    return true;
}

// Returns the item in the back of the list. Returns -1 if empty.
int SinglyLinkedList::back()
{
    if (empty())
    {
        return -1;
    }
    ListNode* back_ptr = GetBackPointer();
    return back_ptr->val;
}

// Returns a pointer to the back of the list.
ListNode* SinglyLinkedList::GetBackPointer()
{
    ListNode* tmp_ptr = head();
    if (tmp_ptr == nullptr)
    {
        return nullptr;
    }
    while (tmp_ptr->next != nullptr)
    {
        tmp_ptr = tmp_ptr->next;
    }
    return tmp_ptr;
}

// Returns a pointer to the i(th) element in the list. nullptr if it doesn't
// exist.
ListNode* SinglyLinkedList::GetIthPointer(int i) const
{
    if ((i >= size()) || (empty()))
    {
        return nullptr;
    }
    ListNode* tmp_ptr = head();
    for (int j = 1; j <= i ; j++)
    {
        tmp_ptr = tmp_ptr->next;
    }
    return tmp_ptr;
}

// Returns the i(th) element in the list. -1 if it doesn't exits.
int SinglyLinkedList::operator[](int i) const
{
    ListNode* ith_ptr = GetIthPointer(i);
    if (ith_ptr == nullptr)
    {
        return -1;
    }
    return ith_ptr->val;
}

// Prints the items in the list.
void SinglyLinkedList::print()
{
    for (int i = 0, n = size(); i < n; i++)
    {
        std::cout << this->operator[](i)<<std::endl;
    }
}

// Write a function that converts the list into a vector. Example:
// The list: 1->4->5->6->10
// Output: a vector with value: {1, 4, 5, 6, 10}
std::vector<int> SinglyLinkedList::convert_to_vector()
{
    std::vector<int> result;
    for (int i = 0, n = size(); i < n; i++)
    {
        result.push_back(this->operator[](i));
    }
    return result;
}

// Erases element i from the list if it exists and returns a pointer to item
// i-1. If item i doesn't exist, returns nullptr. The first item in the list
// has index 0.

// Example:
// Input: 1 -> 5 -> 10 ->20, i= 2.
// Output: 1 -> 5 -> 20, return value: a pointer to element 5.
ListNode* SinglyLinkedList::erase(int i)
{
    if ((i >= size()) || (i < 0) || (size() == 0))
    {
        return nullptr;
    }
    else
    {
        if (i == 0)
        {
            ListNode* new_head = head()->next;
            delete head_;
            head_ = new_head;
            return head_;
        }
        else if (i == (size() - 1))
        {
            pop_back();
            return GetBackPointer();
        }
        else
        {
            ListNode* prev_ptr = GetIthPointer(i - 1);
            ListNode* curr_ptr = GetIthPointer(i);
            prev_ptr->next = curr_ptr->next;
            delete curr_ptr;
            return prev_ptr;
        }
    }
}

// Removes duplicate elements and only keeps the first one.
// Example:
// Input: 1 -> 5 -> 1 -> 20 -> 4 -> 5 -> 32
// Output: 1 -> 5 -> 20 -> 4 -> 32
void SinglyLinkedList::remove_duplicates()
{
    std::unordered_set<int> unique_elements;
    ListNode* tmp_ptr = head();
    int tmp_value;
    int counter = 0;
    while (tmp_ptr != nullptr)
    {
        tmp_value = tmp_ptr->val;
        auto set_iter = unique_elements.find(tmp_value);
        if (set_iter == unique_elements.end())
        {
            unique_elements.insert(tmp_value);
            counter++;
        }
        else
        {
            tmp_ptr = erase(counter);
        }
        tmp_ptr = tmp_ptr->next;
    }
    return;
}