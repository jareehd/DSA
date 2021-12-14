class TrieNode {
    public:
      TrieNode* data[2];
    
      TrieNode(){
          for(int i=0; i<2; i++)
              data[i] = nullptr;
      }
};

class Trie {
public:
    TrieNode *root;
    
    Trie() {
        root = new TrieNode();    
    }
    
    void insert(int n) {
      TrieNode *head = root;
      for(int i=30; i>=0; i--){
          int cur = (n>>i) & 1;
          if(head->data[cur] == nullptr) 
              head->data[ cur ] = new TrieNode();
          head = head->data[cur];
      } 
    }
    
    int search(int n) {
      TrieNode *head = root;
      int res = 0 ;
      
     for(int i=30; i>=0; i--){
          int cur = (n>>i) & 1;
          
          if(head->data[1-cur] == nullptr)
          {
            head = head->data[cur];   
          }
          else
          {
              head = head->data[1-cur];
              res += (1<<i);
          }
      }
        
      return res;      
    }
    
};
