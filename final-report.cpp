#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<random>
#include<fstream>

using namespace std;

mt19937 rng(std::time(0)); //����������̍쐬

//���k�̃N���X�쐬

class Student {
public:
	string name;
	double vision = 0;

};
//���͂̔�r������֐��i�̂��ɔ�r����Ƃ��Ɏg�p�j
bool comparevision(const Student& a, const Student& b) {
	return a.vision < b.vision;
}

int main() {

	double a = 0;
	int x = 0, m = 0, n = 0, sel = 0, m1 = 0, n1 = 0, yesno;
	double vision = 0;
	string name;
	vector<Student> students;
	vector<Student> frontstudents;
	vector<Student> backstudents;
	vector<Student> Nostudents;

	cout << "���l�N���X�ł����H\n";
	for (int i = 0; i < 1; ++i) {
		if (!(cin >> x)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "���k�l���͐��l�œ��͂��Ă��������B" << endl;
			i -= 1;
		}
		else if (x <= 0) {
			cout << "���k�l����0���傫���l�œ��͂��Ă��������B" << endl;
			i -= 1;
		}
	}

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	cout << "�Ȃ͉�����ł����H\n";
	for (int i = 0; i < 1; ++i) {
		if (!(cin >> m)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "���񐔂͐��l�œ��͂��Ă��������B" << endl;
			i -= 1;
		}
		else if (x <= 0) {
			cout << "�񐔂�0���傫���l�œ��͂��Ă��������B" << endl;
			i -= 1;
		}

		cout << "�c����ł����H\n";
		for (int i = 0; i < 1; ++i) {
			if (!(cin >> n)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�c�񐔂͐��l�œ��͂��Ă��������B" << endl;
				i -= 1;
			}
			else if (x <= 0) {
				cout << "�񐔂�0���傫���l�œ��͂��Ă��������B" << endl;
				i -= 1;
			}

			int numSeats = m * n;

			if (x > numSeats) {

				cout << "���Ȑ�������܂���B\n";
				cout << "1�D�Ȃ�z�u�������܂����H\n";
				cout << "2�D��𑝂₵�܂����H\n";
				cin >> sel;
				int numSeats = 0;

				switch (sel) {
				case 1:
					cout << "�N���X�l���F" << x << endl;
					cout << "�Ȃ͉�����ł����H\n";
					for (int i = 0; i < 1; ++i) {
						if (!(cin >> m)) {
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "���k�l���͐��l�œ��͂��Ă��������B" << endl;
							i -= 1;
						}
					}
					cout << "�c����ł����H\n";
					for (int i = 0; i < 1; ++i) {
						if (!(cin >> n)) {
							cin.clear();
							cout << "���k�l���͐��l�œ��͂��Ă��������B" << endl;
							i -= 1;
						}
					}
					numSeats = m * n;
					break;

				case 2:
					cout << "�c�̗񐔂𑝂₵�܂��B\n";
					while (numSeats < x) {
						n += 1;
						numSeats = m * n;
					}
					break;

				default:

					system("cls");

					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

					cout << "�����ǂ�łȂ��l����������B(Press Enter key) \n";

					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


					cout << "����͋����Ă����邯�ǎ��͋����Ȃ��j����(=^�E^=)�B(Press Enter key)\n";

					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

					cout << "�c�̗񐔂𑝂₳���Ă��������܂��B(Press Enter key)\n";

					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

					while (numSeats < x) {
						n += 1;
						numSeats = m * n;

					}
					break;
				}

				system("cls");
				cout << "�N���X�l���F" << x << endl;
				cout << "���Ȑ��F" << numSeats << endl;
			}

			else {
				system("cls");
				cout << "�N���X�l���F" << x << endl;
				cout << "���Ȑ��F" << numSeats << endl;
			}

			ofstream outfile("Student.txt");

			cout << "���k�̖��O�Ǝ��͂��L�����Ă��������B\n";

			for (int i = 1; i <= x; ++i) {
				Student newStudent;
				cout << "���O�F";
				cin >> newStudent.name;

				while (true) {
					cout << "���́F ";

					if (!(cin >> newStudent.vision)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "���͂͐��l�œ��͂��Ă��������B" << endl;
						i -= 1;
					}
					else if (newStudent.vision <= 0) {
						cout << "���͂�0���傫���l�œ��͂��Ă��������B" << endl;
						i -= 1;
					}
					else {
						students.push_back(newStudent);
					}
					break;
				}

			}
			//student�t�@�C���ɐ��k�̃f�[�^���i�[
			for (int i = 0; i < x; i++) {
				outfile << "���O�F" << students[i].name << " ���́F" << students[i].vision << endl;
			}
			outfile.close();

			sort(students.begin(), students.end(), comparevision); //���͏��ɕ��ёւ�

			//���͂�0.3�ȉ��̐l��frontstudents�ɁC����ȊO�̐l��backstudents�Ɋi�[
			for (int k = 0; k < size(students); k++) {
				if (students[k].vision <= 0.3) {
					frontstudents.push_back(students[k]);
				}

				else {
					backstudents.push_back(students[k]);
				}
			}

			shuffle(backstudents.begin(), backstudents.end(), mt19937(std::time(0))); //���̐Ȃ�ȑւ�

			//���ȏc�񐔂�2�ȉ��̎��̏���
			if (n <= 2) {

				ofstream outfile("class Seats.txt");

				shuffle(students.begin(), students.end(), mt19937(std::time(0)));  //�ȑւ�

				while (size(students) < m * n) {
					Student a;
					a.name = "�[�[";
					a.vision = 100;
					students.push_back(a);
				}

				system("cls)");

				cout << "������������������������������������������������������������������������������" << endl;
				outfile << "������������������������������������������������������������������������������" << endl;
				cout << endl;

				for (int p = 0; p <= n - 1; p++) {

					for (int i = 1; i <= m; i++) {

						int d = p * m + i;
						cout << "  | " << students[d - 1].name << " |  ";
						outfile << "  | " << students[d - 1].name << " |  ";
					}
					cout << endl;
					outfile << endl;
					cout << "�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[" << endl;
					outfile << "�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[" << endl;

				}
				outfile.close();
			}

			//���ȗ񐔂�2���傫���Ƃ��̏���
			else {
				ofstream outfile("class Seats.txt");
				if (size(frontstudents) > 2 * m) {

					cout << "�ڈ����l�������[�w������I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�����ہ_(^o^)�^���\n";
					cout << "�ڂ̈����l���Ȃ�ׂ��O�Ɏ����Ă��܂��B\n";
					
					while (size(frontstudents) > 2 * m) { //frontstudents���O2�񕪂�葽�������ꍇ2�񕪂ɂȂ�܂�backstudents�Ɉڍs����

						backstudents.push_back(frontstudents[0]);
						frontstudents.erase(frontstudents.begin());
					}
				}

				if (size(frontstudents) <= 2 * m) { //�O2�񕪂̐Ȃ𖄂߂邽�߂�backstudents���玝���Ă���
					while (size(frontstudents) < 2 * m) {

						frontstudents.push_back(backstudents[0]);
						backstudents.erase(backstudents.begin());
					}

					while (size(backstudents) < m * (n - 2)) {

						Student a;
						a.name = "�[�[";
						a.vision = 100;
						backstudents.push_back(a);
					}

					shuffle(frontstudents.begin(), frontstudents.end(), mt19937(std::time(0))); //�O2��̐ȂŃV���b�t��
				}

				system("cls");

				cout << "������������������������������������������������������������������������������" << endl;
				outfile << "������������������������������������������������������������������������������" << endl;
				cout << endl;

				for (int p = 0; p <= 1; p++) {

					for (int i = 1; i <= m; i++) {

						int d = p * m + i;
						cout << "  | " << frontstudents[d - 1].name << " |  ";
						outfile << "  | " << frontstudents[d - 1].name << " |  ";
					}

					cout << endl;
					outfile << endl;
					cout << "�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[" << endl;
					outfile << "�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[" << endl;
				}

				for (int p = 2; p < n; p++) {

					for (int i = 1; i <= m; i++) {

						int d = p * m + i;
						cout << "  | " << backstudents[d - (2 * m + 1)].name << " |  ";
						outfile << "  | " << backstudents[d - (2 * m + 1)].name << " |  ";
					}

					cout << endl;
					outfile << endl;
					cout << "�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[" << endl;
					outfile << "�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[" << endl;


				}
			}
			outfile.close();
		}
	}
}
	

	

	
	

	




