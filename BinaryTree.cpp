/**
 *    author:  Mohammad Jashim Uddin
**/
#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define Y cout << "YES" << endl;
#define yy cout << "Yes" << endl;
#define N cout << "NO" << endl;
#define nn cout << "No" << endl;
#define one cout << "1" << endl;
#define onee cout << "-1" << endl;
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
}; // Binary Tree এর Node এর নীল নকশা 


Node *input_tree() // একটি ফাংশন তৈরি করা হয়েছে। যা একটি Binary Tree input নিয়ে তার Root Node এর এড্রেস রিটার্ন করবে
{
    int val;
    cin >> val; // প্রথমে Root Node এর ভ্যালু ইনপুটে নিলাম 
    Node *root;  
    if (val == -1) // যদি Root -1 হয় তবে Root টি Null হবে অর্থাৎ Binary Tree টি empty
        root = NULL;
    else
        root = new Node(val); // Otherwise ঐ Node টি হলো Root Node
    
    queue<Node *> q; // এরপর বাকি প্রসেস Queue এর সাহায্যে করার জন্য আমরা একটি Node এর Queue নিলাম 
    

    if (root) 
        q.push(root); // এরপর Root Node কে queue তে পুশ করলাম 
    while (!q.empty())
    {
        // এরপর একটি একটি Node পিক করতে থাকবো 
        Node *p = q.front(); // প্রথমে শুরুতে যে Node আছে তাকে পিক করলাম
        q.pop();

        // যেহেতু এই Node এর সাথে তার Child গুলোকে কানেক্ট করা লাগবে , তাই এর child গুলো ইনপুট নেয়া হচ্ছে
        int l, r;
        cin >> l >> r;

       // দুটি Node পয়েন্টার তৈরি করা হয়েছে যা ঐ picked নোড এর children দের এড্রেস রাখবে
        Node *myLeft; 
        Node *myRight;
        
        // l এর মান -1 হলে , ঐ Node এর কোনো left children নেই 
        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l); // Otherwise left Node ক্রিয়েট করা হয়েছে

        // r এর মান -1 হলে , ঐ Node এর কোনো right children নেই 
        if (r == -1)
            myRight = NULL;
        else
            myRight = new Node(r); // Otherwise right Node ক্রিয়েট করা হয়েছে

        p->left = myLeft; // picked Node এর left এ left child কানেক্ট করা হয়েছে 
        p->right = myRight; // picked Node এর left এ right child কানেক্ট করা হয়েছে 

        // এরপর ঐ Children গুলোকে লাইনে দাড় করানো হয়েছে। 
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root; // সবশেষে Root Node টি রিটার্ন করা হয়েছে। 
}

// pre-order traversal এর function 
void preorder(Node *root)
{
    /* এটি base case অর্থাৎ root এ যদি null পাওয়া যায় তাহলে pre-order traversal শেষ হবে */
    if (root == NULL)
    {
        return;
    }
    //এখানে root print হবে।
    cout << root->val << " ";
    
    preorder(root->left);
    preorder(root->right);
}

// post-order traversal এর function 
void postorder(Node *root)
{
  /* এটি base case অর্থাৎ root এ যদি null পাওয়া যায় তাহলে post-order traversal শেষ হবে */
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    //এখানে root print হবে।
    cout << root->val << " ";
}

// in-order traversal এর function 
void inorder(Node *root)
{
  /* এটি base case অর্থাৎ root এ যদি null পাওয়া যায় তাহলে in-order traversal শেষ হবে */
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void level_order(Node *root) // আমরা শুরুতে ফাংশনে Root পাস করে কাজটি শুরু করবো 
{
    if (root == NULL) // যদি Root , Null হয় , তার মানে Tree টি খালি। অর্থাৎ , কোনো Node নেই
    {
        cout << "Tree nai" << endl; 
        return;
    }
    queue<Node *> q; // লাইনটি ঠিকমতো পরিচালনা করার জন্য Queue নিলাম  
    q.push(root); // এবং Queue এর সর্বপ্রথম সদস্য Root কে পুশ করে দিলাম
    
    // এরপর বাকি কাজটুকু আমরা Automated করে দিলাম 
    while (!q.empty()) // যতক্ষন Queue তে কেও থাকবে 
    {
        // 1. লাইনের শুরুতে যে আছে তাকে বের করে আনবো 
        Node *f = q.front(); // আমরা তাকে পিক করবো
        q.pop(); // এবং Queue থেকে বের করে আনবো 

        // 2. ঐ Node এর যাবতীয় কাজ গুলো করবো 
        cout << f->val << " "; // সেই Node টিকে প্রসেসিং করবো 

        // 3. এরপর পরবর্তীতে যারা আসবে তাদের লিস্ট নিয়ে পরের জন্য Queue তে পুশ করে দিবো 
         // এই ক্ষেত্রে ঐ Node এর Child গুলোকে Queue তে পুশ করে দিবো
        if (f->left) // left child থাকলে তাকে পুশ করবো 
            q.push(f->left);
        if (f->right) // right child থাকলে তাকে পুশ করবো 
            q.push(f->right);
    }
}
int main()
{
    Node *root = input_tree();
    // level_order(root);
    cout<<"Pre Order"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"Post Order"<<endl;
    postorder(root);
    cout<<endl;
    cout<<"In Order"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"Level Order"<<endl;
    level_order(root);
    return 0;
}