import matplotlib.pyplot as plt
from pymazegui import maze, agent, COLOR, textLabel
from queue import PriorityQueue as MinHeap

# Manhattan Distance
def dist(cell1, cell2):
    x1, y1 = cell1
    x2, y2 = cell2
    return abs(x1 - x2) + abs(y1 - y2)

# A* Algorithm Implementation
def astar(m, start=None):
    if start is None:
        start = (m.rows, m.cols)
    
    # Priority queue for open set (MinHeap for better clarity)
    open_set = MinHeap()
    open_set.put((dist(start, m._goal), dist(start, m._goal), start))

    # Dictionary to store paths from the start
    path_from_start = {}

    # Dictionary for g scores (cost from start to current cell)
    g = {row: float("inf") for row in m.grid}
    g[start] = 0

    # Dictionary for f scores (total cost from start to goal through current cell)
    f = {row: float("inf") for row in m.grid}
    f[start] = dist(start, m._goal)

    # List to store the cells visited during the search
    search_path = [start]

    while not open_set.empty():
        # Current cell
        c = open_set.get()[2]
        search_path.append(c)

        # Break if goal is reached
        if c == m._goal:
            break

        for d in 'ESNW':
            # Neighbor cell based on the direction
            if m.maze_map[c][d] == True:
                if d == 'E':
                    nc = (c[0], c[1] + 1)
                elif d == 'W':
                    nc = (c[0], c[1] - 1)
                elif d == 'N':
                    nc = (c[0] - 1, c[1])
                elif d == 'S':
                    nc = (c[0] + 1, c[1])

                # Calculate tentative g score and f score
                tg = g[c] + 1
                tf = tg + dist(nc, m._goal)

                # Update if the new scores are better
                if tf < f[nc]:
                    path_from_start[nc] = c
                    g[nc] = tg
                    f[nc] = tf
                    open_set.put((f[nc], dist(nc, m._goal), nc))

    # Dictionary to store the forward path from goal to start
    fwd_path = {}
    cell = m._goal

    while cell != start:
        fwd_path[path_from_start[cell]] = cell
        cell = path_from_start[cell]

    return search_path, path_from_start, fwd_path

# Function to visualize the heuristic graph
def visualize_heuristic(search_path, m):
    heuristic_values = [dist(cell, m._goal) for cell in search_path]
    search_lengths = list(range(len(search_path)))

    plt.plot(search_lengths, heuristic_values, label='Heuristic Values')
    plt.xlabel('Search Length')
    plt.ylabel('Heuristic Value')
    plt.title('Heuristic Value with Respect to Search Length')

    # Calculate and display total search path length, final path length, and efficiency
    total_search_path_length = len(search_path) - 2  # subtracting 1 for the start cell
    final_path_length = len(fwd_path)  # subtracting 2 for start and goal cells
    efficiency = final_path_length / total_search_path_length * 100

    info_text = f'Total Search Path Length: {total_search_path_length}\nFinal Path Length: {final_path_length}\nEfficiency: {efficiency:.2f}%'
    plt.text(0.5, -0.1, info_text, ha='center', va='center', transform=plt.gca().transAxes, bbox=dict(facecolor='white', alpha=0.5))

    plt.legend()
    plt.show()


if __name__ == '__main__':
    # Maze
    m = maze(20, 27)
    m.CreateMaze(1, 3, loopPercent=85)

    # Find paths using A* search
    search_path, path_from_start, fwd_path = astar(m, (19, 23))

    # Calculating efficiency metrics
    forward_path_length = len(fwd_path)
    search_path_length = len(search_path) - 2  # subtracting 2 for start and goal cells
    efficiency = forward_path_length / search_path_length * 100
    # Print information
    print(f"Forward Path Length: {forward_path_length}")
    print(f"Search Path Length: {search_path_length}")
    print(f"Efficiency: {efficiency:.3f}%")

    # Visualize the heuristic graph
    visualize_heuristic(search_path, m)
    
