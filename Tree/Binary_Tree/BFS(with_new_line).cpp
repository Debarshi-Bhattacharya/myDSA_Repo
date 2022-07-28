//BFS traversal(with'\n')_technique1
void BFS(node *root)
{
    int prev_level=0;
    queue<pair<node*,int>>q;//making pair of nodes and their level
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        node* f=q.front().first;
        int curr_level=q.front().second;
        if(prev_level<curr_level)//if level of current node is greater than previous we add new line
        {
            cout<<"\n"<<f->data<<" ";
            prev_level=curr_level;//and previous level changes to current one
        }
        else
            cout<<f->data<<" ";//if current level is same as prev then keep printing nodes
        q.pop();
        if(f->left)
            q.push(make_pair(f->left,curr_level+1));
        if(f->right)
            q.push(make_pair(f->right,curr_level+1));
    }
    return;
}

//BFS traversal(with'\n')_technique2
void BFS2(node* root)
{
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* f=q.front();
        if(f==NULL)
        {
            cout<<endl;
            q.pop();
            if(!q.empty())//if queue is not empty then the elements present inside queue will be of same level,so we push a null after them
                q.push(NULL);
        }
        else
        {
            cout<<f->data<<" ";
            q.pop();
        if(f->left)
            q.push(f->left);
        if(f->right)
            q.push(f->right);
        }
    }
    return;
}