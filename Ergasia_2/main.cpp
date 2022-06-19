#include<iostream>
#include<cstdlib>
#include<ctime>
#include<chrono>
#include<vector>
#include<sstream>
#include<fstream>

using namespace std;
using namespace std::chrono;

//Klash ylopoihshs komvou dyadikou dendrou
class Bnode{
public:
  int num;
  string string1;
  string string2;
  string string3;
	Bnode* left;
	Bnode* right;
  //gia na mporesoume na dhmiourgisoume ena array typou class Bnode
  //tha prepei na ftiaksoume enan dummy constructor
  Bnode(){}
  Bnode(int number,string s1,string s2,string s3){
    num=number;
    string1=s1;
    string2=s2;
    string3=s3;
  }
};

//Klash ylopoihshs komvo AVL dendrou
class AVLnode{
public:
  int num;
  string string1;
  string string2;
  string string3;
	AVLnode* left;
	AVLnode* right;
  int height;
  //gia na mporesoume na dhmiourgisoume ena array typou class AVLnode
  //tha prepei na ftiaksoume enan dummy constructor
  AVLnode(){}
  AVLnode(int number,string s1,string s2,string s3){
    num=number;
    string1=s1;
    string2=s2;
    string3=s3;
  }
};

//synarthseis gia ta dyadika dendra
Bnode* GetNewNodeB(int data);
Bnode* InsertB(Bnode* root,int data);
Bnode* SearchB(Bnode* root,int data);
void PostorderB(Bnode* node);
void PreorderB(Bnode* node);
void InorderB(Bnode* node);
//synarthseis gia ta AVL dendra
int max(int a,int b);
int height(AVLnode *N);
int getBalance(AVLnode *N);
AVLnode* GetNewNodeAVL(int data);
AVLnode* InsertAVL(AVLnode* root,int data);
AVLnode* SearchAVL(AVLnode* root,int data);
void PostorderAVL(AVLnode* node);
void PreorderAVL(AVLnode* node);
void InorderAVL(AVLnode* node);
AVLnode *rightRotate(AVLnode *y);
AVLnode *leftRotate(AVLnode *x);

int main(){
  fstream file;
  file.open("data.txt",ios::app);//anoigma arxeiou sto opoio tha katagrafoun oi xronoi

  //DYADIKA DENDRA
  Bnode Barray[100];
	//perasma tyxaiwn dedomenwn apo to arxeio rand_data.csv sto pinaka Barray
  fstream rand_data;
  rand_data.open("rand_data.csv",ios::in);
	vector<string>row;
	for(int i=0;i<100;i++){
		row.clear();
		//h katalhksh .clear() katharizei to vector
		string line,word;
		getline(rand_data,line);
		stringstream s(line);
		while (getline(s,word,','))
			row.push_back(word);
    //to vector apo8hkeyei string data,ara to row[0] pou periexei ton akeraio arithmo prepei na metatrapei apo string se int
    int a=stoi(row[0]);
		Barray[i]=Bnode(a,row[1],row[2],row[3]);
	}
  //Eisagwgh eggrafwn sto dyadiko dendro
  Bnode* stoixeio;
  auto start=high_resolution_clock::now();
  Bnode* root = NULL;  // Dhmiourgia adeiou dendrou
  for(int i=0;i<100;i++){
    root = InsertB(root,Barray[i].num);
    if (i==0)
      stoixeio=root;
  }
  auto stop=high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  file<<"Xronos eisagwghs eggrafwn sto Binary Search dendro: "<<duration.count()<<" microseconds."<<endl;

	cout<<"Menu Binary Search Tree"<<endl;
	cout<<"1. Search "<<endl;
	cout<<"2. Print Preorder  "<<endl;
	cout<<"3. Print Postorder "<<endl;
	cout<<"4. Print Inorder \n--------------"<<endl;
  int answer;//metavlhth pou tha apo8hkeysei thn epilogh toy xrhsth
  cin>>answer;
	if (answer==1){
		int numberS;
		cout<<"Eisagete ton arithmo anazhthshs: ";
		cin>>numberS;
    auto start=high_resolution_clock::now();
		Bnode* komvos=SearchB(root,numberS);
    auto stop=high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    if (komvos->num==-1){
      cout<<"O arithmos pou anazhthsate den yparxei.\n";
    }else{
      file<<"Xronos anazhths sto Binary Search dendro: "<<duration.count()<<" microseconds."<<endl;
      for(int i=0;i<100;i++){
      		if(Barray[i].num == numberS){
        		cout<<"Eggrafh: "<<endl;
            cout<<Barray[i].string1<<endl;
          	cout<<Barray[i].string2<<endl;
         		cout<<Barray[i].string3<<endl;
         	}
      	}
    }
	}else if(answer==2){
		PreorderB(stoixeio);
	}else if(answer==3){
		PostorderB(stoixeio);
	}else if(answer==4){
		InorderB(stoixeio);
	}

  //AVL DENDRA
  AVLnode AVLarray[100];
  //perasma tyxaiwn dedomenwn apo to arxeio rand_data.csv sto pinaka AVLarray
  fstream rand_data2;
  rand_data2.open("rand_data.csv",ios::in);
  vector<string>row2;
  for(int i=0;i<100;i++){
    row2.clear();
    //h katalhksh .clear() katharizei to vector
    string line2,word2;
    getline(rand_data2,line2);
    stringstream s2(line2);
    while (getline(s2,word2,','))
      row2.push_back(word2);
    //to vector apo8hkeyei string data,ara to row2[0] pou periexei ton akeraio arithmo prepei na metatrapei apo string se int
    int a2=stoi(row2[0]);
    AVLarray[i]=AVLnode(a2,row2[1],row2[2],row2[3]);
  }
  //Eisagwgh eggrafwn sto dyadiko dendro
  AVLnode* riza2;
  auto start2=high_resolution_clock::now();
  AVLnode* AVLroot = NULL;  // Dhmiourgia adeiou dendrou
  for(int i=0;i<100;i++){
    AVLroot = InsertAVL(AVLroot,AVLarray[i].num);
    if (i==0)
      riza2=AVLroot;
  }
  auto stop2=high_resolution_clock::now();
  auto duration2 = duration_cast<microseconds>(stop - start);
  file<<"Xronos eisagwghs eggrafwn sto AVL dendro: "<<duration2.count()<<" microseconds."<<endl;

	cout<<"\nMenu AVL Tree"<<endl;
	cout<<"1. Search "<<endl;
	cout<<"2. Print Preorder  "<<endl;
	cout<<"3. Print Postorder "<<endl;
	cout<<"4. Print Inorder \n--------------"<<endl;
  int answer2;//metavlhth pou tha apo8hkeysei thn epilogh toy xrhsth
  cin>>answer2;
	if (answer2==1){
		int numberS;
		cout<<"Eisagete ton arithmo anazhthshs: ";
		cin>>numberS;
    auto start2=high_resolution_clock::now();
		AVLnode* komvos=SearchAVL(AVLroot,numberS);
    auto stop2=high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    if (komvos->num==-1){
      cout<<"O arithmos pou anazhthsate den yparxei.\n";
    }else{
      file<<"Xronos anazhths se AVL dendro: "<<duration2.count()      <<" microseconds."<<endl;
      for(int i=0;i<100;i++){
      		if(AVLarray[i].num == numberS){
        		cout<<"Eggrafh: "<<endl;
            cout<<AVLarray[i].string1<<endl;
          	cout<<AVLarray[i].string2<<endl;
         		cout<<AVLarray[i].string3<<endl;
         	}
      	}
    }
	}else if(answer2==2){
		PreorderAVL(riza2);
	}else if(answer2==3){
		PostorderAVL(riza2);
	}else if(answer2==4){
		InorderAVL(riza2);
	}else{
    cout<<" "<<endl;
  }

	return 0;
}

Bnode* GetNewNodeB(int data) {
	Bnode* newNode = new Bnode();
	newNode->num = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

//Eisagwgh eggrafhs sto dyadiko dendro
Bnode* InsertB(Bnode* root,int data) {
	if(root == NULL) {
		root = GetNewNodeB(data);
	}
	//an to num ths eggrafhs einai mikrotero,tote ginetai eisasgwgh ths eggrafhs sto aristero ypodendro
	else if(data <= root->num) {
		root->left = InsertB(root->left,data);
	}
	//diaforetika,eisagwgh sto deksi ypodendro
	else {
		root->right = InsertB(root->right,data);
	}
	return root;
}

//Anazhthsh eggrafhs,epistrefei True an h eggrafh yparxei sto dyadiko dendro
Bnode* SearchB(Bnode* root,int data) {
	if(root == NULL) {
		root->num=-1;
    return root;
	}
	else if(root->num == data) {
		return root;
	}
	else if(data <= root->num) {
		return SearchB(root->left,data);
	}
	else {
		return SearchB(root->right,data);
	}
}

//Postorder diasxish dendrou
void PostorderB(Bnode* node){
    if (node == NULL)
        return;
    // first recur on left subtree
    PostorderB(node->left);
    // then recur on right subtree
    PostorderB(node->right);
    // now deal with the node
    printf("%d ", node->num);
}

//Preorder diasxish dendrou
void PreorderB(Bnode* node){
    if (node == NULL)
        return;
    printf("%d ", node->num);

    PreorderB(node->left);

    PreorderB(node->right);
}

//Inorder diasxish dendrou
void InorderB( Bnode* node){
    if (node == NULL)
        return;

    InorderB(node->left);

    printf("%d ", node->num);

    InorderB(node->right);
}

//----------------------------------------

int max(int a, int b){
	return (a > b)? a : b;
}

int height(AVLnode *N){
	if (N == NULL)
		return 0;
	return N->height;
}

int getBalance(AVLnode *N){
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}


AVLnode* GetNewNodeAVL(int data){
  AVLnode* newNode = new AVLnode();
  newNode->num = data;
  newNode->left = newNode->right = NULL;
  newNode->height = 1; // new node is initially added at leaf
  return newNode;
}

//Eisagwgh eggrafhs sto AVL dendro
AVLnode* InsertAVL(AVLnode* node, int data){
	if (node == NULL)
		return(GetNewNodeAVL(data));

	if (data < node->num)
		node->left = InsertAVL(node->left, data);
	else if (data > node->num)
		node->right = InsertAVL(node->right, data);
	else
		return node;

		node->height = 1 + max(height(node->left),
						height(node->right));

	int balance = getBalance(node);

  if (balance > 1 && data < node->left->num)
  		return rightRotate(node);

	if (balance < -1 && data > node->right->num)
		return leftRotate(node);

	if (balance > 1 && data > node->left->num)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && data < node->right->num)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

//Anazhthsh eggrafhs,epistrefei True an h eggrafh yparxei sto AVL dendro
AVLnode* SearchAVL(AVLnode* root,int data) {
	if(root == NULL) {
		root->num=-1;
    return root;
	}
	else if(root->num == data) {
		return root;
	}
	else if(data <= root->num) {
		return SearchAVL(root->left,data);
	}
	else {
		return SearchAVL(root->right,data);
	}
}

//Postorder diasxish dendrou
void PostorderAVL(AVLnode* node){
    if (node == NULL)
        return;

    PostorderAVL(node->left);

    PostorderAVL(node->right);

    printf("%d ", node->num);
}

//Preorder diasxish dendrou
void PreorderAVL(AVLnode* node){
    if (node == NULL)
        return;
    printf("%d ", node->num);

    PreorderAVL(node->left);

    PreorderAVL(node->right);
}

//Inorder diasxish dendrou
void InorderAVL( AVLnode* node){
    if (node == NULL)
        return;

    InorderAVL(node->left);

    printf("%d ", node->num);

    InorderAVL(node->right);
}

AVLnode *rightRotate(AVLnode *y){
	AVLnode *x = y->left;
	AVLnode *T2 = x->right;

	// Rotation
	x->right = y;
	y->left = T2;

	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	return x;
}

AVLnode *leftRotate(AVLnode *x)
{
	AVLnode *y = x->right;
	AVLnode *T2 = y->left;

	// Rotation
	y->left = x;
	x->right = T2;

	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	return y;
}

