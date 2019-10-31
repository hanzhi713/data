//
// Created by hanzhi713 on 10/30/19.
//

#include <bits/stdc++.h>

using namespace std;

bool results[262144];
bool visited[262144] = {false};

struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    int val = -1;
};

int postOrder(Node* root) {
    if (root) {
        int left = postOrder(root->left);
        int right = postOrder(root->right);
        return root->val;
    }
}

int main() {
    int n;
    cin >> n;
    int max = pow(2, n);
    auto* nodes = new Node[max]();
    for (int i = 0; i < max; ++i) {
        cin >> nodes[i].val;
    }

    for (int j = 2; j < max; j *= 2) {
        auto* levelUp = new Node[max / j];
        for (int i = 0; i < max / j; ++i) {
            levelUp[i].left = &nodes[i * 2];
            levelUp[i].right = &nodes[i * 2 + 1];
        }
        nodes = levelUp;
    }
    Node root;
    root.left = &nodes[0];
    root.right = &nodes[1];



//
//    bool flag = false;
//    for (int k = 1; k < max; ++k) {
//        if (results[k] != results[k - 1]) {
//            flag = true;
//            break;
//        }
//    }
//    if (!flag) {
//        cout << 1 << endl;
//        return 0;
//    }
//
//    int count = 1;
//    for (int i = 0; i < n; ++i) {
//        int mask = 1 << i;
//        int oddZeroCount = 0;
//        int oddOneCount = 0;
//        int evenZeroCount = 0;
//        int evenOneCount = 0;
//        for (unsigned j = 0; j < max; ++j) {
//            if (mask & j) {
//                oddOneCount += results[j];
//                oddZeroCount += !results[j];
//            } else {
//                evenOneCount += results[j];
//                evenZeroCount += !results[j];
//            }
//        }
//        int temp[] = {oddZeroCount, oddOneCount, evenZeroCount, evenOneCount};
//        int max_E = *max_element(temp, temp + 4);
//        if (max_E == oddZeroCount && oddOneCount == 0) {
//            for (unsigned j = 0; j < max; ++j) {
//                if ((mask & j) && !results[j]) visited[j] = true;
//            }
//        } else if (max_E == oddOneCount && oddZeroCount == 0) {
//            for (unsigned j = 0; j < max; ++j) {
//                if ((mask & j) && results[j]) visited[j] = true;
//            }
//        } else if (max_E == evenZeroCount && evenOneCount == 0) {
//            for (unsigned j = 0; j < max; ++j) {
//                if ((mask & j) == 0 && !results[j]) visited[j] = true;
//            }
//        } else if (max_E == evenOneCount && evenZeroCount == 0) {
//            for (unsigned j = 0; j < max; ++j) {
//                if ((mask & j) == 0 && results[j]) visited[j] = true;
//            }
//        }
////        cout << oddZeroCount << " " << oddOneCount << " " << evenZeroCount << " " << evenOneCount << endl;
//        bool flag = false;
//        for (int k = 0; k < max; ++k) {
//            if (!visited[k]) {
//                flag = true;
//                break;
//            }
//        }
//        if (!flag) {
//            cout << count << endl;
//            return 0;
//        }
//        count += 2;
//    }
//    cout << count << endl;
}