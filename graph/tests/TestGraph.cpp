#include "Test.hpp"

typedef std::map<int, std::set<int>> IntAdjList;

class GraphTestF : public ::testing::Test
{
protected:
	void SetUp() override
	{
		adjList1[0] = {1,4,2};	// island 1
		adjList1[1] = {3};
		adjList1[2] = {3,4};
		adjList1[3] = {0};
		adjList1[4] = {};
		adjList1[5] = {};		// disconnected node
		graph1 = Graph<int>(adjList1);
	}
	IntAdjList adjList1;
	Graph<int> graph1;
};

TEST(GraphTest, InstantiateEmptyGraph)
{
    Graph<int> g;
	IntAdjList adjList;
	checkGraphAttributes(g, adjList);
}

TEST(GraphTest, InstantiateFromVector)
{
    std::vector<std::pair<int, int>> edges({ {1, 2}, {1, 3}, {2, 3} });
	IntAdjList adjList;
	adjList[1] = {2, 3};
	adjList[2] = {3};
	adjList[3] = {};
    Graph<int> g(edges);
	checkGraphAttributes(g, adjList);
}

TEST(GraphTest, InstantiatetFromAdjList)
{
	IntAdjList adjList;
	adjList[1] = {2, 3};
	adjList[2] = {3};
	adjList[3] = {};
    Graph<int> g(adjList);
	checkGraphAttributes(g, adjList);
}

TEST(GraphTest, AddVertex)
{
    Graph<char> g;
    g.addVertex('a');
	std::map<char, std::set<char>> adjList;
	adjList['a'] = {};
	
	checkGraphAttributes(g, adjList);
}

TEST_F(GraphTestF, AddPreexistingVertex)
{
	graph1.addVertex(1);
	graph1.addVertex(5);
	checkGraphAttributes(graph1, adjList1);
}

TEST_F(GraphTestF, AddEdge)
{
	graph1.addEdge(5,2);
	adjList1.at(5).insert(2);
	checkGraphAttributes(graph1, adjList1);

	graph1.addEdge(4,5);
	adjList1.at(4).insert(5);
	checkGraphAttributes(graph1, adjList1);

	graph1.addEdge(0,2);
	checkGraphAttributes(graph1, adjList1, "add preexisting edge");

	graph1.addEdge(1,0);
	adjList1.at(1).insert(0);
	checkGraphAttributes(graph1, adjList1, "1->0, make edge undirected");

	graph1.addEdge(5,9);
	graph1.addEdge(11,3);
	graph1.addEdge(15,6);
	adjList1[5].insert(9);
	adjList1[9];
	adjList1[11].insert(3);
	adjList1[15].insert(6);
	adjList1[6];
	checkGraphAttributes(graph1, adjList1, "add edge with new vertices");
}

TEST_F(GraphTestF, HasEdge)
{
	EXPECT_TRUE(graph1.hasEdge(0,2));
	EXPECT_FALSE(graph1.hasEdge(2,0)) << "0->2 exists, but not 2->0";
	EXPECT_FALSE(graph1.hasEdge(5,2)) << "node does not have any edge";
	EXPECT_FALSE(graph1.hasEdge(10,7)) << "edge between nonexisting nodes";
	EXPECT_FALSE(graph1.hasEdge(9,5)) << "edge from nonexisting nodes";
	EXPECT_FALSE(graph1.hasEdge(2,21)) << "edge to nonexisting nodes";
	checkGraphAttributes(graph1, adjList1);
}
