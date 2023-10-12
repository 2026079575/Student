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
    static void showChoice();
    //��ʾ����ѧ����Ϣ
    static void showStudent(const string& filename);
    //���ѧ����Ϣ
    void insertStudent(const string &filename);
    //ɾ��ѧ����Ϣ
    static void deleteStudent(const string&filename);
    //����ѧ����Ϣ
    void selectStudent(const string&filename);
    //�޸�ѧ����Ϣ
    void reviseStudent(const string &filename);
    //�ж��ļ��Ƿ�Ϊ���ļ�
    static bool isFileEmpty(const string& filename);
    //�ж�ѧ�Ÿ�ʽ�Ƿ���ȷ
    static bool isNumber(const string &str);
    //�ж��Ա��ʽ�Ƿ���ȷ
    static bool isSex(const string &str);
    //�ж������ʽ�Ƿ���ȷ
    static bool isAge(const string &str);
    //�ж��Ƿ�Ϊ������
    static bool isSerialNumber(const string &str);
    //�����ļ����Ƿ��е�ǰѧ��
    static bool checkForPlagiarism(const string &filename,const string &digit);
    //��ӡvector
    void printVector(const vector<string>&v);
    //����ѧ�Ų���
    void studentNumberLookup(const string &filename);
    //������������
    void studentNameLookup(const string &filename);
    //�����Ա����
    void studentSexLookup(const string &filename);
    //�����������
    void studentAgeLookup(const string &filename);
    //����רҵ����
    void studentSpecializedLookup(const string &filename);



};

#endif