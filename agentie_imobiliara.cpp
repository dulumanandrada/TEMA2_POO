//|=================== TEMA 2 POO ======================|// 
//| link GitHub:                                        |//
//|     https://github.com/dulumanandrada/TEMA2_POO     |//
//|                                                     |//
//|=====================================================|//


#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>
#define N 10001

using namespace std;


//==================== LOCUINTA ====================//
//clasa abstracta --->vazuta ca interfata ---> nu poate instantia obiecte
class Locuinta
{
    //encapsulare 
protected:    
    string numeClient;
    int suprafataUtila;
    float discount;

public:
    virtual void citire();
    virtual void afisare();
    friend istream& operator>> (istream&, Locuinta&);
    friend ostream& operator<< (ostream&, Locuinta&);
    virtual float CalculChirie(int x, int y) = 0;

    //get-eri:
    string getNumeClient(){return numeClient;}

    bool operator== (Locuinta& l1)
    {
        return numeClient == l1.numeClient && suprafataUtila == l1.suprafataUtila && discount == l1.discount;
    }

    Locuinta& operator= (Locuinta& l)
    {
        if(this != &l)
        {
            this->numeClient = l.numeClient;
            this->suprafataUtila = l.suprafataUtila;
            this->discount = l.discount;
        }
        return *this;
    }
    
    //constructori:
    Locuinta()
    {
        numeClient = "";
        suprafataUtila = 0;
        discount = 0;
    }

    Locuinta(string s, int sU, float d)
    {
        numeClient = s;         
        suprafataUtila = sU;    
        discount = d;          
    }

    Locuinta(const Locuinta& l)
    {
        numeClient = l.numeClient;
        suprafataUtila = l.suprafataUtila;
        discount = l.discount;
    }

    ///=> memory leak ------> se rezolva prin destructor virtual:
    virtual ~Locuinta() {cout << "~Locuinta \n";}
};

void Locuinta::citire()
{
    //exceptiile:
    bool ok = 0;
    do
    {
        if(ok > 0) cout << "Incercati din nou: \n";
        try
        {
            cout << "Nume client: ";
            cin >> numeClient;
            for(int i = 0; numeClient[i]; i++)
                if(isalpha(numeClient[i]) == 0) throw -9;     

            cout << "Suprafata utila: ";
            cin >> suprafataUtila;    
            if(suprafataUtila < 0) throw -1;
        
            cout << "Discount: ";
            cin >> discount;
            if(discount > 100) throw -13;
            else if(discount < 0) throw -14;  
            ok = 0;
        }
    
        catch(int n)
        {
            if(n == -1)
                cout << "Valoarea introdusa pentru suprafata utila este invalida! Aceasta nu poate fi un numar negativ! \n";
            else if(n == -9) cout << "Numele introdus este unul invalid! \n";
            else if(n == -13) cout << "Valoarea introdusa pentru discount este invalida! Aceasta nu poate fi mai mare de 100%! \n";
            else if(n == -14) cout << "Valoarea introdusa pentru discount este invalida! Aceasta nu poate fi una negativa! \n";
            ok = 1;
        }
    }while(ok != 0);
}

void Locuinta::afisare()
{
    cout << "Nume client: ";
    cout << numeClient << "\n";
    cout << "Suprafata utila: ";
    cout << suprafataUtila << "\n";
    cout << "Discount: ";
    cout << discount << "\n"; 
}

istream& operator>> (istream& in, Locuinta& l)
{
    //exceptiile:
    bool ok = 0;
    do
    {
        if(ok > 0) cout << "Incercati din nou: \n";
        try
        {
            cout << "Nume client: ";
            in >> l.numeClient;
            for(int i = 0; l.numeClient[i]; i++)
                if(isalpha(l.numeClient[i]) == 0) throw -9;     

            cout << "Suprafata utila: ";
            in >> l.suprafataUtila;    
            if(l.suprafataUtila < 0) throw -1;
        
            cout << "Discount: ";
            in >> l.discount;
            if(l.discount > 100) throw -13;
            else if(l.discount < 0) throw -14;  
            ok = 0;
        }
    
        catch(int n)
        {
            if(n == -1)
                cout << "Valoarea introdusa pentru suprafata utila este invalida! Aceasta nu poate fi un numar negativ! \n";
            else if(n == -9) cout << "Numele introdus este unul invalid! \n";
            else if(n == -13) cout << "Valoarea introdusa pentru discount este invalida! Aceasta nu poate fi mai mare de 100%! \n";
            else if(n == -14) cout << "Valoarea introdusa pentru discount este invalida! Aceasta nu poate fi una negativa! \n";
            ok = 1;
        }
    }while(ok != 0);
    return in;
}

ostream& operator<< (ostream& out, Locuinta& l)
{
    cout << "Nume client: ";
    out << l.numeClient << "\n";
    cout << "Suprafata utila: ";
    out << l.suprafataUtila << "\n";
    cout << "Discount: ";
    out << l.discount << "\n";
    return out;
}

//================== APARTAMENT ===================//
class Apartament: public Locuinta
{
    int etaj;

public:
    void citire();
    void afisare();
    friend istream& operator>> (istream&, Apartament&);
    friend ostream& operator<< (ostream&, Apartament&);
    float CalculChirie(int x, int y);

    Apartament& operator= (Apartament& a)
    {
        if(this != &a)
        {
            this->Locuinta::operator=(a);
            this->etaj = a.etaj;
        }
        return *this;
    }

    bool operator== (Apartament& a)
    {
        return Locuinta::operator==(a) && etaj == a.etaj;
    }

    //constructori:
    Apartament():Locuinta()
    {
        etaj = 0;
    }
    Apartament(string s, int sU, float d, int e);

    ///destructor:
    ~Apartament() {cout << "~Apartament \n";}
};

Apartament:: Apartament(string s, int sU = 0, float d = 0, int e = 0): Locuinta(s, sU, d)
{
    etaj = e;
}

void Apartament::citire()
{
    Locuinta::citire();
    cout << "Etaj: ";
    cin >> etaj;
}

void Apartament::afisare()
{
    cout << "Locuinta de tip: Apartament \n";
    Locuinta::afisare();
    cout << "Etaj: ";
    cout << etaj << "\n";
}

istream& operator>> (istream& in, Apartament& a)
{
    in >> dynamic_cast<Locuinta&> (a);
    cout << "Etaj: ";
    in >> a.etaj;
    return in;
}

ostream& operator<< (ostream& out, Apartament& a)
{
    out << "Locuinta de tip: Apartament \n";
    out << dynamic_cast<Locuinta&> (a);
    out << "Etaj: ";
    out << a.etaj << "\n";
    return out;
}


float Apartament::CalculChirie(int x, int y)
{
    float chirie;
    chirie = x * suprafataUtila * (1 - y * discount / 100.0);
    return chirie;   
}


//===================== CASA =====================//
class Casa: public Locuinta
{
    int suprafataCurte;

public:
    void citire();
    void afisare();
    friend istream& operator>> (istream&, Casa&);
    friend ostream& operator<< (ostream&, Casa&);
    float CalculChirie(int x, int y);

    Casa& operator= (Casa& c)
    {
        if(this != &c)
        {
            this->Locuinta::operator=(c);
            this->suprafataCurte = c.suprafataCurte;
        }
        return *this;
    }

    //constructori:
    Casa():Locuinta()
    {
        suprafataCurte = 0;
    }

    Casa(string s, int sU, float d, int sC);

    ///destructor:
    ~Casa() {cout << "~Casa \n";}
};

Casa:: Casa(string s, int sU = 0, float d = 0, int sC = 0): Locuinta(s, sU, d)
{
    suprafataCurte = sC;
}

void Casa::citire()
{
    Locuinta::citire();
    bool ok = 0;
    do
    {
        if(ok > 0) cout << "Incercati din nou: \n";
        try
        {
            cout << "Suprafata curte: ";
            cin >> suprafataCurte;
            if(suprafataCurte < 0) throw -20; 
            ok = 0;
        }
        catch(int x)
        {
            if(x == -20) 
                cout << "Valoarea introdusa pentru suprafata de curte este invalida! Aceasta nu poate fi un numar negativ! \n"; 
            ok = 1;
        }
        
    } while (ok != 0);
}

void Casa::afisare()
{
    cout << "Locuinta de tip: Casa \n";
    Locuinta::afisare();
    cout << "Suprafata curte: ";
    cout << suprafataCurte << "\n";
}

istream& operator>> (istream& in, Casa& c)
{
    in >> dynamic_cast<Locuinta&> (c);
    bool ok = 0;
    do
    {
        if(ok > 0) cout << "Incercati din nou: \n";
        try
        {
            cout << "Suprafata curte: ";
            in >> c.suprafataCurte;
            if(c.suprafataCurte < 0) throw -20; 
            ok = 0;
        }
        catch(int x)
        {
            if(x == -20) 
                cout <<"Valoarea introdusa pentru suprafata de curte este invalida! Aceasta nu poate fi un numar negativ! \n"; 
            ok = 1;
        }
        
    } while (ok != 0);
    return in;
}

ostream& operator<< (ostream& out, Casa& c)
{
    out << "Locuinta de tip: Casa \n";
    out << dynamic_cast<Locuinta&> (c);
    out << "Suprafata curte: ";
    out << c.suprafataCurte << "\n";
    return out;
}

float Casa::CalculChirie(int x, int y)
{
    float chirie;
    chirie = x * (suprafataUtila + 0.2 * suprafataCurte) * (1 - y * discount / 100.0);
    return chirie;
}


//=============== AGENTIE IMOBILIARA ===============//
class AgentieImobiliara
{
    vector<Locuinta*> L;      ///vector de pointeri la obiecte de tip Locuinta alocat dinamic
    int NR;

    //date statice:
    static int nrCase;
    static int nrApartamente;

public:
    void afisareChirie(int x, int y); 
    int nrlocClient(string nume);
    float minChirie();
    float maxChirie();
    void afisareMinChirie();
    void afisareMaxChirie();
    void afisareLocuinteBuget(float vmin, float vmax, int pret, int d);
    friend istream& operator>>(istream&, AgentieImobiliara&);
    friend ostream& operator<<(ostream&, AgentieImobiliara&);

    //constructori:
    AgentieImobiliara()
    { NR = 0;}

    AgentieImobiliara(const AgentieImobiliara& ai)
    {
        NR = ai.NR;
        L = ai.L;
    }

    //destructor:
    ~AgentieImobiliara() {cout << "~AgentieImobiliara \n";}

    void addApartament()
    {
        L.push_back(new Apartament("")); 
        L[NR]->citire(); 
        NR++;
        AgentieImobiliara::nrApartamente++; 
    }

    void addCasa()
    {
        L.push_back(new Casa(""));
        L[NR]->citire();
        NR++;
        AgentieImobiliara::nrCase++;
    }

    void deleteLocuinta(int nr)
    {
        if(typeid(*L[nr-1]) == typeid(Apartament)) AgentieImobiliara::nrApartamente--;
        else if(typeid(*L[nr-1]) == typeid(Casa)) AgentieImobiliara::nrCase--;
        for(int i = nr-1; i < NR-1; i++)
            L[i] = L[i+1];
        L.pop_back();
        NR--;
    }

    //functii statice:
    static void afisNrCase() 
    { 
        cout << "In aceasta agentie imobiliara sunt " << AgentieImobiliara::nrCase << " case. \n"; 
    }               
    static void afisNrApartamente() 
    { 
        cout << "In aceasta agentie imobiliara sunt " << AgentieImobiliara::nrApartamente << " apartamente. \n"; 
    }

    //get-eri:
    int getNR(){return NR;}
};

int AgentieImobiliara::nrCase;
int AgentieImobiliara::nrApartamente;

istream& operator>> (istream& in, AgentieImobiliara& a)
{
    cout << "Cate locuinte sunt? \n";
    in >> a.NR;

    if(a.NR > 0)
    {
    cout << "Care sunt acestea? \n";
    for(int i = 0; i < a.NR; i++)
    {
        int op;
        cout << "Tip de locuinta: 1-Apartament 2-Casa \n";
        in >> op;   
        switch(op)
        {   //upcasting
            case 1: {a.L.push_back(new Apartament("")); a.L[i]->citire(); AgentieImobiliara::nrApartamente++; break;} 
            case 2: {a.L.push_back(new Casa("")); a.L[i]->citire(); AgentieImobiliara::nrCase++; break;} 
        }
    }
    }
    else cout << "Insuficiente locuinte! \n";
    return in;
}

ostream& operator<< (ostream& out, AgentieImobiliara& a)
{
    int i = 1;
    out << "\n";
    out << "Agentia imobiliara are " << a.NR  << " locuinte: \n";
    for(auto p = a.L.begin(); p != a.L.end(); p++,i++)
    {
        out << i << ". ";
        if(typeid(**p) == typeid(Apartament))   //downcasting
            {
                out << * dynamic_cast<Apartament*>(*p) << "\n";
            }

        else if(typeid(**p) == typeid(Casa))
            {
                out << * dynamic_cast<Casa*>(*p) << "\n";
            }
    }
    return out;
}

void AgentieImobiliara::afisareChirie(int x, int y)
{
    int i = 1;
    cout << "\n";
    cout << "Agentia imobiliara are " << NR  << " locuinte: \n";
    for(auto p = L.begin(); p != L.end(); p++,i++)
    {
        cout << i << ". ";
        if(typeid(**p) == typeid(Apartament)) 
            {
                cout << "Chiria/luna: ";
                cout << (* dynamic_cast<Apartament*>(*p)).CalculChirie(x, y) << "\n";
            }

        else if(typeid(**p) == typeid(Casa))
            {
                cout << "Chiria/luna: ";
                cout << (* dynamic_cast<Casa*>(*p)).CalculChirie(x, y) << "\n";
            }
    }
}

int AgentieImobiliara::nrlocClient(string nume)
{
    int ct = 0;
    for(int i = 0; i < NR; i++)
        if(L[i]->getNumeClient() == nume) ct ++;
    return ct;
}

float AgentieImobiliara::minChirie()
{
    float vmin;
    auto p = L.begin();
    if(typeid(**p) == typeid(Apartament))   
        vmin = (* dynamic_cast<Apartament*>(*p)).CalculChirie(1, 1); 
    else if(typeid(**p) == typeid(Casa))
        vmin = (* dynamic_cast<Casa*>(*p)).CalculChirie(1, 1);

    for(auto p = L.begin() + 1; p != L.end(); p++)
    {
        if(typeid(**p) == typeid(Apartament)) 
                {if((* dynamic_cast<Apartament*>(*p)).CalculChirie(1, 1) < vmin) vmin = (* dynamic_cast<Apartament*>(*p)).CalculChirie(1, 1);} 
        else if(typeid(**p) == typeid(Casa))
                {if((* dynamic_cast<Casa*>(*p)).CalculChirie(1, 1) < vmin) vmin = (* dynamic_cast<Casa*>(*p)).CalculChirie(1, 1);} 
    }
    return vmin;
}

float AgentieImobiliara::maxChirie()
{
    float vmax;
    auto p = L.begin();
    if(typeid(**p) == typeid(Apartament))  
        vmax = (* dynamic_cast<Apartament*>(*p)).CalculChirie(1, 1); 
    else if(typeid(**p) == typeid(Casa))
        vmax = (* dynamic_cast<Casa*>(*p)).CalculChirie(1, 1);

    for(auto p = L.begin() + 1; p != L.end(); p++)
    {
        if(typeid(**p) == typeid(Apartament))  
                {if((* dynamic_cast<Apartament*>(*p)).CalculChirie(1, 1) > vmax) vmax = (* dynamic_cast<Apartament*>(*p)).CalculChirie(1, 1);}
        else if(typeid(**p) == typeid(Casa))
                {if((* dynamic_cast<Casa*>(*p)).CalculChirie(1, 1) > vmax) vmax = (* dynamic_cast<Casa*>(*p)).CalculChirie(1, 1);} 
    }
    return vmax;
}

void AgentieImobiliara::afisareMinChirie()
{
    float vmin = minChirie();
    int k = 0;
    for(auto p = L.begin(); p != L.end(); p++)
    {
        if(typeid(**p) == typeid(Apartament))  
                {if((* dynamic_cast<Apartament*>(*p)).CalculChirie(1, 1) == vmin) cout << ++k << ". " << * dynamic_cast<Apartament*>(*p) << "\n";}
        else if(typeid(**p) == typeid(Casa))
                {if((* dynamic_cast<Casa*>(*p)).CalculChirie(1, 1) == vmin) cout << ++k << ". " << * dynamic_cast<Casa*>(*p) << "\n";} 
    }
}

void AgentieImobiliara::afisareMaxChirie()
{
    float vmax = maxChirie();
    int k = 0;
    for(auto p = L.begin(); p != L.end(); p++)
    {
        if(typeid(**p) == typeid(Apartament))  
                {if((* dynamic_cast<Apartament*>(*p)).CalculChirie(1, 1) == vmax) cout << ++k << ". " << * dynamic_cast<Apartament*>(*p) << "\n";}
        else if(typeid(**p) == typeid(Casa))
                {if((* dynamic_cast<Casa*>(*p)).CalculChirie(1, 1) == vmax) cout << ++k << ". " << * dynamic_cast<Casa*>(*p) << "\n";} 
    }
}

void AgentieImobiliara::afisareLocuinteBuget(float vmin, float vmax, int pret, int d)
{
    int k = 0;
    for(auto p = L.begin(); p != L.end(); p++)
    {
        if(typeid(**p) == typeid(Apartament))  
                {
                    float PRET = (* dynamic_cast<Apartament*>(*p)).CalculChirie(pret, d);
                    if(PRET >= vmin && PRET <= vmax) 
                        cout << ++k << ". " << * dynamic_cast<Apartament*>(*p) << "Chiria: " << PRET << "\n\n";
                }
        else if(typeid(**p) == typeid(Casa))
                {
                    float PRET = (* dynamic_cast<Casa*>(*p)).CalculChirie(pret, d);
                    if(PRET >= vmin && PRET <= vmax) 
                        cout << ++k << ". " << * dynamic_cast<Casa*>(*p) << "Chiria: " << PRET << "\n\n";
                }
    }
}


//===================== MENIU =====================//
void AfisareMeniu()
{
    cout << "\n";
    cout << "Acesta este meniul aplicatiei. \n" << "Pentru a executa o anumita comanda apasati tasta corespunzatoare nr. din fata fiecarei operatii din lista de mai jos: \n";
    cout << "0. Opriti acest proces acum. \n"; 
    cout << "1. Introduceti primele date in agentia imobiliara. \n"; 
    cout << "2. Adaugati locuinte in agentie. \n"; 
    cout << "3. Eliminati locuinte din agentie. \n"; 
    cout << "4. As vrea sa stiu cate case/apartamente sunt in agentia imobiliara. \n"; 
    cout << "5. As vrea sa aflu de cate locuinte este interesat un anumit client. \n"; 
    cout << "6. Cautati optiunea ideala de locuinta. \n"; 
    cout << "7. Calculati pretul pentru fiecare locuinta in functie de pretul actual de pe piata. \n"; 
    cout << "8. Care este cea mai ieftina locuinta pusa la dispozitie? Dar cea mai scumpa? \n"; 
    cout << "9. Afisati toate locuintele din agentia imobiliara. \n"; 
    cout << "\n";
}


//===================== MAIN =====================//
int main()
{
    //declararea datelor necesare:
    int op;
    AgentieImobiliara A;

    AfisareMeniu();
    cout << "Ce comanda doriti sa executati? \n";
    cin >> op;
    while(op)
    {
        try
        {
            if(op < 0 || op > 10) throw -1;
            else
            {
                if(op == 1) cin >> A;
                
                if(op == 2)
                {
                    try
                    {
                        cout << "Ce tip de locuinta adaugati? 1-Apartament 2-Casa \n";
                        int tip;
                        cin >> tip;
                        if(tip == 1) A.addApartament();
                        else if(tip == 2) A.addCasa();
                        else throw 10;
                    }
                    catch(int x)
                    {
                        if(x == 10) cout << "ERROR! Nu exista acest tip de locuinte. \n";
                    }
                }

                if(op == 3)
                {
                    try
                    {
                        cout << "Locuinta cu ce numar doriti sa eliminati? \n";
                        int nr;
                        cin >> nr;
                        if(nr <= A.getNR() && nr > 0) A.deleteLocuinta(nr);
                        else if(nr > A.getNR()) throw 55;
                        else if(nr <= 0) throw 56;
                    }
                    catch(int x)
                    {
                        if(x == 55) cout << "ERROR! Nu exista asa multe locuinte. \n";
                        else if(x == 56) cout << "ERROR! Indicele nu poate fi <= 0. \n";
                    }
                    
                }

                if(op == 4)
                {
                    try
                    {
                        cout << "Pentru ce tip de locuinta doriti sa aflati numarul? 1-Apartament 2-Casa \n";
                        int tip;
                        cin >> tip;
                        if(tip == 1) A.afisNrApartamente();
                        else if(tip == 2) A.afisNrCase();
                        else throw 11;
                    }
                    catch(int x)
                    {
                        if(x == 11) cout << "ERROR! Nu exista acest tip de locuinte. \n";
                    }
                }
                
                if(op == 5)
                {
                    try
                    {
                        cout << "Care este numele clientului? \n";
                        string nume;
                        cin >> nume;
                        if(A.nrlocClient(nume) > 0) cout << nume << " este interesat de " << A.nrlocClient(nume) << " locuinte. \n";
                        else throw 77;
                    }
                    catch(int x)
                    {
                        if(x == 77) cout << "ERROR! Aceasta persoana nu este un client al agentiei. \n";
                    }   
                }

                if(op == 6)
                {
                    try
                    {
                        float vmin, vmax;
                        int pret, d;
                        cout << "Care este tariful actual pentru chirie /mp? (nr. intreg) \n";
                        cin >> pret;
                        if(pret < 0) throw 18;
                        cout << "Se aplica discountul pentru fiecare locuinta? 1-da 0-nu \n";
                        cin >> d;
                        if(d < 0 || d > 100) throw 19;
                        cout << "Care este bugetul dumneavoastra? \n";
                        cout << "Limita minima: ";
                        cin >> vmin;
                        cout << "Limita maxima: ";
                        cin >> vmax;
                        if(vmin > vmax) throw 20;
                        else if(vmax < A.minChirie()) throw 21;
                        else if(vmin > A.maxChirie()) throw 22;
                        else 
                        {
                            cout << "Acestea ar fi locuintele ideale pentru tine: \n";
                            A.afisareLocuinteBuget(vmin, vmax, pret, d);
                        }
                    }
                    catch(int x)
                    {
                        if(x == 18) cout << "ERROR! Valoarea chiriei pe mp nu poate fi <= 0. \n";
                        else if(x == 19) cout << "ERROR! Valoarea discountului nu poate fi mai mare de 100%, sau negativa.";
                        else if(x == 20) cout << "ERROR! Valoarea minima trebuie sa fie <= decat cea maxima. \n";
                        else if(x == 21) cout << "Ne pare rau...Locuintele noastre sunt prea scumpe pentru tine. \n";
                        else if(x == 22) cout << "Ne pare rau...Locuintele noastre sunt prea ieftine pentru tine. \n";
                    }
                    
                }

                if(op == 7)
                {
                    try
                    {
                        int pret;
                        int d;
                        cout << "Care este tariful actual pentru chirie /mp? (nr. intreg) \n";
                        cin >> pret;
                        cout << "Se aplica discountul pentru fiecare locuinta? 1-da 0-nu \n";
                        cin >> d;
                        if(pret > 0 && (d == 0 || d == 1)) A.afisareChirie(pret, d);
                        else throw 23;
                    }
                    catch(int x)
                    {
                        if(x == 23) cout << "ERROR! Valoarea chiriei pe mp nu poate fi <= 0, iar discountul diferit de 0 sau 1. \n";
                    }
                    
                }

                if(op == 8)
                {
                    cout << "Cea mai ieftina locuinta este: " << "\n";
                    A.afisareMinChirie();
                    cout << "Cea mai scumpa locuinta este: " << "\n";
                    A.afisareMaxChirie();
                }
               
                if(op == 9) cout << A;
            }
        }
        catch(int x)
        {
            if(x == -1)
            {
                cout << "ERROR! Aceasta optiune nu este una valida. Mai incercati o data va rugam! \n";
            }
        }

        cout << "Ce comanda doriti sa executati? \n";
        cin >> op; 
    }

    return 0;
}





















