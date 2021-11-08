
#include "DocumentoMP3.h"
#include "DocumentoPDF.h"
#include "GestoreDocumenti.h"

int main()
{


    GestoreDocumenti gest1;
    

    DocumentoMP3 doc1("seed","ddefe",10,10);
    DocumentoMP3 doc2("eeed","ddefe",15,13);
    DocumentoPDF doc3("test","vrgg",5);

    

    gest1.aggiungiDocumento(&doc1);
    gest1.aggiungiDocumento(&doc2);
    gest1.aggiungiDocumento(&doc3);

    

    GestoreDocumenti gest2(gest1);

    gest2.ordinaElementi(1);

    

    gest1.stampaDocumenti();
    gest2.stampaDocumenti();
  

    return 0;
}