from collections import deque

class GameGraph:
    def __init__(self):
        self.graph = {}  # Represents the game world as a graph

    def add_edge(self, node1, node2):
        if node1 not in self.graph:
            self.graph[node1] = []
        self.graph[node1].append(node2)

def bfs(graph, start_node, target_node):
    queue = deque([start_node])
    visited = set()

    while queue:
        current_node = queue.popleft()

        if current_node == target_node:
            return True

        visited.add(current_node)

        if current_node in graph:
            for neighbor in graph[current_node]:
                if neighbor not in visited and neighbor not in queue:
                    queue.append(neighbor)

    return False

def is_valid_path(graph, path):
    for i in range(len(path) - 1):
        current_node, next_node = path[i], path[i + 1]
        if next_node not in graph.get(current_node, []):
            return False
    return True

def detect_cheating(graph, start_node, end_node, player_path):
    if not is_valid_path(graph, player_path):
        return "Cheating detected: Invalid path taken."

    if not bfs(graph, start_node, end_node):
        return "Cheating detected: Impossible path taken."

    return "Player is clean: Path is valid."

# Example usage:
game_graph = GameGraph()
game_graph.add_edge("A", "B")
game_graph.add_edge("B", "C")
game_graph.add_edge("C", "D")
game_graph.add_edge("D", "E")
game_graph.add_edge("E", "F")

start_node = "A"
end_node = "F"

result = detect_cheating(game_graph.graph, start_node, end_node)
print(result)
