#ifndef NODE_H
#define NODE_H



template<typename T> class Node
{

public:

    // constructor
    Node(T data)
        :data(data), previousNode(nullptr), nextNode(nullptr)
    { }
    ~Node() {
        delete data;
    }

    // getter/setter
    Node* getNextNode() const {
        return nextNode;
    }

    void setNextNode(Node* nextNode) {
        this->nextNode = nextNode;
    }

    Node* getPreviousNode() const {
        return previousNode;
    }

    void setPreviousNode(Node* previousNode) {
        this->previousNode = previousNode;
    }

    T getData() const {
        return data;
    }

    void setData(T data) {
        this->data = data;
    }


private:

    // data
    T data;

    // nodes
    Node* previousNode;
    Node* nextNode;

};

#endif // NODE_H
