#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef string famLastName;
typedef string birthday;
typedef vector<pair<famLastName, birthday>> vChilderNamesBirth;

void addFam(const famLastName &familyName, const vChilderNamesBirth &childNames, map<famLastName, vChilderNamesBirth> &mapName) {
    for (const pair<famLastName, birthday> &childNameBirth: childNames)
        mapName[familyName].push_back(childNameBirth);
}

int main(void) {
    map<famLastName, vChilderNamesBirth> family;
    pair<famLastName, vChilderNamesBirth> NarutoFamily{"Uzumaki", {{"Boruto", "10/05/2015"}, {"Himawari", "10/05/2020"}}},
                                     SasukeFamily{"Uchiha", {{"Sarada", "15/07/2015"}}},
                                     SikamaruFamily{"Nara", {{"Sidamaru", "20/03/2014"}}};

    addFam(NarutoFamily.first, NarutoFamily.second, family);
    addFam(SasukeFamily.first, SasukeFamily.second, family);
    addFam(SikamaruFamily.first, SikamaruFamily.second, family);

    for(const pair<const famLastName, vChilderNamesBirth> &fam: family) {
        cout << fam.first << " has children: " << endl;
        for (const pair<famLastName, birthday> &childName: fam.second)
            cout << childName.first << " " << childName.second << endl;
    }

    return 0;
}