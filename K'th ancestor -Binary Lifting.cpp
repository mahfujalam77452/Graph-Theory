class TreeAncestor {
public:
    vector<vector<int>> jump;
    int size;
// We can see the anather implementation of Binary Lifing  in LCA part.
    TreeAncestor(int n, vector<int>& parent) {
        size = logb(n) + 1;//
        jump = vector<vector<int>> (n, vector<int> (size, -1));
        for (int i = 0; i < n; i++)
        jump[i][0] = parent[i];
        for (int i = 1; i < size; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (jump[j][i - 1] != -1)
                jump[j][i] = jump[jump[j][i - 1]][i - 1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if (k >= pow(2, size))
        return -1;
        int x = 0;
        while (k)
        {
            if (k & 1)
            {
                node = jump[node][x];
                if (node == -1)
                return -1;
            }
            x++;
            k >>= 1;
        }
        return node;
    }
};
