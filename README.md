# TEMA2_POO

Se dau clasele: 
1. Locuință (string numeClient, int suprafataUtila, float discount) 
2. Apartament (int etaj) : Locuinta 
3. Casa (int suprafataCurte) : Locuinta 

- La clasa **Locuinta** se va adauga metoda virtuala pura **CalculChirie (X,Y)** 
cu: X = valoare standard chirie/mp(intreg), Y=1 daca se ia in considerare discountul 
si 0 daca nu se ia in considerare. 

- Metoda va fi adaugata in clasa:
**Apartament** dupa formula X*suprafataUtila*(1-Y*discount/100.0), 
respectiv in clasa **Casa** dupa formula X*(suprafataUtila + 0.2*suprafataCurte) * (1-Y*discount/100.0). 

- Metodele vor fi testate prin parcurgerea unui **vector de pointeri la Locuinta**, incarcat 
cu obiecte de tip Apartament si Casa. 

- Se defineste clasa AgentieImobiliara continand un vector de pointeri la obiecte de tip 
Locuinta alocat dinamic. Se va supraincarca operatorul >> pentru a citi locuintele agentiei si 
operatorul << pentru afisarea lor. 

 ### MENIUL:
  
0. Opriti acest proces acum. 
1. Introduceti primele date in agentia imobiliara.
2. Adaugati locuinte in agentie.
3. Eliminati locuinte din agentie. 
4. As vrea sa stiu cate case/apartamente sunt in agentia imobiliara. 
5. As vrea sa aflu de cate locuinte este interesat un anumit client. 
6. Cautati optiunea ideala de locuinta.
7. Calculati pretul pentru fiecare locuinta in functie de pretul actual de pe piata. 
8. Care este cea mai ieftina locuinta pusa la dispozitie? Dar cea mai scumpa? 
9. Afisati toate locuintele din agentia imobiliara.
