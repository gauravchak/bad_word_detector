#include "filter.hpp"

#include <gtest/gtest.h>

namespace ifilter
{
    namespace
    {
        // Check that MyLib works properly
        TEST(FilterTest, AllOk)
        {
            std::map<char, std::vector<char>> input_subs;
            input_subs['i'] = {'1', '2'};

            std::vector<std::string> input_bad_words{"silly"};
            IntegrityFilter filter(input_subs, input_bad_words);
            EXPECT_TRUE(filter.IsFine("good"));
            EXPECT_FALSE(filter.IsFine("silly"));
            EXPECT_FALSE(filter.IsFine("s1lly"));
            EXPECT_FALSE(filter.IsFine("s2lly"));
        }

        TEST(FilterTest, bad_names_without_substitutions)
        {
            std::vector<std::string> input_bad_words = {
                "fool",
                "silly",
                "fork"};
            std::vector<std::string> test_cases = {
                "fool",
                "fork",
                "silly",

                "fooluser",
                "forkuser",
                "sillyuser",

                "userfool",
                "userfork",
                "usersilly",

                "afooluser",
                "aforkuser",
                "asillyuser",
            };
            std::map<char, std::vector<char>> input_subs;
            input_subs['o'] = {'0'};
            input_subs['l'] = {'1', '|'};
            input_subs['i'] = {'1', '!'};
            input_subs['s'] = {'$', '5'};
            input_subs['r'] = {'4'};

            IntegrityFilter filter(input_subs, input_bad_words);
            for (const std::string &word : test_cases)
            {
                EXPECT_FALSE(filter.IsFine(word));
            }
        }
    }

    TEST(FilterTest, bad_words_with_substitutions)
    {
        std::vector<std::string> input_bad_words = {
            "fool",
            "silly",
            "fork"};
        std::vector<std::string> test_cases = {
            "f00l",
            "fo4k",
            "s111y",

            "fo01user",
            "f04ku$e4",
            "$111yuser",

            "userf0o|",
            "u$erf04k",
            "user5!1ly",

            "afo0|user",
            "af0rku$er",
            "asil|yuser",
        };
        std::map<char, std::vector<char>> input_subs;
        input_subs['o'] = {'0'};
        input_subs['l'] = {'1', '|'};
        input_subs['i'] = {'1', '!'};
        input_subs['s'] = {'$', '5'};
        input_subs['r'] = {'4'};

        IntegrityFilter filter(input_subs, input_bad_words);
        for (const std::string &word : test_cases)
        {
            EXPECT_FALSE(filter.IsFine(word));
        }
    }

    TEST(FilterTest, good_names_without_substitutions)
    {
        std::vector<std::string> input_bad_words = {
            "fool",
            "silly",
            "fork"};
        std::vector<std::string> test_cases = {
            "user",

            "foo",
            "ool",
            "sil",
            "lly",
            "for",
            "ork",

            "userfoo",
            "userool",
            "usersil",
            "userlly",
            "userfor",
            "userork",

            "foouser",
            "ooluser",
            "siluser",
            "llyuser",
            "foruser",
            "orkuser",

            "afoouser",
            "aooluser",
            "asiluser",
            "allyuser",
            "aforuser",
            "aorkuser"};
        std::map<char, std::vector<char>> input_subs;
        input_subs['o'] = {'0'};
        input_subs['l'] = {'1', '|'};
        input_subs['i'] = {'1', '!'};
        input_subs['s'] = {'$', '5'};
        input_subs['r'] = {'4'};

        IntegrityFilter filter(input_subs, input_bad_words);
        for (const std::string &word : test_cases)
        {
            EXPECT_TRUE(filter.IsFine(word));
        }
    }

    TEST(FilterTest, good_names_with_substitutions)
    {
        std::vector<std::string> input_bad_words = {
            "fool",
            "silly",
            "fork"};
        std::vector<std::string> test_cases = {
            "u$e4",

            "f00",
            "o01",
            "s11",
            "1|y",
            "f04",
            "0rk",

            "userf00",
            "usero01",
            "users11",
            "user1|y",
            "userf04",
            "user0rk",

            "f00user",
            "o01user",
            "s11user",
            "1|yuser",
            "f04user",
            "0rkuser",

            "af00user",
            "ao01user",
            "as11user",
            "a1|yuser",
            "af04user",
            "a0rkuser",

            "foxol",
            "f0xxrk",
            "s1m1l1ly"};
        std::map<char, std::vector<char>> input_subs;
        input_subs['o'] = {'0'};
        input_subs['l'] = {'1', '|'};
        input_subs['i'] = {'1', '!'};
        input_subs['s'] = {'$', '5'};
        input_subs['r'] = {'4'};

        IntegrityFilter filter(input_subs, input_bad_words);
        for (const std::string &word : test_cases)
        {
            EXPECT_TRUE(filter.IsFine(word));
        }
    }
}