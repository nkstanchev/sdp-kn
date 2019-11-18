## Binary Tree
Да се реализира имплементация на двойчно наредено дърво, като за целта се използва дадената структура:
```
struct Node {
        int value;
        Node * left, *right;
        Node(int value_) : value(value_), left(nullptr), right(nullptr) {}
};
```
За дървото трябва да се реализират следните методи:
```
Node* find(Node* current, int value)
std::vector<Node*> getLeaves(Node* current)
void insert(Node* current, int value) 
void erase(Node* current, int value) 
int  findMin(Node* current)
int findMax(Node* current)
void printElements(Node* current)
bool isFullBinaryTree(Node* root)
bool isSubtree(struct Node *T, struct node *S) 
void printKDistant(struct Node *root , int k)  
void serialize(Node *root, FILE *fp) 
void deSerialize(Node *&root, FILE *fp) 
```
