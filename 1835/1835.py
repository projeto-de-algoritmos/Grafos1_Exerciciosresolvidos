
class Graph:

    def __init__(self, vertices):
        self.V = vertices
        self.adj = [[] for i in range(vertices)]

    def addEdge(self, u, v):
        self.adj[u].append(v)
        self.adj[v].append(u)

    def DFS(self, v, visited):
        visited[v] = True
        for i in self.adj[v]:
            if visited[i] == False:
                self.DFS(i, visited)
            

    def connectedComponents(self):
        visited = [False] * (self.V)
        cc = 0
        for v in range(self.V):
            if visited[v] == False:
                cc += 1
                self.DFS(v, visited)
        return cc


if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        x = input()
        if(' ' not in x):
            m = int(input())
            n = int(x)
        else:
            n,m = x.split()
        g = Graph(int(n))
        for j in range(int(m)):
            x,y = map(int, input().split())
            g.addEdge(x-1, y-1)
        CC = g.connectedComponents()
        if(CC == 1):
            print("Caso #{}: a promessa foi cumprida".format(i+1))
        else:
            print("Caso #{}: ainda falta(m) {} estrada(s)".format(i+1, CC-1))   
    
