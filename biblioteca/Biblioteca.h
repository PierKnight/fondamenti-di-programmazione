
using namespace std;

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <vector>
#include "Cliente.h"
#include "Libro.h"
#include <algorithm>


class Biblioteca
{
    vector<Cliente> clienti;
    vector<Libro> libri;

public:
    void aggiungereLibro()
    {
        Libro libro;
        cin >> libro;

        libri.push_back(libro);
    }

    void rimuovereLibro()
    {
        unsigned int codice;
        cout << "Inserire Codice Libro: ";
        cin >> codice;
        vector<Libro>::iterator pos = getLibro(codice);
        if (pos != libri.end())
        {
            if (pos->inPrestito)
            {
                cout << "Non è possibile rimuovere il libro perche' e' in prestito" << endl;
                return;
            }

            cout << "Rimosso Libro: \"" << pos->nome << "\"!" << endl;
            libri.erase(pos);
        }
        else
            cout << "Non è stato trovato nessun libro!" << endl;
    }

    void aggiungereCliente()
    {
        Cliente cliente;
        cin >> cliente;
        if (getCliente(cliente.codice_fiscale) == clienti.end())
            clienti.push_back(cliente);
        else
            cout << "Il cliente con codice fiscale: " << cliente.codice_fiscale << " esiste gia'." << endl;
    }

    void rimuovereCliente()
    {
        unsigned int codice;
        cout << "Inserire Codice Cliente: ";
        cin >> codice;
        vector<Cliente>::iterator pos = getCliente(codice);
        if (pos != clienti.end())
        {
            if (pos->haLibro())
            {
                cout << "Non è possibile rimuovere il cliente  perche' ha un libro in prestito." << endl;
                return;
            }
            cout << "Rimosso Cliente: \"" << (pos)->nome << "\"!" << endl;
            clienti.erase(pos);
        }
        else
            cout << "Non è stato trovato nessun cliente!" << endl;
    }

    void inserirePrestito()
    {
        unsigned int codiceC;
        cout << "Inserire Codice Cliente Che prende libro: ";
        cin >> codiceC;

        unsigned int codiceL;
        cout << "Inserire Codice Libro In Prestito: ";
        cin >> codiceL;

        vector<Cliente>::iterator iteratorCliente = getCliente(codiceC);
        vector<Libro>::iterator iteratorLibro = getLibro(codiceL);
        if (iteratorCliente != clienti.end() && iteratorLibro != libri.end())
        {
            if (presta(*iteratorCliente, *iteratorLibro))
                cout << "Libro prestato con successo!" << endl;
            else
                cout << "Il libro è gia in prestito oppure il Cliente ha già un libro in prestito!." << endl;
        }
        else
            cout << "Codice del Cliente o del Libro Invalidi!" << endl;
    }

    void riconsegnareLibro()
    {
        unsigned int codiceC;
        cout << "Inserire Codice Cliente Che ha Libro in prestito: ";
        cin >> codiceC;

        vector<Cliente>::iterator iteratorCliente = getCliente(codiceC);
        if (iteratorCliente != clienti.end())
        {
            Cliente &cliente = *iteratorCliente;
            if (riconsegna(cliente))
            {
                cout << "Libro riconsegnato con successo!." << endl;
            }
            else
                cout << "Il Cliente " << cliente.nome << " non ha un libro in prestito!." << endl;
        }
        else
            cout << "Codice del Cliente invalido!" << endl;
    }

    vector<Libro>::iterator getLibro(const unsigned int codice)
    {
        vector<Libro>::iterator pos;
        for (pos = libri.begin(); pos < libri.end() && pos->codice != codice; pos++)
            ;
        return pos;
    }
    vector<Libro>::iterator getLibro(const string titolo)
    {
        vector<Libro>::iterator pos;
        for (pos = libri.begin(); pos < libri.end() && pos->nome != titolo; pos++)
            ;
        return pos;
    }

    vector<Cliente>::iterator getCliente(const unsigned int codice)
    {
        vector<Cliente>::iterator pos;
        for (pos = clienti.begin(); pos < clienti.end() && pos->codice != codice; pos++)
            ;
        return pos;
    }
    vector<Cliente>::iterator getCliente(const string codiceFiscale)
    {
        vector<Cliente>::iterator pos;
        for (pos = clienti.begin(); pos < clienti.end() && pos->codice_fiscale != codiceFiscale; pos++)
            ;
        return pos;
    }

    //tenta di prestare un libro a cliente
    //se cliente ha già un libro oppure il libro è in prestito ritorna false.
    bool presta(Cliente &cliente, Libro &libro)
    {
        if (!libro.isInPrestito() && !cliente.haLibro())
        {
            libro.setInPrestito(true);
            cliente.libro = &libro;
            return true;
        }
        return false;
    }

    bool presta(string codice_fiscale, Libro &libro)
    {
        vector<Cliente>::iterator c = getCliente(codice_fiscale);
        if (c != clienti.end())
            return presta(*c, libro);
        return false;
    }

    bool riconsegna(Cliente &cliente)
    {
        if (cliente.haLibro())
        {
            cliente.libro->setInPrestito(false);
            cliente.libro = nullptr;
            return true;
        }
        return false;
    }

    void infoClienti()
    {
        bool empty = true;
        for (int i = 0; i < clienti.size(); i++)
        {
            if (clienti[i].haLibro())
            {
                cout << "-Cliente " << clienti[i].getCodice() << " ha un libro in prestito: "
                     << clienti[i].libro->getNome()
                     << endl;
                empty = false;
            }
        }
        if (empty)
            cout << "Nessun Cliente ha un libro in prestito." << endl;
    }

    void infoLibri()
    {
        bool empty = true;
        for (int i = 0; i < clienti.size(); i++)
        {
            if (clienti[i].haLibro())
            {
                Libro &libro = *clienti[i].libro;
                cout << "-Libro \"" << libro.nome << "\" preso in prestito da " << clienti[i].getNome() << " Codice fiscale: " << clienti[i].getCodiceFiscale() << endl;
                empty = false;
            }
        }
        if (empty)
            cout << "Nessun Libro e' in prestito" << endl;
    }

    friend ostream &operator<<(ostream &os, const Biblioteca &b)
    {
        os << "Totale Libri: " << b.libri.size() << endl;
        os << "Totale Clienti: " << b.clienti.size() << endl;
        return os;
    }
};

#endif