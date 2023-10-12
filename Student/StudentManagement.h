#ifndef __STUDENTMANAGEMENT_H__
#define __STUDENTMANAGEMENT_H__
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
class Student{
private:
    string number;
    string name;
    string sex;
    string age;
    string specialized;
public:
    //显示菜单
    static void showChoice();
    //显示所有学生信息
    static void showStudent(const string& filename);
    //添加学生信息
    void insertStudent(const string &filename);
    //删除学生信息
    static void deleteStudent(const string&filename);
    //查找学生信息
    void selectStudent(const string&filename);
    //修改学生信息
    void reviseStudent(const string &filename);
    //判断文件是否为空文件
    static bool isFileEmpty(const string& filename);
    //判断学号格式是否正确
    static bool isNumber(const string &str);
    //判断性别格式是否正确
    static bool isSex(const string &str);
    //判断年龄格式是否正确
    static bool isAge(const string &str);
    //判断是否为纯数字
    static bool isSerialNumber(const string &str);
    //查找文件中是否有当前学号
    static bool checkForPlagiarism(const string &filename,const string &digit);
    //打印vector
    void printVector(const vector<string>&v);
    //根据学号查找
    void studentNumberLookup(const string &filename);
    //根据姓名查找
    void studentNameLookup(const string &filename);
    //根据性别查找
    void studentSexLookup(const string &filename);
    //根据年龄查找
    void studentAgeLookup(const string &filename);
    //根据专业查找
    void studentSpecializedLookup(const string &filename);



};

#endif