

class Solution
{

public:
    void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track, TreeNode *target)
    {

        queue<TreeNode *> q;

        q.push(root);

        while (!q.empty())
        {

            TreeNode *curr = q.front();

            q.pop();

            if (curr->left)
            {
                q.push(curr->left);
                parent_track[curr->left] = curr;
            }
            if (curr->right)
            {
                q.push(curr->right);
                parent_track[curr->right] = curr;
            }
        }
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {

        unordered_map<TreeNode *, TreeNode *> parent_track;

        markParents(root, parent_track, target);

        unordered_map<TreeNode *, bool> visited;

        visited[target] = true;

        queue<TreeNode *> q;
        q.push(target);

        int lvl = 0;
        while (!q.empty())
        {
            if (lvl++ == k)
            {
                break;
            }

            for (int i = 0; i < q.size(); i++)
            {

                TreeNode *curr = q.front();
                q.pop();

                if (curr->left && !visited[curr->left])
                {
                    /* code */

                    q.push(curr->left);
                    visited[curr->left] = true;
                }

                if (curr->right && !visited[curr->right])
                {
                    /* code */

                    q.push(curr->right);
                    visited[curr->right] = true;
                }

                if (parent_track.count(curr) && !visited[parent_track[curr]])
                {
                    /* code */

                    q.push(parent_track[curr]);
                    visited[parent_track[curr]] = true;
                }
            }
        }

        vector<int> ans;

        while (!q.empty())
        {
            ans.push_back(q.curr()->val);
            q.pop();
        }

        return ans;
    }
};
