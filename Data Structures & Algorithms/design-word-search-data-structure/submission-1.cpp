class WordDictionary {
public:
    WordDictionary* children[26];
    bool isEndOfWord;

    WordDictionary() : children(nullptr), isEndOfWord(false) {}
    
    void addWord(string word) {
        WordDictionary* curr = this;
        for (char c : word) {
            int index = c - 'a';
            if (!curr->children[index]) curr->children[index] = new WordDictionary();
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }

    bool search(string word) {
        return dfs(word, this);
    }
    
    bool dfs(string word, WordDictionary* curr) {
        if (word.empty()) return curr->isEndOfWord;
        if (word[0] == '.') {
            for (WordDictionary* wd : curr->children) {
                if (wd && dfs(word.substr(1), wd)) return true;
            }
            return false;
        }
        int index = word[0] - 'a';
        if (!curr->children[index]) return false;
        return dfs(word.substr(1), curr->children[index]);
    }
};
