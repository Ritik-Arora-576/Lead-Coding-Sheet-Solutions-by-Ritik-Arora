// TC: O(n)
// SC: O(n)

class MyQueue {
    class node{
        public:
        int val;
        node* next;
        
        node(int val)
        {
            this->val=val;
            this->next=NULL;
        }
    };
    node* head;
    node* tail;
    int size;
    
public:
    MyQueue() {
        this->head=NULL;
        this->tail=NULL;
        this->size=0;
    }
    
    void push(int x) {
        node* n=new node(x);
        if(head==NULL)
        {
            head=n;
            tail=n;
        }
        
        else
        {
            tail->next=n;
            tail=tail->next;
        }
        
        size++;
    }
    
    int pop() {
        node* temp=head;
        head=head->next;
        temp->next=NULL;
        size--;
        return temp->val;
    }
    
    int peek() {
        return head->val;
    }
    
    bool empty() {
        return size==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */