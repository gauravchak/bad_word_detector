#include "filter.hpp"
namespace ifilter
{

    IntegrityFilter::IntegrityFilter(std::map<char, std::vector<char>> input_subs,
                                     std::vector<std::string> input_bad_words) : bad_words(input_bad_words), subs(input_subs)
    {
        root_node = new TrieNode();
        for (const std::string &bad_word : bad_words)
        {
            root_node->AddWord(bad_word, 0, subs);
        }
    }

    bool IntegrityFilter::IsFine(const std::string &word)
    {
        for (int i = 0; i < word.length(); i++)
        {
            if (root_node->WordExists(word, i, subs))
            {
                return false;
            }
        }
        return true;
    }
}