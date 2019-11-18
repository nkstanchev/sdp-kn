#include <iostream>
#include <stack>
#include <queue>

struct Node {
int value;
Node* left, * right;
Node(int value_) : value(value_), left(nullptr), right(nullptr) {}
};

void dfs(Node*& root)
{
if (!root) return;

std::cout << root->value << " ";

if (root->left) dfs(root->left);
if (root->right) dfs(root->right);
}

void stackDFS(Node*& root)
{
Node* crr;
crr = root;

std::stack stack;
stack.push(root);

while (!stack.empty())
{
crr = stack.top();
stack.pop();
std::cout << crr->value << " ";

if (crr->right)stack.push(crr->right);
if (crr->left) stack.push(crr->left);
}
}

void queueBFS(Node*& root)
{
std::queue queue;
queue.push(root);

Node* crr;
while (!queue.empty())
{
crr = queue.front();
queue.pop();

std::cout << crr->value << " ";

if (crr->left) queue.push(crr->left);
if (crr->right)queue.push(crr->right);
}
}





int main()
{
Node* root = new Node(5);
root->left = new Node(6);
root->right = new Node(8);
root->left->left = new Node(20);
root->left->right = new Node(13);

dfs(root);
std::cout << '\n';
stackDFS(root);
std::cout << '\n';
queueBFS(root);
}

