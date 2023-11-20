class GameGraph:
    def __init__(self):
        self.graph = {}  # Represents the game world as a graph

    def add_edge(self, node1, node2):
        if node1 not in self.graph:
            self.graph[node1] = []
        self.graph[node1].append(node2)

def iddfs(graph, start_node, target_node, max_depth):
    for depth in range(max_depth + 1):
        visited = set()
        if dls(graph, start_node, target_node, depth, visited):
            return True
    return False

def dls(graph, current_node, target_node, depth, visited):
    if depth == 0 and current_node == target_node:
        return True

    if depth > 0:
        visited.add(current_node)

        if current_node in graph:
            for neighbor in graph[current_node]:
                if neighbor not in visited:
                    if dls(graph, neighbor, target_node, depth - 1, visited):
                        return True

    return False

def detect_cheating(graph, start_node, end_node, player_path):
    max_depth = len(player_path)  # Adjust the maximum depth based on the length of the player's path
    if not iddfs(graph, start_node, end_node, max_depth):
        return "Cheating detected: Impossible path taken."

    return "Player is clean: Path is valid."

# Example usage:
game_graph = GameGraph()
game_graph.add_edge("A", "B")
game_graph.add_edge("B", "C")
game_graph.add_edge("C", "F")
game_graph.add_edge("E", "F")


start_node = "A"
end_node = "F"
player_path = ["A", "B", "C", "D", "E", "F"]

result = detect_cheating(game_graph.graph, start_node, end_node, player_path)
print(result)
