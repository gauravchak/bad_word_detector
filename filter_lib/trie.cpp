#include "trie.hpp"
namespace ifilter
{

    TrieNode::~TrieNode()
    {
        // TODO(gchak) deallocate properly
    }

    void TrieNode::AddWord(const std::string &word, int idx, std::map<char, std::vector<char>> &subs)
    {
        if (idx >= word.length())
        {
            is_leaf = true;
            return;
        }
        char ch = word[idx];
        std::vector<char> allch = {ch};
        if (auto it = subs.find(ch); it != subs.end())
        {
            for (auto subch : it->second)
            {
                // TODO(gchak) check if it->second is a pointer
                allch.push_back(subch);
            }
        }
        for (auto this_char : allch)
        {
            if (auto it = children.find(this_char); it == children.end())
            {
                children[this_char] = new TrieNode();
            }
            // children[this_char] exists
            children[this_char]->AddWord(word, idx + 1, subs);
        }
    }
    bool TrieNode::WordExists(const std::string &word, int idx, std::map<char, std::vector<char>> &subs)
    {
        if (is_leaf)
        {
            return true;
        }
        if (idx >= word.length())
        {
            return is_leaf; // false
        }
        char this_char = word[idx];
        if (auto it = children.find(this_char); it == children.end())
        {
            return false;
        }
        // children[this_char] exists
        return children[this_char]->WordExists(word, idx + 1, subs);
    }
}