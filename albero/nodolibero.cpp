#include <iostream>
#include "AlberoB.h"
using namespace std;

void visitaNodo(Direzione dir,bool libero,AlberoB<int> a,int& liberoN,int& vincolatoN)
{
    if(a.nullo())
       return;
    
    if(libero)
       liberoN += a.radice();
    else
       vincolatoN += a.radice();
    visitaNodo(dir,libero,a.figlio(dir),liberoN,vincolatoN);
    Direzione other = dir == SIN ? DES : SIN;
    visitaNodo(other,false,a.figlio(other),liberoN,vincolatoN);
}

void esercizio1(const AlberoB<int>& a)
{
    if(a.nullo())
      return;

    int nodiLiberi = 0;
    int nodiVincolati = 0;
    nodiLiberi += a.radice();
    visitaNodo(SIN,true,a.figlio(SIN),nodiLiberi,nodiVincolati);
    visitaNodo(DES,true,a.figlio(DES),nodiLiberi,nodiVincolati);
    cout<<nodiLiberi<<endl;
    cout<<nodiVincolati<<endl;

}
int main()
{
    AlberoB<int> a(2);
	AlberoB<int> b(2);
	AlberoB<int> c(2);
	AlberoB<int> d(2);
	AlberoB<int> e(1);
	AlberoB<int> f(1);
	AlberoB<int> g(2);
	AlberoB<int> h(2);
	AlberoB<int> i(1);
	AlberoB<int> l(1);
	AlberoB<int> m(1);
	AlberoB<int> n(1);
	AlberoB<int> o(1);
	AlberoB<int> p(1);
	AlberoB<int> q(2);
	AlberoB<int> r(6);
	
	a.insFiglio(SIN,b);
	a.insFiglio(DES,c);
	b.insFiglio(SIN,d);	
	b.insFiglio(DES,e);
	c.insFiglio(SIN,f);
	c.insFiglio(DES,g);
	d.insFiglio(SIN,h);
	d.insFiglio(DES,i);	
	e.insFiglio(SIN,l);
	e.insFiglio(DES,m);
	f.insFiglio(SIN,n);
	f.insFiglio(DES,o);
	g.insFiglio(SIN,p);
	g.insFiglio(DES,q);
	p.insFiglio(SIN,r);

    esercizio1(a);

    //stampa 16 valore nodi liberi e 0 nodi vincolati


    return 0;
}