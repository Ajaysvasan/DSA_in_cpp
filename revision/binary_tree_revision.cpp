#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val){
            this->data = val;
            this->left = this->right = nullptr;
        }
};

class BinaryTree{
    private:
    Node* root;

        Node* insertData(Node* node,int data){
            if(node == nullptr) return new Node(data);
            if(node->data > data) node->left = insertData(node->left,data);
            else node->right = insertData(node->right,data);
            return node;
        }

        vector<int> inOrderTraversal(Node* node,vector<int>&arr){
            if(node){
                inOrderTraversal(node->left,arr);
                arr.push_back(node->data);
                inOrderTraversal(node->right,arr);
            }
            return arr;
        }
        vector<int> postOrderTraversal(Node* node,vector<int>&arr){
            if(node){
                postOrderTraversal(node->left,arr);  
                postOrderTraversal(node->right,arr);
                arr.push_back(node->data);
            }
            return arr;
        }

        vector<int> preOrderTraversal(Node* node,vector<int>&arr){
            if(node){                
                arr.push_back(node->data);
                preOrderTraversal(node->left,arr);
                preOrderTraversal(node->right,arr);

            }
            return arr;
        }

        bool search(Node* node,int target){
            if (node == nullptr) {
                cout << "The element is not Found" << endl;
                return false;
            }
            if (node->data == target) {
                cout << "The element is Found" << endl;
                return true;
            }
            if (target < node->data)
                return search(node->left, target);
            else
                return search(node->right, target);
        }

        public:
            BinaryTree(){root = nullptr;}
            
            void insert(int data){
                root = insertData(root,data);
            }

            void traverlal(int choice){
                vector<int> arr;
                switch(choice){
                    case 1:
                        cout<<"Inorder Traversal"<<endl;
                        arr = inOrderTraversal(root,arr);
                        break;
                    case 2:
                        cout<<"Postorder Traversal"<<endl;
                        arr = postOrderTraversal(root,arr);
                        break;
                    case 3:
                        cout<<"Pre order Traversal"<<endl;
                        arr = preOrderTraversal(root,arr);
                        break;
                }
                for(int num:arr)
                    cout<<num<<" ";
                cout<<endl;
            }

            void Search(int target){
                search(root,target);
            }
};

main(){
    BinaryTree tree;

    int values[] = {7, 4, 9, 1, 6, 8, 10};
    for (int val : values) {
        tree.insert(val);
    }

    for(int i = 1;i<4;i++)
        tree.traverlal(i);

    // Search test
    tree.Search(11);
}