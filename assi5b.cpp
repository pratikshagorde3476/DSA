#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;


struct Node{
char data;
Node *left,*right;
Node(char val):data(val),left(NULL),right(NULL){}
};

class Tree{
public:
Node *root;
Tree():root(NULL){}

void buildExpressionTree(const char *prefix){
Node *stack[50];
int top = -1;

for(int i = strlen(prefix) - 1;i>=0;i--){
if(isalpha(prefix[i])){
stack[++top] = new Node(prefix[i]);
}else{
Node *node = new Node(prefix[i]);
node->left = stack[top--];
node->right = stack[top--];
stack[++top] = node;
}
}
root = stack[top];

}

void displayPostfix(Node *node){
if(!node) return;
displayPostfix(node->left);
displayPostfix(node->right);
cout<<node->data;
}

void deleteTree(Node *node){
if(!node) return;
deleteTree(node->left);
deleteTree(node->right);
cout<<node->data;
delete node;
}
};

int main(){
Tree tree;
char expression[50];
int choice;

do{
cout<<"1--->Enter Prefix Expression\n";
cout<<"2--->Display Postfix Expression\n";
cout<<"3--->Delete Tree\n";
cout<<"4--->Exit\n";
cout<<"5--->Choose An Option(1-4)";
cin>>choice;

switch(choice){
case 1:
cout<<"Enter Prefix expression(eg:- +--a*bc/def)";
cin>>expression;
tree.buildExpressionTree(expression);
break;
case 2:
if(tree.root){
tree.displayPostfix(tree.root);
cout<<endl;
}else{
cout<<"Tree Is empty\n";
}
break;
case 4:
cout<<"\n##End Of Code##\n";
break;
default:
cout<<"Choose Valid Option(1-4)\n";
}

}while(choice!=4);
return 0;

}