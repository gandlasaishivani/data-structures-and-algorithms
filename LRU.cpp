class LRUCache {
public:
    class node{
          public :
          int key;
          int val;
          node *next;
          node *prev;
          node(int _key,int _val) {
            key = _key;
            val = _val;
          }
    };
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    unordered_map<int,node*> mpp;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev= head;
    }
    void addnode(node *newnode) {
         node *temp = head->next;
         newnode->next = temp;
         newnode->prev = head;
         temp->prev = newnode;
         head->next = newnode;
    }
    void deletenode(node *temp) {
        node *p = temp->prev;
        node *n = temp->next;
        p->next = n;
        n->prev = p;
    }
    int get(int key) {
        if(mpp.find(key) != mpp.end()) {
            node *temp = mpp[key];
            int ans = temp->val;
            mpp.erase(key);
            deletenode(temp);
            addnode(temp);
            mpp[key] = head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
         if(mpp.find(key) != mpp.end()) {
            node *temp = mpp[key];
            mpp.erase(key);
            deletenode(temp);
         }
         else if(mpp.size() == cap) {
              mpp.erase(tail->prev->key);
               deletenode(tail->prev);
         }
         addnode(new node(key,value));
         mpp[key] = head->next;
    }
};
