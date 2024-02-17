#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
#include <vector>

using namespace std;

class Minesweeper {
    bool **bomb;
    string **background;
    int row;
    int column;
    int bomb_row;
    int bomb_column;
    int loose_counter = 1;  // for first time loose which we don't loose!
    int bomb_counter;
    int win_counter = 0;    // for each coordinate doesn't contain bomb!
    int found_bomb_counter = 0;
    bool get_order = true;

public:
    Minesweeper() {
        cout << "set your row" << endl;
        cin >> row;
        cout << "set your column" << endl;
        cin >> column;
        cout << "set your bomb number" << endl;
        cin >> bomb_counter;
        while (true) {
            if (bomb_counter > (row * column) - 1) {
                cout << "invalid number\nplease set number lower than the matrix boxes" << endl;
                cin >> bomb_counter;
            } else {
                break;
            }
        }
        srand(time(NULL));

        /* make array */
        background = new string *[row];
        for (int i = 0; i < row; i++)
            background[i] = new string[column];

        /* fill the array(hash_tags) */
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                background[i][j] = "#";
            }
        }
    }

    void make_bombs() {
        /* make bomb array */
        bomb = new bool *[row];
        for (int i = 0; i < row; i++)
            bomb[i] = new bool[column];

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                bomb[i][j] = {false};
            }
        }

        /* fill the bomb's array with random bombs */
        for (int k = 0; k < bomb_counter;) {
            bomb_row = rand() % row;
            bomb_column = rand() % column;
            if (!bomb[bomb_row][bomb_column]) {
                bomb[bomb_row][bomb_column] = true;
                k++;
            }
        }
    }

    void print_array2() {
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < column; j++) {
                cout << bomb[i][j] << " ";
            }
            cout << endl;
        }
    }

    void print_array() {
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < column; j++) {
                cout << background[i][j] << " ";
            }
            cout << endl;
        }
    }

    void set_flag() {
        cout << "enter your coordinate" << endl;
        int r;
        cin >> r;
        int c;
        cin >> c;
        if (background[r][c] == "#") {
            background[r][c] = "|>";
            print_array();
        } else if (background[r][c] == "|>") {
            background[r][c] = "#";
            print_array();
        }
        if (background[r][c] == "?") {
            background[r][c] = "|>?";
            print_array();
        } else if (background[r][c] == "|>?") {
            background[r][c] = "?";
            print_array();
        }
        if (background[r][c] == background[bomb_row][bomb_column]) {
            found_bomb_counter++;
        }
    }

    void set_question_mark() {
        cout << "enter your coordinate" << endl;
        int r;
        cin >> r;
        int c;
        cin >> c;
        if (background[r][c] == "#") {
            background[r][c] = "?";
            print_array();
        } else if (background[r][c] == "?") {
            background[r][c] = "#";
            print_array();
        }
        if (background[r][c] == "|>") {
            background[r][c] = "|>?";
            print_array();
        } else if (background[r][c] == "|>?") {
            background[r][c] = "|>";
            print_array();
        }
    }

    void show_bomb_counter() {
        cout << bomb_counter << endl;
    }

    void show_notfound_bomb() {
        cout << bomb_counter - found_bomb_counter << endl;
    }

    void game_setup() {
        int counter = 0;
        cout << "enter your coordinate" << endl;
        int r;
        cin >> r;
        int c;
        cin >> c;
        while (true) {
            if (background[r][c] == "|>") {
                cout << "you can't see this coordinate" << endl;
                cout << "set another coordinate" << endl;
                cin >> r;
                cin >> c;
            } else if (bomb[r][c]) {
                if (loose_counter == 1) {
                    for (int i = 0; i < row; i++)
                        delete bomb[i];
                    delete bomb;
                    make_bombs();
                    print_array();
                    loose_counter++;
                    break;
                } else {
                    background[r][c] = "*";
                    print_array();
                    cout << "you lost :(" << endl;
                    for (int i = 0; i < row; i++)
                        delete background[i];
                    delete background;

                    for (int i = 0; i < row; i++)
                        delete bomb[i];
                    delete bomb;

                    get_order = false;
                    break;
                }
            } else {
                if (bomb[r + 1][c]) {
                    counter++;
                    loose_counter++;
                }
                if (bomb[r][c + 1]) {
                    counter++;
                    loose_counter++;
                }
                if (bomb[r - 1][c]) {
                    counter++;
                    loose_counter++;
                }
                if (bomb[r][c - 1]) {
                    counter++;
                    loose_counter++;
                }
                if (bomb[r + 1][c + 1]) {
                    counter++;
                    loose_counter++;
                }
                if (bomb[r - 1][c - 1]) {
                    counter++;
                    loose_counter++;
                }
                if (bomb[r + 1][c - 1]) {
                    counter++;
                    loose_counter++;
                }
                if (bomb[r - 1][c + 1]) {
                    counter++;
                    loose_counter++;
                }
                background[r][c] = (char) counter + '0';
                win_counter++;
                print_array();
                break;
            }
        }
        if (((row - 1) * (column - 1)) - bomb_counter == win_counter) {
            cout << "you won :)" << endl;
            for (int i = 0; i < row; i++)
                delete background[i];
            delete background;

            for (int i = 0; i < row; i++)
                delete bomb[i];
            delete bomb;

            get_order = false;
        }
    }

    bool getGet_Order() {
        return get_order;
    }

    int get_row() {
        return row;
    }

    int get_column() {
        return column;
    }
};

int main() {
    int minimum_required_score = 60;
    cout << "if you want to see the top players type 1 else 0" << endl;
    int checking;
    cin >> checking;
    if (checking == 1) {
        ifstream file("MineSweeper");

        vector<string> names;

        string input;
        while (file >> input) {
            names.push_back(input);
        }

        for (string name : names) {
            cout << name << endl;
        }
    }
    Minesweeper ms;
    ms.make_bombs();
    ms.print_array();
    // ms.print_array2();
    auto start_time = chrono::steady_clock::now();
    while (true) {
        cout << "if you want to play type: 1" << endl;
        cout << "if you want to print the table type: 2" << endl;
        cout << "if you want to set flag type: 3" << endl;
        cout << "if you want to set question mark type: 4" << endl;
        cout << "if you want to see the numbers of bombs type: 5" << endl;
        cout << "if you want to see the numbers of hidden bombs type: 6" << endl;
        cout << "if you want to exit the game type: 7" << endl;
        cout << "ATTENTION: array made with row-1 and column-1 rows and columns!!" << endl;
        int answer;
        cin >> answer;
        if (answer == 1 && ms.getGet_Order()) {
            ms.game_setup();
            if (!ms.getGet_Order()) {
                break;
            }
        } else if (answer == 2 && ms.getGet_Order()) {
            ms.print_array();
        } else if (answer == 3 && ms.getGet_Order()) {
            ms.set_flag();
        } else if (answer == 4 && ms.getGet_Order()) {
            ms.set_question_mark();
        } else if (answer == 5 && ms.getGet_Order()) {
            ms.show_bomb_counter();
        } else if (answer == 6 && ms.getGet_Order()) {
            ms.show_notfound_bomb();
        } else if (answer == 7 && ms.getGet_Order()) {
            break;
        } else {
            cout << "invalid order" << endl;
            cin >> answer;
        }
    }
    auto end_time = chrono::steady_clock::now();
    cout << "duration time is: " << chrono::duration_cast<chrono::seconds>(end_time - start_time).count() << " seconds!"
         << endl;

    int estimate = chrono::duration_cast<chrono::seconds>(end_time - start_time).count();

    ofstream file("MineSweeper", ios::app);
    vector<int> data;
    data.push_back(ms.get_row());
    data.push_back(ms.get_column());
    data.push_back(estimate);

    if (estimate < minimum_required_score) {
        cout << "enter your name" << endl;
        string name;
        cin >> name;
        file << "player's name is:" << name << endl;
        file << "row and column and estimate time is:" << endl;
        for (int data : data) {
            file << data << endl;
        }
    }

    file.close();
    return 0;

}
