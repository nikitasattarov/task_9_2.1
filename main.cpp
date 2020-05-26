


#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
using namespace std;

void updateMap(map < string, vector < string > > &dict, string desc) {
    // �������, ������� ��������� ������� �� ������ ��������
    string::iterator id = desc.begin();
    string engWord, translation;
    while ((id != desc.end()) && (*id != ' ')) { // �������� ���������� �����
        engWord += (*id);
        ++id;
    }
    id += 3; // ����������� ����� ����
    while (id != desc.end()) {
        while ((id != desc.end()) && (*id != ',') && (*id != ' ')) {  // �������� ��������
            translation += (*id);
            ++id;
        }
        if (!translation.empty()){
            dict[translation].push_back(engWord);
            //cout << translation << '\n';
            translation.clear();
        }
        if (id != desc.end() && (*id == ',')) id += 2; // ����� �� �����

    }
}
int main() {
    // ������ ���������� �������� � ���� �������� � ��������� ������� � ������� ������� apple - malum, pomum, popula
    int n; // ���������� ���������� ����-��������
    string s;
    map < string, vector < string > > dict;

    ifstream input;
    input.open("input.txt");

    input >> n;
    getline(input, s); // �������, ����� ������� ������ ������ � ������ � �������
    s.clear();
    // ��������� ������ � ��������� �������
    for (int i = 0; i < n; ++i) {
        getline(input, s);
        updateMap(dict, s);
    }

    map < string, vector < string > > ::iterator it;
    vector<string>::iterator iv;
    // ������� ���������� ��������� � ������� � ��� ����������
    cout << dict.size() << '\n';
    for ( it = dict.begin(); it != dict.end(); it++ ) {
        cout << it->first << " - ";  // ��������� �����
        vector<string> values = it->second;
        for (iv = values.begin(); iv != values.end(); iv++)
            if (iv != values.begin()) cout << ", " << *iv; // ��������
            else cout << *iv;
        cout << '\n';
    }
    return 0;
}


