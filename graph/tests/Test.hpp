#ifndef TESTINGLIB_CPP
#define TESTINGLIB_CPP 

#include <gtest/gtest.h>
#include "Graph.cpp"
#include <string>
#include <sstream>

template<typename T>
void checkGraphAttributes(Graph<T> graph, std::map<T, std::set<T>> adjList, std::string err="")
{
	if (err != "")
		err.push_back('\n');
	for (auto vertex_adj_pair : adjList)
	{
		EXPECT_EQ(graph.getNeighbors(vertex_adj_pair.first),
				vertex_adj_pair.second) << err << "Adjacency list mismatch";
	}
	ASSERT_EQ(graph.size(), adjList.size()) << err << "Size mismatch";
}


#endif /* ifndef TESTINGLIB_CPP */
