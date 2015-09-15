#include <string>
#include <fstream>
using namespace std;
int main(int argc, char* argv[]) 
{

    ifstream inVert("shinyPlasticCellShade.vert"); // Open for reading
    ofstream outVert("shinyPlasticCellShade.h"); // Open for writing
    string vert;
    while(getline(inVert, vert)) // Discards newline char
    outVert << "\" "<< vert << "                                                                                 \\n\""<<  "\n"; // ... must add it back
    //----------------------------------------------------------
    ifstream inFrag("shinyPlasticCellShade.frag"); // Open for reading
    ofstream outFrag("shinyPlasticCellShade.hpp"); // Open for writing
    string frag;
    while(getline(inFrag, frag)) // Discards newline char
    outFrag << "\" "<< frag << "                                                                                 \\n\""<<  "\n"; // ... must add it back



}
