#include <iostream>
#include <ctime>
#include <cstdlib>
#include <map>
#include <gtkmm.h>

#include "cellule.h"
#include "grid.h"


using namespace std;

void test_grid_getters(Grid g);
void test_bool_function(Cellule c,int try_nbr, float Pdeath, float Pmutation);
void test_affichages(Grid g1);
void test_division(Cellule c1, float p_mut);

int main(int argc, char* argv[]){
	
	srand(time(0));//initialise les valeurs aléatoire, a mettre au debut du code
	Cellule c1('L');// test Cellule

	Grid g1;

	
	//test_grid_getters(g1); //change le genotype de toute les cellules wtf? Erreur de segmentation quand compilé avec diffusion...
	//test_bool_function(c1,50,0.2,0.2);
	test_affichages(g1);
	//test_division(c1,0.5);
	
	return 0;
}

void test_grid_getters(Grid g){
	cout << "Taille de la grille : " << g.get_taille() << endl;
	cout << "Coefficient de diffusion D : " << g.get_coeff_diff() << endl;
	cout << "Probabilité de mort des cellules : " << g.get_p_death() << endl;
	cout << "Probabilité de mutation des cellules : " << g.get_p_mut() << endl;
	cout << "Fitness minimale nécessaire à la division : " << g.get_W_min() << endl;
	cout << "Taux métabolique Raa : " << g.get_Raa() << endl;
	cout << "Taux métabolique Rab : " << g.get_Rab() << endl;
	cout << "Taux métabolique Rbb : " << g.get_Rbb() << endl;
	cout << "Taux métabolique Rbc : " << g.get_Rbc() << endl;
}

/*void test_bool_function(Cellule c,int try_nbr, float Pdeath, float Pmutation){
	
	srand(time(0));//initialise les valeurs aléatoire, a mettre au debut du code
	int morts =0;
	int mutations=0;
	for (int i(0);i<=try_nbr;i++){
		if(c.is_dead(Pdeath)){
			morts++;
		}
		//if(c.is_mutating(Pmutation)){
		//	mutations++;
		//}
	}
	cout << morts << "morts et "<<mutations<< "mutations.\n"<<endl; //resultat bizarre je tombe sur 7 7 beaucoup trop souvent à voir..
}*/


void test_affichages(Grid g1){
	cout<<g1.zoliaffissage()<<endl;
	
	cout<<g1.zoliaffissagemet()<<endl;
	g1.step(0.5,0.5);

	cout<<g1.zoliaffissagemet()<<endl;
	g1.step(0.5,0.5);
	
	cout<<g1.zoliaffissage()<<endl;
	
}

void test_division(Cellule c1, float p_mut){
	cout<<"\n"<<"Cellule mere avant division : " << endl;
	cout << c1.getGen()<<endl;
	cout<<c1.getReseauMet()["Glucose"]<<endl;
	cout<<"\n"<<c1.getReseauMet()["Acetate"]<<endl;
	cout<<"\n"<<c1.getReseauMet()["Ethanol"]<<endl<<endl;
	
	Cellule c2(c1,p_mut);
	
	cout<<"\n"<<"Cellule mere apres division : " << endl;
	cout << c1.getGen()<<endl;
	cout<<c1.getReseauMet()["Glucose"]<<endl;
	cout<<"\n"<<c1.getReseauMet()["Acetate"]<<endl;
	cout<<"\n"<<c1.getReseauMet()["Ethanol"]<<endl<<endl;
	
	cout<<"\n"<<"Cellule fille : " << endl;
	cout << c2.getGen()<<endl;
	cout<<c2.getReseauMet()["Glucose"]<<endl;
	cout<<"\n"<<c2.getReseauMet()["Acetate"]<<endl;
	cout<<"\n"<<c2.getReseauMet()["Ethanol"]<<endl<<endl;
}
	
