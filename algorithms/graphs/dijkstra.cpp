#include <stdio.h>
#include <bits/stdc++.h>
#define int_max 9999
using namespace std;

void dijkstra(vector<vector<pair<int, int> > >grafo, int qtV, int s, int *custos, vector<int>visitados){
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>aux;
  aux.push(make_pair(0, s)); //caminho de s para s, custo 0;
  for(int i=0; i<qtV; i++){
    custos[i] = int_max;
    visitados[i] = 0;
  }
  custos[s] = 0;
  for(int i=0; i<qtV; i++){
    pair<int, int>v;
    do{
       if(aux.size()>0){
         v = aux.top();
         aux.pop();
       }
       else return;
    }while(visitados[v.second]);
    visitados[v.second] = 1;
    for(auto w:grafo[v.second]){
      if(!visitados[w.second] && custos[w.second] > custos[v.second]+w.first){
        custos[w.second] = custos[v.second]+w.first;
        aux.push(make_pair(custos[w.second], w.second));
      }
    }
  }
};
int main(){
  vector<vector<pair<int, int>>> grafo(5);
  vector<int> visitados(5);
  grafo[0].push_back(make_pair(3, 1)); // a --3-- b
	grafo[0].push_back(make_pair(7, 3)); // a --7-- d
	grafo[1].push_back(make_pair(3, 0)); // b --3-- a
	grafo[1].push_back(make_pair(2, 3)); // b --2-- d
	grafo[1].push_back(make_pair(4, 2)); // b --4-- c
	grafo[2].push_back(make_pair(4, 1)); // c --4-- b
	grafo[2].push_back(make_pair(5, 3)); // c --5-- d
	grafo[2].push_back(make_pair(6, 4)); // c --6-- e
	grafo[3].push_back(make_pair(7, 0)); // d --7-- a
	grafo[3].push_back(make_pair(2, 1)); // d --2-- b
	grafo[3].push_back(make_pair(5, 2)); // d --5-- c
	grafo[3].push_back(make_pair(4, 4)); // d --4-- e
	grafo[4].push_back(make_pair(6, 2)); // e --6-- c
	grafo[4].push_back(make_pair(4, 3)); // e --4-- d
  int custos[5];
  dijkstra(grafo, 5, 0, custos, visitados);
  for(int i=0; i<5; i++){
    printf("%d ", custos[i]);
  }
  return 0;
}
