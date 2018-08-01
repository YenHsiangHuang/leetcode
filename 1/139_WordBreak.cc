#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

/**
   This can also be done by dynamic programming. I will implement that next
   time.
 */
bool wordBreak(std::string& s, size_t begin, std::vector<std::string>& wordDict,
               std::unordered_map<int, bool>& memo) {
    if (memo.count(begin) > 0) return memo[begin];  // Use pre-stored result
    if (begin == s.length()) return true;           // Reach the end of string

    for (auto& word : wordDict) {
        int len = word.length();
        int isSame =
            s.compare(begin, len, word);  // Compare head of s with word
        if (isSame != 0) continue;        // Not the same
        if (wordBreak(s, begin + len, wordDict, memo)) {  // Same
            memo[begin] = true;
            return true;
        }
    }

    memo[begin] = false;
    return false;
}

bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
    std::unordered_map<int, bool> memo;
    return wordBreak(s, 0, wordDict, memo);
}

bool wordBreak(std::string s, std::vector<std::string>&& wordDict) {
    return wordBreak(s, wordDict);
}

int main(int argc, const char *argv[]) {
    std::cout << wordBreak("leetcode", std::vector<std::string>{"leet", "code"})
              << std::endl;
    std::cout << wordBreak("applepenapple",
                           std::vector<std::string>{"apple", "pen", "code"})
              << std::endl;
    std::cout << wordBreak("catsandog",
                           std::vector<std::string>{"cats", "sand", "dog",
                                                    "cat", "and"})
              << std::endl;
    std::cout << wordBreak(
                     "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
                     std::vector<std::string>{"a", "aa", "aaa", "aaaaa", "aaaaaa"})
              << std::endl;

    return 0;
}
