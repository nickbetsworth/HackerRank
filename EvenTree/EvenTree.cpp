#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>

typedef int Node;
typedef std::unordered_multimap<Node, Node> EdgeMap;
typedef std::vector<EdgeMap::value_type> EdgeList;

// Gathers the list of all accessible edges from the root node (sub-graph)
EdgeList get_edge_list(const Node root, const EdgeMap& edge_map) {
	EdgeList edge_list;
	// Map that stores the nodes which we have visited
	std::unordered_map<Node, bool> visited;

	// Stores the nodes that we must visit
	std::queue<Node> nodes_to_visit;
	nodes_to_visit.push(root);

	while (!nodes_to_visit.empty()) {
		Node node = nodes_to_visit.front();
		nodes_to_visit.pop();
		visited[node] = true;

		// Get the iterator range for the current node's adjacency list
		auto range = edge_map.equal_range(node);
		for (auto it = range.first; it != range.second; ++it) {
			Node neighbour = it->second;

			// If we have not visited this node yet
			if (!visited[neighbour]) {
				edge_list.push_back(*it);
				nodes_to_visit.push(neighbour);
			}
		}
	}

	return edge_list;
}

// Counts the number of nodes accessible from the given starting point (root)
int count_nodes(const Node root, const EdgeMap& edge_map) {
	// Return the number of edges in the graph + 1 vertex (always holds true for a tree)
	return get_edge_list(root, edge_map).size() + 1;
}

// Removes the given edge from the edge map provided
void remove_edge(EdgeMap::value_type edge, EdgeMap& edge_map) {
	// Remove the edge in both directions
	auto range = edge_map.equal_range(edge.first);
	for (auto it = range.first; it != range.second; ++it) {
		if (it->second == edge.second) {
			edge_map.erase(it);
			break;
		}	
	}

	range = edge_map.equal_range(edge.second);
	for (auto it = range.first; it != range.second; ++it) {
		if (it->second == edge.first) {
			edge_map.erase(it);
			break;
		}
			
	}
}

// Calculates the final result;
// the maximum number of edges that can be removed from the original
// graph, such that each sub-graph contains an even number of vertices.
void split_graph(const Node root, EdgeList& edges, EdgeMap& edge_map) {
	for (auto edge : edges) {
		// Attempt to remove this edge from the map, and check if there are
		// an even number of nodes in each sub-graph
		remove_edge(edge, edge_map);

		std::vector<EdgeMap::value_type> edges_a = get_edge_list(edge.first, edge_map);
		std::vector<EdgeMap::value_type> edges_b = get_edge_list(edge.second, edge_map);

		// The number of nodes in a tree is always the number of edges + 1
		int nodes_a = edges_a.size() + 1;
		int nodes_b = edges_b.size() + 1;

		// If both sub-trees/graphs have an even number of nodes
		if ((nodes_a % 2 == 0) && (nodes_b % 2 == 0)) {
			// Recursively call the split on the sub-graphs
			split_graph(edge.first, edges_a, edge_map);
			split_graph(edge.second, edges_b, edge_map);
			// Break out, as the recursive call would have explored this graph again
			break;
		}
		// Otherwise, return the edge back in to the graph
		else {
			edge_map.insert({ edge.first, edge.second });
			edge_map.insert({ edge.second, edge.first });
		}

	}
}

// Main function to calculate the result
int get_num_even_tree_edges(const Node root, EdgeMap& edge_map) {
	// Store the number of edges in graph before splitting takes place
	int original_edge_count = edge_map.size();
	// Generate a list of all edges within this sub-graph
	EdgeList edges = get_edge_list(root, edge_map);
	split_graph(root, edges, edge_map);
	
	int final_edge_count = edge_map.size();

	// Divide by 2 as we present each undirected edge, as 2 directed edges
	int result = (original_edge_count - final_edge_count) / 2;

	return result;
}

int main() {
	int num_vertices, num_edges;

	std::cin >> num_vertices >> num_edges;

	EdgeMap edge_map;
	Node v1, v2;
	for (int i = 0; i < num_edges; i++) {
		// Read in the pair of vertices that form the edge
		std::cin >> v1 >> v2;
		// Add the edge in both directions (as the graph is undirected)
		edge_map.insert({ { v1, v2 }, { v2, v1 } });
	}

	std::cout << get_num_even_tree_edges(1, edge_map);
	std::cin >> v1;
}