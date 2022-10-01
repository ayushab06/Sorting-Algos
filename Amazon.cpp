//Code
int MaxSubarraySum(vector<int> nums, int k){
    unordered_set<int> map;
    int left = 0, res = -1, sum = 0;
    for(int right = 0; right<nums.size(); right++){
        while(left < right && (map.count(nums[right]) || map.size() >= k)){
            sum -= nums[left];
            map.erase(nums[left]);
            left++;
        }
        sum +=nums[right];
        map.insert(nums[right]);
            
        if (map.size() == k)
            res = max(res, sum);
    }
    return res;
}

int findMinimumCharacters(string searchWord, string resultWord) {
    int i=0,j=0;

    while(i < searchWord.length()) {
        if(searchWord[i] == resultWord[j]) {
            j++;
            if(j == resultWord.length()) break;
        }
        i++;
    }
    return resultWord.length() - j;
}

//About
//Amazon.com launched in 1995, it was with the mission 
//“to be Earth’s most customer-centric company.”
//we start with the customer and work backwards


/*Leadership
Customer Obsession  
Ownership
Invent and Simplify
Are right, A Lot
Learn and Be Curious
Hire and Develop the Best
Insist on the Highest Standards
Think Big
Bias for Action
Frugality
Earn Trust
Dive Deep
Have Backbone; Disagree and Commit
Deliver Results
Strive to be Earth's Best Employer
Success and Scale Bring Broad Responsibility
*/

/*STAR
SITUATION
TASK
ACTION
RESULT
*/
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output;
        int i=0;
        int j=0;
        list<int> l;
        while(j<nums.size())
        {
            if(l.empty())
                l.push_back(nums[j]);   
            else{
                while(!l.empty() && l.back()<nums[j])
                    l.pop_back();
                l.push_back(nums[j]);               
            }
            
            if(j-i+1<k) ++j;
            else if(j-i+1==k){
                output.push_back(l.front());
                if(nums[i]==l.front())
                    l.pop_front();
                ++i;++j;
            }
        }
        return output;
    }

// Function to transfer elements of
// the stack s1 to the stack s2
void transfer(stack<int>& s1,
              stack<int>& s2, int n)
{
    for (int i = 0; i < n; i++) {
 
        // Store the top element
        // in a temporary variable
        int temp = s1.top();
 
        // Pop out of the stack
        s1.pop();
 
        // Push it into s2
        s2.push(temp);
    }
}
 
// Function to reverse a stack using another stack
void reverse_stack_by_using_extra_stack(stack<int>& s,
                                        int n)
{
    stack<int> s2;
 
    for (int i = 0; i < n; i++) {
 
        // Store the top element
        // of the given stack
        int x = s.top();
 
        // Pop that element
        // out of the stack
        s.pop();
 
        transfer(s, s2, n - i - 1);
        s.push(x);
        transfer(s2, s, n - i - 1);
    }
}

int countPlatforms(int n,int arr[],int dep[])
 {
    int ans=1; //final value
    for(int i=0;i<=n-1;i++)
    {
        int count=1; // count of overlapping interval of only this   iteration
        for(int j=i+1;j<=n-1;j++)
        {
            if((arr[i]>=arr[j] && arr[i]<=dep[j]) ||
           (arr[j]>=arr[i] && arr[j]<=dep[i]))
           {
               count++;
           }
        }
        ans=max(ans,count); //updating the value
    }
    return ans;
 }

 TreeNode* getNextGreaterNodeBST(TreeNode* root, int B) {
   
    TreeNode* ceil = NULL;
    int val = B + 1;
    while (root)
    {
        if (root -> val == val)
            return root;
        if (val > root -> val)
            root = root -> right;
        else
        {
            ceil = root;
            root = root -> left;
        }
    }    
    return ceil;
}

int trap(vector < int > & height) {
  int n = height.size();
  int left = 0, right = n - 1;
  int res = 0;
  int maxLeft = 0, maxRight = 0;
  while (left <= right) {
    if (height[left] <= height[right]) {
      if (height[left] >= maxLeft) {
        maxLeft = height[left];
      } else {
        res += maxLeft - height[left];
      }
      left++;
    } else {
      if (height[right] >= maxRight) {
        maxRight = height[right];
      } else {
        res += maxRight - height[right];
      }
      right--;
    }
  }
  return res;
}

bool subArrayExists(int arr[], int N)
{
    unordered_set<int> sumSet;
 
    // Traverse through array
    // and store prefix sums
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
 
        // If prefix sum is 0 or
        // it is already present
        if (sum == 0 || sumSet.find(sum) != sumSet.end())
            return true;
 
        sumSet.insert(sum);
    }
    return false;
}



int res = 0;
// Function to find the time for the tree to burn
int burnTime(Node* root, int leaf, int& dist)
{
    if (root == NULL)
        return 0;
    if (root->key == leaf) {
        dist = 0;
        return 1;
    }
    int ldist = -1, rdist = -1;
    int lh = burnTime(root->left, leaf, ldist);
    int rh = burnTime(root->right, leaf, rdist);
 
    if (ldist != -1) {
        dist = ldist + 1;
        res = max(res, dist + rh);
    }
    else if (rdist != -1) {
        dist = rdist + 1;
        res = max(res, dist + lh);
    }
    return max(lh, rh) + 1;
}


    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n=nums.size();
        if(n==0)
            return ans;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long needed=(long long)target-(long long)nums[i]-(long long)nums[j];
                int left=j+1;
                int right=n-1;
                while(left<right){
                    if(nums[left] + nums[right]<needed)
                        left++;
                    else if(nums[left] + nums[right]>needed)
                        right--;
                    else{
                        int a=nums[i];
                        int b=nums[j];
                        int c=nums[left];
                        int d=nums[right];
                        ans.push_back({a,b,c,d});
                        
                        //ignoring duplicates for left
                        while(left<right && nums[left]==c)
                            left++;
                        //ignoring duplicates for right
                        while(right<right && nums[right]==d)
                            right--;
                    }
                }
                //ignoring duplicates for j
                while(j+1<n && nums[j]==nums[j+1])
                    j++;
            }
            //ignoring duplicates for i
            while(i+1<n && nums[i]==nums[i+1])
                i++;
        }
        return ans;
    }



vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            nodes[p.second.first][p.second.second].insert(node->val);
            if (node -> left)
                todo.push({node->left,{p.second.first-1,p.second.second+1}});
            if (node -> right)
                todo.push({node->right,{p.second.first+1,p.second.second+1}});
        }
        vector<vector<int>> ans;
        for (auto &p : nodes) {
            vector<int> col;
            for (auto &q : p.second)
                col.insert(col.end(), q.second.begin(), q.second.end());
            
            ans.push_back(col);
        }
        return ans;
    }


ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *even_start = head->next;
        
        while(odd->next && even->next){
            odd->next = even->next; //Connect all odds
            even->next = odd->next->next;  //Connect all evens
            odd = odd->next;
            even = even->next;
        }
        odd->next = even_start;   //Place the first even node after the last odd node.
        return head; 
    }


int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    grid[i][j]='0';
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                        int nodex=q.front().first;
                        int nodey=q.front().second;
                        q.pop();
                        
                        if(nodex-1>=0 && grid[nodex-1][nodey]=='1'){
                            grid[nodex-1][nodey]='0';
                            q.push({nodex-1,nodey});
                        }
                        if(nodex+1<n && grid[nodex+1][nodey]=='1'){
                            grid[nodex+1][nodey]='0';
                            q.push({nodex+1,nodey});
                        }
                        if(nodey-1>=0 && grid[nodex][nodey-1]=='1'){
                            grid[nodex][nodey-1]='0';
                            q.push({nodex,nodey-1});
                        }
                        if(nodey+1<m && grid[nodex][nodey+1]=='1'){
                            grid[nodex][nodey+1]='0';
                            q.push({nodex,nodey+1});
                        }
                    }
                }
            }
        }
        return ans;
    }
