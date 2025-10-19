#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val, key;
	Node *prev, *next;
	Node(): val(0), key(0), prev(nullptr), next(nullptr) {};
	Node(int _val, int _key): val(_val), key(_key), prev(nullptr), next(nullptr) {};
};

class LRUCache {
	private:
		Node *head, *tail;
		unordered_map<int, Node *> mp;
		int size, capacity;
		void removeNode(Node *node) {
			node->next->prev = node->prev;
			node->prev->next = node->next;
		}

		void addNodeToHead(Node *node) {
			node->next = head->next;
			node->prev = head;
			head->next->prev = node;
			head->next = node;
		}

	public:

		LRUCache(int _capacity): capacity(_capacity), size(0) {
			head = new Node();
			tail = new Node();
			head->next = tail;
			tail->prev = head;
		}

		int get(int key) {
			if (mp.find(key) == mp.end()) {
				return -1;
			}
			Node *node = mp[key];
			removeNode(node);
			addNodeToHead(node);
			return node->val;
		}

		void put(int key, int value) {
			if (mp.count(key)) {
				Node *node = mp[key];
				node->val = value;  // 修复：更新value值
				removeNode(node);
				addNodeToHead(node);
			} else {
				// 容量已满，移除尾结点，并插入头部
				if (size == capacity) {
					// 移除尾节点
					Node *RemovedNode = tail->prev;
					removeNode(RemovedNode);
					// 移除哈希表的值
					mp.erase(RemovedNode->key);
					size--;
				}
				Node *node = new Node(value, key);
				addNodeToHead(node);
				mp[key] = node;
				size++;
			}
		}
};

int main(int argc, char **argv) {
	// 模拟示例输入
	LRUCache *lRUCache = new LRUCache(2);

	cout << "LRUCache(2)" << endl;

	lRUCache->put(1, 1);
	cout << "put(1, 1)" << endl;

	lRUCache->put(2, 2);
	cout << "put(2, 2)" << endl;

	int result1 = lRUCache->get(1);
	cout << "get(1) = " << result1 << " (expected: 1)" << endl;

	lRUCache->put(3, 3);
	cout << "put(3, 3)" << endl;

	int result2 = lRUCache->get(2);
	cout << "get(2) = " << result2 << " (expected: -1)" << endl;

	lRUCache->put(4, 4);
	cout << "put(4, 4)" << endl;

	int result3 = lRUCache->get(1);
	cout << "get(1) = " << result3 << " (expected: -1)" << endl;

	int result4 = lRUCache->get(3);
	cout << "get(3) = " << result4 << " (expected: 3)" << endl;

	int result5 = lRUCache->get(4);
	cout << "get(4) = " << result5 << " (expected: 4)" << endl;

	// 验证结果
	cout << "\n验证结果:" << endl;
	cout << "输出序列应为: [null, null, null, 1, null, -1, null, -1, 3, 4]" << endl;
	cout << "实际输出: [null, null, null, " << result1 << ", null, " << result2
	     << ", null, " << result3 << ", " << result4 << ", " << result5 << "]" << endl;

	delete lRUCache;
	return 0;
}

