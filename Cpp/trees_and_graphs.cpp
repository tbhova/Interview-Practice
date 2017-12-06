#include <tuple>
#include <algorithm>
#include "trees_and_graphs.h"

using std::string;

using Dependency = std::pair<std::string, std::string>;
using Dependencies = std::vector<Dependency>;

struct Node {
    std::string project;
    std::vector<Node*> adjacent;
    bool visited = false;
};

bool BuildDFS(Node* n, std::vector<string>* build_order) {
  if (n->visited) {
    // If this node has already been output then there is a cycle.
    return std::find_if(build_order->begin(), build_order->end(),
                        [n](const string& p){ return p == n->project; }) != build_order->end();
  }

  n->visited = true;
  for (Node* adj : n->adjacent) {
    BuildDFS(adj, build_order);
  }
  build_order->push_back(n->project);
  return true;
}

std::vector<std::string> BuildOrder(const std::vector<std::string>& projects, const Dependencies& deps) {
  std::vector<Node> graph;
  std::vector<string> out;

  for (const string& p : projects) {
    graph.emplace_back(Node{p});
  }
  for (const Dependency& d : deps) {
    std::string proj = std::get<1>(d);
    std::string dep = std::get<0>(d);
    if (proj == dep) return out;


    // Get index of the node
    auto find_node = [graph](string p){
      return std::distance(graph.begin(),
                           std::find_if(graph.begin(), graph.end(), [p](const Node& n){ return n.project == p; }));
    };

    graph.at(find_node(proj)).adjacent.push_back(&graph.at(find_node(dep)));
  }

  for (Node& n : graph) {
    if (!BuildDFS(&n, &out)) {
      return std::vector<string>();
    }
  }
  return out;
}
