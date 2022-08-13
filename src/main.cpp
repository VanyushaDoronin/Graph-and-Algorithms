#include <iostream>

#include "Graph.hpp"

int main() {

    auto source = new graph<int>(5, true, SIZE_MAX_LOCAL);

    source->add_edge(0, 1, 2);
    source->add_edge(1, 0, 2);
    source->add_edge(0, 2, 3);
    source->add_edge(1, 2, 4);
    source->add_edge(3, 4, 5);
    source->add_edge(3, 2, 6);
    source->add_vertex();
    source->add_edge(0, 5, 11);
    source->add_edge(5, 4, 22);

    std::cout << source << "\n\n\nIs empty: " <<  source->empty() << "\nElements quantity: " << source->get_elements_quantity() << "\nWeight vertex 0 1: " << source->get_edge_weight(0, 1);
    
    auto adjency_matrix = source->get_adjency_matrix();
    std::cout << "\n\n\n" << adjency_matrix;
    delete adjency_matrix;

    auto djkstra = source->find_shortest_path_djkstra(2);
    auto wallsher = source->find_all_shortest_path_wallsher();
    auto breadth_search = source->breadth_first_search(2);

    std::cout << "\n\n\n" << djkstra << "\n\n\n" << breadth_search << "\n\n\n" << wallsher;
    delete djkstra;
    delete wallsher;
    delete breadth_search;

    auto spanning = source->find_minimal_spanning_tree();
    std::cout << "\n\n\n" << spanning << "\n\n\n";
    delete spanning;
    
    auto to_out = new array_sequence<bool>(source->get_elements_quantity(), false);
    source->depth_first_search(0, to_out);
    std::cout << to_out;
    delete to_out;

    auto components = source->find_connected_components();
    for (std::size_t i = 0; i < components->get_size(); i++) {
        std::cout << components->operator[](i);
        delete components->operator[](i);
    }
    delete components;
    
    auto top_sorted = source->topological_sort();
    std::cout << "\n\n\n" << top_sorted;
    delete top_sorted;

    delete source;
    return 0;
}
