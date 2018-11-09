#include <bits/stdc++.h>
using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};
typedef struct UndirectedGraphNode Graph;
class Solution {
	UndirectedGraphNode *dfs(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode *, UndirectedGraphNode *>& map) {
		if (node == nullptr) return nullptr;
		if (map.find(node) != map.end()) return map[node];			// is visited?
		UndirectedGraphNode *copy = new UndirectedGraphNode(node->label);	// now visit by clone, visit 1/2
		map[node] = copy;							// visit 2/2
		for (auto n: node->neighbors) {
			UndirectedGraphNode *next = dfs(n, map);			// clone neighbor 1/2
			copy->neighbors.push_back(next);				// clone neighbor 2/2
		}
		return copy;
	}
public:
	// DSF approach
	UndirectedGraphNode *cloneGraph1(UndirectedGraphNode *node) {
		if (node == nullptr) return nullptr;
		unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> map;
		return dfs(node, map);
	}
	// BFS approach
	UndirectedGraphNode *cloneGraph(Graph *node) {
		if (!node) return nullptr;
		unordered_map<Graph*, Graph*> m;
		queue<Graph*> q;			// deal w/ src queue 1/2
		q.push(node);				// deal w/ src queue 1/2
		Graph *copy = new Graph(node->label);	// clone 1/2
		m[node] = copy;				// clone 2/2
		while (!q.empty()) {
			Graph *cur = q.front();		// src queue
			q.pop();
			for (auto ne: cur->neighbors) {
				if (m.find(ne) == m.end()) {
					Graph *ne1 = new Graph(ne->label);	// clone 1/4
					m[ne]=ne1;				// clone 2/4
					m[cur]->neighbors.push_back(ne1);	// clone 3/4
					q.push(ne);				// clone 4/4
				} else
					m[cur]->neighbors.push_back(m[ne]);
			}
		}
		return copy;
	}
};

int main() {
    return 0;
}
