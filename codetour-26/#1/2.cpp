#include <bits/stdc++.h>

using namespace std;

struct Node {
    array<Node*, 28> next_char{};
    bool ends_rule = false;
};

void deleteRecursive(Node* node) {
    for (int i = 0; i < 28; ++i) {
        if (node->next_char[i] != nullptr) {
            deleteRecursive(node->next_char[i]);
        }
    }

    delete node;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_set<string> bannedWords;

    string res;

    Node bannedPrefixes;
    Node bannedSuffixes;

    while (n--) {
        int instruction;
        string input;

        cin >> instruction >> input;
        Node* traversal;
        Node* rule_before_start;
        Node* rule_start;

        switch (instruction) {
            case 1:
                bannedWords.erase(input);
                break;
            case 2:
                bannedWords.insert(input);
                break;
            case 3:
                rule_before_start = rule_start = traversal = &bannedPrefixes;

                for (int i = 0; i < input.size(); ++i) {
                    int index = input[i] - 'a';
                    if (traversal->next_char[index] == nullptr) {
                        break;
                    }
                    traversal = traversal->next_char[index];
                    if (traversal->ends_rule) {
                        rule_before_start = rule_start;
                        rule_start = traversal;
                    }
                }

                rule_start = rule_before_start;

                for (int i = 0; i < 28; ++i) {
                    if (rule_start->next_char[i] != nullptr) {
                        deleteRecursive(rule_start->next_char[i]);
                        rule_start->next_char[i] = nullptr;
                    }
                }

                break;
            case 4:
                traversal = &bannedPrefixes;

                for (const char& c : input) {
                    int index = c - 'a';
                    if (traversal->next_char[index] == nullptr) {
                        traversal->next_char[index] = new Node{};
                    }
                    traversal = traversal->next_char[index];
                }

                traversal->ends_rule = true;

                break;
            case 5:
                rule_before_start = rule_start = traversal = &bannedPrefixes;

                for (int i = 0; i < input.size(); ++i) {
                    int index = input[input.size() - 1 - i] - 'a';
                    if (traversal->next_char[index] == nullptr) {
                        break;
                    }
                    traversal = traversal->next_char[index];
                    if (traversal->ends_rule) {
                        rule_before_start = rule_start;
                        rule_start = traversal;
                    }
                }

                rule_start = rule_before_start;

                for (int i = 0; i < 28; ++i) {
                    if (rule_start->next_char[i] != nullptr) {
                        deleteRecursive(rule_start->next_char[i]);
                        rule_start->next_char[i] = nullptr;
                    }
                }

                break;
            case 6:
                traversal = &bannedSuffixes;

                for (auto it = input.rbegin(); it != input.rend(); ++it) {
                    int index = *it - 'a';
                    if (traversal->next_char[index] == nullptr) {
                        traversal->next_char[index] = new Node{};
                    }
                    traversal = traversal->next_char[index];
                }

                traversal->ends_rule = true;
                break;
            case 7:
                if (bannedWords.count(input)) {
                    res += "N\n";
                    goto clean_exit;
                }

                traversal = &bannedPrefixes;

                for (auto it = input.begin(); it != input.end(); ++it) {
                    int index = *it - 'a';
                    traversal = traversal->next_char[index];
                    if (traversal == nullptr) break;

                    if (traversal->ends_rule) {
                        res += "N\n";
                        goto clean_exit;
                    }
                }

                traversal = &bannedSuffixes;

                for (auto it = input.rbegin(); it != input.rend(); ++it) {
                    int index = *it - 'a';
                    traversal = traversal->next_char[index];
                    if (traversal == nullptr) break;

                    if (traversal->ends_rule) {
                        res += "N\n";
                        goto clean_exit;
                    }
                }

                res += "Y\n";
            clean_exit:
                break;
            default:
                break;
        }
    }

    cout << res;

    return 0;
}
