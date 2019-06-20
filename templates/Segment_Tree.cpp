//
// Created by User on 19-May-19.
const int maxn = 1e5+7;
int A[maxn];
int tree[4*maxn];
int lazy[4*maxn];

void build(int node, int start, int end) {
    if(start == end)
        tree[node] = A[start];
    else{
        int mid = (start + end)/2;
        //recurse left
        build(2*node,start,mid);
        //recurse right
        build(2*node+1, mid+1, end);

        //use --> array sum
        tree[node] = tree[2*node] + tree[2*node+1];
        //use --> array min
        //tree[node] = min(tree[2*node],tree[2*node+1]);
    }
}

int query(int node, int start, int end, int l, int r){
    if (r < start || end < l)
        return 0; // out of range
        // return INT_MAX -- for min
    if(start >= l && end <= r)
        return tree[node]; //  inside
    int mid = (start + end)/2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);

    // use --> sum
    return (p1 + p2);
    //use -- min
    // return min(p1,p2);

}

void update(int node, int start, int end , int indx, int val){
    if (start == end)
    {
        A[indx] += val;
        tree[node] += val;
        return;
    }
    int mid = (start + end)/2;
    if(indx >= start && indx <= mid) {
        //indx in left
        update(2*node, start, mid, indx,val);
    }
    else
        //right
        update(2*node+1, mid+1, end , indx, val );
    //use ---
    tree[node] =  tree[2*node] + tree[2*node+1];
}
void range_update(int node ,int left , int right ,int lq ,int rq)
{
    if( lazy[node] )
    {
        tree[node] += (right-left+1)*lazy[node];
        if(left != right)
        {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(left > rq || right < lq)
        return ;
    if(left >= lq && right <= rq)
    {
        tree[node] += (right - left + 1);
        if(left != right)
        {
            lazy[2*node] += 1;
            lazy[2*node+1] += 1;
        }
        lazy[node] = 0;
        return ;
    }
    int mid = (left+right)/2;
    range_update(2*node,left,mid,lq,rq);
    range_update(2*node+1,mid+1,right,lq,rq);
    tree[node] = tree[2*node] + tree[2*node+1];
}
int point_query(int node ,int left ,int right ,int id)
{
    if( lazy[node] )
    {
        tree[node] += (right-left+1)*lazy[node];
        if(left != right)
        {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(id > right || id < left)
        return 0;
    if( left >= id && right <= id)
        return tree[node];
    int mid =(left+right)/2;
    return point_query(2*node ,left ,mid ,id)+point_query(2*node+1,mid+1,right ,id);
}