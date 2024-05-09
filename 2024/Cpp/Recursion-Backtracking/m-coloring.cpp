// approach : starting from vertex 0 color one by one the different vertices. 
// case : return true if all the nodes are colored

//Recursion
// try every color from 1 to m with the help of a for loop.
// returns true if it is possible to color it with that color i.e none of the adjacent nodes have the same color.
// color it with color i then call the recursive function for the next node if it returns true we will return true.
// And If it is false then take off the color.
// try out every color from 1 to m and if it was not possible to color it with any of the m colors then return fa
// keep bacttracking , and remove if coloring is not possible

//TC: O(N^M), SC: O(N) + Auxiliary space O(n)

bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
  for (int k = 0; k < n; k++) {
    if (k != node && graph[k][node] == 1 && color[k] == col) {
      return false;
    }
  }
  return true;
}

bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
  if (node == N) {
    return true;
  }

  for (int i = 1; i <= m; i++) {
    if (isSafe(node, color, graph, N, i)) {
      color[node] = i;
      if (solve(node + 1, color, m, N, graph)) return true;
      color[node] = 0;
    }

  }
  return false;
}