#include "StudentManagement.h"
using namespace std;
int main(){
    string choice;
    string filename = "ѧ����Ϣ.txt";
    ifstream file(filename);
    if (!file.good()) {
        file.close();
        ofstream newFile(filename ,ios::out | std::ios::binary);
        if (newFile){
            cout << "û�з���ѧ����Ϣ�ļ�,���Զ�����ѧ����Ϣ�ļ�" << endl;
            cout << "��ʾ: �������ļ�Ϊ���ļ�,û���κ�ѧ����Ϣ,��Ҫ�鿴ѧ����Ϣ�����ѧ����Ϣ" << endl;
            newFile.close();
        } else{
            cout << "�޷�����ѧ����Ϣ�ļ�! " << endl;
        }
    }else{
        file.close();
    }
    Student student{};
    while (true){
        student.show_choice();
        getline(cin,choice);
        while(choice!="1"&&choice!="2"&&choice!="3"&&choice!="4"&&choice!="5"&&choice!="6"){
            cout << "�����������������!" << endl;
            cout << "������ѡ��: ";
            getline(cin,choice);
        }
        if(choice == "1"){
            student.show_student(filename);
        }else if(choice == "2"){
            student.insert_student(filename);
        }else if(choice == "3"){
            student.delete_student(filename);
        }else if(choice == "4"){
            student.revise_student(filename);
        }else if(choice == "5"){
            student.select_student(filename);
        }else if(choice == "6"){
            cout << "Bye Bye~" << endl;
            break;
        }
    }



    return 0;
}