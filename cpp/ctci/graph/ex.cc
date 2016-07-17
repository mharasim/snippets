class Graph {
public:
	Graph(size_t size)
		:	adj_(size)
	{}

	std::vector<size_t> get_adj(size_t v) 
	{
		return adj_[v];
	}

	size_t vert_count()
	{ 
		return adj_.size(); 
	}

private:
	std::vector<std::vector<size_t>> adj_;
};

class enum Color { White, Gray, Black };

std::vector<int> bfs(Graph g, size_t v)
{
	std::vector<Color> color(g.vert_count(), Color::White);
	std::vector<int> parent(g.vert_count(), -1);
	std::queue<size_t> verts;
	
	color[v] = Color::Gray;
	parent[v] = -1;
	verts.enqueue(v);

	while (!verts.empty()) {
		size_t u = verts.dequeue();
		std::vector<size_t> adj = g.get_adj(u);
		for (auto n = adj.begin(), n != adj.end(), ++n) {
			if (color[*n] == Color::White) {
				color[*n] = Color::Gray;
				parent[*n] = u;
				verts.enqueue(*n);
			}
		}
		color[u] = Color::Black;
	}
	return parent;
}

bool IsPath(Graph g, size_t v, size_t dst)
{
	std::vector<Color> color(g.vert_count(), Color::White);
	std::vector<int> parent(g.vert_count(), -1);
	std::queue<size_t> verts;
	
	color[v] = Color::Gray;
	parent[v] = -1;
	verts.enqueue(v);

	while (!verts.empty()) {
		size_t u = verts.dequeue();
		std::vector<size_t> adj = g.get_adj(u);
		for (auto n = adj.begin(), n != adj.end(), ++n) {
			if (color[*n] == Color::White) {
				if (*n == *dst) 
					return true;
				color[*n] = Color::Gray;
				parent[*n] = u;
				verts.enqueue(*n);
			}
		}
		color[u] = Color::Black;
	}
	return false;
}

