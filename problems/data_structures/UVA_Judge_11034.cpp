#include<iostream>
#include<string>
using namespace std;

typedef struct node{
	double meter;
	struct node *prox;
} Node;

Node *head_l = NULL;
Node *tail_l = NULL;

Node *head_r = NULL;
Node *tail_r = NULL;

string actual_side;

void pop_l();
void push_l(double m);
void pop_r();
void push_r(double m);

void transitate();
int ehIgual(string s, char c);
int isempty_l();
int isempty_r();
int ehDireita();
int ehEsquerda();

void printar_esq();
void printar_dir();

int main(){
	int qt_viagens = 0, can = 1;
	double l, n, m, n_cases;
	string side;
	char s;
	double tam_analisado = 0;
	cin >> n_cases;
	for(int a = 0; a < n_cases; a++){
		cin >> l >> n;
		for(int x = 0; x < n; x++){
			cin >> m >> side;
			if(side == "right"){
				s = 'r';
			}else{
				s = 'l';
			}
			if(s == 'r') push_r(m/100);
			if(s == 'l') push_l(m/100);
		}

		actual_side = "left";

		while(can){
			if(isempty_l() && isempty_r()){
				break;
			}
			if(ehDireita()){
				//cout << "ta no lado direito" << endl;
				if(isempty_r()){
					tam_analisado = 0;
					//cout << "transitou do direito pra o esquerdo por n ter nada" << actual_side << endl;
					transitate();
					qt_viagens++;
				}else{
					while(!isempty_r() && tam_analisado + head_r->meter <= l){
						//cout << head_r->meter << " saiu" << endl;
						tam_analisado += head_r->meter;
						pop_r();
					}
					//cout << "transitou do direito pra o esquerdo " << actual_side << endl;
					tam_analisado = 0;
					transitate();
					qt_viagens++;
				}
			}else{
				//cout << "ta no lado esquerdo" << endl;
				if(isempty_l()){
					tam_analisado = 0;
					//cout << "transitou do esquerdo pra o direito por n ter nada" << actual_side << endl;
					transitate();
					qt_viagens++;
				}else{
					while(!isempty_l() && tam_analisado + head_l->meter <= l){
						//cout << head_l->meter << " saiu" << endl;
						tam_analisado += head_l->meter;
						pop_l();
					}
					//cout << "transitou do esquerdo pra o direito " << actual_side << endl;
					tam_analisado = 0;
					transitate();
					qt_viagens++;
				}
			}
		}

		cout << qt_viagens << endl;
		tam_analisado = 0;
		qt_viagens = 0;
		head_r = NULL;
		head_l = NULL;
		tail_l = NULL;
		tail_r = NULL;
	}
}

void printar_dir(){
	while(head_r != NULL){
		cout << head_r->meter << endl;
		head_r = head_r->prox;
	}
}

void printar_esq(){
	while(head_l != NULL){
		cout << head_l->meter << endl;
		head_l = head_l->prox;
	}
}

int ehDireita(){
	if(actual_side == "right"){
		return 1;
	}
	return 0;
}

int ehEsquerda(){
	if(actual_side == "left"){
		return 1;
	}
	return 0;
}

int isempty_r(){
	if(head_r == NULL){
		return 1;
	}
	return 0;
}

int isempty_l(){
	if(head_l == NULL){
		return 1;
	}
	return 0;
}

void transitate(){
	if(actual_side == "right"){
		actual_side = "left";
	}else{
		actual_side = "right";
	}
}

int ehIgual(string s, char c){
	if(s == "right" && c == 'r'){
		return 1;
	}else if(s == "left" && c == 'l'){
		return 1;
	}
	return 0;
}

void pop_l(){
	if(head_l != NULL){
		head_l = head_l->prox;
	}
}

void push_l(double m){
	Node *no = (Node*) malloc(sizeof(Node));
	if(no != NULL){
		no->meter = m;
		no->prox = NULL;
		if(tail_l != NULL && head_l != NULL){
			tail_l->prox = no;
			tail_l = no;
		}else{
			head_l = no;
			tail_l = no;
		}
	}
}

void pop_r(){
	if(head_r != NULL){
		head_r = head_r->prox;
	}
}

void push_r(double m){
	Node *no = (Node*) malloc(sizeof(Node));
	if(no != NULL){
		no->meter = m;
		no->prox = NULL;
		if(tail_r != NULL && head_r != NULL){
			tail_r->prox = no;
			tail_r = no;
		}else{
			head_r = no;
			tail_r = no;
		}
	}
}
