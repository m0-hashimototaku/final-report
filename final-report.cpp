#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<random>
#include<fstream>

using namespace std;

mt19937 rng(std::time(0)); //乱数生成器の作成

//生徒のクラス作成

class Student {
public:
	string name;
	double vision = 0;

};
//視力の比較をする関数（のちに比較するときに使用）
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

	cout << "何人クラスですか？\n";
	for (int i = 0; i < 1; ++i) {
		if (!(cin >> x)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "生徒人数は数値で入力してください。" << endl;
			i -= 1;
		}
		else if (x <= 0) {
			cout << "生徒人数は0より大きい値で入力してください。" << endl;
			i -= 1;
		}
	}

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	cout << "席は横何列ですか？\n";
	for (int i = 0; i < 1; ++i) {
		if (!(cin >> m)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "横列数は数値で入力してください。" << endl;
			i -= 1;
		}
		else if (x <= 0) {
			cout << "列数は0より大きい値で入力してください。" << endl;
			i -= 1;
		}

		cout << "縦何列ですか？\n";
		for (int i = 0; i < 1; ++i) {
			if (!(cin >> n)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "縦列数は数値で入力してください。" << endl;
				i -= 1;
			}
			else if (x <= 0) {
				cout << "列数は0より大きい値で入力してください。" << endl;
				i -= 1;
			}

			int numSeats = m * n;

			if (x > numSeats) {

				cout << "座席数が足りません。\n";
				cout << "1．席を配置し直しますか？\n";
				cout << "2．列を増やしますか？\n";
				cin >> sel;
				int numSeats = 0;

				switch (sel) {
				case 1:
					cout << "クラス人数：" << x << endl;
					cout << "席は横何列ですか？\n";
					for (int i = 0; i < 1; ++i) {
						if (!(cin >> m)) {
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "生徒人数は数値で入力してください。" << endl;
							i -= 1;
						}
					}
					cout << "縦何列ですか？\n";
					for (int i = 0; i < 1; ++i) {
						if (!(cin >> n)) {
							cin.clear();
							cout << "生徒人数は数値で入力してください。" << endl;
							i -= 1;
						}
					}
					numSeats = m * n;
					break;

				case 2:
					cout << "縦の列数を増やします。\n";
					while (numSeats < x) {
						n += 1;
						numSeats = m * n;
					}
					break;

				default:

					system("cls");

					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

					cout << "説明読んでない人私嫌いだよ。(Press Enter key) \n";

					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


					cout << "今回は許してあげるけど次は許さないニャン(=^・^=)。(Press Enter key)\n";

					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

					cout << "縦の列数を増やさせていただきます。(Press Enter key)\n";

					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

					while (numSeats < x) {
						n += 1;
						numSeats = m * n;

					}
					break;
				}

				system("cls");
				cout << "クラス人数：" << x << endl;
				cout << "座席数：" << numSeats << endl;
			}

			else {
				system("cls");
				cout << "クラス人数：" << x << endl;
				cout << "座席数：" << numSeats << endl;
			}

			ofstream outfile("Student.txt");

			cout << "生徒の名前と視力を記入してください。\n";

			for (int i = 1; i <= x; ++i) {
				Student newStudent;
				cout << "名前：";
				cin >> newStudent.name;

				while (true) {
					cout << "視力： ";

					if (!(cin >> newStudent.vision)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "視力は数値で入力してください。" << endl;
						i -= 1;
					}
					else if (newStudent.vision <= 0) {
						cout << "視力は0より大きい値で入力してください。" << endl;
						i -= 1;
					}
					else {
						students.push_back(newStudent);
					}
					break;
				}

			}
			//studentファイルに生徒のデータを格納
			for (int i = 0; i < x; i++) {
				outfile << "名前：" << students[i].name << " 視力：" << students[i].vision << endl;
			}
			outfile.close();

			sort(students.begin(), students.end(), comparevision); //視力順に並び替え

			//視力が0.3以下の人をfrontstudentsに，それ以外の人をbackstudentsに格納
			for (int k = 0; k < size(students); k++) {
				if (students[k].vision <= 0.3) {
					frontstudents.push_back(students[k]);
				}

				else {
					backstudents.push_back(students[k]);
				}
			}

			shuffle(backstudents.begin(), backstudents.end(), mt19937(std::time(0))); //後ろの席を席替え

			//座席縦列数が2以下の時の処理
			if (n <= 2) {

				ofstream outfile("class Seats.txt");

				shuffle(students.begin(), students.end(), mt19937(std::time(0)));  //席替え

				while (size(students) < m * n) {
					Student a;
					a.name = "ーー";
					a.vision = 100;
					students.push_back(a);
				}

				system("cls)");

				cout << "＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝黒板＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝" << endl;
				outfile << "＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝黒板＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝" << endl;
				cout << endl;

				for (int p = 0; p <= n - 1; p++) {

					for (int i = 1; i <= m; i++) {

						int d = p * m + i;
						cout << "  | " << students[d - 1].name << " |  ";
						outfile << "  | " << students[d - 1].name << " |  ";
					}
					cout << endl;
					outfile << endl;
					cout << "ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー" << endl;
					outfile << "ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー" << endl;

				}
				outfile.close();
			}

			//座席列数が2より大きいときの処理
			else {
				ofstream outfile("class Seats.txt");
				if (size(frontstudents) > 2 * m) {

					cout << "目悪い人多すぎー学級崩壊！！！！！！！！！！！！！！！！！！！！！！無理ぽ＼(^o^)／ｵﾜﾀ\n";
					cout << "目の悪い人をなるべく前に持ってきます。\n";
					
					while (size(frontstudents) > 2 * m) { //frontstudentsが前2列分より多かった場合2列分になるまでbackstudentsに移行する

						backstudents.push_back(frontstudents[0]);
						frontstudents.erase(frontstudents.begin());
					}
				}

				if (size(frontstudents) <= 2 * m) { //前2列分の席を埋めるためにbackstudentsから持ってくる
					while (size(frontstudents) < 2 * m) {

						frontstudents.push_back(backstudents[0]);
						backstudents.erase(backstudents.begin());
					}

					while (size(backstudents) < m * (n - 2)) {

						Student a;
						a.name = "ーー";
						a.vision = 100;
						backstudents.push_back(a);
					}

					shuffle(frontstudents.begin(), frontstudents.end(), mt19937(std::time(0))); //前2列の席でシャッフル
				}

				system("cls");

				cout << "＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝黒板＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝" << endl;
				outfile << "＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝黒板＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝" << endl;
				cout << endl;

				for (int p = 0; p <= 1; p++) {

					for (int i = 1; i <= m; i++) {

						int d = p * m + i;
						cout << "  | " << frontstudents[d - 1].name << " |  ";
						outfile << "  | " << frontstudents[d - 1].name << " |  ";
					}

					cout << endl;
					outfile << endl;
					cout << "ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー" << endl;
					outfile << "ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー" << endl;
				}

				for (int p = 2; p < n; p++) {

					for (int i = 1; i <= m; i++) {

						int d = p * m + i;
						cout << "  | " << backstudents[d - (2 * m + 1)].name << " |  ";
						outfile << "  | " << backstudents[d - (2 * m + 1)].name << " |  ";
					}

					cout << endl;
					outfile << endl;
					cout << "ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー" << endl;
					outfile << "ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー" << endl;


				}
			}
			outfile.close();
		}
	}
}
	

	

	
	

	




