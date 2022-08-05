#include"BSTree.h"
#include"AccountsRecords.h"

int main() {
	AccountsRecords ar1("Sameet", "Asadullah", 100, 1, 10);
	AccountsRecords ar2("Tayyab", "Ali", 100, 1, 3);
	AccountsRecords ar3("Syed", "Hamza", 100, 1, 4);
	BSTree<AccountsRecords> t1;
	t1.insert(ar1);
	t1.insert(ar2);
	t1.insert(ar3);
	cout << "========== Post Order Display ===========" << endl << endl;
	t1.postOrderDisplay(t1.getRoot());
	cout << endl << "========== In Order Display ===========" << endl << endl;
	t1.inOrderDisplay(t1.getRoot());
	cout << "Is Tree a Full Binary Tree: " << t1.FullBinaryTree(t1.getRoot()) << endl;
}