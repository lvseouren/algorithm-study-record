#include "ListPrinter.h"
#include <iostream>
using namespace std;
ListPrinter::ListPrinter() {}

void ListPrinter::print(ListNode* head)
{
	while (head)
	{
		cout << head->val << ",";
		head = head->next;
	}
	cout << endl;
}