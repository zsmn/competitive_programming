#include<bits/stdc++.h>
using namespace std;

int main(){
	stack<int> s;
	queue<int> q;
	priority_queue<int> pq;

	int n, op, numb;
	int eh_stack = 0;
	int eh_queue = 0;
	int eh_priority = 0;
	int coisas = 0;
	while(cin >> n){
		eh_priority = 1;
		eh_queue = 1;
		eh_stack = 1;
		coisas = 0;
		for(int x = 0; x < n; x++){
			cin >> op;
			if(op == 1){
				cin >> numb;
				s.push(numb);
				q.push(numb);
				pq.push(numb);
			}else if(op == 2){
				cin >> numb;
				if(s.empty() || numb != s.top()){
					//cout << "Nao bate com o topo da Stack" << endl;
					eh_stack = 0;
				}else{
					//cout << "Removi da Stack" << endl;
					if(!s.empty()){
						s.pop();
					}
				}
				if(q.empty() || numb != q.front()){
					//cout << "Nao bate com a frente da fila" << endl;
					eh_queue = 0;
				}else{
					//cout << "Removi da Fila" << endl;
					if(!q.empty()){
						q.pop();
					}
				}
				if(pq.empty() || numb != pq.top()){
					//cout << "Nao bate com a frente da priority" << endl;
					eh_priority = 0;
				}else{
					//cout << "Removi da priority" << endl;
					if(!pq.empty()){
						pq.pop();
					}
				}
			}
		}
		if(eh_priority){
			coisas++;
		}
		if(eh_queue){
			coisas++;
		}
		if(eh_stack){
			coisas++;
		}

		if(coisas == 0){
			cout << "impossible" << endl;
		}else if(coisas == 1){
			if(eh_priority){
				cout << "priority queue" << endl;
			}
			if(eh_queue){
				cout << "queue" << endl;
			}
			if(eh_stack){
				cout << "stack" << endl;
			}
		}else if(coisas > 1){
			cout << "not sure" << endl;
		}
		while(!q.empty()){
			q.pop();
		}
		while(!pq.empty()){
			pq.pop();
		}
		while(!s.empty()){
			s.pop();
		}
	}
}
