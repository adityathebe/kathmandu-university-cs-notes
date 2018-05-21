class BST {
	private:
		struct node {
			int key;
			node *left;
			node *right;
		}*root;

		void addLeafPvt(int key, node *ptr);
		void displayPvt(node *ptr);
		node *ReturnNodePvt(int key, node *ptr);
	public:
		BST();
		node* createLeaf(int key);
		void addLeaf(int key);
		void display();
		node *ReturnNode(int key);
};