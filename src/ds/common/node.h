namespace ds{
struct Node{
   Node(int value): data_(value){};
   virtual ~Node(){}
   int getValue() { return data_;}
   Node* next_ = nullptr;
private:
    int data_;
};
}
