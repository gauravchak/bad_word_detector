
#include "trie.hpp"

namespace ifilter
{
    class IntegrityFilter
    {
        std::vector<std::string> bad_words;     // saving them in case AddSub is called
        std::map<char, std::vector<char>> subs; // saving them in case AddBadWord is called

        TrieNode *root_node;
        void AddBadWord(const std::string &word);

    public:

        IntegrityFilter(std::map<char, std::vector<char>> subs, std::vector<std::string> bad_words);
        bool IsFine(const std::string &word);
        // TODO(gchak) AddSub, AddBadWord
    };
}