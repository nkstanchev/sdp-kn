class Node
{
    public:
    int data;
    TNode* left;
    TNode* right;
};
  
Node* newNode(int data)
{
    Node* node = new Node();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
  
    return node;
}

// Task 1
Node* sortedArrayToBST(int arr[],
                        int start, int end)
{
    /* Base Case */
    if (start > end)
    return NULL;
  
    /* Make middle the root */
    int mid = (start + end)/2;
    Node *root = newNode(arr[mid]);
  
    /* Recursively construct the left subtree
    and make it left child of root */
    root->left = sortedArrayToBST(arr, start,
                                    mid - 1);
  
    /* Recursively construct the right subtree
    and make it right child of root */
    root->right = sortedArrayToBST(arr, mid + 1, end);
  
    return root;
}

// Task 2
bool isBalanced(Node* root)
{
    int lh; /* for height of left subtree */
    int rh; /* for height of right subtree */
  
    /* If tree is empty then return true */
    if (root == nullptr)
        return 1;
  
    /* Get the height of left and right sub trees */
    lh = height(root->left);
    rh = height(root->right);
  
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
  
    /* If we reach here then
    tree is not height-balanced */
    return 0;
}
  

int max(int a, int b)
{
    return (a >= b) ? a : b;
}
  
int height(Node* node)
{

    if (node == nullptr)
        return 0;
  
    return 1 + max(height(node->left),
                   height(node->right));
}

// TASK 3
int isBSTUtil(Node* node, int min, int max);
  
/* Returns true if the given
tree is a binary search tree
(efficient version). */
int isBST(Node* node)
{
    return(isBSTUtil(node, INT_MIN, INT_MAX));
}
  
/* Returns true if the given
tree is a BST and its values
are >= min and <= max. */
int isBSTUtil(Node* node, int min, int max)
{
    /* an empty tree is BST */
    if (node==NULL)
        return 1;
              
    /* false if this node violates
    the min/max constraint */
    if (node->data < min || node->data > max)
        return 0;
      
    /* otherwise check the subtrees recursively,
    tightening the min or max constraint */
    return
        isBSTUtil(node->left, min, node->data-1) && // Allow only distinct values
        isBSTUtil(node->right, node->data+1, max); // Allow only distinct values
}
