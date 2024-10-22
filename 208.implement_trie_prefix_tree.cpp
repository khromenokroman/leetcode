/*
 208. Implement Trie (Prefix Tree)
Solved
Medium
Topics
Companies
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a
dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false
otherwise. boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the
prefix prefix, and false otherwise.


Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True


Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.
 */

#include <iostream>
#include <memory>
#include <string>
#include <vector>
static constexpr int MAX_SIZE = 26;

struct Node {
    Node() { m_data = std::vector<std::unique_ptr<Node>>(MAX_SIZE); }
    Node* m_node_next = nullptr;
    std::vector<std::unique_ptr<Node>> m_data;
    bool m_is_key{false};
};

class Trie {
   private:
    std::unique_ptr<Node> m_node_root;

   public:
    Trie() : m_node_root{std::make_unique<Node>()} {}
    bool insert(std::string const& word) {
        if (!word.empty()) {
            Node* node = m_node_root.get();
            for (auto const& symbol : word) {
                auto index = symbol - 'a';
                if (!node->m_data[index]) {
                    node->m_data[index] = std::make_unique<Node>();
                    node = node->m_data[index].get();
                } else {
                    node = node->m_data[index].get();
                }
            }
            node->m_is_key = true;
            return true;
        } else {
            return false;
        }
    }
    bool search(std::string const& word) {
        if (!word.empty()) {
            Node* node = m_node_root.get();
            for (auto const& symbol : word) {
                auto index = symbol - 'a';
                if (!node->m_data[index]) {
                    return false;
                } else {
                    node = node->m_data[index].get();
                }
            }
            if (node->m_is_key) {
                return true;
            } else {
                return false;
            }

        } else {
            return false;
        }
    }
    bool startsWith(std::string const& word) {
        if (!word.empty()) {
            Node* node = m_node_root.get();
            for (auto const& symbol : word) {
                auto index = symbol - 'a';
                if (!node->m_data[index]) {
                    return false;
                } else {
                    node = node->m_data[index].get();
                }
            }
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Trie tree;
    std::cout << "insert apple: " << tree.insert("apple") << std::endl;
    std::cout << "search apple: " << tree.search("apple") << std::endl;
    std::cout << "search app: " << tree.search("app") << std::endl;
    std::cout << "starts_with app: " << tree.startsWith("app") << std::endl;
    std::cout << "insert app: " << tree.insert("app") << std::endl;
    std::cout << "search app: " << tree.search("app") << std::endl;
    return 0;
}