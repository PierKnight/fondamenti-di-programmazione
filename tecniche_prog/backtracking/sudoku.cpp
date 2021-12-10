#include <iostream>
using namespace std;
void stampaMappa(int mappa[9][9]);

struct  Soluzione
{
    int mappa[9][9];
    int rigaCorrente;
    int colonnaCorrente;

    Soluzione(int m[][9]) : rigaCorrente(0), colonnaCorrente(0){
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                mappa[i][j] = m[i][j];
    }
};
void decrementaCella(Soluzione& soluzione);
void incrementaCella(Soluzione& soluzione);
void remove(Soluzione& soluzione);
bool isComplete(const Soluzione& sol);
void add(Soluzione& soluzione, int val);
bool canAdd(const Soluzione& soluzione, int val);
bool solve(Soluzione& soluzione);
void stampaMappa(int mappa[9][9]);

int main(){


    int mappa[9][9];

    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            mappa[i][j] = 0;

    int riga = 0, colonna = 0, valore = 0;

    cout << "Inserisci -1 per uscire." << endl;
    cout << "Altrimenti, riga colonna valore." << endl;
    cout << "-> " ;


    while(riga != -1){

        cin >> riga;

        if(riga == -1)
            break;
        
        cin >> colonna >> valore;

        mappa[riga][colonna] = valore;
        cout << "Inserita (" << riga << "," << colonna << ") = " << valore << endl;
        cout << "-> ";
    }

    stampaMappa(mappa);

    Soluzione s(mappa);

    cout << "Inserire 0 per risolvere: ";
    int scelta; cin >> scelta;
    if(scelta == 0)
    {
        if(solve(s))
            stampaMappa(s.mappa);
        else   
            cout << "Non esiste alcuna soluzione" << endl;
    }
}

void stampaMappa(int mappa[9][9]){
    cout  << "  __________________________________ "<<endl;
	for (int i = 0; i < 9; i++){
		cout << " |";
		for (int j = 0; j < 9; j++){
			if (mappa[i][j] == 0)
				cout << " - ";
			else 
				cout << " " << mappa[i][j] << " ";
			
			if( (j+1) % 3 == 0)
				cout << " | ";
		}

		cout << endl;

		if ((i+1) % 3 == 0)
			cout  << "  __________________________________ " << endl << endl;

		
	}
}

bool solve(Soluzione& soluzione){

    /* La posizione corrente ha gia' un valore*/
    if(soluzione.rigaCorrente < 9 && soluzione.colonnaCorrente < 9 && soluzione.mappa[soluzione.rigaCorrente][soluzione.colonnaCorrente] != 0){
        incrementaCella(soluzione);

        if(solve(soluzione))
            return true;

        decrementaCella(soluzione);
        return false;
    }
    /*****************************************/

    for(int val = 1;val < 10;val++)
    {
        if(canAdd(soluzione, val)){
            add(soluzione, val);

            if(isComplete(soluzione))
                return true;

            if(solve(soluzione))
                return true;
            
            remove(soluzione);
        }
    }

    return false;
}
void decrementaCella(Soluzione& soluzione){
    if(--soluzione.colonnaCorrente < 0)
    {
        --soluzione.rigaCorrente;
        soluzione.colonnaCorrente = 8;
    }
}

void incrementaCella(Soluzione& soluzione){
    if(++soluzione.colonnaCorrente >= 9)
    {
        ++soluzione.rigaCorrente;
        soluzione.colonnaCorrente = 0;

    }
}
void remove(Soluzione& soluzione)
{
    if(soluzione.rigaCorrente < 9 && soluzione.colonnaCorrente < 9)
    soluzione.mappa[soluzione.rigaCorrente][soluzione.colonnaCorrente] = 0;
}
bool isComplete(const Soluzione& sol)
{
    for(int i = 0;i < 9;i++)
    {
        for(int j = 0;j < 9;j++)
        {
            if(sol.mappa[i][j] == 0)
               return false;
        }
    }
    return true;
}
void add(Soluzione& soluzione, int val)
{
    soluzione.mappa[soluzione.rigaCorrente][soluzione.colonnaCorrente] = val;
}

bool canAdd(const Soluzione& soluzione, int val){

    if(soluzione.rigaCorrente >= 9 || soluzione.colonnaCorrente >= 9)
         return false;
    //controlliamo che non ci sia già nella sotto-matrice
    int sottoMatriceR = soluzione.rigaCorrente / 3;
    int sottoMatriceC = soluzione.colonnaCorrente / 3;

    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            if(soluzione.mappa[sottoMatriceR * 3 + i][sottoMatriceC * 3 + j] == val)
            {
                return false;
            }
        }
    }
    

    //non deve essere presente nella colonna corrente
    for(int i = 0;i < 9;i++)
    {
        if(soluzione.mappa[i][soluzione.colonnaCorrente] == val)
           return false;
    }
    
    //non deve essere presente nella riga corrente
    for(int j = 0;j < 9;j++)
    {
        if(soluzione.mappa[soluzione.rigaCorrente][j] == val)
           return false;
    }



    return true;
}

