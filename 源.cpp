#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

char tempnum[15] = { 0 };

class person {
public:
	void add();
	void setfile();
	void search_name();
	void search_num();
	void show();
protected:
	char name[10] = { 0 };
	char sex[5] = { 0 };
	int tel;
	char num[15]={0};
};

class student{
public:
	void scoreadd();
	void setfile();
	void continue_add();
	void continue_setfile();
	void search_score();
private:
	char num[15] = {0};
	char cname[15] = { 0 };
	int score;
	float credit;
};

void person::add() {
	int choose;
	cout << "���������ѧ�ţ�";
	cin >> num;
	cout << "������������";
	cin >> name;
	lable1:
	cout << "��ѡ���Ա�" << '\t'<<"1����\t2��Ů"<<endl;
	cout << "���������ѡ��";
	cin >> choose;
	if (choose == 1) {
		char temp[4] = "��";
		strcpy_s(sex, temp);
	}
	else if (choose == 2) {
		char temp[4] = "Ů";
		strcpy_s(sex, temp);
	}
	else {
		cout << "��������������ѡ��" << endl;
		goto lable1;
	}
	cout << "��������ĵ绰��";
	cin >> tel;
}

void person::setfile() {
	person p;
	p.add();
	fstream file("user.txt", ios::out | ios::app);
	file.write((char*)&p, sizeof(p));
	file.close();
	cout << "����ɹ�" << endl;
}

void student::scoreadd() {
	cout << "������ѧ�ţ�";
	cin >> num;
	strcpy_s(tempnum, num);
	cout << "\n������γ����ƣ�";
	cin >> cname;
	cout << "\n������ɼ���";
	cin >> score;
	cout << "������ÿγ�ѧ��";
	cin >> credit;
}

void student::setfile() {
	student s;
	s.scoreadd();
	fstream file("score.txt", ios::out | ios::app);
	file.write((char*)&s, sizeof(s));
	file.close();
	cout << "����ɹ�" << endl;
	cout << "�Ƿ������� Y or F" << endl;
	char continue_choose;
	cin >> continue_choose;
	if (continue_choose == 'y' || continue_choose == 'Y') {
		s.continue_setfile();
	}
}


void student::continue_add() {
	strcpy_s(num, tempnum);
	cout << "\n������γ����ƣ�";
	cin >> cname;
	cout << "\n������ɼ���";
	cin >> score;
	cout << "������ÿγ�ѧ��";
	cin >> credit;
}

void student::continue_setfile() {
	student s;
	s.continue_add();
	fstream file("score.txt", ios::out | ios::app);
	file.write((char*)&s, sizeof(s));
	file.close();
	cout << "����ɹ�" << endl;
	cout << "�Ƿ������� Y or F" << endl;
	char continue_choose;
	cin >> continue_choose;
	if (continue_choose == 'y' || continue_choose == 'Y') {
		s.continue_setfile();
	}
}

void person::search_name() {
	char s_name[10] = { 0 };
	cout << "������Ҫ��ѯ��������";
	cin >> s_name;
	person p;
	fstream file("user.txt", ios::in);
	file.read((char*)&p, sizeof(p));
	while (!file.eof()) {
		if (strcmp(p.name,s_name)==0) {
			p.show();
		}
		file.read((char*)&p, sizeof(p));
	}
}

void person::search_num() {
	char s_num[15] = { 0 };
	cout << "������Ҫ��ѯ��ѧ�ţ�";
	cin >> s_num;
	person p;
	fstream file("user.txt", ios::in);
	file.read((char*)&p, sizeof(p));
	while (!file.eof()) {
		if (strcmp(p.num, s_num)==0) {
			p.show();
		}
		file.read((char*)&p, sizeof(p));
	}
}

void person::show() {
	cout << "������" << name << endl;
	cout << "ѧ�ţ�" << num << endl;
	cout << "�Ա�" << sex << endl;
	cout << "�绰��" << tel << endl;
}

void student::search_score() {
	float sum_credit=0,sum_score=0;
	char s_num[15] = { 0 };
	cout << "������Ҫ��ѯ��ѧ�ţ�";
	cin >> s_num;
	cout << "1����ѯȫ���ɼ�" << "2����ѯ���Ƴɼ�" << endl;
	int choose;
	cin >> choose;
	student s;
	fstream file("score.txt", ios::in);
	file.read((char*)&s, sizeof(s));
	if (choose == 1) {
		while (!file.eof()) {
			if (strcmp(s.num, s_num)==0) {
				cout << s.cname << '\t' << s.score << '\t' << s.credit << endl;
				sum_score +=((s.score - 50)/ 10)*s.credit;
				sum_credit += s.credit;
			}
			file.read((char*)&s, sizeof(s));
		}
		cout << "ƽ������Ϊ��" << sum_score / sum_credit<<endl;
	}
	if (choose == 2) {
		char classname[10] = { 0 };
		cout << "������γ����ƣ�";
		cin >> classname;
		while (!file.eof()) {
			if (strcmp(s.num, s_num)==0&&strcmp(s.cname,classname)==0) {
				cout << s.cname << '\t' << s.score << '\t' << s.credit << endl;
			}
			file.read((char*)&s, sizeof(s));
		}
	}
}

void search() {
	int choose;
	person p1;
	cout << "1��ͨ��������ѯ" <<endl<< "2��ͨ��ѧ�Ų�ѯ\n";
	cin >> choose;
	switch (choose) {
	case 1:p1.search_name(); break;
	case 2:p1.search_num(); break;
	}
}

int main() {
	int choose;
	person p;
	student s;
	while (1) {
		cout << "1�������Ϣ\n2����ѯ��Ϣ\n3��¼��ɼ�\n4����ѯ�ɼ�\n5���˳�ϵͳ\n";
		cin >> choose;
		switch (choose) {
		case 1:p.setfile(); break;
		case 2:search(); break;
		case 3:s.setfile(); break;
		case 4:s.search_score(); break;
		case 5:return 0;
		}
	}
	return 0;
}