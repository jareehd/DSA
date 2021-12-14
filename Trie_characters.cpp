class TrieNode{
  public:
    TrieNode *data[26];
    int end;
    int count;
    
    TrieNode(){
        for(int i=0; i<26; i++)
            data[i] = nullptr;
        end = 0;
        count = 0;
    }
};

class Trie{

    public:
    TrieNode * root;
    Trie(){
        root = new TrieNode();
    }

    void insert(string &word){
      TrieNode *head = root;
      for(int i=0; i<word.size(); i++){
          if(head->data[word[i]-'a'] == nullptr) 
              head->data[word[i]-'a'] = new TrieNode();
          head = head->data[word[i]-'a'];
          head->count++;
      }
        
      head->end++;
    }

    int countWordsEqualTo(string &word){
      TrieNode *head = root;
      for(int i=0; i<word.size(); i++){
          if(head->data[word[i]-'a'] == nullptr) return 0;
          head = head->data[word[i]-'a'];
      }
        
      return head->end;
    }

    int countWordsStartingWith(string &word){
      TrieNode *head = root;
      for(int i=0; i<word.size(); i++){
          if(head->data[word[i]-'a'] == nullptr) return 0;
          head = head->data[word[i]-'a'];
      }
        
      return head->count;
    }

    void erase(string &word){
      TrieNode *head = root;
      for(int i=0; i<word.size(); i++){
          if(head->data[word[i]-'a'] == nullptr) 
              head->data[word[i]-'a'] = new TrieNode();
          head = head->data[word[i]-'a'];
          head->count--;
      }
        
      head->end--;
    }
};
