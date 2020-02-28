class Node
{
    private:
        int payload;
        Node* nextNode;

    public:
        Node(int payload);
        int getPayload();
        void setNextNode(Node* n);
        Node* getNextNode();
};