#pragma once
#include "Solution_findRepeatNumber.h"
#include "Solution_subsets.h"
#include "Solution_maxDepth.h"
#include "Solution_validateBinarySearchTree.h"
#include "Solution_insertIntoBST.h"
#include "Solution_reverseList.h"
#include "Solution_reverseBetween.h"
#include "Solution_mergeTwoList.h"
#include "BSTPrinter.h"
#include "Solution_solveNQueens.h"
#include "Solution_findAllTreePath.h"
#include "Solution_maxPathSum.h"
#include "Solution_longestValidParentheses.h"
#include "Solution_findCommonAncestor.h"
#include "Solution_partition.h"
#include "Solution_sortList.h"
#include "Solution_reorderList.h"
#include "Solution_hasCycle.h"
#include "Solution_detectCycle.h"
#include "Solution_isPalindrome.h"
#include "Solution_evenReorderMerge.h"
#include "Solution_copyRandomList.h"
#include "MinStack.h"
#include "Solution_evalRPN.h"
#include "Solution_decodeString.h"
#include "Solution_inorderTraversal.h"
#include "Solution_cloneGraph.h"
#include "Solution_numIslands.h"
#include "Solution_largestRectangleArea.h"
#include "Solution_dailyTemperatures.h"
#include "Solution_maximalRectangle.h"
#include "Solution_maximalSquare.h"
#include "MyQueue.h"
#include "Solution_updateMatrix.h"
#include "Solution_singleNumber.h"
#include "Solution_hammingWeight.h"
#include "Solution_countBits.h"
#include "Solution_reverseBits.h"
#include "Solution_rangeBitwiseAnd.h"
#include "Solution_search.h"
#include "Solution_findMedianSortedArrays.h"
#include "Solution_mySqrt.h"
#include "Solution_guessNumber.h"
#include "Solution_firstBadVersion.h"
#include "Solution_findPeakElement.h"
#include "Solution_findMin.h"
#include "Solution_searchRange.h"
#include "Solution_findClosestElements.h"
#include "Solution_findDuplicate.h"
#include "Solution_smallestDistancePair.h"
#include "Solution_splitArray.h"
#include "Solution_sortArray.h"
#include "Solution_minimumTotal.h"
#include "Solution_canJump.h"
#include "Solution_jump.h"
#include "Solution_minCut.h"
#include "Solution_longestOfLIS.h"
#include "Solution_wordBreak.h"
#include "Solution_longestCommonSubSeq.h"
#include "Solution_bestSoluToReachSpecValue.h"
#include "Solution_sumNumbers.h"
#include "Solution_minWindow.h"
#include "Solution_validMountainArray.h"
#include "Solution_insert.h"
#include "Solution_dachuijiaodui.h"
#include "Solution_ladderLength.h"
#include "Solution_countRangeSum.h"
#include "Solution_getMaximumGenerated.h"
#include "Solution_minDeletions.h"
#include "Solution_maxProfit.h"
#include "Solution_smallestRange.h"
#include "Solution_checkInclusion.h"
#include "Solution_findAnagrams.h"
#include "Solution_genHuffmanCode.h"
#include "Solution_myHashMap.h"
#include "Solution_Answerofjudge.h"
#include "Solution_solve.h"
#include "Solution_permute.h"
#include "Solution_interpret.h"
#include "Solution_maxOperation.h"
#include "Solution_concatenatedBinary.h"
#include "Solution_minimumIncompatibility.h"
#include "Solution_longestConsecutive.h"
#include "Solution_calculateInsurance.h"
#include "Solution_subsets2.h"
#include "Solution_subsetsWithDup.h"
#include "Solution_permuteUnique.h"
#include "Solution_isToeplitzMatrix.h"
//#include "astar.h"
#include "Solution_medianSlidingWindow.h"
#include "Solution_Leyi_Atoi.h"
#include "Solution_decodeMessage.h"
#include "Solution_spiralMatrix.h"

class solution
{
public:
	void RunTest()
	{
		//findRepeatNumber();
		//subsets();
		//maxDepth();
		//isValidBST();
		//insertBST();
		//reverseList();
		//reverserBetween();
		//mergeTwoList();
		//solveNQueens();
		//findAllTreePath();
		//maxPathSum();
		//longestValidParentheses();
		//lowestCommonAncestor();
		//partition();
		//sortList();
		//reorderList();
		//hasCycle();
		//detectCycle();
		//isPalindrome();
		//copyRandomList();
		//minStackTest();
		//evalRPN();
		//decodeString();
		//inorderTravelsal();
		//cloneGraph();
		//numIslands();
		//largestRectangleArea();
		//dailyTemperatures();
		//maximalRectangle();
		//maximalSquare();
		//myQueueRunTest();
		//updateMatrix();
		//singleNumber();
		//hammingWeight();
		//countBits();
		//reverseBits();
		//rangeBitwiseAnd();
		//search();
		//findMedianSortedArray();
		//mySqrt();
		//guessNumber();
		//firstBadVersion();
		//findPeakElement();
		//findMin();
		//searchRange();
		//findClosestElements();
		//findDuplicate();
		//smallestDistancePair();
		//splitArray();
		//sortArray();
		//minimumTotal();
		//canJump();
		//jump();
		//minCut();
		//lengthOfLIS();
		//wordBreak();
		//longestCommonSubSequence();
		//bestSoluToReachSpecValue();
		//sumNumbers();
		//minWindow();
		//validMountainArray();
		//insert();
		//dachuijiaodui();
		//ladderLength();
		//countRangeSum();
		//getMaximumGenerated();
		//minDeletions();
		//maxProfit();
		//smallestRange();
		//checkInclusion();
		//findAnagrams();
		//generateHuffmanCode();
		//myHashMap();
		//Answerofjudge();
		//nowcoder_solve();
		//permute();
		//interpret();
		//maxOperations();
		//concatenatedBinary();
		//minimumIncompatibility();
		//longestConsecutive();
		//subsetsWithDup();
		//permuteUnique();
		//isToeplitzMatrix();
		//astarPathFinding();
		//medianSlidingWidnow();
		//leyiAtoi();
		//decodeMessage();
		spiralMatrix();
	}

	void spiralMatrix()
	{
		Solution_spiralMatrix s;
		s.RunTest();
	}

	void decodeMessage()
	{
		Solution_decodeMessage s;
		s.RunTest();
	}

	void leyiAtoi()
	{
		Solution_Leyi_Atoi s;
		s.RunTest();
	}

	void medianSlidingWidnow()
	{
		Solution_medianSlidingWindow s;
		s.RunTest();
	}

	void isToeplitzMatrix()
	{
		Solution_isToeplitzMatrix s;
		s.RunTest();
	}

	//void astarPathFinding()
	//{
	//	Solution_astar s;
	//	s.RunTest();
	//}

	void permuteUnique()
	{
		Solution_permuteUnique s;
		s.RunTest();
	}

	void subsetsWithDup()
	{
		Solution_subsetsWithDup s;
		s.RunTest();
	}

	void longestConsecutive()
	{
		Solution_longestConsecutive s;
		s.RunTest();
	}

	void minimumIncompatibility()
	{
		Solution_minimumIncompatibility s;
		s.RunTest();
	}

	void concatenatedBinary()
	{
		Solution_concatenatedBinary s;
		s.RunTest();
	}

	void maxOperations()
	{
		Solution_maxOperation s;
		s.RunTest();
	}

	void interpret()
	{
		Solution_interpret s;
		//calculateInsurance();
		subsets2();
	}

	void subsets2()
	{
		Solution_subsets2 s;
		s.RunTest();
	}

	void calculateInsurance()
	{
		Solution_calculateInsurance s;
		s.RunTest();
	}

	void permute()
	{
		Solution_permute s;
		s.RunTest();
	}

	void nowcoder_solve()
	{
		Solution_solve s;
		s.RunTest();
	}

	void Answerofjudge()
	{
		Solution_Answerofjudge s;
		s.RunTest();
	}

	void myHashMap()
	{
		Solution_myHashMap s;
		s.RunTest();
	}

	void generateHuffmanCode()
	{
		Solution_genHuffmanCode s;
		s.RunTest();
	}

	void findAnagrams()
	{
		Solution_findAnagrams s;
		s.RunTest();
	}

	void checkInclusion()
	{
		Solution_checkInclusion s;
		s.RunTest();
	}

	void smallestRange()
	{
		Solution_smallestRange s;
		s.RunTest();
	}

	void maxProfit()
	{
		Solution_maxProfit s;
		s.RunTest();
	}

	void minDeletions()
	{
		Solution_minDeletions s;
		s.RunTest();
	}

	void getMaximumGenerated()
	{
		Solution_getMaximumGenerated s;
		s.RunTest();
	}

	void countRangeSum()
	{
		Solution_countRangeSum s;
		s.RunTest();
	}

	void ladderLength()
	{
		Solution_ladderLength s;
		s.RunTest();
	}

	void dachuijiaodui()
	{
		Solution_dachuijiaodui s;
		s.RunTest();
	}

	void insert()
	{
		Solution_insert s;
		s.RunTest();
	}

	void validMountainArray()
	{
		Solution_validMountainArray s;
		s.RunTest();
	}

	void minWindow()
	{
		Solution_minWindow s;
		s.RunTest();
	}

	void sumNumbers()
	{
		Solution_sumNumbers s;
		s.RunTest();
	}

	void bestSoluToReachSpecValue()
	{
		Solution_bestSoluToReachSpecValue s;
		s.RunTest();
	}

	void longestCommonSubSequence()
	{
		Solution_longestCommonSubSeq s;
		s.RunTest();
	}

	void wordBreak()
	{
		Solution_wordBreak s;
		s.RunTest();
	}

	void lengthOfLIS()
	{
		Solution_lengthOfLIS s;
		s.RunTest();
	}

	void minCut()
	{
		Solution_minCut s;
		s.RunTest();
	}

	void jump()
	{
		Solution_jump s;
		s.RunTest();
	}

	void canJump()
	{
		Solution_canJump s;
		s.RunTest();
	}

	void minimumTotal()
	{
		Solution_minimumtotal s;
		s.RunTest();
	}

	void sortArray()
	{
		Solution_sortArray s;
		s.RunTest();
	}

	void splitArray()
	{
		Solution_splitArray s;
		s.RunTest();
	}

	void smallestDistancePair()
	{
		Solution_smallestDistancePair s;
		s.RunTest();
	}

	void findDuplicate()
	{
		Solution_findDuplicate s;
		s.RunTest();
	}

	void findClosestElements()
	{
		Solution_findClosestElements s;
		s.RunTest();
	}

	void searchRange()
	{
		Solution_searchRange s;
		s.RunTest();
	}

	void findMin()
	{
		Solution_findMin s;
		s.RunTest();
	}

	void findPeakElement()
	{
		Solution_findPeakElement s;
		s.RunTest();
	}

	void firstBadVersion()
	{
		Solution_firstBadVersion s;
		s.RunTest();
	}

	void guessNumber()
	{
		Solution_guessNumber s;
		s.RunTest();
	}

	void mySqrt()
	{
		Solution_mySqrt s;
		s.RunTest();
	}

	void findMedianSortedArray()
	{
		Solution_findMedianSortedArrays s;
		s.RunTest();
	}

	void search()
	{
		Solution_search s;
		s.RunTest();
	}

	void rangeBitwiseAnd()
	{
		Solution_rangeBitwiseAnd s;
		s.RunTest();
	}

	void reverseBits()
	{
		Solution_reverseBits s;
		s.RunTest();
	}

	void countBits()
	{
		Solution_countBits s;
		s.RunTest();
	}

	void hammingWeight()
	{
		Solution_hammingWeight s;
		s.RunTest();
	}

	void singleNumber()
	{
		Solution_singleNumer s;
		s.RunTest();
	}

	void updateMatrix()
	{
		Solution_updateMatrix s;
		s.RunTest();
	}

	void myQueueRunTest()
	{
		int input = 3;
		cout << "push:" << input << endl;
		MyQueue* obj = new MyQueue();
		obj->push(input);
		obj->push(4);
		obj->push(5);
		obj->push(6);
		int param_2 = obj->pop();
		cout << param_2 << endl;
		int param_3 = obj->pop();
		cout << param_3 << endl;
		bool param_4 = obj->empty();
		if (param_4)
			cout << "����Ϊ��" << endl;
		else
			cout << "���в�Ϊ��" << endl;
		param_2 = obj->pop();
		cout << param_2 << endl;
		param_2 = obj->pop();
		cout << param_2 << endl;
	}

	void PrintBST_preOrder(TreeNode* root)
	{
		if (root == NULL)
			return;
		cout << root->val << ",";
		PrintBST_preOrder(root->left);
		PrintBST_preOrder(root->right);
	}

	void findRepeatNumber()
	{
		std::vector<int> nums = { 3,1,2,3 };
		std::map<int, bool> table;
		Solution_findRepeatNumber s;
		s.findRepeatNumber(nums);
	}

	void subsets()
	{
		vector<int> nums = { 1,2,3 };
		Solution_subsets s;
		s.subsets(nums);
		//s.subsets_backtrack(nums);
	}

	void maxDepth()
	{
		Solution_maxDepth s;
		TreeNode root(3);
		root.left = new TreeNode(9);
		root.right = new TreeNode(20);
		root.right->left = new TreeNode(15);
		root.right->right = new TreeNode(7);
		int ret = s.maxDepth_iterate_bfs(&root);
		cout << "������Ϊ��" << ret << endl;
	}

	void isValidBST()
	{
		TreeNode root(4);
		root.left = new TreeNode(3);
		root.right = new TreeNode(15);
		root.right->left = new TreeNode(9);
		root.right->right = new TreeNode(20);
		Solution_validateBinarySearchTree s;
		bool ret = s.isValidBST(&root);
		if (ret)
			//cout << "����Ч�Ķ��������" << endl;
			cout << endl;
		else
			cout << endl;
			//cout << "������Ч�Ķ��������" << endl;
	}

	void insertBST()
	{
		Solution_insertIntoBST s;
		s.RunTest();
	}

	void reverseList()
	{
		Solution_reverseList s;
		s.RunTest();
	}

	void reverserBetween()
	{
		//ListNode* head = new ListNode({3,5});
		//PrintList(head);
		//Solution_reverseBetween s;
		//head = s.reverseBetween(head, 1, 2);
		//PrintList(head);
		Solution_reverseBetween s;
		s.RunTest();
	}

	void mergeTwoList()
	{
		Solution_mergeTwoList s;
		s.RunTest();
	}

	void solveNQueens()
	{
		Solution_solveNQueens s;
		s.RunTest();
	}

	void findAllTreePath()
	{
		Solution_findAllTreePath s;
		s.RunTest();
	}

	void maxPathSum()
	{
		Solution_maxPathSum s;
		s.RunTest();
	}

	void longestValidParentheses()
	{
		Solution_longestValidParentheses s;
		s.RunTest();
	}

	void lowestCommonAncestor()
	{
		Solution_findCommonAncestor s;
		s.RunTest();
	}

	void partition()
	{
		Solution_partition s;
		s.RunTest();
	}

	void sortList()
	{
		Solution_sortList s;
		s.RunTest();
	}

	void reorderList()
	{
		Solution_reorderList s;
		s.RunTest();
	}

	void hasCycle()
	{
		Solution_hasCycle s;
		s.RunTest();
	}

	void detectCycle()
	{
		Solution_detectCycle s;
		s.RunTest();
	}

	void isPalindrome()
	{
		Solution_isPalindrome s;
		s.RunTest();
	}

	void evenReorderMerge()
	{
		Solution_evenReorderMerge s;
		s.RunTest();
	}

	void copyRandomList()
	{
		Solution_copyRandomList s;
		s.RunTest();
	}

	void minStackTest()
	{
		MinStack minStack;
		minStack.push(2);
		minStack.push(0);
		minStack.push(3);
		minStack.push(0);
		int min1 = minStack.getMin();
		minStack.pop();
		int min2 = minStack.getMin();
		minStack.pop();
		int min3 = minStack.getMin();
		minStack.pop();
		int min4 = minStack.getMin();
		cout << min1 << endl << min2 << endl << min3 << endl << min4 << endl;
	}

	void evalRPN()
	{
		vector<string> input = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
		Solution_evalRPN s;
		cout << s.evalRPN(input) << endl;
	}

	void decodeString()
	{
		Solution_decodeString s;
		s.RunTest();
	}

	void inorderTravelsal()
	{
		Solution_inorderTraversal s;
		s.RunTest();
	}

	void cloneGraph()
	{
		Solution_cloneGraph s;
		s.RunTest();
	}

	void numIslands()
	{
		Solution_numIslands s;
		s.RunTest();
	}

	void largestRectangleArea()
	{
		Solution_largestRectangleArea s;
		s.RunTest();
	}

	void dailyTemperatures()
	{
		Solution_dailyTemperatures s;
		s.RunTest();
	}

	void maximalRectangle()
	{
		Solution_maximalRectangle s;
		s.RunTest();
	}

	void maximalSquare()
	{
		Solution_maximalSquare s;
		s.RunTest();
	}
};
