#implementation of a DFS algorithm using recursion for tracking the graph
# made of an adjacency list

graph = {
    'B' : ['D','E'],
    'D' : ['F', 'A'],
    'E' : ['C'],
    'F' : [],
    'A' : ['C'],
    'C' : []
}
visited = set() # set to keep track of which nodes already been visited

def dfs(visited, graph, node):
    if node not in visited:
        print(f'Visitting node {node}')
        visited.add(node)
        for neighbor in graph[node]:
            dfs(visited, graph, neighbor)

if __name__ == "__main__":
    dfs(visited, graph, 'B')