/*
* 
* Data Structures Compendium and Functions Encyclopedia
* Created By Taib Izzat Samawi
* For ITS' Spring 2023 Data Structures Course
*/

/**
 * IF ITS Data Structures
 * Final Lab Work
 * Data Structures Compendium and Functions Encyclopedia
 *
 * Oportunitas (Taib Izzat Samawi)
 *
 * via GNU C++ 20 11.2.0 (64bit, winlibs)
 * Created		: 2022
 * Remastered	: 2023
**/


#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define lli int64_t
#define llu uint64_t
#define li int32_t
#define lu uint32_t
#define si int16_t
#define su uint16_t
#define str string
#define flt float
#define dbl double
#define umap unordered_map
#define uset unordered_set
#define sp shared_ptr
#define ms make_shared
using namespace std;

// find the maximum value between two int64
lli getLliMax(lli& in_1, lli& in_2) {
	return (in_1 > in_2) ? in_1 : in_2;
}

// find the minimum value between two int64
lli getLliMin(lli& in_1, lli& in_2) {
	return (in_1 < in_2) ? in_1 : in_2;
}

// single linked list, linked to front/node after
class Slf {
public:
	lli val = NULL;
	Slf* after = NULL;
};

// single linked list, linked to back/node before
class Slb {
public:
	Slb* before = NULL;
	lli val = NULL;
};

// doubly linked list
class Dl {
public:
	Dl* before = NULL;
	lli val = NULL;
	Dl* after = NULL;
};

// binary tree node, parent->node[idx, key, value]->(left || right)
class BinaryTreeNode {
public:
	lli index = NULL;
	lli key = NULL;
	dbl value = NULL;
	lli height = 1; //used for AVL Trees
	lli depth = 0;	//used for knowing levels

	sp<BinaryTreeNode> parent = nullptr;
	sp<BinaryTreeNode> left = nullptr;
	sp<BinaryTreeNode> right = nullptr;
};

//binary tree
class BinaryTree {
public:
	sp<BinaryTreeNode> root = ms<BinaryTreeNode>();
	sp<BinaryTreeNode> last = ms<BinaryTreeNode>();

	// insert a node into a binary tree
	void branch(lli leafNum, dbl leafValue = 0, lli leafIndex = 1)
	{
		sp<BinaryTreeNode> node = root;
		if (node->key == NULL)
		{
			node->key = leafNum;
			node->index = leafIndex;
			node->value = leafValue;
			last = node;
			return;
		}

		tree_node* parent = node;
		while (node_exists(node))
		{
			parent = node;
			if (leafNum == node->key)
			{
				if (leafValue == node->value) return;
				else if (leafValue > node->value) node = node->right;
				else if (leafValue < node->value) node = node->left;
			}
			else if (leafNum > node->key) node = node->right;
			else if (leafNum < node->key) node = node->left;
		}

		tree_node* cache = new tree_node;
		cache->parent = parent;
		cache->depth = parent->depth + 1;
		cache->key = leafNum;
		cache->value = leafValue;
		cache->index = leafIndex;

		if (leafNum == parent->key)
		{
			if (leafValue == parent->value) return;
			else if (leafValue > parent->value) parent->right = cache;
			else if (leafValue < parent->value) parent->left = cache;
		}
		else if (leafNum > parent->key) parent->right = cache;
		else if (leafNum < parent->key) parent->left = cache;
		if (maxDepth < cache->depth) maxDepth = cache->depth;

		last = cache;
	}

	void pluck(lli findKey)
	{
		auto pathToTheDeletedNode = xfind(findKey);
		if (pathToTheDeletedNode.size() == 0) return;

		//cout << "doing pluck\n";

		tree_node* toBeDeleted = xfind(findKey).back();
		str positionToParent = "";
		if (toBeDeleted == toBeDeleted->parent->left) positionToParent = "left";
		if (toBeDeleted == toBeDeleted->parent->right) positionToParent = "right";

		if ((!node_exists(toBeDeleted->right)) && (!node_exists(toBeDeleted->left)))
		{
			if (positionToParent == "left") toBeDeleted->parent->left = NULL;
			if (positionToParent == "right") toBeDeleted->parent->right = NULL;
		}
		else if (node_exists(toBeDeleted->right) != node_exists(toBeDeleted->left))
		{
			if (node_exists(toBeDeleted->right))
			{
				if (positionToParent == "left") toBeDeleted->parent->left = toBeDeleted->right;
				if (positionToParent == "right") toBeDeleted->parent->right = toBeDeleted->right;
			}
			if (node_exists(toBeDeleted->left))
			{
				if (positionToParent == "left") toBeDeleted->parent->left = toBeDeleted->left;
				if (positionToParent == "right") toBeDeleted->parent->right = toBeDeleted->left;
			}
		}
		else if ((node_exists(toBeDeleted->right)) && (node_exists(toBeDeleted->left)))
		{
			tree_node* toBeShiftedUp = __find_leftest_node(toBeDeleted->right);
			toBeDeleted->key = toBeShiftedUp->key;
			toBeDeleted->value = toBeShiftedUp->value;
			toBeDeleted->index = toBeShiftedUp->index;
			pluck(toBeShiftedUp->key);
		}
	}

	//The most Sophisticated form of Find(), can determine LCA by nature
	deque<tree_node*> xfind(lli findKey)
	{
		tree_node* curNode = root;
		deque<tree_node*>* result = new deque<tree_node*>;

		__xfind(curNode, findKey, result);
		return *result;
	}


	void balance()
	{
		tree_node* node = last;
		while ((node_exists(node->parent)) && (abs(find_tilt(node)) <= 1))
		{
			//cout << "checking node: " << node->key << "; height: " << node->height << endl;
			node->parent->height = node->height + 1;
			node = node->parent;
		}

		//if (node_exists(node->left)) cout << "left : " << node->left->key << ", height: " << node->left->height << endl;
		//if (node_exists(node->right)) cout << "right : " << node->right->key << ", height: " << node->right->height << endl;

		lli tilt = find_tilt(node);
		//cout << "finalnode: " << node->key << "; found tilt of " << tilt << endl;
		if (tilt > 1)
		{
			if (last->key < node->right->key)
			{
				//cout << "entered condition" << endl;
				rotate_right(node->right);
			}
			rotate_left(node);
		}
		else if (tilt < -1)
		{
			//cout << "last: " << last->key << "; left: " << node->left->key << endl;
			if (last->key > node->left->key)
			{
				//cout << "entered rleft first" << endl;
				rotate_left(node->left);
			}
			rotate_right(node);
		}
	}

	bool node_exists(tree_node* node)
	{
		if (node == NULL) return false;
		else if (node->key == NULL) return false;
		else return true;
	}

	//DEPRECATED
	tree_node* find(lli findKey, dbl findValue = NULL)
	{
		tree_node* node = root;
		//cout << "find: [" << findKey << "," << findValue << "]" << endl;

		tree_node* res = new tree_node;
		find_node(node, findKey, findValue, res);
		//cout << "found res: [" << res->key << "," << res->value << "] " << endl;
		/*
		if (node_exists(res->parent)) cout << "p: [" << res->parent->key << "," << res->parent->value << "]" << endl;
		if (node_exists(res->right)) cout << "r: [" << res->right->key << "," << res->right->value << "]" << endl;
		if (node_exists(res->left)) cout << "l: [" << res->left->key << "," << res->left->value << "]" << endl << endl;
		*/
		return res;
	}

	//tree_node* basic_find(lli findKey)
	//{
	//	tree_node* cur = root;
	//	tree_node* res = new tree_node;
	//	__basic_find(cur, findKey, res);
	//	cout << res->key << " found, returning\n";
	//	return res;
	//}

	//---Descents (Searching for Path from one node to another)---//
	deque<lli> least_distance_descent(lli fromKey, lli toKey)
	{
		cout << "finding keys\n";
		tree_node* fromNode = find(fromKey);
		tree_node* toNode = find(toKey);
		cout << "keys found\n";
		cout << fromNode->key << "|" << toNode->key << endl;

		tree_node_slb* first = new tree_node_slb;
		*first = { NULL, fromNode };

		deque<tree_node_slb*> nodeQ;
		nodeQ.push_back(first);
		unordered_set<lli> visited;
		visited.insert(nodeQ.front()->cur->key);

		//cout << "entring while\n";
		while (nodeQ.size() > 0)
		{
			for (auto kt : nodeQ)
			{
				cout << kt->cur->key << " ";
			}
			cout << "\n";

			auto front = nodeQ.front();

			if (node_exists(front->cur->parent))
			{
				if (visited.find(front->cur->parent->key) == visited.end())
				{
					tree_node_slb* curParent = new tree_node_slb;
					*curParent = { front, front->cur->parent };
					visited.insert(front->cur->parent->key);
					nodeQ.push_back(curParent);
					if (curParent->cur->key == toKey)
					{
						goto path_found;
					}
				}
			}
			if (node_exists(front->cur->left))
			{
				if (visited.find(front->cur->left->key) == visited.end())
				{
					tree_node_slb* curLeft = new tree_node_slb;
					*curLeft = { front, front->cur->left };
					visited.insert(front->cur->left->key);
					nodeQ.push_back(curLeft);
					if (curLeft->cur->key == toKey)
					{
						goto path_found;
					}
				}
			}
			if (node_exists(front->cur->right))
			{
				if (visited.find(front->cur->right->key) == visited.end())
				{
					tree_node_slb* curRight = new tree_node_slb;
					*curRight = { front, front->cur->right };
					visited.insert(front->cur->right->key);
					nodeQ.push_back(curRight);
					if (curRight->cur->key == toKey)
					{
						goto path_found;
					}
				}
			}

			nodeQ.pop_front();
		}
		return {};

	path_found:
		deque<lli> result;
		auto curNode = *nodeQ.rbegin();

		while (true)
		{
			//cout << "pushing " << curNode->cur->key << "\n";
			result.push_front(curNode->cur->key);
			curNode = curNode->before;

			if (curNode->before == NULL) break;
		}
		result.push_front(fromKey);
		return result;
	}
	//lli least_keyDiff_descent(lli fromKey, lli toKey)
	//{
	//	lli descentDistance = 0;
	//
	//	auto fromNode = find(fromKey);
	//	auto toNode = find(toKey);
	//	auto curNode = fromNode;
	//
	//	void(0);
	//
	//	while (true)
	//	{
	//		lli curKey = curNode->key;
	//
	//		lli parentKey = NULL;
	//		lli leftKey = NULL;
	//		lli rightKey = NULL;
	//		if (node_exists(curNode->parent)) parentKey = curNode->parent->key;
	//		if (node_exists(curNode->left)) leftKey = curNode->left->key;
	//		if (node_exists(curNode->right)) rightKey = curNode->right->key;
	//
	//		cout << leftKey << " |" << parentKey << "| " << rightKey << "\n";
	//
	//		if (curKey == toKey)
	//		{
	//			break;
	//		}
	//		//descending right
	//		else if (curKey < toKey)
	//		{
	//			if ((curKey < parentKey) && (parentKey < toKey))
	//			{
	//				if (!node_exists(curNode->parent)) return NULL;
	//				curNode = curNode->parent;
	//				descentDistance += abs(curKey - parentKey);
	//			}
	//			else if (curKey < right)
	//			{
	//				if (!node_exists(curNode->right)) return NULL;
	//				curNode = curNode->right;
	//				descentDistance += abs(curKey - rightKey);
	//			}
	//		}
	//		//descending left
	//		else if (curKey > toKey)
	//		{
	//			if ((curKey > parentKey) && (parentKey > toKey))
	//			{
	//				if (!node_exists(curNode->parent)) return NULL;
	//				curNode = curNode->parent;
	//				descentDistance += abs(curKey - parentKey);
	//			}
	//			else
	//			{
	//				if (!node_exists(curNode->left)) return NULL;
	//				curNode = curNode->left;
	//				descentDistance += abs(curKey - leftKey);
	//			}
	//		}
	//		else
	//		{
	//			return NULL;
	//		}
	//	}
	//	return descentDistance;
	//}

	//for bepi's MLM scam problem
	dbl least_value_descent(tree_node* node)
	{
		map<dbl, tree_node*> path_card;
		path_card.insert({ 0, node });

		while (path_card.size() > 0)
		{
			tree_node* front = path_card.begin()->second;
			dbl frontDst = path_card.begin()->first;
			/*
			if (node_exists(front->parent)) cout << "p: [" << front->parent->key << "," << front->parent->value << "]" << endl;
			if (node_exists(front->right)) cout << "r: [" << front->right->key << "," << front->right->value << "]" << endl;
			if (node_exists(front->left)) cout << "l: [" << front->left->key << "," << front->left->value << "]" << endl << endl;
			*/

			lli childCnt = 0;
			if (node_exists(front->left))
			{
				dbl leftDst = front->left->value;
				dbl totlDst = frontDst + leftDst;
				path_card.insert({ totlDst, front->left });
				childCnt += 1;
			}
			if (node_exists(front->right))
			{
				dbl rightDst = front->right->value;
				dbl totlDst = frontDst + rightDst;
				path_card.insert({ totlDst, front->right });
				childCnt += 1;
			}
			if (node_exists(front->parent))
			{
				dbl parentDst = front->parent->value;
				dbl totlDst = frontDst + parentDst;
				path_card.insert({ totlDst, front->parent });
			}

			/*
			for (auto kt = path_card.begin(); kt != path_card.end(); ++kt)
			{
				cout << "[" << kt->first << ",{" << kt->second->key << "," << kt->second->value << "}]; ";
			}
			cout << endl;
			*/

			if (childCnt == 0)
			{
				break;
			}

			path_card.erase(path_card.begin());
		}

		//cout << "res: [" << path_card.begin()->first << ",{" << path_card.begin()->second->key << "," << path_card.begin()->second->value << "}]; ";
		return path_card.begin()->first;;
	}

	void inorder()
	{
		tree_node* node = root;
		do_inorder(node);
		cout << endl;
	}

	void preorder()
	{
		tree_node* node = root;
		do_preorder(node);
		cout << endl;
	}

	void postorder()
	{
		tree_node* node = root;
		do_postorder(node);
		cout << endl;
	}

	void advanced_preorder()
	{
		tree_node* node = root;
		do_advanced_preorder(node);
		cout << endl;
	}

	void advanced_inorder()
	{
		tree_node* node = root;
		do_advanced_inorder(node);
		cout << endl;
	}

	void advanced_postorder()
	{
		tree_node* node = root;
		do_advanced_postorder(node);
		cout << endl;
	}

	void parse_inorder(vector<lli> inorder, binary_tree* tree, lli fromIdx, lli toIdx)
	{
		if (fromIdx > toIdx) return;

		lli midIdx = (fromIdx + toIdx + 1) / 2;
		tree->branch(inorder[midIdx], NULL);

		parse_inorder(inorder, tree, fromIdx, midIdx - 1);
		parse_inorder(inorder, tree, midIdx + 1, toIdx);
	}

	void bst_print()
	{
		deque<tree_node*> queue; queue.push_back(root);
		lli currentDepth = -1;

		cout << endl << "/-";
		while (queue.size() > 0)
		{
			tree_node* front = queue.front();
			tree_node* cache = new tree_node;
			cache->key = NULL; cache->depth = front->depth + 1;

			if (node_exists(front->left)) queue.push_back(front->left);
			else if (front->depth + 1 <= maxDepth) (queue.push_back(cache));
			if (node_exists(front->right)) queue.push_back(front->right);
			else if (front->depth + 1 <= maxDepth) (queue.push_back(cache));

			if (front->depth != currentDepth)
			{
				cout << endl;
				currentDepth = front->depth;
				for (lli l = 0; l < ((pow(2, (maxDepth - currentDepth)) - 1) * 3); ++l) cout << " ";
			}
			if (front->key != NULL) cout << setw(4) << setfill('0') << front->key << "  ";
			else cout << "      ";

			for (lli k = 0; k < ((pow(2, (maxDepth - currentDepth)) - 1) * 6); ++k) cout << " ";
			queue.pop_front();
		}
		cout << endl << "-/" << endl;
	}

	//from fp21_22-battle_of_secrets
	void find_safeSpaces()
	{
		vector<lli> result;

		deque<tree_node*> nodeQ;
		nodeQ.push_back(root);

		while (nodeQ.size() > 0)
		{
			deque<tree_node*> temp = {};
			for (auto kt = nodeQ.begin(); kt != nodeQ.end(); ++kt)
			{
				if ((kt > nodeQ.begin()) && (kt < nodeQ.end() - 1))
				{
					if ((node_exists((*kt)->parent) && (node_exists((*kt)->left) || node_exists((*kt)->right))))
					{
						result.push_back((*kt)->key);
					}
				}

				if (node_exists((*kt)->left))
				{
					temp.push_back((*kt)->left);
				}
				if (node_exists((*kt)->right))
				{
					temp.push_back((*kt)->right);
				}
			}
			nodeQ = temp;
		}

		sort(result.begin(), result.end());
		if (result.size() == 0)
		{
			cout << "It's not safe\n";
		}
		else
		{
			for (lli j = 0; j < result.size(); ++j)
			{
				cout << result[j] << " ";
			}
			cout << endl;
		}
	}

	void basic_print()
	{
		deque<tree_node*> nodeQ;
		nodeQ.push_back(root);

		while (nodeQ.size() > 0)
		{
			deque<tree_node*> temp;
			for (auto kt : nodeQ)
			{
				cout << kt->key << " ";
			}
			cout << endl;
			for (auto kt : nodeQ)
			{
				if (node_exists(kt->left)) temp.push_back(kt->left);
				if (node_exists(kt->right)) temp.push_back(kt->right);
			}

			nodeQ = temp;
		}
	}

	lli find_level(lli findKey)
	{
		tree_node* curNode = root;
		lli curLevel = 0;
		lli* resLevel = new lli; *resLevel = NULL;

		__find_level(root, findKey, curLevel, resLevel);
		return *resLevel;
	}

	lli find_maxLevel()
	{
		tree_node* curNode = root;
		lli curLevel = 0;
		lli* resLevel = new lli; *resLevel = -1;

		__find_maxLevel(curNode, curLevel, resLevel);
		return *resLevel;
	}

	deque<lli> one_child_families()
	{
		deque<lli> result = {};
		tree_node* curNode = root;

		__one_child_families(curNode, &result);
		return result;
	}

private:
	tree_node* __pluck(tree_node* curNode, lli findKey)
	{
		if (!node_exists(curNode)) return NULL;
		else if (node_exists(curNode))
		{
			if (findKey > curNode->key)
			{
				curNode->right = __pluck(curNode->right, findKey);
			}
			else if (findKey < curNode->key)
			{
				curNode->left = __pluck(curNode->left, findKey);
			}
			else if (findKey == curNode->key)
			{
				if (!node_exists(curNode->left))
				{
					tree_node* right = curNode->right;
					//cout << "returning " << right->key << "\n";
					return right;
				}
				else if (!node_exists(curNode->right))
				{
					tree_node* left = curNode->left;
					return left;
				}
			}

			tree_node* result = new tree_node;

			tree_node* temp = __find_leftest_node(curNode->right);
			result->key = temp->key;
			result->value = temp->value;
			result->index = temp->index;
			result->parent = curNode->parent;
			result->right = __pluck(curNode->right, temp->key);

			return result;
		}
	}

	void __xfind(tree_node* curNode, lli findKey, deque<tree_node*>* result)
	{
		result->push_back(curNode);
		if (findKey < curNode->key)
		{
			if (node_exists(curNode->left))
			{
				__xfind(curNode->left, findKey, result);
			}
			else
			{
				*result = {};
				return;
			}
		}
		else if (findKey > curNode->key)
		{
			if (node_exists(curNode->right))
			{
				__xfind(curNode->right, findKey, result);
			}
			else
			{
				*result = {};
				return;
			}
		}
		else
		{
			return;
		}
	}

	tree_node* __find_leftest_node(tree_node* curNode)
	{
		while (node_exists(curNode->left))
		{
			curNode = curNode->left;
		}
		return curNode;
	}

	void print_key(tree_node* node)
	{
		cout << node->key << " ";
	}

	void do_inorder(tree_node* node)
	{
		if (node_exists(node))
		{
			do_inorder(node->left);
			print_key(node);
			do_inorder(node->right);
		}
	}

	void do_preorder(tree_node* node)
	{
		if (node_exists(node))
		{
			print_key(node);
			do_preorder(node->left);
			do_preorder(node->right);
		}
	}

	void do_postorder(tree_node* node)
	{
		if (node_exists(node))
		{
			do_postorder(node->left);
			do_postorder(node->right);
			print_key(node);
		}
	}

	void do_advanced_preorder(tree_node* node)
	{
		if (node_exists(node))
		{
			printf("[");
			cout << node->index;
			cout << "|" << node->key;
			cout << "|" << node->value;
			printf("]\n");
			do_advanced_preorder(node->left);
			do_advanced_preorder(node->right);
		}
	}

	void do_advanced_inorder(tree_node* node)
	{
		if (node_exists(node))
		{
			do_advanced_inorder(node->left);
			printf("[");
			cout << node->index;
			cout << "|" << node->key;
			cout << "|" << node->value;
			printf("]\n");
			do_advanced_inorder(node->right);
		}
	}

	void do_advanced_postorder(tree_node* node)
	{
		if (node_exists(node))
		{
			do_advanced_postorder(node->left);
			do_advanced_postorder(node->right);
			printf("[");
			cout << node->index;
			cout << "|" << node->key;
			cout << "|" << node->value;
			printf("]\n");
		}
	}

	lli find_height(tree_node* node)
	{
		if (node == NULL) return 0;
		else return node->height;
	}

	lli find_tilt(tree_node* node)
	{
		lli rightHeight = 0; lli leftHeight = 0;
		if (node_exists(node))
		{
			if (node_exists(node->right)) rightHeight = node->right->height;
			if (node_exists(node->left)) leftHeight = node->left->height;
		}
		return rightHeight - leftHeight;
	}

	void find_node(tree_node* node, lli findKey, dbl findValue, tree_node* res)
	{
		if ((node_exists(node)) && (res->key == NULL))
		{
			/*
			cout << "trucheck: [" << node->key << "," << node->value << "]" << endl;
			if (node_exists(node->parent)) cout << "p: [" << node->parent->key << "," << node->parent->value << "]" << endl;
			if (node_exists(node->right)) cout << "r: [" << node->right->key << "," << node->right->value << "]" << endl;
			if (node_exists(node->left)) cout << "l: [" << node->left->key << "," << node->left->value << "]" << endl << endl;
			*/

			if ((node->key == findKey) && (node->value == findValue))
			{
				//cout << "NODE FONDDDDDDDDD" << endl;
				res->key = node->key;
				res->value = node->value;
				res->parent = node->parent;
				res->left = node->left;
				res->right = node->right;
				return;
			}
			else
			{
				if (node_exists(node->left)) find_node(node->left, findKey, findValue, res);
				if (node_exists(node->right)) find_node(node->right, findKey, findValue, res);
			}
		}
	}

	void rotate_right(tree_node* max)
	{
		tree_node* min = max->left;
		tree_node* mid = min->right;

		if (node_exists(max->parent))
		{
			min->parent = max->parent;
			if (min->parent->right == max) min->parent->right = min;
			else if (min->parent->left == max) min->parent->left = min;
		}
		else
		{
			min->parent = NULL;
			root = min;
		}

		max->parent = min;
		min->right = max;
		max->left = NULL;

		if (node_exists(mid))
		{
			max->left = mid;
			mid->parent = max;
		}

		if (node_exists(min->left)) min->left->height = find_max(find_height(min->left->left), find_height(min->left->right)) + 1;
		if (node_exists(min->right)) min->right->height = find_max(find_height(min->right->left), find_height(min->right->right)) + 1;
		max->height = find_max(find_height(max->left), find_height(max->right)) + 1;
		min->height = find_max(find_height(min->left), find_height(min->right)) + 1;

		//cout << "rotated right" << endl;
	}

	void rotate_left(tree_node* min)
	{
		tree_node* max = min->right;
		tree_node* mid = max->left;

		if (node_exists(min->parent))
		{
			max->parent = min->parent;
			if (max->parent->right == min) max->parent->right = max;
			else if (max->parent->left == min) max->parent->left = max;
		}
		else
		{
			max->parent = NULL;
			root = max;
		}

		min->parent = max;
		max->left = min;
		min->right = NULL;

		if (node_exists(mid))
		{
			min->right = mid;
			mid->parent = min;
		}

		if (node_exists(max->left)) max->left->height = find_max(find_height(max->left->left), find_height(max->left->right)) + 1;
		if (node_exists(max->right)) max->right->height = find_max(find_height(max->right->left), find_height(max->right->right)) + 1;
		max->height = find_max(find_height(max->left), find_height(max->right)) + 1;
		min->height = find_max(find_height(min->left), find_height(min->right)) + 1;

		//cout << "rotated left" << endl;
	}

	//from fp21_22-battle_of_secrets
	void __do_find_safeSpaces(tree_node* curNode, vector<lli>& result)
	{
		if (node_exists(curNode->parent) && (node_exists(curNode->left) || node_exists(curNode->right)))
		{

		}
	}

	void __find_level(tree_node* curNode, lli findKey, lli curLevel, lli* resLevel)
	{
		if (node_exists(curNode))
		{
			if (findKey == curNode->key)
			{
				*resLevel = curLevel;
				return;
			}
			else if (findKey > curNode->key)
			{
				if (node_exists(curNode->right)) __find_level(curNode->right, findKey, curLevel + 1, resLevel);
			}
			else if (findKey < curNode->key)
			{
				if (node_exists(curNode->left)) __find_level(curNode->left, findKey, curLevel + 1, resLevel);
			}
		}
	}

	void __find_maxLevel(tree_node* curNode, lli curLevel, lli* resLevel)
	{
		if (node_exists(curNode))
		{
			*resLevel = max(*resLevel, curLevel);
			if (node_exists(curNode->left))
			{
				__find_maxLevel(curNode->left, curLevel + 1, resLevel);
			}
			else if (node_exists(curNode->right))
			{
				__find_maxLevel(curNode->right, curLevel + 1, resLevel);
			}
		}
	}

	//customised inorder operation
	void __one_child_families(tree_node* curNode, deque<lli>* result)
	{
		if (node_exists(curNode->left)) __one_child_families(curNode->left, result);
		if (node_exists(curNode->left) != node_exists(curNode->right))
		{
			result->push_back(curNode->key);
		}
		if (node_exists(curNode->right)) __one_child_families(curNode->right, result);
	}

	//void __basic_find(tree_node* cur, lli findKey, tree_node* res)
	//{
	//	if (node_exists(cur))
	//	{
	//		cout << "checking " << cur->key << endl;
	//		if (cur->key == findKey)
	//		{
	//			cout << "GOOOOOOOOOO" << cur->key << endl;
	//			res->index = cur->index;
	//			res->key = cur->key;
	//			res->value = cur->value;
	//			res->height = cur->height;
	//			res->depth = cur->depth;
	//
	//			res->parent = cur->parent;
	//			res->left = cur->left;
	//			res->right = cur->right;
	//			return;
	//		}
	//		else
	//		{
	//			if (node_exists(cur->right)) __basic_find(cur->right, findKey, res);
	//			if (node_exists(cur->left)) __basic_find(cur->left, findKey, res);
	//		}
	//	}
	//}
};

//graph/network/node unions
class network
{
public:
	lli nodeCount = NULL;
	deque<lli> node;
	unordered_map<lli, unordered_map<lli, lli>> edge;
	unordered_map<lli, unordered_map<lli, lli>> redge;

	deque<lli> availablePath;
	deque<lli> shortestPath;
	deque<lli> topologicalSort;

	bool initedLoops = false;
	deque<deque<lli>> loops;

	void uconnect(lli node1, lli node2, lli weight)
	{
		edge[node1][node2] = weight;
	}
	void iconnect(lli node1, lli node2, lli weight)
	{
		edge[node1][node2] = weight;
		edge[node2][node1] = weight;
	}
	void rconnect(lli node1, lli node2, lli weight)
	{
		edge[node2][node1] = weight;
	}

	//deque<lli> depthFirst_findAvailablePath(lli node1, lli node2)
	//{
	//	unordered_set<lli> visited;
	//	deque<slb> pathS; pathS.push_back(node1);
	//	visited.insert(node1);
	//
	//	while (pathS.size() > 0)
	//	{
	//
	//	}
	//	return {};
	//
	//path_found:
	//
	//}
	deque<lli> dijkstra_findShortestPath(lli node1, lli node2)
	{
		multimap<lli, slb> pathQ;
		unordered_map<lli, bool> visited;

		pathQ.insert({ 0, {NULL, node1} });
		visited[node1] = true;
		slb* cur = NULL;

		deque<lli> result;

		while (pathQ.size() > 0)
		{
			auto front = pathQ.begin();
			slb frontNode = front->second;
			cur = &front->second;

			//for (auto it = pathQ.begin(); it != pathQ.end(); ++it)
			//{
			//	cout << it->first << "|" << it->second.val << "|";
			//	if (it->second.before != NULL) cout << it->second.before->val << " ";
			//	else cout << "0 ";
			//}
			//cout << endl;

			if (front->second.val == node2) goto exit;

			for (auto it : edge[front->second.val])
			{
				if (!visited[it.first])
				{
					slb curPath;
					slb* temp = new slb;
					*temp = frontNode;
					curPath.before = temp;
					curPath.val = it.first;
					pathQ.insert({ (front->first + it.second), curPath });
				}
			}

			visited[front->second.val] = true;
			pathQ.erase(front);
		}

		shortestPath = result;
		return result;

	exit:
		while (true)
		{
			if (cur == NULL) break;
			else
			{
				result.push_front(cur->val);
				if (cur->before != NULL) cur = cur->before;
				else break;
			}
		}
		cout << "path found\n";
		return result;
	}

	deque<lli> dijkstra_findLongestPath(lli node1, lli node2)
	{
		multimap<lli, slb> pathQ;
		unordered_map<lli, bool> visited;

		//if (edge[node1].size() == 0 || redge[node2].size() == 0)
		//{
		//	return {};
		//}

		pathQ.insert({ 0, {NULL, node1} });
		visited[node1] = true;
		slb* cur = NULL;

		deque<lli> result;

		while (pathQ.size() > 0)
		{
			auto front = pathQ.end();
			front--;
			slb frontNode = front->second;
			cur = &front->second;

			//for (auto it = pathQ.begin(); it != pathQ.end(); ++it)
			//{
			//	cout << it->first << "|" << it->second.val << "|";
			//	if (it->second.before != NULL) cout << it->second.before->val << " ";
			//	else cout << "0 ";
			//}
			//cout << endl;

			if (front->second.val == node2) goto exit;

			for (auto it : edge[front->second.val])
			{
				if (!visited[it.first])
				{
					slb curPath;
					slb* temp = new slb;
					*temp = frontNode;
					curPath.before = temp;
					curPath.val = it.first;
					pathQ.insert({ (front->first + it.second), curPath });
				}
			}

			visited[front->second.val] = true;
			pathQ.erase(front);
		}

		shortestPath = result;
		return result;

	exit:
		while (true)
		{
			if (cur == NULL) break;
			else
			{
				result.push_front(cur->val);
				if (cur->before != NULL) cur = cur->before;
				else break;
			}
		}
		return result;
	}

	deque<lli> sort_topologically()
	{
		if (!initedLoops)
		{
			static_cast<void>(tarjan_findStrongComponents());
		}
		if (loops.size() > 0)
		{
			return {};
		}

		deque<lli> res = {};

		uset<lli> visited;
		deque<lli> nodeQ = {};

		for (lli j = 1; j <= nodeCount; ++j)
		{
			if (visited.find(j) == visited.end())
			{
				deque<lli> peekQ = {};
				peekQ.push_back(j);
				visited.insert(j);

				while (peekQ.size() > 0)
				{
					//for (auto mt : peekQ)
					//{
					//	cout << mt << " ";
					//}
					//cout << endl;

					auto top = peekQ.back();
					for (auto mt : edge[top])
					{
						if (visited.find(mt.first) == visited.end())
						{
							visited.insert(mt.first);
							peekQ.push_back(mt.first);
							break;
						}
					}
					if (top == peekQ.back())
					{
						res.push_front(top);
						peekQ.pop_back();
					}
				}
			}
		}

		topologicalSort = res;
		return res;
	}

	//PATH FINDING INCOMPLETE FOR OVERLAPPING LOOPS, 
	//BUT CAN ACCURATELY DETERMINE WHETHER A LOOP EXISTS
	deque<deque<lli>> tarjan_findStrongComponents()
	{
		//set the result, lowlink map, and visited set
		deque<deque<lli>> result;
		unordered_map<lli, lli> lowLink;
		unordered_set<lli> visited;

		//set the path stack and onstack condition
		deque<lli> pathS;
		unordered_set<lli> onStack;

		//for every node in the graph:
		for (auto& jt : node)
		{
			if (visited.find(jt) == visited.end())
			{
				if (pathS.size() == 0)
				{
					lowLink[jt] = jt;
					pathS.push_back(jt);
					onStack.insert(jt);
					visited.insert(jt);
					//cout << "added " << jt << " because stack is empty\n";
				}

				deque<lli> curLoop = {};

				lli cur = 0;

				while (true)
				{
					//for (auto& mt : pathS)
					//{
					//	cout << mt << " " << lowLink[mt] << "|";
					//}
					//cout << "\n";
					//for (lli m = 0; m <= cur; ++m)
					//{
					//	cout << pathS[m] << " " << lowLink[pathS[m]] << "|";
					//}
					//cout << "\n";

					//for every edge branching from cur node:
					for (auto& mt : edge[pathS[cur]])
					{
						//if the destination node is in current dfs path
						if (onStack.find(mt.first) != onStack.end())
						{
							//cout << "check: " << pathS[cur] << ">" << mt.first << endl;
							//change the lowlink of top to be the min of
							//its lowlink value and the lowlink of the dest node
							lowLink[pathS[cur]] = min(lowLink[pathS[cur]], lowLink[mt.first]);

							if (
								(cur >= 0) &&
								(cur != (pathS.size() - 1)) &&
								(pathS.size() > 1) &&
								(lowLink[pathS[cur + 1]] == lowLink[pathS[cur]]) &&
								(lowLink[pathS[cur]] == pathS[cur])
								)
							{
								break;
							}
							else
							{
								cur--;
								goto redo_tarjan_dfsLoop;
							}
						}
						//else if the destination node have not been visited:
						else if (visited.find(mt.first) == visited.end())
						{
							//set the current node's lowlink equal to its id
							//and update corresponding datas (visited, onstack, stack)
							lowLink[mt.first] = mt.first;
							pathS.push_back(mt.first);
							onStack.insert(mt.first);
							visited.insert(mt.first);

							//add index & break for loop, next, this node will be top
							cur++;
							goto redo_tarjan_dfsLoop;
						}
					}
					//for (auto& mt : pathS)
					//{
					//	cout << mt << " " << lowLink[mt] << ":";
					//}
					//cout << "\n\n";

					if (lowLink[pathS[cur]] == pathS[cur])
					{
						deque<lli> temp = {};
						for (lli n = pathS.size() - 1; n >= cur; --n)
						{
							//for (auto& mt : pathS)
							//{
							//	cout << mt << " " << lowLink[mt] << "!";
							//}
							//cout << "\n";

							temp.push_front(pathS.back());
							onStack.erase(pathS[n]);
							pathS.pop_back();
						}
						if (temp.size() > 1) result.push_back(temp);

						//for (auto& nt : temp)
						//{
						//	cout << nt << " ";
						//}
						//cout << "\n\n\n";
						break;
					}
					--cur;

				redo_tarjan_dfsLoop:
					if (cur < 0)
					{
						for (auto& nt : pathS)
						{
							onStack.erase(nt);
							visited.erase(nt);
						}
						pathS.clear();
						break;
					}
				}
			}
		}

		initedLoops = true;
		loops = result;
		return result;
	}

	//void uconnect(lli node1, lli node2, lli weight);
	//void iconnect(lli node1, lli node2, lli weight);
	//void rconnect(lli node1, lli node2, lli weight);
	//deque<lli> dijkstra_findShortestPath(lli node1, lli node2);
	//deque<lli> sort_topologically()
};

//class slf
//class slb
//class dl
//class network

int main()
{
	network myNetwork;
	lli nodeCount; cin >> nodeCount;
	for (lli i = 1; i <= nodeCount; ++i)
	{
		myNetwork.node.push_back(i);
	}

	lli edgeCount; cin >> edgeCount;
	for (lli i = 0; i < edgeCount; ++i)
	{
		lli node1; cin >> node1;
		lli node2; cin >> node2;
		lli weight; cin >> weight;

		myNetwork.uconnect(node1, node2, weight);
		myNetwork.rconnect(node1, node2, weight);
	}
	//cout << "asking\n";

	lli askCount; cin >> askCount;
	for (lli i = 0; i < askCount; ++i)
	{
		//cout << "asking\n";
		lli node1; cin >> node1;
		lli node2; cin >> node2;
		//cout << "received input\n";

		deque<lli> foundPath = myNetwork.dijkstra_findLongestPath(1, nodeCount);
		//cout << "finding between " << node1 << " and " << node2 << "\n";
		lli pathLen = 0;
		lli biggestTree = LLONG_MIN;

		for (auto jt : foundPath)
		{
			cout << jt << "a ";
		}
		cout << "\n";

		if (foundPath.size() == 0)
		{
			cout << "So Long and Good Night\n";
			continue;
		}

		for (lli j = 0; j < foundPath.size() - 1; ++j)
		{
			pathLen += myNetwork.edge[foundPath[j]][foundPath[j + 1]];
			biggestTree = max(biggestTree, myNetwork.edge[foundPath[j]][foundPath[j + 1]]);
		}

		if (biggestTree >= node1 && biggestTree <= node2)
		{
			cout << pathLen << " " << biggestTree << "\n";
		}
		else
		{
			cout << "So Long and Good Night\n";
		}
	}
	return 0;
}
