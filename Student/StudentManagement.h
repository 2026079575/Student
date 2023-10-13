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
    void show_choice();
    //显示所有学生信息
    void show_student(const string& filename);
    //添加学生信息
    void insert_student(const string &filename);
    //删除学生信息
    void delete_student(const string&filename);
    //查找学生信息
    void select_student(const string&filename);
    //修改学生信息
    void revise_student(const string &filename);
    //判断文件是否为空文件
    static bool is_file_empty(const string& filename);
    //判断学号格式是否正确
    static bool is_number(const string &str);
    //判断性别格式是否正确
    static bool is_sex(const string &str);
    //判断年龄格式是否正确
    static bool is_age(const string &str);
    //判断是否为纯数字
    static bool is_serial_number(const string &str);
    //查找文件中是否有当前学号
    static bool check_for_plagiarism(const string &filename,const string &digit);
    //打印vector
    void print_vector(const vector<string>&v);
    //根据学号查找
    void student_number_lookup(const string &filename);
    //根据姓名查找
    void student_name_lookup(const string &filename);
    //根据性别查找
    void student_sex_lookup(const string &filename);
    //根据年龄查找
    void student_age_lookup(const string &filename);
    //根据专业查找
    void student_specialized_lookup(const string &filename);



};

#endif