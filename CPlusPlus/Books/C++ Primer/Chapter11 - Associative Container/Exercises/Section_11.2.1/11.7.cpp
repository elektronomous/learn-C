#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef string famLastName;
typedef vector<string> vChilderNames;

void addFam(const famLastName &familyName, const vChilderNames &childNames, map<famLastName, vChilderNames> &mapName) {
    for (const famLastName &childName: childNames)
        mapName[familyName].push_back(childName);
}

int main(void) {
    map<famLastName, vChilderNames> family;

    pair<famLastName, vChilderNames> NarutoFamily{"Uzumaki", {"Boruto", "Himawari"}},
                                     SasukeFamily("Uchiha", {"Sarada"}),
                                     SikamaruFamily("Nara", {"Sidamaru"});

    addFam(NarutoFamily.first, NarutoFamily.second, family);
    addFam(SasukeFamily.first, SasukeFamily.second, family);
    addFam(SikamaruFamily.first, SikamaruFamily.second, family);

    for(const pair<const famLastName, vChilderNames> &fam: family) {
        cout << fam.first << " has children: " << endl;
        for (const string &childName: fam.second)
            cout << childName << " ";
        cout << endl;
    }

    return 0;
}