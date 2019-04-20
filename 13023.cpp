#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

int friendship[2000][2000];
int visit[2000];
int cnt_node;
int cnt_edge;


using namespace std;
int main (){
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int edge1,edge2;
  cin >> cnt_node >> cnt_edge;

  for(int i = 0; i < cnt_edge; i++){
    cin >> edge1 >> edge2;
    friendship[edge1][edge2] = 1;
    friendship[edge2][edge1] = 1;
  }

  int flag = 0;;
  int node_num = 0;
  for(node_num = 0; node_num < cnt_node; node_num++){
        stack<int> s;
        int depth = 0;
        s.push(node_num);

        while(!s.empty() && flag == 0){
            for(int i = 0; i < cnt_node && flag == 0; i++){
              if(friendship[node_num][i] == 1 && visit[i] == 0){
                s.push(i); node_num = i;
                visit[i] = 1;  i = 0;
                depth++;
                if(depth >= 4) flag = 1;
              }
            }
            s.pop(); depth--;

            if(!s.empty())
              node_num = s.top();
        }

        for(int i = 0; i < cnt_node; i++) visit[i] = 0;
    }
  if(flag == 1) cout << 1;
  else cout << 0;
}
