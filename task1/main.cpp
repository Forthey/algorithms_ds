#include <fstream>
#include "list.hpp"

int compareStrings(const std::string& s1, const std::string& s2) {
    return s1.compare(s2);
}

void test() {
    using namespace std;
    cout << "�������� ��������� ��������� ����� �� words1.data � words2.data �������������� � ������, \n� ����� ���������� ��������������� �������������� ������ � ���� words12.data" << endl;
    cout << "���������� ������� � ���������..." << endl;

    Alg::List<string> list1, list2;
    ifstream file1("files/words1.data"), file2("files/words2.data");

    if (!file1.is_open() || !file2.is_open()) {
        cout << "�� ������� ����� *.data ��� �����, ����������..." << endl;
        return;
    }
    list1.readSorted(file1, compareStrings);
    list2.readSorted(file2, compareStrings);
    file1.close();
    file2.close();

    cout << "������ �������" << endl;
    cout << "������ 1 ������������?: " << (list1.sorted(compareStrings) ? "true" : "false") << endl;
    cout << "������ 2 ������������?: " << (list2.sorted(compareStrings) ? "true" : "false") << endl;

    Alg::List<std::string> list12 = (list1 + list2).sort(compareStrings);

    cout << "�������������� ������ ������������?: " << (list12.sorted(compareStrings) ? "true" : "false") << endl;
    cout << "����������� ��������������� ������ � ����..." << endl;

    ofstream file("files/words12.data");
    if (!file.is_open()) {
        cout << "��� - �� �������� ������� ���� words12.data, ����������..." << endl;
        return;
    }
    list12.display(file);
    file.close();
    cout << "������ �������" << endl;
}

void customFile() {
    using namespace std;
    string filename;

    cout << "������� ���� � ������� �����: ";
    cin >> filename;
    ifstream file1(filename);
    cout << "������� ���� �� ������� �����: ";
    cin >> filename;
    ifstream file2(filename);

    if (!file1.is_open() || !file2.is_open()) {
        cout << "���� �� ������ �� ����������, �����..." << endl;
        return;
    }

    cout << "���������� ������� � ���������..." << endl;
    Alg::List<string> list1, list2;
    list1.readSorted(file1, compareStrings);
    list2.readSorted(file2, compareStrings);
    file1.close();
    file2.close();

    cout << "������ �������" << endl;
    cout << "������ 1 ������������?: " << (list1.sorted(compareStrings) ? "true" : "false") << endl;
    cout << "������ 2 ������������?: " << (list2.sorted(compareStrings) ? "true" : "false") << endl;

    Alg::List<std::string> list12 = (list1 + list2).sort(compareStrings);

    cout << "�������������� ������ ������������?: " << (list12.sorted(compareStrings) ? "true" : "false") << endl;

    cout << "display - ������� �������������� ������" << endl;
    cout << "write - �������� ������ � ����" << endl;
    cout << "back - �����" << endl;

    std::string response;
    cout << "> ";
    cin >> response;
    if (response == "display") {
        list12.display();
    }
    else if (response == "write") {
        cout << "������� ��� �����: ";
        cin >> filename;
        ofstream file(filename);

        if (!file.is_open()) {
            cout << "���-�� �������� ������� ����, ����������..." << endl;
            return;
        }

        cout << "����������� ��������������� ������ � ����..." << endl;
        list12.display(file);
        file.close();
        cout << "������ �������" << endl;
    }
    else if (response == "back") {
        return;
    }
}

void customConsole() {
    using namespace std;
    Alg::List<string> list1, list2;
    size_t size;
    cout << "�������� ������� ������" << endl;
    cout << "������� ����� ���� � ������: ";
    cin >> size;
    cout << "������� " << size << " ���� ������:" << endl;
    list1.readSorted(size, std::cin, compareStrings);

    cout << "�������� ������� ������" << endl;
    cout << "������� ����� ���� � ������: ";
    cin >> size;
    cout << "������� " << size << " ���� ������ : " << endl;
    list2.readSorted(size, std::cin, compareStrings);

    cout << "������ �������" << endl;
    cout << "������ 1 ������������?: " << (list1.sorted(compareStrings) ? "true" : "false") << endl;
    cout << "������ 2 ������������?: " << (list2.sorted(compareStrings) ? "true" : "false") << endl;

    Alg::List<std::string> list12 = (list1 + list2).sort(compareStrings);

    cout << "�������������� ������ ������������?: " << (list12.sorted(compareStrings) ? "true" : "false") << endl;

    cout << "display - ������� �������������� ������" << endl;
    cout << "write - �������� ������ � ����" << endl;
    cout << "back - �����" << endl;

    std::string response;
    cout << "> ";
    cin >> response;
    if (response == "display") {
        list12.display();
    }
    else if (response == "write") {
        std::string filename;
        cout << "������� ��� �����: ";
        cin >> filename;
        ofstream file(filename);

        if (!file.is_open()) {
            cout << "���-�� �������� ������� ����, ����������..." << endl;
            return;
        }

        cout << "����������� ��������������� ������ � ����..." << endl;
        list12.display(file);
        file.close();
        cout << "������ �������" << endl;
    }
    else if (response == "back") {
        return;
    }
}

void custom() {
    using namespace std;
    cout << "file - ��������� ������" << endl;
    cout << "console - ������� �� �������" << endl;
    cout << "back - ��������� � �������� ����" << endl;

    std::string response;
    cout << "> ";
    cin >> response;
    if (response == "file") {
        customFile();
    }
    else if (response == "console") {
        customConsole();
    }
    else if (response == "back") {
        return;
    }
    else {
        cout << "����������� �������" << endl;
    }
}

void printMenuHelp() {
    using namespace std;
    cout << "test - ��������� �������� ���������" << endl;
    cout << "custom - ������������ ����������� ���������" << endl;
    cout << "help - ������� ��� ���� ������" << endl;
    cout << "exit - �����" << endl;

}

void menu() {
    using namespace std;
    cout << "<< N1. ������ �� ������� (������� 15) >>" << endl;
    printMenuHelp();

    bool isOpened = true;
    std::string response;
    while (isOpened) {
        cout << "> ";
        cin >> response;
        if (response == "test") {
            test();
        }
        else if (response == "custom") {
            custom();
        }
        else if (response == "help") {
            printMenuHelp();
        }
        else if (response == "exit") {
            isOpened = false;
        }
        else {
            cout << "����������� ������� (\"help\" - ������� ������ ���� ������)" << endl;
        }
    }
}

int main() {
    system("chcp 1251");
    menu();
    return 0;
}