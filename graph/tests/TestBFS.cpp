#include "Test.hpp"

class BFSTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
		textbookAdjList['w'] = { 'r', 'v', 'x', 'z' };
		textbookAdjList['r'] = { 'w', 't', 's' };
		textbookAdjList['t'] = { 'r', 'u' };
		textbookAdjList['u'] = { 't', 's', 'y' };
		textbookAdjList['s'] = { 'r', 'u', 'v' };
		textbookAdjList['v'] = { 'w', 's', 'y' };
		textbookAdjList['x'] = { 'w', 'y', 'z' };
		textbookAdjList['y'] = { 'x', 'u', 'v' };
		textbookAdjList['z'] = { 'w', 'x' };

		// added separate island for testing
		textbookAdjList['a'] = { 'b', 'c' };
		textbookAdjList['b'] = { 'a', 'c' };
		textbookAdjList['c'] = { 'a', 'b', 'd' };
		textbookAdjList['d'] = { 'c' };

		textbookGraph = Graph<char>(textbookAdjList);
	}
	std::map<char, std::set<char>> textbookAdjList;
	Graph<char> textbookGraph;
};

TEST_F(BFSTest, InstantiateFromEdges)
{
    Graph<int> g({ {1, 2}, {1, 3}, {2, 3} });
    ASSERT_EQ(g.size(), 3);

    std::vector<int> bfs = g.BFS(1);
    std::vector<int> expected{ 1, 2, 3};

    EXPECT_EQ(bfs.size(), g.size());
    ASSERT_EQ(bfs, expected);
}

TEST_F(BFSTest, TextbookExampleBFS)
{
	textbookGraph.BFS('s');
	checkGraphAttributes(textbookGraph, textbookAdjList);
	EXPECT_EQ(textbookGraph.shortestPath('s', 's'), 0);
	EXPECT_EQ(textbookGraph.shortestPath('s', 'r'), 1);
	EXPECT_EQ(textbookGraph.shortestPath('s', 'u'), 1);
	EXPECT_EQ(textbookGraph.shortestPath('s', 'v'), 1);
	EXPECT_EQ(textbookGraph.shortestPath('s', 'w'), 2);
	EXPECT_EQ(textbookGraph.shortestPath('s', 't'), 2);
	EXPECT_EQ(textbookGraph.shortestPath('s', 'y'), 2);
	EXPECT_EQ(textbookGraph.shortestPath('s', 'x'), 3);
	EXPECT_EQ(textbookGraph.shortestPath('s', 'z'), 3);
	
	EXPECT_EQ(textbookGraph.shortestPath('s', 'a'), -1);
	EXPECT_EQ(textbookGraph.shortestPath('s', 'd'), -1);
}

TEST_F(BFSTest, TextbookShortestPathWithBfs)
{
	textbookGraph.BFS('x');
	EXPECT_EQ(textbookGraph.shortestPath('s', 's', true), 0);
	textbookGraph.BFS('u');
	EXPECT_EQ(textbookGraph.shortestPath('s', 'r', true), 1);
	textbookGraph.BFS('v');
	EXPECT_EQ(textbookGraph.shortestPath('s', 'u', true), 1);
	textbookGraph.BFS('r');
	EXPECT_EQ(textbookGraph.shortestPath('s', 'v', true), 1);
	textbookGraph.BFS('y');
	EXPECT_EQ(textbookGraph.shortestPath('s', 'w', true), 2);
	textbookGraph.BFS('s');
	EXPECT_EQ(textbookGraph.shortestPath('s', 't', true), 2);
	textbookGraph.BFS('x');
	EXPECT_EQ(textbookGraph.shortestPath('s', 'y', true), 2);
	textbookGraph.BFS('z');
	EXPECT_EQ(textbookGraph.shortestPath('s', 'x', true), 3);
	textbookGraph.BFS('w');
	EXPECT_EQ(textbookGraph.shortestPath('s', 'z', true), 3);

	textbookGraph.BFS('r');
	EXPECT_EQ(textbookGraph.shortestPath('s', 'a', true), -1);
	textbookGraph.BFS('y');
	EXPECT_EQ(textbookGraph.shortestPath('s', 'b', true), -1);
	textbookGraph.BFS('s');
	EXPECT_EQ(textbookGraph.shortestPath('s', 'c', true), -1);

	checkGraphAttributes(textbookGraph, textbookAdjList);
}

TEST_F(BFSTest, InvalidBFS)
{
	EXPECT_THROW(textbookGraph.BFS('g'), std::domain_error);
	EXPECT_THROW(textbookGraph.BFS('h'), std::domain_error);

	EXPECT_THROW(textbookGraph.shortestPath('i','z'), std::domain_error);
	EXPECT_THROW(textbookGraph.shortestPath('w','g'), std::domain_error);
	EXPECT_THROW(textbookGraph.shortestPath('h','i'), std::domain_error);

	EXPECT_THROW(textbookGraph.shortestPath('g','z',true), std::domain_error);
	EXPECT_THROW(textbookGraph.shortestPath('x','j',true), std::domain_error);
	EXPECT_THROW(textbookGraph.shortestPath('l','k',true), std::domain_error);
}
