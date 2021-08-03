#include "trie.hpp"

#include <gtest/gtest.h>

namespace ifilter
{
    namespace
    {
        TEST(TrieTest, AllOk)
        {
            // AddWord("hello", 0);
            // WordExists("hello", 0) should be true
            TrieNode root_node;
            std::map<char, std::vector<char>> subs;
            root_node.AddWord("hello", 0, subs);
            EXPECT_TRUE(root_node.WordExists("hello", 0, subs));
        }
    }
}
