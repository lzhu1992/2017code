#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

//LinkedList
template<typename T>
class LinkedList {
private:
    class Node {
    public:
        T val;
        Node* next;
        Node* prev;
        Node(const T& v, Node* next, Node* prev)
        : val(v), next(next), prev(prev) {}
    };
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }
    ~LinkedList() {
        delete head; // O(n) space complexity O(n)
    }
    void addStart(const T& v) {
        if (head == nullptr) {
            head = new Node(v, head, nullptr);
            return;
        }
        head = new Node(v, head, nullptr);
        head->next->prev = head;
    }
    void addEnd(const T& v) {
        if (head == nullptr) {
            head = new Node(v, nullptr, nullptr);
            return;
        }
        Node* p;
        for (p = head; p->next != nullptr; p = p->next)
            ;
        p->next = new Node(v, nullptr, p);
    }
    void add(const T& v) { addStart(v); }
    void insert(const T& v, int pos) {
        Node* p = head;
        for (int i = 0; i < pos; i++)
            p = p->next;
        Node* temp = new Node(v, p->next, p);
        p->next = temp; // break the link with the node before us
        temp->next->prev = temp;
    }
    void out_put(){
        Node* p;
        for(p=head;p!=nullptr;p=p->next){
            cout<<p->val;
        }
        cout <<'\n';
    }
    void Remove_Front(int n){
        Node* p=head;
        for(int i=0;i<n;i++){
            p=head->next;
            delete head;
            p->prev=nullptr;
            head=p;
        }
    }
    void Remove_Back(int n){
        Node* p;
        Node* q;
        for(p=head;p->next!=nullptr;p=p->next);
        for(int i=0;i<n;i++){
            q=p->prev;
            q->next=nullptr;
            delete p;
            p=q;
        }
        
    }
    
    
};



template <typename T>
void Checkflag(int flag,LinkedList<T>& t,T a[],int len){
    switch (flag) {
        case 0:
            break;
        case 1:
            for(int i=len-1;i>=0;i--){
                t.add(a[i]);
            }
            break;
        case 2:
            for(int i=0;i<len;i++){
                t.addEnd(a[i]);
            }
            
            break;
        case 3:
            t.Remove_Front(a[0]);
            break;
        case 4:
            t.Remove_Back(a[0]);
            break;
        default:
            break;
    }
    
}

int main(){
    ifstream myfile;
    myfile.open("HW4b.txt");
    if (myfile.fail())
    {
        cout << "Read file fail!!!" << endl;
        return -1;
    }
    LinkedList<int> t;
    string str;
    int a[100]={0};
    int len=0;
    int flag=0;
    
    while(!myfile.eof()){
        myfile >> str;
        if(isdigit(str[0])){
            a[len]= atoi(str.c_str());
            len++;
        }
        else if(str=="ADD_FRONT"){
            Checkflag(flag,t,a,len);
            len=0;
            flag=1;
        }
        else if(str=="ADD_BACK"){
            Checkflag(flag,t,a,len);
            flag=2;
            len=0;
        }
        else if(str=="REMOVE_FRONT"){
            Checkflag(flag,t,a,len);
            flag=3;
            len=0;
        }
        else if(str=="REMOVE_BACK"){
            Checkflag(flag,t,a, len);
            flag=4;
            len=0;
        }
        else if(str=="OUTPUT"){
            Checkflag(flag,t,a,len);
            flag=0;
            len=0;
            t.out_put();
        }
        
    }
    return 0;
}
