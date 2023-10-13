#include "StudentManagement.h"
using namespace std;
int main(){
    string choice;
    string filename = "学生信息.txt";
    ifstream file(filename);
    if (!file.good()) {
        file.close();
        ofstream newFile(filename ,ios::out | std::ios::binary);
        if (newFile){
            cout << "没有发现学生信息文件,已自动创建学生信息文件" << endl;
            cout << "提示: 创建的文件为空文件,没有任何学生信息,若要查看学生信息先添加学生信息" << endl;
            newFile.close();
        } else{
            cout << "无法创建学生信息文件! " << endl;
        }
    }else{
        file.close();
    }
    Student student{};
    while (true){
        student.show_choice();
        getline(cin,choice);
        while(choice!="1"&&choice!="2"&&choice!="3"&&choice!="4"&&choice!="5"&&choice!="6"){
            cout << "输入错误请重新输入!" << endl;
            cout << "请重新选择: ";
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