#ifndef GRAPH_CPP
#define GRAPH_CPP

#include "Graph.hpp"
#include "GraphNode.hpp"
#include <queue>
#include <exception>

template<typename T>
void Graph<T>::DFS_visit(T &u, int &time, std::list<T> &record)
{
	_vertices.at(u).color = Black;
	time++;
	_vertices.at(u).discovery_time = time;
	for (T neighbor : _adjList.at(u))
	{
		if (_vertices.at(neighbor).color == White)
		{
			_vertices.at(neighbor).predecessor = u;
			DFS_visit(neighbor, time, record);
		}
	}
	time++;
	_vertices.at(u).finish_time = time;
	record.push_front(u);
}

template<typename T>
Graph<T>::Graph(const std::vector<std::pair<T,T>> &edges)
{
	for (std::pair<T,T> edge : edges)
	{
		addEdge(edge.first, edge.second);
	}
}

template<typename T>
Graph<T>::Graph(const std::map<T, std::set<T>> &adjList) : _adjList(adjList)
{
	for (std::pair<T, std::set<T>> vertex_adj_pair : _adjList)
	{
		// Note: using addVertex() will purge the adjList
		_vertices[vertex_adj_pair.first] = GraphNode<T>(vertex_adj_pair.first);
	}
}

template<typename T>
int Graph<T>::size() const
{
	return _vertices.size();
}

template<typename T>
void Graph<T>::addVertex(T vertex)
{
	if (_vertices.find(vertex) != _vertices.end())
		return;
	_vertices[vertex] = GraphNode<T>(vertex);
	_adjList[vertex] = std::set<T>();
}

template<typename T>
void Graph<T>::addEdge(T from, T to)
{
	if (_vertices.find(from) == _vertices.end())
		addVertex(from);
	if (_vertices.find(to) == _vertices.end())
		addVertex(to);

	_adjList.at(from).insert(to);
}

template<typename T>
bool Graph<T>::hasEdge(T from, T to) const
{
	if (_vertices.find(from) == _vertices.end() || _vertices.find(to) == _vertices.end())
		return false;

	return _adjList.at(from).find(to) != _adjList.at(from).end();
}

template<typename T>
std::optional<std::set<T>> Graph<T>::getNeighbors(T vertex) const
{
	if (_vertices.find(vertex) == _vertices.end())
		return std::nullopt;
	return _adjList.at(vertex);
}

template<typename T>
std::vector<T> Graph<T>::BFS(T start)
{
	if (_vertices.find(start) == _vertices.end())
		throw std::domain_error("Vertex does not exist in graph, aborted");

	// reset graph node attributes
	for (std::pair<const T, GraphNode<T>> &val_node_pair : _vertices)
	{
		val_node_pair.second.color = White;
		val_node_pair.second.distance = -1;
		val_node_pair.second.predecessor = std::nullopt;
	}
	_vertices.at(start).distance = 0;
	_vertices.at(start).color = Black;
	
	std::vector<T> output;
	// BFS
	std::queue<T> visiting;
	visiting.push(start);
	while (!visiting.empty())
	{
		T current_visit = visiting.front();
		output.push_back(current_visit);
		visiting.pop();
		for (T neighbor : _adjList.at(current_visit))
		{
			if (_vertices.at(neighbor).color != White)		// !White := visited
				continue;
			_vertices.at(neighbor).color = Black;
			_vertices.at(neighbor).predecessor = current_visit;
			_vertices.at(neighbor).distance = 1 + _vertices.at(current_visit).distance;
			visiting.push(neighbor);
		}
	}
	return output;
}

template<typename T>
int Graph<T>::shortestPath(T start, T end, bool runBFS)
{
	if (_vertices.find(start) == _vertices.end() || _vertices.find(end) == _vertices.end())
		throw std::domain_error("start or end does not exist in graph");

	if (!runBFS)
		return _vertices.at(end).distance;

	BFS(start);
	return _vertices.at(end).distance;
}

template<typename T>
std::list<T> Graph<T>::DFS()
{
	// reset graph node attributes
	for (std::pair<const T, GraphNode<T>> &val_node_pair : _vertices)
	{
		val_node_pair.second = GraphNode<T>(val_node_pair.first);
		val_node_pair.second.color = White;
		val_node_pair.second.discovery_time = -1;
		val_node_pair.second.finish_time = -1;
		val_node_pair.second.predecessor = std::nullopt;
	}
	int time = 0;

	std::list<T> output;
	for (std::pair<T, GraphNode<T>> val_node_pair : _vertices)
	{
		if (val_node_pair.second.color == White)
			DFS_visit(val_node_pair.first, time, output);
	}
	return output;
}

#endif // GRAPH_CPP
