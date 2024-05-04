#pragma once
#include <iostream> 
#include <vector> 
#include <set> 
#include <algorithm> 
#include <tuple>

//
//
typedef std::pair<int, int> intpair;

const int infinity = std::numeric_limits<int>::max();
const int MAXN = 1e4;

// Структура для зберігання шляху та його довжини
struct ShortestPathInfo {
    std::vector<int> path;
    int length;
};

//// Функція Дейкстри, яка повертає структуру зі шляхом та його довжиною
//ShortestPathInfo dijkstra() {
//    int n;
//    std::cout << "Enter the number of vertices: ";
//    std::cin >> n;
//    int m;
//    std::cout << "Enter the number of edges: ";
//    std::cin >> m;
//
//    std::vector<intpair> adjList[MAXN];
//    std::cout << "Filling the edges." << std::endl;
//    for (int i = 0; i < m; ++i) {
//        int ver1, ver2, weight;
//        std::cout << "Enter the vertices and the weight of edge " << i << " (all separated by a space): ";
//        std::cin >> ver1 >> ver2 >> weight;
//
//        adjList[ver1].emplace_back(weight, ver2);
//        adjList[ver2].emplace_back(weight, ver1);
//    }
//
//    int s;
//    std::cout << "Enter the starting vertex (0 to " << n - 1 << "): ";
//    std::cin >> s;
//    int e;
//    std::cout << "Enter the ending vertex (0 to " << n - 1 << "): ";
//    std::cin >> e;
//
//    std::set<intpair> priority_queue;
//    priority_queue.emplace(0, s);
//
//    int distance[MAXN];
//    std::fill_n(distance, n, infinity);
//    distance[s] = 0;
//
//    int parent[MAXN];
//    std::fill_n(parent, n, -1);
//
//    while (!priority_queue.empty()) {
//        intpair current_vertex = *priority_queue.begin();
//        priority_queue.erase(priority_queue.begin());
//        int cur_distance = current_vertex.first;
//        int cur_idx = current_vertex.second;
//
//        if (cur_idx == e || cur_distance == infinity) break;
//
//        std::vector<intpair> cur_edges = adjList[cur_idx];
//        for (auto& cur_edge : cur_edges) {
//            int edge_to = cur_edge.second;
//            int edge_weight = cur_edge.first;
//
//            if (distance[cur_idx] + edge_weight < distance[edge_to]) {
//                if (distance[edge_to] != infinity) {
//                    priority_queue.erase(priority_queue.find(std::make_pair(distance[edge_to], edge_to)));
//                }
//                priority_queue.emplace(distance[cur_idx] + edge_weight, edge_to);
//
//                distance[edge_to] = distance[cur_idx] + edge_weight;
//                parent[edge_to] = cur_idx;
//            }
//        }
//    }
//
//    if (parent[e] != -1) {
//        std::cout << std::endl << std::endl << "Shortest path from " << s << " to " << e << " found!" << std::endl;
//        std::vector<int> s_to_e;
//        for (int v = e; v != s; v = parent[v]) s_to_e.push_back(v);
//        s_to_e.push_back(s);
//        reverse(s_to_e.begin(), s_to_e.end());
//
//        int shortest_distance = distance[e];
//        ShortestPathInfo path_info;
//        path_info.path = s_to_e;
//        path_info.length = shortest_distance;
//
//        return path_info;
//    }
//    else {
//        std::cout << std::endl << std::endl << "Path not found. Make sure your graph is valid and only contains one component." << std::endl;
//        std::vector<int> error = { -1 };
//        std::vector<int> s_to_e;
//        int shortest_distance = -1;
//
//        ShortestPathInfo path_info;
//        path_info.path = s_to_e;
//        path_info.length = shortest_distance;
//
//        return path_info;
//    }
//}
ShortestPathInfo dijkstra(int n_vertices, std::vector<std::tuple<int, int, int>> edges, int start_vertex, int end_vertex) {
    std::vector<intpair> adjList[MAXN];
    
    for (const auto& edge : edges) {
        int weight = std::get<2>(edge);
        if (weight < 0)
            throw std::runtime_error("Edge weight cannot be negative in Dijkstra algorithm");
        int ver1 = std::get<0>(edge);
        int ver2 = std::get<1>(edge);
        adjList[ver1].emplace_back(weight, ver2);
        adjList[ver2].emplace_back(weight, ver1);
    }
    
    
    std::set<intpair> priority_queue;
    priority_queue.emplace(0, start_vertex);

    int distance[MAXN];
    std::fill_n(distance, n_vertices, infinity);
    distance[start_vertex] = 0;

    int parent[MAXN];
    std::fill_n(parent, n_vertices, -1);

    while (!priority_queue.empty()) {
        intpair current_vertex = *priority_queue.begin();
        priority_queue.erase(priority_queue.begin());
        int cur_distance = current_vertex.first;
        int cur_idx = current_vertex.second;

        if (cur_idx == end_vertex || cur_distance == infinity) break;

        std::vector<intpair> cur_edges = adjList[cur_idx];
        for (auto& cur_edge : cur_edges) {
            int edge_to = cur_edge.second;
            int edge_weight = cur_edge.first;

            if (distance[cur_idx] + edge_weight < distance[edge_to]) {
                if (distance[edge_to] != infinity) {
                    priority_queue.erase(priority_queue.find(std::make_pair(distance[edge_to], edge_to)));
                }
                priority_queue.emplace(distance[cur_idx] + edge_weight, edge_to);

                distance[edge_to] = distance[cur_idx] + edge_weight;
                parent[edge_to] = cur_idx;
            }
        }
    }

    if (parent[end_vertex] != -1) {
        std::cout << std::endl << std::endl << "Shortest path from " << start_vertex << " to " << end_vertex << " found!" << std::endl;
        std::vector<int> s_to_e;
        for (int v = end_vertex; v != start_vertex; v = parent[v]) s_to_e.push_back(v);
        s_to_e.push_back(start_vertex);
        std::reverse(s_to_e.begin(), s_to_e.end());

        int shortest_distance = distance[end_vertex];
        ShortestPathInfo path_info;
        path_info.path = s_to_e;
        path_info.length = shortest_distance;

        return path_info;
    }
    else {
        std::cout << std::endl << std::endl << "Path not found. Make sure your graph is valid and only contains one component." << std::endl;
        std::vector<int> error = { -1 };
        std::vector<int> s_to_e;
        int shortest_distance = -1;

        ShortestPathInfo path_info;
        path_info.path = s_to_e;
        path_info.length = shortest_distance;

        return path_info;
    }
}
