#include <iostream>
#include <queue>
#include <fstream>
#define MAX 10
using namespace std;
struct graphnode
{
    int vertex;
    int time;
    int cost;
    graphnode *next;
};
class graph
{
    graphnode *head[MAX];
    int n;
    string city[MAX];

public:
    graph()
    {
        for (int i = 0; i < MAX; i++)
            head[i] = NULL;
    }
    int readgraph();
    void setedge(int u, int v, int ftime, int fcost);
    void displaygraph();
    void displaycity();
    void flightexists(int u, int v);
    void connectedcomp();
    void bfs(int v);
    void dfs(int v, int varr[]);
};
int graph::readgraph()
{
    ifstream f("ass8.dat");
    f >> n;
    for (int i = 0; i < n; i++)
    {
        head[i] = new graphnode;
        head[i]->next = NULL;
    }
    string cityname;
    for (int i = 0; i < n; i++)
    {
        f >> cityname;
        city[i] = cityname;
    }
    int u, v, ftime, fcost;
    while (f)
    {
        f >> u;
        f >> v;
        f >> ftime;
        f >> fcost;
        setedge(u, v, ftime, fcost);
        setedge(v, u, ftime, fcost);
    }
    cout << "Graph Successfully Created" << endl;
    return n;
}
void graph::setedge(int u, int v, int ftime, int fcost)
{
    graphnode *curr, *temp;
    curr = new graphnode;
    curr->vertex = u;
    curr->time = ftime;
    curr->cost = fcost;
    curr->next = NULL;
    temp = head[v];
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = curr;
}
void graph::displaygraph()
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << " : " << city[i];
        graphnode *temp = head[i]->next;
        while (temp->next != NULL)
        {

            cout << " -> " << city[temp->vertex] << " : " << temp->time << " hr : $" << temp->cost;
            temp = temp->next;
        }
        cout << " -> " << city[temp->vertex] << " : " << temp->time << " hr : $" << temp->cost;
        cout << endl;
    }
}
void graph::displaycity()
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << " : " << city[i] << endl;
    }
    cout << endl;
}
void graph::flightexists(int u, int v)
{
    graphnode *temp = head[u]->next;
    while (temp != NULL)
    {
        if (temp->vertex == v)
        {
            cout << "Flight exists between the given cities" << endl;
            cout << "Time : " << temp->time << " hr" << endl;
            cout << "Cost : $" << temp->cost << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Flight does not exist between the given cities" << endl;
    return;
}
void graph::bfs(int v)
{
    int x;
    int varr[n];
    for (int i = 0; i < n; i++)
    {
        varr[i] = 0;
    }
    queue<int> Q;
    Q.push(v);
    varr[v] = 1;
    while (!Q.empty())
    {
        x = Q.front();
        Q.pop();
        cout << " -> " << city[x];
        for (graphnode *i = head[x]->next; i != NULL; i = i->next)
        {
            if (!varr[i->vertex])
            {
                varr[i->vertex] = 1;
                Q.push(i->vertex);
            }
        }
    }
    cout << endl;
}
void graph::dfs(int v, int varr[])
{
    varr[v] = 1;
    cout << " -> " << city[v];
    for (graphnode *i = head[v]->next; i != NULL; i = i->next)
    {
        if (!varr[i->vertex])
            dfs(i->vertex, varr);
    }
}
void menu()
{
    cout << endl;
    cout << "*** FLIGHT MANAGEMENT ***" << endl;
    cout << "1. Read Graph" << endl;
    cout << "2. Display Graph" << endl;
    cout << "3. Check if flight exists or not" << endl;
    cout << "4. BFS" << endl;
    cout << "5. DFS" << endl;
    cout << "6. Exit" << endl;
    cout << endl;
}
int main()
{
    graph g;
    int nv;
    int choice;
    do
    {
        menu();
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            nv = g.readgraph();
            break;
        }
        case 2:
        {
            g.displaygraph();
            break;
        }
        case 3:
        {
            int u, v;
            g.displaycity();
            cout << "Enter the first city index : ";
            cin >> u;
            cout << "Enter the second city index : ";
            cin >> v;
            g.flightexists(u, v);
            cout << endl;
            break;
        }
        case 4:
        {
            g.displaycity();
            int startvertex;
            cout << "Enter the starting vertex : ";
            cin >> startvertex;
            cout << endl;
            cout << "BFS";
            g.bfs(startvertex);
            break;
        }
        case 5:
        {
            g.displaycity();
            int startvertex;
            cout << "Enter the starting vertex : ";
            cin >> startvertex;
            cout << endl;
            cout << "DFS";
            int varr[nv];
            for (int i = 0; i < nv; i++)
            {
                varr[i] = 0;
            }
            g.dfs(startvertex, varr);
            cout << endl;
            break;
        }
        }
    } while (choice < 6);
    cout << "Exited" << endl;
    return 0;
}