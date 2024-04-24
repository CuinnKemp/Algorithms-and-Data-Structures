#ifndef NODE
#define NODE

class Node {
private:
    int data;
    Node* link;

public:
    Node(int value, Node* link);
    int get_data();
    void set_data(int value);

    Node* get_link();
    void set_link(Node* link);
};

#endif //NODE