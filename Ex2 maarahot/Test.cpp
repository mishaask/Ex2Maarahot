//314085986
//mishaaskarov@gmail.com
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test graph operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 2, 0},
        {3, 0, 4},
        {0, 5, 0}};
    g2.loadGraph(graph2);
    ariel::Graph g3 = g1 + g2;
    CHECK(g3.printGraph() == "[0, 3, 0]\n[4, 0, 5]\n[0, 6, 0]");

    ariel::Graph g4 = g1 - g2;
    CHECK(g4.printGraph() == "[0, -1, 0]\n[-2, 0, -3]\n[0, -4, 0]");

    ariel::Graph g5 = g1 * 2;
    CHECK(g5.printGraph() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]");

    ariel::Graph g6 = g2 / 2;
    CHECK(g6.printGraph() == "[0, 1, 0]\n[1, 0, 2]\n[0, 2, 0]");
}

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);
    ariel::Graph g3 = g1 + g2;
    CHECK(g3.printGraph() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]");

    ariel::Graph g5;
    vector<vector<int>> graph4 = {
        {0, 1, 2},
        {3, 0, 4},
        {5, 6, 0}};
    g5.loadGraph(graph4);
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 10, 20},
        {30, 0, 40},
        {50, 60, 0}};
    g6.loadGraph(graph3);
    ariel::Graph g4 = g5 + g6;
    CHECK(g4.printGraph() == "[0, 11, 22]\n[33, 0, 44]\n[55, 66, 0]");
}
TEST_CASE("Test graph subtraction")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);
    ariel::Graph g3 = g2 - g1;
    CHECK(g3.printGraph() == "[0, 0, 1]\n[0, 0, 1]\n[1, 1, 0]");
}

TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);
    ariel::Graph g4 = g1 * g2;
    CHECK(g4.printGraph() == "[1, 0, 2]\n[1, 3, 1]\n[1, 0, 2]");

    ariel::Graph g5;
    vector<vector<int>> graph3 = {
        {0, 1, 2},
        {3, 0, 4},
        {5, 6, 0}};
    g5.loadGraph(graph3);
    ariel::Graph g6;
    vector<vector<int>> graph4 = {
        {0, 10, 20},
        {30, 0, 40},
        {50, 60, 0}};
    g6.loadGraph(graph4);
    ariel::Graph g7 = g5 * g6;
    CHECK(g7.printGraph() == "[130, 120, 40]\n[200, 270, 60]\n[180, 50, 340]");
}

TEST_CASE("Test graph equality")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);
    CHECK(g1 == g2);
}

TEST_CASE("Test graph inequality")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 0, 0}};
    g2.loadGraph(graph2);
    CHECK(g1 != g2);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 11, 0}};
    g3.loadGraph(graph3);
    CHECK(g1 != g3);
}
TEST_CASE("Test graph less than")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 0, 0}};
    g2.loadGraph(graph2);
    CHECK(g2 < g1);
}

TEST_CASE("Test graph greater than")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 0, 0}};
    g2.loadGraph(graph2);
    CHECK(g1 > g2);
}

TEST_CASE("Test graph less than or equal to")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 0, 0}};
    g2.loadGraph(graph2);
    CHECK(g2 <= g1);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 1}};
    g3.loadGraph(graph3);
    CHECK(g1 <= g3);
}

TEST_CASE("Test graph greater than or equal to")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 0, 0}};
    g2.loadGraph(graph2);
    CHECK(g1 >= g2);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 1}};
    g3.loadGraph(graph3);
    CHECK(g3 >= g1);
}

TEST_CASE("Test graph unary plus")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = +g1;
    CHECK(g2 == g1);
}

TEST_CASE("Test graph unary minus")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = -g1;
    CHECK(g2.printGraph() == "[0, -1, 0]\n[-1, 0, -1]\n[0, -1, 0]");
}

TEST_CASE("Test graph increment")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = ++g1;
    CHECK(g2.printGraph() == "[1, 2, 1]\n[2, 1, 2]\n[1, 2, 1]");
}

TEST_CASE("Test graph decrement")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = --g1;
    CHECK(g2.printGraph() == "[-1, 0, -1]\n[0, -1, 0]\n[-1, 0, -1]");
}

TEST_CASE("Test graph scalar multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = g1 * 2;
    CHECK(g2.printGraph() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]");
}

TEST_CASE("Test graph scalar division")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = g1 / 2;
    CHECK(g2.printGraph() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");
}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    ariel::Graph g2;
    vector<vector<int>> badGraph = {
         {0, 1, 1, 1},
         {1, 0, 2, 1},
         {1, 2, 0, 1}};
    CHECK_THROWS(g2.loadGraph(badGraph));

     ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);

    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}
