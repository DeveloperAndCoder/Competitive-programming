#include<iostream>
#include<vector>
#include<utility>
#include<math.h>
#include<stdlib.h>

using namespace std;

struct Edge
{
    int src, dest, weight;
};

struct Graph
{
    int V,E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
   struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph -> V = V;
    graph -> E = E;

    graph -> edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));
    return graph;
};

int find_shortest(Graph* g, int v1, int v2)
{
    int sum1 = 0, sum2 = 0;
    int v = v1;

    while(v != v2)
    {
        sum1 += g->edge[v].weight;
     //   cout << " v = " << v+1 << " edge[v].weight = " << g->edge[v].weight << endl;
        v++;
        v = v%(g->V);
       // cout << v2 << "hi' ";
    }
    while(v != v1)
    {
        sum2 += g->edge[v].weight;
        //cout << " v = " << v+1 << " edge[v].weight = " << g->edge[v].weight << endl;
        v++;
        v = v%(g->V);
    }
    return min(sum1, sum2);
}

int shortest(Graph* g[],int n,int v1,int c1,int v2,int c2, int s[], int dist[])
{
    int v = v1;
    int d1 = find_shortest(g[c1], v1, g[c1]->edge[g[c1]->E-2].src);
    int d2 = find_shortest(g[c1], v1, g[c1]->edge[g[c1]->E-1].src);
   //cout << "d1 = " << d1 << " d2 = " << d2  << " g[c1]->edge[g[c1]->E-2].src = " << g[c1]->edge[g[c1]->E-2].src << "v1 = " << v1 << endl;
    //int c = c1;
    /*while(c != c2)
    {
        if(c != c1)
        d1 += (s[c]+g[c]->edge[g[c]->E-2].weight);
        else
        d1 += g[c]->edge[g[c]->E-2].weight;
        //cout << "d1 = " << d1 << " c = " << c << " s[c] = " << s[c]
             << " g[c]->edge[g[c]->E-2].weight = " << g[c]->edge[g[c]->E-2].weight << endl;
        c++;
        c = c%n;
    }
    */
    if(c1 == 0 && c2 != 0)
    {
        d1 += dist[c2-1];
        d2 += dist[n-1] - dist[c2-1];
        d1 -= s[0];
        d2 -= s[c2];
    }
    else if(c1 != 0 && c2 == 0)
    {
        d2 += dist[c1-1];
        d1 += dist[n-1] - dist[c1-1];
        d2 -= s[0];
        d1 -= s[c1];
    }
    else if(c1 == c2)
    {
        d1 = find_shortest(g[c1], v1, v2);
        return d1;
    }
    else
    {
        if( c2 > c1)
        {
            d1 += abs(dist[c2-1] - dist[c1-1]) - s[c1];
            d2 += dist[n-1] - abs(dist[c2-1]-dist[c1-1]);
            d2 -= s[c2];
        }
        else
        {
            d2 += abs(dist[c2-1] - dist[c1-1]) - s[c2];
            d1 += dist[n-1] - abs(dist[c2-1]-dist[c1-1]);
            d1 -= s[c1];
        }
    //c = c1;
    /*
    while(c != c2)
    {
        if(c != c1)
        d2 += (s[c]+g[c]->edge[g[c]->E-1].weight);
        else
        d2 += g[c]->edge[g[c]->E-1].weight;
      /*  cout << "d2 = " << d2 << " c = " << c << " s[c] = " << s[c]
             << " g[c]->edge[g[c]->E-1].weight = " << g[c]->edge[g[c]->E-1].weight << endl;
        c--;
        if(c == -1)
            c = n-1;
    }
    */
    }
    //cout << "reached\n";
    //cout << "v2 = " << v2 << " g[c2]->edge[g[c2]->E-1].src = " << g[c2]->edge[g[c2]->E-1].src << endl;
    //cout << "2) d1 = " << d1 << " d2 = " << d2 << endl;
    d1 += find_shortest(g[c2], v2, g[c2]->edge[g[c2]->E-1].src);
    d2 += find_shortest(g[c2], v2, g[c2]->edge[g[c2]->E-2].src);
    //cout << "3) d1 = " << d1 << " d2 = " << d2 << endl;
    return min(d1,d2);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, q;
        cin >> n >> q;
        struct Graph* g[n];
        for(int i = 0; i < n; i++)
        {
            //cout << " i = " << i << endl;
            int size_cycle;
            cin >> size_cycle;
            int e[size_cycle];
            g[i] = createGraph(size_cycle, size_cycle+2);
            for(int j = 0; j < size_cycle; j++)
            {
                cin >> e[j];
            }
            //if(size_cycle > 2)
            for(int j = 0; j < size_cycle; j++)
            {
                g[i]->edge[j].src = j;
                g[i]->edge[j].dest = (j+1)%size_cycle;
                g[i]->edge[j].weight = e[j];
                //cout << "j = " << j << " g[i]->edge[j].src = " << g[i]->edge[j].src << " g[i]->edge[j].dest = " << g[i]->edge[j].dest
                //<< " g[i]->edge[j].weight = " << g[i]->edge[j].weight << endl;
            }
            /*
            else
            {
                int m = e[0];
                for(int i = 0; i < size_cycle; i++)
                    m = min(e[i], m);
                g[i]->edge[0].src = 0;
                g[i]->edge[0].dest = 1;
                g[i]->edge[0].weight = m;
                cout << "g[i]->edge[0].src = " << g[i]->edge[0].src << " g[i]->edge[0].dest = " << g[i]->edge[0].dest
                << " g[i]->edge[0].weight = " << g[i]->edge[0].weight << endl;
            }
            */
        }
        //cout << "\nCROSS EDGES\n";
        for(int i = 0; i < n; i++)
        {
            int v1,v2,w;
            cin >> v1 >> v2 >> w;
            g[i]->edge[g[i]->E-2].src = v1-1;
            g[i]->edge[g[i]->E-2].dest = v2-1;
            g[i]->edge[g[i]->E-2].weight = w;
            g[(i+1)%n]->edge[g[(i+1)%n]->E-1].src = v2-1;
            g[(i+1)%n]->edge[g[(i+1)%n]->E-1].dest = v1-1;
            g[(i+1)%n]->edge[g[(i+1)%n]->E-1].weight = w;
            //cout << "i = " << i << " g[i]->V-2 = " << g[i]->E-2 << " g[i]->edge[g[i]->V-2].src = " << g[i]->edge[g[i]->E-2].src << " g[i]->edge[g[i]->E-2].dest = "
            //<<g[i]->edge[g[i]->E-2].dest << " g[i]->edge[g[i]->E-2].weight = " << g[i]->edge[g[i]->E-2].weight << endl;
        }

        int s[n], dist[n];
        for(int i = 0; i < n; i++)
        {
            int v1 = g[i]->edge[g[i]->E-1].src;
            int v2 = g[i]->edge[g[i]->E-2].src;
            //cout << "v1 = " << v1+1 << " v2 = " << v2+1 << endl;
            s[i] = find_shortest(g[i], v1, v2);
            if(i > 0)
            dist[i] = dist[i-1] + s[i] + g[i]->edge[g[i]->E-2].weight;
            else
                dist[i] = s[i] + g[i]->edge[g[i]->E-2].weight;
            //cout << "s[i] = " << i << " " << s[i] << endl;
        }

        while(q--)
        {
            int v1, c1, v2, c2;
            cin >> v1 >> c1 >> v2 >> c2;
            int ans = shortest(g, n, v1-1, c1-1, v2-1, c2-1, s, dist);
            cout << ans << endl;
        }
    }
    return 0;
}

/*
Example.
1
4 4
3 1 1 1
3 1 1 1
3 1 1 1
3 1 1 1
2 3 1
2 1 1
3 2 1
1 2 1
1 2 3 4
*/
