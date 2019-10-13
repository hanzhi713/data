import networkx as nx
import random

number_of_nodes = 20
connected_probability = 0.5

graph = nx.Graph()

graph.add_nodes_from([i for i in range(number_of_nodes)])

f1 = open('dijkstra_in', 'w')
f2 = open('dijkstra_ans', 'w')

f1.write(f'{number_of_nodes}\n')

# construct the graph

for i in range(0, number_of_nodes):
    for j in range(i + 1, number_of_nodes):
        r = random.random()
        if(r <= connected_probability):
            graph.add_edge(i, j)

# adjacency list

for node, l in graph.adjacency():
    f1.write(f'{len(l)} ')
    for n in l:
        f1.write(f'{n} ')
    f1.write('\n')

bfs = nx.bfs_edges(graph, 0)

# expected result

for i in bfs:
    f2.write(f'{i}\n')
