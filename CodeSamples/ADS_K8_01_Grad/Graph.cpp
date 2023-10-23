#include "Graph.h"

Graph::Graph(std::string fname)
{
	std::ifstream infile(fname);
	int tmp_e = 0;
	infile >> this->V >> tmp_e;

	this->E = 0;

	this->adj.resize(this->V, std::vector<int>());

	int v, w;
	while (infile >> v >> w)
	{
		this->addEdge(v, w);
	}

	assert(("Missing edges!", tmp_e == this->E));
}

int Graph::getV() const { return this->V; }
int Graph::getE() const { return this->E; }

void Graph::addEdge(int v, int w)
{
	this->validateVertexWithError(v);
	this->validateVertexWithError(w);

	if (Utils::contains(this->adj[v], w)) return;

	this->E++;
	this->adj[v].push_back(w);
	this->adj[w].push_back(v);
}

bool Graph::removeEdge(int v, int w)
{
	if (this->validateVertex(v) && this->validateVertex(w))
	{
		if (Utils::remove(this->adj[v], w)) {
			Utils::remove(this->adj[w], v);
			return true;
		}
	}
	return false;
}

int Graph::degree(int v)
{
	this->validateVertexWithError(v);
	return this->adj[v].size();
}

const std::vector<int> Graph::operator[](int v) const
{
	this->validateVertexWithError(v);
	return this->adj[v];
}

bool Graph::validateVertex(int v) const
{
	return v >= 0 && v < this->V;
}

void Graph::validateVertexWithError(int v) const
{
	assert(("Vertex is out of bounds!", this->validateVertex(v)));
}

std::ostream& operator<<(std::ostream& stream, const Graph& graph)
{
	stream << graph.V << " vertecies and " << graph.E << " edges:" << std::endl;
	for (int v = 0; v < graph.V; v++)
	{
		stream << v << ": ";
		for (int w = 0; w < graph[v].size(); w++)
		{
			stream << graph[v][w] << " ";
		}
		stream << std::endl;
	}
	return stream;
}