#include "pch.h"
#include "CppUnitTest.h"
#include "../Dijkstra Algorithm/Dijkstra.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Dijkstratests
{
	TEST_CLASS(Dijkstratests)
	{
	public:
		
		TEST_METHOD(ShortestPathFound1)
		{
			
			std::vector<int> expected_path = { 0, 1, 3, 4 };
			int n_vertices = 11; // кількість вершин
			std::vector<std::tuple<int, int, int>> edges;
			edges.emplace_back(0, 1, 5);
			edges.emplace_back(1, 2, 3);
			edges.emplace_back(1, 3, 2);
			edges.emplace_back(2, 3, 2);
			edges.emplace_back(3, 4, 1);
			edges.emplace_back(4, 0, 24);
			int start_vertex = 0;
			int end_vertex = 4;
			ShortestPathInfo shortest_path_info = dijkstra(n_vertices, edges, start_vertex, end_vertex);
			Assert::AreEqual(shortest_path_info.length, 8);
			Assert::IsTrue(std::equal(shortest_path_info.path.begin(), shortest_path_info.path.end(), expected_path.begin()));
			
			
		}
		TEST_METHOD(ShortestPathFound2)
		{

			std::vector<int> expected_path = { 0, 1, 2, 3, 10 };
			int n_vertices = 11; // кількість вершин
			std::vector<std::tuple<int, int, int>> edges;
			edges.emplace_back(0, 1, 2);
			edges.emplace_back(0, 6, 10);
			edges.emplace_back(1, 4, 1);
			edges.emplace_back(1, 2, 8);
			edges.emplace_back(2, 3, 4);
			edges.emplace_back(2, 5, 6);
			edges.emplace_back(3, 5, 5);
			edges.emplace_back(3, 10, 1);
			edges.emplace_back(4, 5, 7);
			edges.emplace_back(4, 6, 4);
			edges.emplace_back(4, 7, 5);
			edges.emplace_back(4, 8, 3);
			edges.emplace_back(5, 9, 3);
			edges.emplace_back(6, 7, 6);
			edges.emplace_back(7, 8, 2);
			edges.emplace_back(8, 9, 4);
			edges.emplace_back(9, 10, 7);
			int start_vertex = 0;
			int end_vertex = 10;
			ShortestPathInfo shortest_path_info = dijkstra(n_vertices, edges, start_vertex, end_vertex);
			Assert::AreEqual(shortest_path_info.length, 15);
			Assert::IsTrue(std::equal(shortest_path_info.path.begin(), shortest_path_info.path.end(), expected_path.begin()));


		}
		TEST_METHOD(ShortestPathFound3)
		{

			std::vector<int> expected_path = { 0, 2, 3, 4 , 6};
			int n_vertices = 7; // кількість вершин
			std::vector<std::tuple<int, int, int>> edges;
			edges.emplace_back(0, 1, 3);
			edges.emplace_back(0, 2, 2);
			edges.emplace_back(0, 3, 5);
			edges.emplace_back(1, 4, 5);
			edges.emplace_back(2, 3, 2);
			edges.emplace_back(2, 5, 3);
			edges.emplace_back(3, 4, 3);
			edges.emplace_back(3, 6, 7);
			edges.emplace_back(4, 6, 1);
			edges.emplace_back(5, 6, 4);
			int start_vertex = 0;
			int end_vertex = 6;
			ShortestPathInfo shortest_path_info = dijkstra(n_vertices, edges, start_vertex, end_vertex);
			Assert::AreEqual(shortest_path_info.length, 8);
			Assert::IsTrue(std::equal(shortest_path_info.path.begin(), shortest_path_info.path.end(), expected_path.begin()));


		}
		
			TEST_METHOD(ShortestPathNotFound_DisconnectedGraph)
			{
				int n_vertices = 5; 
				std::vector<std::tuple<int, int, int>> edges;
				edges.emplace_back(0, 1, 5);
				edges.emplace_back(1, 2, 3);
				edges.emplace_back(1, 1, 0);
				edges.emplace_back(3, 4, 1);
				// Цей граф має вершини 3 і 4, які не з'єднані з іншими вершинами
				int start_vertex = 0;
				int end_vertex = 4;
				ShortestPathInfo shortest_path_info = dijkstra(n_vertices, edges, start_vertex, end_vertex);
				Assert::AreEqual(shortest_path_info.length, -1); // Очікуємо, що шлях не знайдено
				Assert::IsTrue(shortest_path_info.path.empty()); // Очікуємо порожній шлях
			}
			TEST_METHOD(ShortestPathFound_GraphWithNegativeWeights)
			{
				std::vector<int> expected_path = { 0, 1, 3, 4 };
				int n_vertices = 5;
				std::vector<std::tuple<int, int, int>> edges;
				edges.emplace_back(0, 1, 5);
				edges.emplace_back(1, 2, -3); // Ребро з від'ємною вагою
				edges.emplace_back(1, 3, 2);
				edges.emplace_back(2, 3, 2);
				edges.emplace_back(3, 4, 1);
				edges.emplace_back(4, 0, 24);
				int start_vertex = 0;
				int end_vertex = 4;

				try {
					ShortestPathInfo shortest_path_info = dijkstra(n_vertices, edges, start_vertex, end_vertex);
					Assert::Fail(L"Expected an exception due to negative edge weight.");
				}
				catch (const std::runtime_error&) {
				}
			}
	};
}
