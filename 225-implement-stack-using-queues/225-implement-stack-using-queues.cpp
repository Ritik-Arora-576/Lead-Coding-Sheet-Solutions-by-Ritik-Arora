// TC: O(n)
// SC: O(n)

class MyStack {
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
    MyStack() {
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
            n->next=head;
            head=n;
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
    
    int top() {
        return head->val;
    }
    
    bool empty() {
        return size==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */