

// jaha pr hame groups bante hote h , jab ham group bnate h to groups ko sets kahte h 

// how many sets 
// properties of groups

// DSU helps in grouping   

 // functions 

 //1. make function => makes independent node  ..{find(x) = x}
 //2. find function => find(a) => gives the root of a { parent of the group}
 //3. union function  => union(a , b) => {agr a, b same group me nhi h to unhe same group me dal do} => connect a to b or b to a 
 
 // ham directly nodes ko nhi add krte h , ham nodes a group ka jo root hota h unhe jodte h 

//  optimization are also there in these 

vector<int>parent(n , -1); 

void make(int node)
{
  parent[node] = node ; // makes node independent
}

int find(int node)
{
    if(node == parent[node]) return node ;

    return find(parent[node]);
}

void Union(int x ,int y)
{
   int a = find(x);
   int  b = find(y); 

   // bcoz ham hamesha roots ko connect karte hai

   if(a !=b ) // dono ek hi grp me nahi hai
   {
     parent[b] = a ;

    //  or 

    parent[a] = b ; 

    // we always try to connect small tree in bigger tree , 
    // kyuki when we add bigger tree in smaller tree, to tree ki length badh jayegi aur find operation will take time {optimize by size}

    // optimize by rank :- rank means depth

    // both have same TC.
   }

}

// path compression :- to optimize the find operation :- ham har ek node ka parent directly unke group k parent ko assign kar dete hai

// optimization by size (union function)

// here we make a size array to store the size of each group 

vector<int>size(n , -1 ) ;


void make(int node)
{
    parent[node] = node ;
    size[node] = 1 ; // currently its alone in its group
}

int find(int node)
{
    if(parent[node ] == node) return node ; 

    return parent[node] = find(parent[node]); // path compression 
}

void Union(int x , int y )
{
    int a = parent[x] ; 
    int b = parent[y] ;

    if(size[a] > size[b])
    {
        parent[b] = a ; 
        size[b] += a ;
    }
}



