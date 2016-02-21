#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <map>

//https://www.hackerrank.com/contests/101hack34/challenges/beautiful-path

#define LARGE_POS 2147483645

int get_minimum_cost(int* edges, int num_nodes, int start_node, int end_node)
{
	std::vector<int> visit_queue(num_nodes);

	std::vector<int> dist(num_nodes);
	std::vector<int> prev(num_nodes);

	for (int i = 0; i < num_nodes; i++)
	{
		dist[i] = LARGE_POS;
		prev[i] = -1;

		visit_queue[i] = i;
	}

	dist[start_node] = 0;

	while (visit_queue.empty() == false)
	{
		auto min_node = visit_queue.begin();
		int min_dist = dist[*min_node];
		for (auto it = visit_queue.begin() + 1; it != visit_queue.end(); ++it)
		{
			if (dist[*it] < min_dist)
			{
				min_node = it;
				min_dist = dist[*it];
			}
		}

		int min_node_id = *min_node;
		// Early termination, we have already reached the destination node.
		if (*min_node == end_node)
			break;

		visit_queue.erase(min_node);

		for (auto v : visit_queue)
		{
			int edge = edges[min_node_id + num_nodes * v];

			if (edge != -1)
			{
				int alt = min_dist | edge;
				if (alt < dist[v])
				{
					dist[v] = alt;
					prev[v] = min_node_id;
				}
			}
		}
	}

	if (dist[end_node] == LARGE_POS)
	{
		return -1;
	}
	else
	{
		return dist[end_node];
	}
}

int main()
{
	int num_nodes, num_edges;
	std::cin >> num_nodes >> num_edges;

	int* edges = new int[num_nodes * num_nodes]{-1};
	for (int i = 0; i < num_nodes; i++)
	{
		for (int j = 0; j < num_nodes; j++)
		{
			edges[i + j * num_nodes] = -1;
		}
	}

	int u, v, c;
	for (int i = 0; i < num_edges; i++)
	{
		std::cin >> u >> v >> c;
		u--; v--;
		int existing_val = edges[u + v * num_nodes];
		if (existing_val != -1)
		{
			if (c >= existing_val)
				continue;
		}

		edges[u + v * num_nodes] = c;
		edges[v + u * num_nodes] = c;
	}

	int start_node, end_node;
	std::cin >> start_node >> end_node;

	std::cout << get_minimum_cost(edges, num_nodes, start_node-1, end_node-1);

	delete[] edges;

	return 0;
}