#include "StudentManagement.h"
using namespace std;

void Student::show_choice()
{
    cout << "\t\t���˵�" << endl;
    cout << "***************************************" << endl;
    cout << "1.�鿴����ѧ����Ϣ" << endl;
    cout << "2.���ѧ����Ϣ" << endl;
    cout << "3.ɾ��ѧ����Ϣ" << endl;
    cout << "4.�޸�ѧ����Ϣ" << endl;
    cout << "5.��ѯѧ����Ϣ" << endl;
    cout << "6.�˳�����" << endl;
    cout << "***************************************" << endl;
    cout << "��ѡ��: ";
}
void Student::show_student(const string& filename){
    ifstream inFile(filename);
    if(inFile.is_open()){
        if(is_file_empty(filename)){
            cout<< "δ���κ�ѧ����Ϣ!"<< endl;
        } else{
            string line;
            int count = 0;
            cout << "\n���\tѧ��\t\t����\t�Ա�\t����\tרҵ" << endl;
            while(getline(inFile,line)){
                count++;
                cout << count << "\t" << line << endl;
            }
        }
    }else{
        cout << "��ʾ: �ļ��޷���,�����ļ�!";
    }
    inFile.close();
}
bool Student::is_file_empty(const std::string &filename) {
    ifstream file(filename);
    bool isEmpty = file.peek() == ifstream::traits_type::eof();
    file.close();
    return isEmpty;
}
void Student::insert_student(const string& filename){
    cout << "������ѧ��ѧ��: ";
    getline(cin,number);
    while(!is_number(number)){
        cout << "ѧ��ѧ�Ÿ�ʽ����!����������(��ʽ: 10λ������)" << endl;
        cout << "������ѧ��ѧ��: ";
        getline(cin,number);
    }
    while(check_for_plagiarism(filename,number)){
        cout << "ѧ��ѧ���Ѵ���!����������" << endl;
        cout << "������ѧ��ѧ��: ";
        getline(cin,number);
        while(!is_number(number)){
            cout << "ѧ��ѧ�Ÿ�ʽ����!����������(��ʽ: 10λ������)" << endl;
            cout << "������ѧ��ѧ��: ";
            getline(cin,number);
        }
    }
    cout << "������ѧ������: ";
    getline(cin,name);
    cout << "������ѧ���Ա�(��/Ů): ";
    getline(cin,sex);
    while(!is_sex(sex)){
        cout << "ѧ���Ա��������!����������(��/Ů)" << endl;
        cout << "������ѧ���Ա�(��/Ů): ";
        getline(cin,sex);
    }
    cout << "������ѧ������: ";
    getline(cin,age);
    while(!is_age(age)){
        cout << "ѧ�������ʽ����!����������(������)" << endl;
        cout << "������ѧ������: ";
        getline(cin,age);
    }
    cout << "������ѧ��רҵ: ";
    getline(cin,specialized);
    ofstream outFile(filename,ios::app);
    if(outFile.is_open()){
        outFile << number << "\t" << name << "\t" << sex << "\t" << age << "\t" << specialized << endl;
        cout << "��ӳɹ��� " << number << "\t" << name << "\t" << sex << "\t" << age << "\t" << specialized << endl;
    } else{
        cout << "��ʾ: �ļ��޷���,�����ļ�!";
    }
    outFile.close();
}
bool Student::is_number(const string &str){
    for(char c:str){
        if(!isdigit(c)){
            return false;
        }
    }
    if (str.length() != 10){
        return false;
    }
    return true;
}
bool Student::is_sex(const std::string &str) {
    if(str == "��"||str == "Ů"){
        return true;
    }
    return false;
}
bool Student::is_serial_number(const std::string &str) {
    return std::all_of(str.begin(), str.end(), [](char c) {
        return isdigit(c);
    });
//    for(char c:str){
//        if(!isdigit(c)){
//            return false;
//        }
//    }
//    return true;
}
bool Student::is_age(const std::string &str) {
    return std::all_of(str.begin(), str.end(), [](char c) {
        return isdigit(c);
    });
//    for(char c:str){
//        if(!isdigit(c)){
//            return false;
//        }
//    }
//    return true;
}
//void Student::print_vector(const vector<std::string> &v) {
//    for(const auto& it : v){
//        cout << it << endl;
//    }
//}

bool Student::check_for_plagiarism(const std::string &filename, const std::string &digit) {
    ifstream inFile(filename);
    string id,line;
    while(getline(inFile,line)){
        istringstream iss(line);
        iss >> id;
        if(id == digit){
            return true;
        }
    }
    return false;
}

void Student::delete_student(const std::string &filename) {
    string serialNumber;
    cout << "������Ҫɾ����ѧ����Ϣ���: ";
    getline(cin, serialNumber);
    while(!is_serial_number(serialNumber)){
        cout << "�������!(������)" << endl;
        cout << "����������: ";
        getline(cin, serialNumber);
    }
    int serial = stoi(serialNumber);
    ifstream inFile(filename);
    if(inFile.is_open()){
        vector<string> lines;
        string line;
        while(getline(inFile,line)){
            lines.push_back(line);
        }
        inFile.close();
        while(serial < 1 || serial > lines.size()){
            cout << "�������Ч(������1~" << lines.size() << ")" << endl;
            cout << "�������������: ";
            getline(cin, serialNumber);
            serial = stoi(serialNumber);
            while(!is_serial_number(serialNumber)){
                cout << "�������!(������)" << endl;
                cout << "�������������: ";
                getline(cin, serialNumber);
                serial = stoi(serialNumber);
            }
        }
        cout << "ȷ��ɾ������ѧ����Ϣ��?" << endl;
        cout << lines.at(serial-1) << endl;
        cout << "��ѡ��(Y/n  y/n): ";
        string isSure;
        getline(cin,isSure);
        while(isSure!="y"&&isSure!="Y"&&isSure!="n"&&isSure!="N"){
            cout << "�������!(Y/N  y/n)" << endl;
            cout << "����������: ";
            getline(cin,isSure);
        }
        if (isSure == "y"||isSure == "Y"){
            lines.erase(lines.begin() + serial - 1);
            ofstream outFile(filename);
            if(outFile.is_open()){
                for(const auto& it:lines){
                    outFile << it << endl;
                }
                outFile.close();
                cout << "��ɾ����ѧ����Ϣ" << endl;
                show_student(filename);
            } else{
                cout << "��ʾ: �ļ��޷���,�����ļ�!";
            }
        }
    }else{
        cout << "��ʾ: �ļ��޷���,�����ļ�!";
        inFile.close();
    }
}
void Student::revise_student(const std::string &filename) {
    string serialNumber;
    cout << "������Ҫ�޸ĵ�ѧ����Ϣ���: ";
    getline(cin, serialNumber);
    while(!is_serial_number(serialNumber)){
        cout << "�������!(������)" << endl;
        cout << "����������: ";
        getline(cin, serialNumber);
    }
    int serial = stoi(serialNumber);
    ifstream inFile(filename);
    if(inFile.is_open()){
        vector<string> lines;
        string line;
        while(getline(inFile,line)){
            lines.push_back(line);
        }
        inFile.close();
        while(serial < 1 || serial > lines.size()){
            cout << "�������Ч(������1~" << lines.size() << ")" << endl;
            cout << "�������������: ";
            getline(cin, serialNumber);
            serial = stoi(serialNumber);
            while(!is_serial_number(serialNumber)){
                cout << "�������!(������)" << endl;
                cout << "�������������: ";
                getline(cin, serialNumber);
                serial = stoi(serialNumber);
            }
        }
        istringstream iss(lines.at(serial-1));
        string id;
        iss >> id;
        cout << "������ѧ������: ";
        getline(cin,name);
        cout << "������ѧ���Ա�(��/Ů): ";
        getline(cin,sex);
        while(!is_sex(sex)){
            cout << "ѧ���Ա��������!����������(��/Ů)" << endl;
            cout << "������ѧ���Ա�(��/Ů): ";
            getline(cin,sex);
        }
        cout << "������ѧ������: ";
        getline(cin,age);
        while(!is_age(age)){
            cout << "ѧ�������ʽ����!����������(������)" << endl;
            cout << "������ѧ������: ";
            getline(cin,age);
        }
        cout << "������ѧ��רҵ: ";
        getline(cin,specialized);

        cout << "ȷ���޸�����ѧ����Ϣ��?" << endl;
        cout << "�޸�ǰ: ";
        cout << lines.at(serial-1) << endl;
        cout << "�޸ĺ�: ";
        cout << id << "\t" << name  << "\t" << sex << "\t" << age << "\t" << specialized << endl;
        cout << "��ѡ��(Y/n  y/n): ";
        string isSure;
        getline(cin,isSure);
        while(isSure!="y"&&isSure!="Y"&&isSure!="n"&&isSure!="N"){
            cout << "�������!(Y/N  y/n)" << endl;
            cout << "����������: ";
            getline(cin,isSure);
        }
        if (isSure == "y"||isSure == "Y"){
            lines.at(serial-1) = id  + "\t" + name + "\t" + sex + "\t" + age + "\t" + specialized;
            ofstream outFile(filename);
            if(outFile.is_open()){
                for(const auto& it:lines){
                    outFile << it << endl;
                }
                outFile.close();
                cout << "���޸ĸ�ѧ����Ϣ" << endl;
                show_student(filename);
            } else{
                cout << "��ʾ: �ļ��޷���,�����ļ�!";
            }
        }
    }else{
        cout << "��ʾ: �ļ��޷���,�����ļ�!";
        inFile.close();
    }
}

void Student::select_student(const std::string &filename) {
    string choice;
    while (true){
        cout << "\t     ����ѧ����Ϣ" << endl;
        cout << "***************************************" << endl;
        cout << "1.����ѧ�Ų���" << endl;
        cout << "2.������������" << endl;
        cout << "3.�����Ա����" << endl;
        cout << "4.�����������" << endl;
        cout << "5.����רҵ����" << endl;
        cout << "6.�������˵�" << endl;
        cout << "***************************************" << endl;
        cout << "��ѡ��: ";
        getline(cin,choice);
        while(choice!="1"&&choice!="2"&&choice!="3"&&choice!="4"&&choice!="5"&&choice!="6"){
            cout << "�����������������!" << endl;
            cout << "������ѡ��: ";
            getline(cin,choice);
        }
        if(choice == "1"){
            student_number_lookup(filename);
        }else if(choice == "2"){
            student_name_lookup(filename);
        }else if(choice == "3"){
            student_sex_lookup(filename);
        }else if(choice == "4"){
            student_age_lookup(filename);
        }else if(choice == "5"){
            student_specialized_lookup(filename);
        }else if(choice == "6"){
            break;
        }
    }
}
void Student::student_number_lookup(const std::string &filename) {
    cout << "������Ҫ��ѯ��ѧ����Ϣ��ѧ��: " << endl;
    cout << "������ѧ��: ";
    getline(cin,number);
    while(!is_number(number)){
        cout << "ѧ��ѧ�Ÿ�ʽ����!����������(��ʽ: 10λ������)" << endl;
        cout << "������ѧ��ѧ��: ";
        getline(cin,number);
    }
    ifstream inFile(filename);
    string digit;
    bool isFound = false;
    if(inFile.is_open()){
        string line;
        while(getline(inFile,line)){
            istringstream iss(line);
            iss >> digit;
            if(number == digit){
                cout << "��ѯ����ѧ����ϢΪ" << endl;
                cout << "ѧ��\t\t����\t�Ա�\t����\tרҵ" << endl;
                cout << line << endl;
                isFound = true;
            }
        }
        inFile.close();
    }else{
        cout << "��ʾ: �ļ��޷���,�����ļ�!";
    }
    if(!isFound){
        cout << "δ��ѯ����ѧ����Ϣ!" << endl;
    }
}

void Student::student_name_lookup(const std::string &filename) {
    cout << "������Ҫ��ѯ��ѧ����Ϣ������: " << endl;
    cout << "����������: ";
    getline(cin,name);
    ifstream inFile(filename);
    string selectName;
    bool isFound = false;
    if(inFile.is_open()){
        string line;
        while(getline(inFile,line)){
            istringstream iss(line);
            iss >> selectName; // ����ѧ��
            iss >> selectName;
            if(name == selectName && isFound){
                cout << line << endl;
            }
            if(name == selectName && !isFound){
                cout << "��ѯ����ѧ����ϢΪ" << endl;
                cout << "ѧ��\t\t����\t�Ա�\t����\tרҵ" << endl;
                cout << line << endl;
                isFound = true;
            }
        }
        inFile.close();
    }else{
        cout << "��ʾ: �ļ��޷���,�����ļ�!";
    }
    if(!isFound){
        cout << "δ��ѯ����ѧ����Ϣ!" << endl;
    }
}
void Student::student_sex_lookup(const std::string &filename) {
    cout << "������Ҫ��ѯ��ѧ����Ϣ���Ա�: " << endl;
    cout << "�������Ա�: ";
    getline(cin,sex);
    while(!is_sex(sex)){
        cout << "ѧ���Ա��������!����������(��/Ů)" << endl;
        cout << "������ѧ���Ա�(��/Ů): ";
        getline(cin,sex);
    }
    ifstream inFile(filename);
    string selectSex;
    bool isFound = false;
    if(inFile.is_open()){
        string line;
        while(getline(inFile,line)){
            istringstream iss(line);
            iss >> selectSex; // ����ѧ��
            iss >> selectSex; // ��������
            iss >> selectSex;
            if(sex == selectSex && isFound){
                cout << line << endl;
            }
            if(sex == selectSex && !isFound){
                cout << "��ѯ����ѧ����ϢΪ" << endl;
                cout << "ѧ��\t\t����\t�Ա�\t����\tרҵ" << endl;
                cout << line << endl;
                isFound = true;
            }
        }
        inFile.close();
    }else{
        cout << "��ʾ: �ļ��޷���,�����ļ�!";
    }
    if(!isFound){
        cout << "δ��ѯ����ѧ����Ϣ!" << endl;
    }
}
void Student::student_age_lookup(const std::string &filename) {
    cout << "������Ҫ��ѯ��ѧ����Ϣ������: " << endl;
    cout << "����������: ";
    getline(cin,age);
    while(!is_age(age)){
        cout << "ѧ�������ʽ����!����������(������)" << endl;
        cout << "������ѧ������: ";
        getline(cin,age);
    }
    ifstream inFile(filename);
    string selectAge;
    bool isFound = false;
    if(inFile.is_open()){
        string line;
        while(getline(inFile,line)){
            istringstream iss(line);
            iss >> selectAge; // ����ѧ��
            iss >> selectAge; // ��������
            iss >> selectAge; //�����Ա�
            iss >> selectAge;
            if(age == selectAge && isFound){
                cout << line << endl;
            }
            if(age == selectAge && !isFound){
                cout << "��ѯ����ѧ����ϢΪ" << endl;
                cout << "ѧ��\t\t����\t�Ա�\t����\tרҵ" << endl;
                cout << line << endl;
                isFound = true;
            }
        }
        inFile.close();
    }else{
        cout << "��ʾ: �ļ��޷���,�����ļ�!";
    }
    if(!isFound){
        cout << "δ��ѯ����ѧ����Ϣ!" << endl;
    }
}
void Student::student_specialized_lookup(const std::string &filename) {
    cout << "������Ҫ��ѯ��ѧ����Ϣ��רҵ: " << endl;
    cout << "������רҵ: ";
    getline(cin,specialized);
    ifstream inFile(filename);
    string selectSpecialized;
    bool isFound = false;
    if(inFile.is_open()){
        string line;
        while(getline(inFile,line)){
            istringstream iss(line);
            iss >> selectSpecialized; // ����ѧ��
            iss >> selectSpecialized; // ��������
            iss >> selectSpecialized; // �����Ա�
            iss >> selectSpecialized; // ��������
            iss >> selectSpecialized;
            if(specialized == selectSpecialized && isFound){
                cout << line << endl;
            }
            if(specialized == selectSpecialized && !isFound){
                cout << "��ѯ����ѧ����ϢΪ" << endl;
                cout << "ѧ��\t\t����\t�Ա�\t����\tרҵ" << endl;
                cout << line << endl;
                isFound = true;
            }
        }
        inFile.close();
    }else{
        cout << "��ʾ: �ļ��޷���,�����ļ�!";
    }
    if(!isFound){
        cout << "δ��ѯ����ѧ����Ϣ!" << endl;
    }
}