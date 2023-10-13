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
    //��ʾ�˵�
    void show_choice();
    //��ʾ����ѧ����Ϣ
    void show_student(const string& filename);
    //���ѧ����Ϣ
    void insert_student(const string &filename);
    //ɾ��ѧ����Ϣ
    void delete_student(const string&filename);
    //����ѧ����Ϣ
    void select_student(const string&filename);
    //�޸�ѧ����Ϣ
    void revise_student(const string &filename);
    //�ж��ļ��Ƿ�Ϊ���ļ�
    static bool is_file_empty(const string& filename);
    //�ж�ѧ�Ÿ�ʽ�Ƿ���ȷ
    static bool is_number(const string &str);
    //�ж��Ա��ʽ�Ƿ���ȷ
    static bool is_sex(const string &str);
    //�ж������ʽ�Ƿ���ȷ
    static bool is_age(const string &str);
    //�ж��Ƿ�Ϊ������
    static bool is_serial_number(const string &str);
    //�����ļ����Ƿ��е�ǰѧ��
    static bool check_for_plagiarism(const string &filename,const string &digit);
    //��ӡvector
    void print_vector(const vector<string>&v);
    //����ѧ�Ų���
    void student_number_lookup(const string &filename);
    //������������
    void student_name_lookup(const string &filename);
    //�����Ա����
    void student_sex_lookup(const string &filename);
    //�����������
    void student_age_lookup(const string &filename);
    //����רҵ����
    void student_specialized_lookup(const string &filename);



};

#endif