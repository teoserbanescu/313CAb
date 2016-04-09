using namespace std;

#ifndef __IOSTREAM__
#define __IOSTREAM__
#include <iostream>
#endif

#ifndef __STRING__
#define __STRING__
#include <string>
#endif

#include "Produs.h"

private:
	string id_palet;
	Produs *produs;
	int nr_itemi;
	int id_slot;

public:
	
	Palet() {

	}

	Palet(string id_palet, int nr_itemi, int id_slot,int prod_type,Produs *produse) {
		this->id_palet = id_palet;
		this->nr_itemi = nr_itemi;
		this->id_slot = id_slot;
		this->produs = &produse[prod_type];
	}
	
	Palet(const Palet& x) {
		this->id_palet = x.id_palet;
		this->nr_itemi = x.nr_itemi;
		this->id_slot = x.nr_itemi;
		this->produs = x.produs; 
	}

	~Palet() {
		this->id_palet = '\0';
		this->nr_itemi = 0;
		this->id_slot = 0;
		delete produs;
	}

	Palet& operator=(const Palet& x) {
		this->id_palet = x.id_palet;
		this->nr_itemi = x.nr_itemi;
		this->id_slot = x.id_slot;
		this->produs = x.produs;
		return *this;
	}


	string getIdPalet() {
		return id_palet;
	}


	int getNrItems() {
		return nr_itemi;
	}

	int getIdSlot() {
		return id_slot;
	}

	void setIdPalet(string id_nou) {
		this->id_palet = id_nou;
	}

	void setNrItems(int nr_nou) {
		this->nr_itemi = nr_nou;
	}

	void setIdSlot(int id_nou) {
		this->id_slot = id_nou;
	}




};

int main() {

	//test
	static Produs *produse = new Produs[100];

	Palet* DEMON=new Palet("1",40,55,1,produse);
	cout << DEMON->getIdPalet() << " " << DEMON->getIdSlot() << " " << DEMON->getNrItems() << endl;

	Palet *aux = new Palet("-1", -1, -1,2,produse);
	DEMON = aux;
	cout << DEMON->getIdPalet() << " " << DEMON->getIdSlot() << " " << DEMON->getNrItems() << endl;
	
	DEMON->setIdPalet("10");
	cout << DEMON->getIdPalet() << endl;

	//l-am numit demon pentru ca facea ca posedatu la inceput..
	//test

	return 0;
}