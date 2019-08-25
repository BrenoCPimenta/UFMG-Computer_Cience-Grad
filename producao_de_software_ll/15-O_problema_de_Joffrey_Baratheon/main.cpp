#include <iostream>
#include "houses.hpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
	
	houseBaratheonofKingsLanding Joffrey;	
	Joffrey.setName("Joffrey Baratheon");
	Joffrey.Allegiance();
	Joffrey.Common();
	Joffrey.Words();	

	houseLannister Cersei;
	Cersei.setName("Cersei Lannister");
	Cersei.Allegiance();
	Cersei.Common();
	Cersei.Words(false);
	
	houseBaratheon Robert;
	Robert.setName("Robert Baratheon");
	Robert.Allegiance();
	Robert.Words();

}
