
#include <vector>
#include <iostream>
using namespace std;


struct Soluzione{
    
    vector<string> benParentesizzate;
    string current;

    int n;

    Soluzione(int n_) : n(n_), current(""){}

};

void solve(Soluzione& soluzione);
string get(int x);
bool canAdd(string parentesi, const Soluzione& soluzione);
void add(string parentesi, Soluzione& soluzione);
bool isComplete(const Soluzione& soluzione);
void remove(Soluzione& soluzione);

int main(){
    cout << "Inserisci numero di parentesi: ";
    int n; cin >> n;

    Soluzione s(n);
    solve(s);

    for(string benParentesizzata: s.benParentesizzate)
        cout << benParentesizzata << endl;
}

void solve(Soluzione& soluzione){
    int x = 0;
    while(x < 2){
        if(canAdd(get(x), soluzione)){
            add(get(x), soluzione);
            
            if(isComplete(soluzione))
                soluzione.benParentesizzate.push_back(soluzione.current);
            
            solve(soluzione);

            remove(soluzione);
            x++;
        }
        else
            x++;
    }

}

string get(int x){
    if(x == 0) 
        return "(";

    return ")";
}

bool canAdd(string parentesi, const Soluzione& soluzione){
    int count_aperte = 0;
    for(int i = 0; i < soluzione.current.size(); i++)
        if(soluzione.current[i] == '(')
            count_aperte ++;
        
    if(parentesi == "(")
        return count_aperte < soluzione.n;
    else //parentesi == ")"
        return count_aperte > (soluzione.current.size() - count_aperte);
}

void add(string parentesi, Soluzione& soluzione){
    soluzione.current += parentesi;
}

bool isComplete(const Soluzione& soluzione){
    return soluzione.current.size() == 2 * soluzione.n;
}

void remove(Soluzione& soluzione){
    soluzione.current.pop_back();
}

