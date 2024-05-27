
/*
Link: https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
*/




class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        
        queue<pair<Node*, int> >q;
        map<int, int> topNode;
        
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            
            topNode[hd] = frontNode->data;
            
            if(frontNode->left)
                q.push(make_pair(frontNode->left, hd-1));
            
            if(frontNode->right)
                q.push(make_pair(frontNode->right, hd+1));
        }
        for(auto i:topNode)
            ans.push_back(i.second);
        
        return ans;
    }
};