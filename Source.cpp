#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int i;
	Node* pLeft;
	Node* pRight;

	Node(int iIn) : i(iIn), pLeft(nullptr), pRight(nullptr) {}
};

bool GetBranch(Node* rootNode, Node* targetNode, vector<int>& largestBranch) {
	if (rootNode == nullptr || targetNode == nullptr)
		return false;
	largestBranch.push_back(rootNode->i);
	if (rootNode == targetNode || GetBranch(rootNode->pLeft, targetNode, largestBranch) || GetBranch(rootNode->pRight, targetNode, largestBranch))
		return true;
	largestBranch.pop_back();
	return false;
}


void LargestSumBranch(Node* rootNode, Node** targetNode, int currentSum, int& largestSum)
{
	if (rootNode == nullptr)
		return;
	currentSum = currentSum + rootNode->i;
	if (rootNode->pLeft == nullptr && rootNode->pRight == nullptr) {
		if (currentSum > largestSum) {
			largestSum = currentSum;
			*targetNode = rootNode;
		}
	}
	LargestSumBranch(rootNode->pLeft, targetNode, currentSum, largestSum);
	LargestSumBranch(rootNode->pRight, targetNode, currentSum, largestSum);
}

void PrintBranchWithLargestSum(Node* rootNode, Node* targetNode, vector<int>& largestBranch, int largestSum) {
	LargestSumBranch(rootNode, &targetNode, 0, largestSum);
	GetBranch(rootNode, targetNode, largestBranch);
	cout << "Branch with the largest sum is: ";
	for (auto i : largestBranch)
		cout << i << " ";
	cout << "-> SUM = " << largestSum;
}

void main()
{
	Node* pRoot = nullptr;
	pRoot = new Node(5);
	pRoot->pLeft = new Node(4);
	pRoot->pLeft->pLeft = new Node(11);
	pRoot->pLeft->pLeft->pLeft = new Node(7);
	pRoot->pLeft->pLeft->pRight = new Node(2);
	pRoot->pRight = new Node(8);
	pRoot->pRight->pLeft = new Node(13);
	pRoot->pRight->pRight = new Node(4);
	pRoot->pRight->pRight->pRight = new Node(1);
	Node* targetNode = nullptr;
	int largestSum = 0;
	vector<int> largestBranch;
	PrintBranchWithLargestSum(pRoot, targetNode, largestBranch, largestSum);
}