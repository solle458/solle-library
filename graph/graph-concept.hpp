#pragma once

#include <ranges>
#include <concepts>

template<typename E>
concept adjacency_edge = requires(E &e){
    requires std::same_as<decltype(e.to), int>;
    requires std::same_as<decltype(e.cost), long long>;
};

template<typename G>
concept adjacency_graph = requires(G &g, int v){
    { g[v] } -> std::ranges::range;
    requires adjacency_edge<std::ranges::range_value_t<decltype(g[v])>>;
};
