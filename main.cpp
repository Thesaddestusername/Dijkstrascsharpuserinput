    #include <cstdio>
    #include <queue>
    #include <vector>
    #include <iostream>
    using namespace std;
    #define MAX 100000
    #define INF (1<<20)
    #define dub pair <int, int>
    #define pb(x) push_back(x)
    struct comp
    {
            bool operator()(const dub &a, const dub &b)
            {
                return a.second > b.second;
            }
    };
    priority_queue<dub, vector<dub > , comp> Q;
    vector<dub > G[MAX];
    int Y[MAX];
    bool X[MAX];
    int main()
    {
        int temp, a, b, c, d, start, node, edge;
        cout << "Enter the number of vertices and edges ";
        cin >> node >> edge;
        cout << "Enter the edges with weigh (source endpoint weight) \n";
        for (temp = 0; temp < edge; temp++)
        {
            cin >> a >> b >> c;
            G[a].pb(dub(b, c));
            G[b].pb(dub(a, c));
        }
        cout << "Enter the source spot ";
        cin >> start;
        for (temp = 1; temp <= node; temp++)
            Y[temp] = INF;
        Y[start] = 0;
        Q.push(dub(start, 0));
        while (!Q.empty())
        {
            a = Q.top().first;
            Q.pop();
            if (X[a])
                continue;
            d = G[a].size();
            for (temp = 0; temp < d; temp++)
            {
                b = G[a][temp].first;
                c = G[a][temp].second;
                if (!X[b] && Y[a] + c < Y[b])
                {
                    Y[b] = Y[a] + c;
                    Q.push(dub(b, Y[b]));
                }
            }
            X[a] = 1;
        }
        for (temp = 1; temp <= node; temp++)
        {
            cout << "Node " << temp << ", minimum weight = " << Y[temp] << endl;
        }
        return 0;
    }
