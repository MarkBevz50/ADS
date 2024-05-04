#include "Dijkstra.h"

int main() {
   /* ShortestPathInfo shortest_path_info = dijkstra();

    std::cout << "Shortest path length: " << shortest_path_info.length << std::endl;
    for (int i = 0; i < shortest_path_info.path.size() - 1; ++i) {
        std::cout << shortest_path_info.path[i] << "->";
    }
    std::cout << shortest_path_info.path[shortest_path_info.path.size() - 1] << std::endl;

    std::string quit;
    while (true) {
        std::cin >> quit;
        if (quit == "quit") break;
    }*/
    //int n_vertices = 11; // кількість вершин
    //std::vector<std::tuple<int, int, int>> edges;
    //edges.emplace_back(0, 1, 2);
    //edges.emplace_back(0, 6, 10);
    //edges.emplace_back(1, 4, 1);
    //edges.emplace_back(1, 2, 8);
    //edges.emplace_back(2, 3, 4);
    //edges.emplace_back(2, 5, 6);
    //edges.emplace_back(3, 5, 5);
    //edges.emplace_back(3, 10, 1);
    //edges.emplace_back(4, 5, 7);
    //edges.emplace_back(4, 6, 4);
    //edges.emplace_back(4, 7, 5);
    //edges.emplace_back(4, 8, 3);
    //edges.emplace_back(5, 9, 3);
    //edges.emplace_back(6, 7, 6);
    //edges.emplace_back(7, 8, 2);
    //edges.emplace_back(8, 9, 4);
    //edges.emplace_back(9, 10, 7);
    ///*edges.emplace_back(0, 1, 3);
    //edges.emplace_back(0, 2, 2);
    //edges.emplace_back(0, 3, 5);
    //edges.emplace_back(1, 4, 5);
    //edges.emplace_back(2, 3, 2);
    //edges.emplace_back(2, 5, 3);
    //edges.emplace_back(3, 4, 3);
    //edges.emplace_back(3, 6, 7);
    //edges.emplace_back(4, 6, 1);
    //edges.emplace_back(5, 6, 4);*/
    //int start_vertex = 0; 
    //int end_vertex = 10; 
    int n_vertices = 6; // кількість вершин
    std::vector<std::tuple<int, int, int>> edges;
    edges.emplace_back(0, 1, 4);
    edges.emplace_back(0, 2, 2);
    edges.emplace_back(2, 1, 1);
    edges.emplace_back(2, 3, 8);
    edges.emplace_back(2, 4, 10);
    edges.emplace_back(1, 3, 5);
    edges.emplace_back(3, 5, 6);
    edges.emplace_back(3, 4, 2);
    edges.emplace_back(4, 5, 3);
   
    /*edges.emplace_back(0, 1, 3);
    edges.emplace_back(0, 2, 2);
    edges.emplace_back(0, 3, 5);
    edges.emplace_back(1, 4, 5);
    edges.emplace_back(2, 3, 2);
    edges.emplace_back(2, 5, 3);
    edges.emplace_back(3, 4, 3);
    edges.emplace_back(3, 6, 7);
    edges.emplace_back(4, 6, 1);
    edges.emplace_back(5, 6, 4);*/
    int start_vertex = 2;
    int end_vertex = 3;
    try {
        ShortestPathInfo shortest_path_info = dijkstra(n_vertices, edges, start_vertex, end_vertex);
    
    std::cout << "Shortest path length: " << shortest_path_info.length << std::endl;
    std::cout << "Shortest path: ";
    for (int i = 0; i < shortest_path_info.path.size() - 1; ++i) {
        std::cout << shortest_path_info.path[i] << "->";
    }
    std::cout << shortest_path_info.path.back() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "Run time error: " << e.what();
    }
    return 0;
}
