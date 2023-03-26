

// // // 863. All Nodes Distance K in Binary Tree
// // // https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

// // // Imp ques
// // // Same approach for Time for Burning of tree qyestion , just the answer would be curr_lvl-1;
// // // Dry run it or watch striver video.
// // class Solution {

// // public:
// // // parent_track = map
// // // The below function will mark the parents , make connection from child to parent which would be stored in map.
// map[children] = parent;
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
            /* code */
            parent_track[curr->left] = curr;
            q.push(curr->left);
        }

        if (curr->right)
        {
            parent_track[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

public:
vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{

    unordered_map<TreeNode *, TreeNode *> parent_track;

    markParents(root, parent_track, target);

    // The map below will initially store false in all iterations or we can say .count =0 or nothing is present in that iteration..
    unordered_map<TreeNode *, bool> visited;

    queue<TreeNode *> q;

    q.push(target);

    // visited[target] = true , we will initially make only target as true others will be stored as 0 or false.
    // We can them further check as by count function also
    visited[target] = true;

    int curr_lvl = 0;

    while (!q.empty())
    {
        int size = q.size();

        if (curr_lvl++ == k)
        {

            break;
        }

        for (int i = 0; i < size; i++)
        {

            TreeNode *curr = q.front();
            q.pop();

            // if (curr->left && !visited[curr->left])
            if (curr->left && visited[curr->left] == false)
            {
                /* code */

                q.push(curr->left);
                visited[curr->left] = true;
            }

            // if (curr->right && !visited[curr->right])
            if (curr->right && visited[curr->right] == false)
            {
                /* code */

                q.push(curr->right);

                visited[curr->right] = true;
            }

            // if (parent_track.count(curr)  && !visited[parent_track[curr]])
            // if(parent_track.count(curr) && !visited.count(parent_track[curr]))
            if (parent_track.count(curr) && visited[parent_track[curr]] == false)
            {
                /* code */

                q.push(parent_track[curr]);
                visited[parent_track[curr]] = true;
            }
        }
    }

    // The required answer will be remaining elements of queue.
    // Store remaining elements into a vector and return.

    vector<int> result;

    while (!q.empty())
    {

        TreeNode *curr = q.front();
        q.pop();
        result.push_back(curr->val);
    }

    return result;
}
}
;