#include "q.h"

#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <algorithm>
// Implement each function of `q.h` here.

std::map<std::string, int> WordHistogram(std::string &text)
{
    std::map<std::string, int> histogram = {};
    if (text.length() == 0)
    {
        return histogram;
    }
    // std::set<std::string> words;
    std::string word;
    for (const auto & character : text)
    {
        if (!((character == ' ') || (character == '.') || (character == '.')))
        {
            word.push_back(character);
        }
        else if (word.length() != 0)
        {
            auto map_iter = histogram.find(word);
            if (map_iter == histogram.end())
            {
                histogram[word] = 0;
            }
            histogram[word]++;
            word = "";
        }
    }
    return histogram;
}