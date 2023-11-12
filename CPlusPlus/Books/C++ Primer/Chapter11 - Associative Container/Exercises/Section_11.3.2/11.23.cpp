#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

typedef string famLastName;
typedef vector<famLastName> vChildren;

void addFamily(multimap<famLastName, vChildren> &shippudenFam, pair<famLastName, vChildren> &famName) {
    shippudenFam.insert(famName);
}

int main(void) {
    multimap<famLastName, vChildren> narutoShipuddenFamily;

    pair<famLastName, vChildren> kushinaFamily {"Uzumaki", {"Naruto Uzumaki"}},
                                 narutoFamily {"Uzumaki", {"Boruto", "Himawari"}},
                                 fugakuFamily {"Uchiha", {"Sasuke", "Itachi"}},
                                 sasukeFamily {"Uchiha", {"Sarada"}},
                                 shikamaruFamily {"Nara", {"Shikadai"}};

    addFamily(narutoShipuddenFamily, kushinaFamily);
}