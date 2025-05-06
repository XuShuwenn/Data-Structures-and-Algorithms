#include <bits/stdc++.h>
using namespace std;

vector<int> orders;

class TreeNode {
private:
    int value;
    TreeNode* lc;
    TreeNode* rc;
public:
    TreeNode(int x) : value(x), lc(nullptr), rc(nullptr) {}
    int getValue() const { return value; }
    TreeNode* getLc() const { return lc; }
    void setLc(TreeNode* node) { lc = node; }
    TreeNode* getRc() const { return rc; }
    void setRc(TreeNode* node) { rc = node; }
};

TreeNode* createNode(int value) {
    return new TreeNode(value);
}

void preorder(TreeNode* root) {
    if (!root) return;
    vector<int> result;
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()) {
        TreeNode* node = s.top();
        s.pop();
        result.push_back(node->getValue());
        if (node->getRc()) s.push(node->getRc());
        if (node->getLc()) s.push(node->getLc());
    }
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << (i < result.size() - 1 ? " " : "");
    }
}

void inorder(TreeNode* root) {
    if (!root) return;
    vector<int> result;
    stack<TreeNode*> s;
    TreeNode* curr = root;
    while (curr || !s.empty()) {
        while (curr) {
            s.push(curr);
            curr = curr->getLc();
        }
        curr = s.top();
        s.pop();
        result.push_back(curr->getValue());
        curr = curr->getRc();
    }
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << (i < result.size() - 1 ? " " : "");
    }
}

void postorder(TreeNode* root) {
    if (!root) return;
    vector<int> result;
    stack<TreeNode*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        TreeNode* node = s1.top();
        s1.pop();
        s2.push(node);
        if (node->getLc()) s1.push(node->getLc());
        if (node->getRc()) s1.push(node->getRc());
    }
    while (!s2.empty()) {
        result.push_back(s2.top()->getValue());
        s2.pop();
    }
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << (i < result.size() - 1 ? " " : "");
    }
}

void RightMostView(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    vector<int> result;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (i == size - 1) result.push_back(node->getValue());
            if (node->getLc()) q.push(node->getLc());
            if (node->getRc()) q.push(node->getRc());
        }
    }
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << (i < result.size() - 1 ? " " : "");
    }
    cout << endl;
}

TreeNode* findLCA(TreeNode* root, const unordered_set<int>& nodes) {
    if (!root) return nullptr;
    if (nodes.count(root->getValue())) return root;
    TreeNode* left = findLCA(root->getLc(), nodes);
    TreeNode* right = findLCA(root->getRc(), nodes);
    if (left && right) return root;
    return left ? left : right;
}

bool IsValidTree(TreeNode* root, const unordered_map<int, TreeNode*>& node_map) {
    if (!root) return false;
    unordered_set<int> visited;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        int val = node->getValue();
        if (visited.count(val)) return false; // Cycle detected
        visited.insert(val);
        if (node->getLc()) q.push(node->getLc());
        if (node->getRc()) q.push(node->getRc());
    }
    return visited.size() == node_map.size(); // All nodes must be reachable
}

void print_results(TreeNode* root) {
    if (!root) return;
    for (int order : orders) {
        if (order == 1) {
            preorder(root);
            cout << endl;
        } else if (order == 2) {
            inorder(root);
            cout << endl;
        } else if (order == 3) {
            postorder(root);
            cout << endl;
        }
    }
}

enum States { NOT_COVERED, COVERED, LIGHTED };

void initStates(TreeNode* root, unordered_map<TreeNode*, States>& states) {
    if (!root) return;
    states[root] = NOT_COVERED;
    initStates(root->getLc(), states);
    initStates(root->getRc(), states);
}

int minLights(TreeNode* root, unordered_map<TreeNode*, States>& states) {
    if (!root) return 0;
    int left = minLights(root->getLc(), states);
    int right = minLights(root->getRc(), states);
    if ((root->getLc() && states[root->getLc()] == NOT_COVERED) ||
        (root->getRc() && states[root->getRc()] == NOT_COVERED)) {
        states[root] = LIGHTED;
        if (root->getLc()) states[root->getLc()] = COVERED;
        if (root->getRc()) states[root->getRc()] = COVERED;
        return 1 + left + right;
    }
    if ((root->getLc() && states[root->getLc()] == LIGHTED) ||
        (root->getRc() && states[root->getRc()] == LIGHTED)) {
        states[root] = COVERED;
        return left + right;
    }
    states[root] = NOT_COVERED;
    return left + right;
}

void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->getLc());
    deleteTree(root->getRc());
    delete root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line, order_line;
    unordered_map<int, TreeNode*> node_map;
    unordered_map<int, int> indegree;
    bool valid = true;

    while (getline(cin, line) && valid) {
        istringstream ss(line);
        int parent_val, child_val;
        char dir;
        if (!(ss >> parent_val >> dir >> child_val) || (dir != 'L' && dir != 'R')) {
            order_line = line;
            break;
        }
        TreeNode *parent, *child;
        if (!node_map.count(parent_val)) {
            parent = createNode(parent_val);
            node_map[parent_val] = parent;
            indegree[parent_val] = 0;
        } else {
            parent = node_map[parent_val];
        }
        if (!node_map.count(child_val)) {
            child = createNode(child_val);
            node_map[child_val] = child;
            indegree[child_val] = 1;
        } else {
            child = node_map[child_val];
            if (++indegree[child_val] > 1) valid = false;
        }
        if ((dir == 'L' && parent->getLc()) || (dir == 'R' && parent->getRc())) {
            valid = false;
        } else if (dir == 'L') {
            parent->setLc(child);
        } else {
            parent->setRc(child);
        }
    }

    if (node_map.empty() || !valid) {
        cout << "false" << endl;
        for (auto& pair : node_map) delete pair.second;
        return 0;
    }

    TreeNode* root = nullptr;
    int root_count = 0;
    for (const auto& pair : indegree) {
        if (pair.second == 0) {
            root = node_map[pair.first];
            root_count++;
        }
    }
    if (root_count != 1 || !IsValidTree(root, node_map)) {
        cout << "false" << endl;
        deleteTree(root);
        return 0;
    }

    istringstream ss(order_line);
    string token;
    while (ss >> token) {
        if (token == "A") {
            orders.push_back(1);
        } else if (token == "B") {
            orders.push_back(2);
        } else if (token == "C") {
            orders.push_back(3);
        } else {
            cout << "false" << endl;
            deleteTree(root);
            return 0;
        }
    }

    string lca_line;
    getline(cin, lca_line);
    istringstream lca_ss(lca_line);
    unordered_set<int> nodes;
    int node_val;
    bool lca_valid = true;
    while (lca_ss >> node_val) {
        if (!node_map.count(node_val)) lca_valid = false;
        nodes.insert(node_val);
    }
    char extra;
    if (lca_ss >> extra) lca_valid = false; // Check for invalid characters

    print_results(root);
    if (lca_valid && !nodes.empty()) {
        TreeNode* lca = findLCA(root, nodes);
        cout << (lca ? lca->getValue() : -1) << endl;
    } else {
        cout << -1 << endl;
    }
    RightMostView(root);
    unordered_map<TreeNode*, States> states;
    initStates(root, states);
    int lights = minLights(root, states);
    if (states[root] == NOT_COVERED) {
        states[root] = LIGHTED;
        lights += 1;
    }
    cout << lights << endl; // Add newline
    deleteTree(root);
    return 0;
}
