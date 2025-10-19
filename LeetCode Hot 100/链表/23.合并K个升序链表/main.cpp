#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(nullptr) {}; // 初始化next为nullptr
};

ListNode *creatList(vector<int> &a) {
	ListNode *root = new ListNode(a[0]);
	ListNode *cur = root;
	for (int i = 1; i < a.size(); i++) {
		cur->next = new ListNode(a[i]);
		cur = cur->next;
	}
	return root;
}

struct compare {
	bool operator()(ListNode *a, ListNode *b) {
		return a->val > b->val;
	}
};

ListNode *mergeKLists(vector<ListNode *> &lists) {
	priority_queue<ListNode *, vector<ListNode *>, compare> pq;
	for (ListNode *list : lists) {
		if (list != nullptr) {
			cout << list->val << " ";
			pq.push(list);
		}
	}
	ListNode *dummy = new ListNode(0);  // 创建堆上的dummy节点
	ListNode *cur = dummy;
	while (!pq.empty()) {
		ListNode *MinNode = pq.top();
		pq.pop();
		cur->next = MinNode;
		cur = cur->next;
		if (MinNode->next != nullptr) {
			pq.push(MinNode->next);
		}
	}
	return dummy->next;
}

void display(ListNode *list) {
	ListNode *cur = list;
	while (cur != nullptr) {
		cout << cur->val << " ";
		cur = cur->next;
	}
}

int main() {
	vector<int> a = {1, 4, 5};
	vector<int> b = {1, 3, 4};
	vector<int> c = {2, 6};
	vector<ListNode *> lists;
	lists.push_back(creatList(a));
	lists.push_back(creatList(b));
	lists.push_back(creatList(c));

	ListNode *mergelist = mergeKLists(lists);

	display(mergelist);

	return 0;
}