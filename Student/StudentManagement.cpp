#include "StudentManagement.h"
using namespace std;

void Student::show_choice()
{
    cout << "\t\t主菜单" << endl;
    cout << "***************************************" << endl;
    cout << "1.查看所有学生信息" << endl;
    cout << "2.添加学生信息" << endl;
    cout << "3.删除学生信息" << endl;
    cout << "4.修改学生信息" << endl;
    cout << "5.查询学生信息" << endl;
    cout << "6.退出程序" << endl;
    cout << "***************************************" << endl;
    cout << "请选择: ";
}
void Student::show_student(const string& filename){
    ifstream inFile(filename);
    if(inFile.is_open()){
        if(is_file_empty(filename)){
            cout<< "未有任何学生信息!"<< endl;
        } else{
            string line;
            int count = 0;
            cout << "\n序号\t学号\t\t姓名\t性别\t年龄\t专业" << endl;
            while(getline(inFile,line)){
                count++;
                cout << count << "\t" << line << endl;
            }
        }
    }else{
        cout << "提示: 文件无法打开,请检查文件!";
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
    cout << "请输入学生学号: ";
    getline(cin,number);
    while(!is_number(number)){
        cout << "学生学号格式错误!请重新输入(格式: 10位纯数字)" << endl;
        cout << "请输入学生学号: ";
        getline(cin,number);
    }
    while(check_for_plagiarism(filename,number)){
        cout << "学生学号已存在!请重新输入" << endl;
        cout << "请输入学生学号: ";
        getline(cin,number);
        while(!is_number(number)){
            cout << "学生学号格式错误!请重新输入(格式: 10位纯数字)" << endl;
            cout << "请输入学生学号: ";
            getline(cin,number);
        }
    }
    cout << "请输入学生姓名: ";
    getline(cin,name);
    cout << "请输入学生性别(男/女): ";
    getline(cin,sex);
    while(!is_sex(sex)){
        cout << "学生性别输入错误!请重新输入(男/女)" << endl;
        cout << "请输入学生性别(男/女): ";
        getline(cin,sex);
    }
    cout << "请输入学生年龄: ";
    getline(cin,age);
    while(!is_age(age)){
        cout << "学生年龄格式错误!请重新输入(纯数字)" << endl;
        cout << "请输入学生年龄: ";
        getline(cin,age);
    }
    cout << "请输入学生专业: ";
    getline(cin,specialized);
    ofstream outFile(filename,ios::app);
    if(outFile.is_open()){
        outFile << number << "\t" << name << "\t" << sex << "\t" << age << "\t" << specialized << endl;
        cout << "添加成功： " << number << "\t" << name << "\t" << sex << "\t" << age << "\t" << specialized << endl;
    } else{
        cout << "提示: 文件无法打开,请检查文件!";
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
    if(str == "男"||str == "女"){
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
    cout << "请输入要删除的学生信息序号: ";
    getline(cin, serialNumber);
    while(!is_serial_number(serialNumber)){
        cout << "输入错误!(纯数字)" << endl;
        cout << "请重新输入: ";
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
            cout << "该序号无效(请输入1~" << lines.size() << ")" << endl;
            cout << "请重新输入序号: ";
            getline(cin, serialNumber);
            serial = stoi(serialNumber);
            while(!is_serial_number(serialNumber)){
                cout << "输入错误!(纯数字)" << endl;
                cout << "请重新输入序号: ";
                getline(cin, serialNumber);
                serial = stoi(serialNumber);
            }
        }
        cout << "确认删除以下学生信息吗?" << endl;
        cout << lines.at(serial-1) << endl;
        cout << "请选择(Y/n  y/n): ";
        string isSure;
        getline(cin,isSure);
        while(isSure!="y"&&isSure!="Y"&&isSure!="n"&&isSure!="N"){
            cout << "输入错误!(Y/N  y/n)" << endl;
            cout << "请重新输入: ";
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
                cout << "已删除该学生信息" << endl;
                show_student(filename);
            } else{
                cout << "提示: 文件无法打开,请检查文件!";
            }
        }
    }else{
        cout << "提示: 文件无法打开,请检查文件!";
        inFile.close();
    }
}
void Student::revise_student(const std::string &filename) {
    string serialNumber;
    cout << "请输入要修改的学生信息序号: ";
    getline(cin, serialNumber);
    while(!is_serial_number(serialNumber)){
        cout << "输入错误!(纯数字)" << endl;
        cout << "请重新输入: ";
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
            cout << "该序号无效(请输入1~" << lines.size() << ")" << endl;
            cout << "请重新输入序号: ";
            getline(cin, serialNumber);
            serial = stoi(serialNumber);
            while(!is_serial_number(serialNumber)){
                cout << "输入错误!(纯数字)" << endl;
                cout << "请重新输入序号: ";
                getline(cin, serialNumber);
                serial = stoi(serialNumber);
            }
        }
        istringstream iss(lines.at(serial-1));
        string id;
        iss >> id;
        cout << "请输入学生姓名: ";
        getline(cin,name);
        cout << "请输入学生性别(男/女): ";
        getline(cin,sex);
        while(!is_sex(sex)){
            cout << "学生性别输入错误!请重新输入(男/女)" << endl;
            cout << "请输入学生性别(男/女): ";
            getline(cin,sex);
        }
        cout << "请输入学生年龄: ";
        getline(cin,age);
        while(!is_age(age)){
            cout << "学生年龄格式错误!请重新输入(纯数字)" << endl;
            cout << "请输入学生年龄: ";
            getline(cin,age);
        }
        cout << "请输入学生专业: ";
        getline(cin,specialized);

        cout << "确认修改以下学生信息吗?" << endl;
        cout << "修改前: ";
        cout << lines.at(serial-1) << endl;
        cout << "修改后: ";
        cout << id << "\t" << name  << "\t" << sex << "\t" << age << "\t" << specialized << endl;
        cout << "请选择(Y/n  y/n): ";
        string isSure;
        getline(cin,isSure);
        while(isSure!="y"&&isSure!="Y"&&isSure!="n"&&isSure!="N"){
            cout << "输入错误!(Y/N  y/n)" << endl;
            cout << "请重新输入: ";
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
                cout << "已修改该学生信息" << endl;
                show_student(filename);
            } else{
                cout << "提示: 文件无法打开,请检查文件!";
            }
        }
    }else{
        cout << "提示: 文件无法打开,请检查文件!";
        inFile.close();
    }
}

void Student::select_student(const std::string &filename) {
    string choice;
    while (true){
        cout << "\t     查找学生信息" << endl;
        cout << "***************************************" << endl;
        cout << "1.根据学号查找" << endl;
        cout << "2.根据姓名查找" << endl;
        cout << "3.根据性别查找" << endl;
        cout << "4.根据年龄查找" << endl;
        cout << "5.根据专业查找" << endl;
        cout << "6.返回主菜单" << endl;
        cout << "***************************************" << endl;
        cout << "请选择: ";
        getline(cin,choice);
        while(choice!="1"&&choice!="2"&&choice!="3"&&choice!="4"&&choice!="5"&&choice!="6"){
            cout << "输入错误请重新输入!" << endl;
            cout << "请重新选择: ";
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
    cout << "请输入要查询的学生信息的学号: " << endl;
    cout << "请输入学号: ";
    getline(cin,number);
    while(!is_number(number)){
        cout << "学生学号格式错误!请重新输入(格式: 10位纯数字)" << endl;
        cout << "请输入学生学号: ";
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
                cout << "查询到的学生信息为" << endl;
                cout << "学号\t\t姓名\t性别\t年龄\t专业" << endl;
                cout << line << endl;
                isFound = true;
            }
        }
        inFile.close();
    }else{
        cout << "提示: 文件无法打开,请检查文件!";
    }
    if(!isFound){
        cout << "未查询到该学生信息!" << endl;
    }
}

void Student::student_name_lookup(const std::string &filename) {
    cout << "请输入要查询的学生信息的姓名: " << endl;
    cout << "请输入姓名: ";
    getline(cin,name);
    ifstream inFile(filename);
    string selectName;
    bool isFound = false;
    if(inFile.is_open()){
        string line;
        while(getline(inFile,line)){
            istringstream iss(line);
            iss >> selectName; // 消除学号
            iss >> selectName;
            if(name == selectName && isFound){
                cout << line << endl;
            }
            if(name == selectName && !isFound){
                cout << "查询到的学生信息为" << endl;
                cout << "学号\t\t姓名\t性别\t年龄\t专业" << endl;
                cout << line << endl;
                isFound = true;
            }
        }
        inFile.close();
    }else{
        cout << "提示: 文件无法打开,请检查文件!";
    }
    if(!isFound){
        cout << "未查询到该学生信息!" << endl;
    }
}
void Student::student_sex_lookup(const std::string &filename) {
    cout << "请输入要查询的学生信息的性别: " << endl;
    cout << "请输入性别: ";
    getline(cin,sex);
    while(!is_sex(sex)){
        cout << "学生性别输入错误!请重新输入(男/女)" << endl;
        cout << "请输入学生性别(男/女): ";
        getline(cin,sex);
    }
    ifstream inFile(filename);
    string selectSex;
    bool isFound = false;
    if(inFile.is_open()){
        string line;
        while(getline(inFile,line)){
            istringstream iss(line);
            iss >> selectSex; // 消除学号
            iss >> selectSex; // 消除姓名
            iss >> selectSex;
            if(sex == selectSex && isFound){
                cout << line << endl;
            }
            if(sex == selectSex && !isFound){
                cout << "查询到的学生信息为" << endl;
                cout << "学号\t\t姓名\t性别\t年龄\t专业" << endl;
                cout << line << endl;
                isFound = true;
            }
        }
        inFile.close();
    }else{
        cout << "提示: 文件无法打开,请检查文件!";
    }
    if(!isFound){
        cout << "未查询到该学生信息!" << endl;
    }
}
void Student::student_age_lookup(const std::string &filename) {
    cout << "请输入要查询的学生信息的年龄: " << endl;
    cout << "请输入年龄: ";
    getline(cin,age);
    while(!is_age(age)){
        cout << "学生年龄格式错误!请重新输入(纯数字)" << endl;
        cout << "请输入学生年龄: ";
        getline(cin,age);
    }
    ifstream inFile(filename);
    string selectAge;
    bool isFound = false;
    if(inFile.is_open()){
        string line;
        while(getline(inFile,line)){
            istringstream iss(line);
            iss >> selectAge; // 消除学号
            iss >> selectAge; // 消除姓名
            iss >> selectAge; //消除性别
            iss >> selectAge;
            if(age == selectAge && isFound){
                cout << line << endl;
            }
            if(age == selectAge && !isFound){
                cout << "查询到的学生信息为" << endl;
                cout << "学号\t\t姓名\t性别\t年龄\t专业" << endl;
                cout << line << endl;
                isFound = true;
            }
        }
        inFile.close();
    }else{
        cout << "提示: 文件无法打开,请检查文件!";
    }
    if(!isFound){
        cout << "未查询到该学生信息!" << endl;
    }
}
void Student::student_specialized_lookup(const std::string &filename) {
    cout << "请输入要查询的学生信息的专业: " << endl;
    cout << "请输入专业: ";
    getline(cin,specialized);
    ifstream inFile(filename);
    string selectSpecialized;
    bool isFound = false;
    if(inFile.is_open()){
        string line;
        while(getline(inFile,line)){
            istringstream iss(line);
            iss >> selectSpecialized; // 消除学号
            iss >> selectSpecialized; // 消除姓名
            iss >> selectSpecialized; // 消除性别
            iss >> selectSpecialized; // 消除年龄
            iss >> selectSpecialized;
            if(specialized == selectSpecialized && isFound){
                cout << line << endl;
            }
            if(specialized == selectSpecialized && !isFound){
                cout << "查询到的学生信息为" << endl;
                cout << "学号\t\t姓名\t性别\t年龄\t专业" << endl;
                cout << line << endl;
                isFound = true;
            }
        }
        inFile.close();
    }else{
        cout << "提示: 文件无法打开,请检查文件!";
    }
    if(!isFound){
        cout << "未查询到该学生信息!" << endl;
    }
}