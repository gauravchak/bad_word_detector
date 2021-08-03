#include <vector>
#include <map>
#include <string>

namespace ifilter
{
    struct TrieNode
    {
        bool is_leaf;
        std::map<char, TrieNode *> children; // TODO(gchak) experiment with unordered_map and vector-map
        TrieNode() : is_leaf(false)
        {
        }

        ~TrieNode();
        void AddWord(const std::string &word, int idx, std::map<char, std::vector<char>> &subs);
        bool WordExists(const std::string &word, int idx, std::map<char, std::vector<char>> &subs);
    };
}