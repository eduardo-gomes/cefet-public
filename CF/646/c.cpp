#include <bits/stdc++.h>
std::vector<int> adj[1001];
int_fast8_t wont_pass_dfs[1001];
//Whose turn starts with the degree of the x node equal 1 win
//Whoever reduce the degree of the x node to 1 loses

//Turns before x node become 1
int turns_before_one = 0;

void DFS(int node){
	for(auto viz : adj[node]){
		if(!wont_pass_dfs[viz]){
			turns_before_one++;
			wont_pass_dfs[viz] = 1;
			DFS(viz);
		}
	}
}

int main(){
	int tcase;
	scanf("%d", &tcase);
	while(tcase--){
		int nodes, special;
		scanf("%d %d", &nodes, &special);

		for(int i = 0; i <= nodes; ++i)
			adj[i].clear();
		turns_before_one = 0;
		memset(wont_pass_dfs, 0, sizeof(wont_pass_dfs));

		for (int i = 0; i < nodes-1; ++i){
			int u, v;
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		wont_pass_dfs[special] = 1;
		for(auto connected_with_x : adj[special])
			wont_pass_dfs[connected_with_x] = 1;
		if(adj[special].size() > 1)
			for (auto connected_with_x : adj[special])
				DFS(connected_with_x);
		turns_before_one += std::max(0, (int)adj[special].size() - 1);
		//result based on turns before...
		// Ashish % 2 == 1
		// Ayush  % 2 == 0
		printf("%s\n", turns_before_one % 2 ? "Ashish" : "Ayush");
	}
}