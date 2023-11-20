import networkx as nx
import matplotlib.pyplot as plt

class GameGraph:
    def __init__(self):
        self.graph = nx.Graph()

    def add_edge(self, node1, node2):
        self.graph.add_edge(node1, node2)

def visualize_game_graph(graph):
    pos = nx.spring_layout(graph)
    nx.draw(graph, pos, with_labels=True, font_weight='bold', node_size=700, node_color='skyblue', font_color='black')
    plt.show()

def visualize_player_path(graph, player_path):
    pos = nx.spring_layout(graph)
    nx.draw(graph, pos, with_labels=True, font_weight='bold', node_size=700, node_color='skyblue', font_color='black')
    
    edges = [(player_path[i], player_path[i+1]) for i in range(len(player_path)-1)]
    nx.draw_networkx_edges(graph, pos, edgelist=edges, edge_color='red', width=2)

    plt.show()

# Example usage:
game_graph = GameGraph()
game_graph.add_edge("A", "B")
game_graph.add_edge("B", "C")
game_graph.add_edge("C", "D")
game_graph.add_edge("D", "E")
game_graph.add_edge("E", "F")

start_node = "A"
end_node = "F"
player_path = ["A", "B", "C", "D", "E", "F"]

# Visualize the game graph
visualize_game_graph(game_graph.graph)

# Visualize the player's path on the game graph
visualize_player_path(game_graph.graph, player_path)
