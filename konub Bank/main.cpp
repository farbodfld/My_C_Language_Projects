#include <iostream>
#include <iterator>
#include <map>
#include <sstream>

using namespace std;

class konub {
    string username;
    string ip;
public:
    int money;

public:
    konub(string username, string ip) {
        this->username = username;
        this->ip = ip;
        this->money = 0;
    }
};

struct colon_is_space : std::ctype<char> {
    colon_is_space()
            : std::ctype<char>(get_table())
    {
    }
    static mask const* get_table()
    {
        static mask rc[table_size];
        rc[':'] = std::ctype_base::space;
        rc['\n'] = std::ctype_base::space;
        rc[' '] = std::ctype_base::space;
        rc['\t'] = std::ctype_base::space;

        return &rc[0];
    }
};

int main() {
    map<string, konub *> users;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin.imbue(locale(cin.getloc(), new colon_is_space));

    int n, type;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> type;

        if (type == 1) {
            string ip, username;
            cin >> ip >> username;
            if (username.find("_"))
                cout << "invalid username" << endl;
            else if (username.find("*"))
                cout << "invalid username" << endl;
            else if (username.find("#"))
                cout << "invalid username" << endl;
            else if (username.find("$"))
                cout << "invalid username" << endl;
            else {
                konub *k = new konub(ip, username);
                users[ip] = k;
            }
        } else if (type == 2) {
            string ip, username;
            int money;

            cin >> ip >> username >> money;

            konub *from = users.find(ip)->second;
            konub *to = users.find(username)->second;
            from->money -= money;
            to->money += money;
        } else if (type == 3) {
            string ip;
            cin >> ip;

            konub *konub = users.find(ip)->second;
            cout << konub->money << endl;
        }
    }
    // konub k;
    // BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

    /*try {
       // int nbInput = Integer.parseInt(reader.readLine());
       string nbInput1;
       cin >> nbInput1;
        stringstream ss(nbInput1);
       int nbInput;
       ss >> nbInput;

        for (int i = 0; i < nbInput; i++) {
           // string s = reader.readLine();
           string s;
           cin >> s;
           // char cases = s.charAt(0);
           char cases = s.at(0);

            // x = scanner.nextInt();

            if (cases == '1') {
                *//*String ip = scanner.next();
                System.out.print(":");
                String username = scanner.next();*//*

                *//*string ip = s.substring(1).substring(0, s.indexOf(":") - 1);
                string username = s.substring(1).substring(s.indexOf(":"));*//*
                string ip = s.substr(1).substr(0, s.find(":") - 1);
                string username = s.substr(1).substr(s.find(":"));

                if (username.find("_"))
                    cout << "invalid username" << endl;
                else if (username.find("*"))
                    cout << "invalid username" << endl;
                else if (username.find("#"))
                    cout << "invalid username" << endl;
                else if (username.find("$"))
                    cout << "invalid username" << endl;
                else {
                    konub* k = new konub(username, ip);
                    users.put(ip, k);
                }

            } else if (cases == '2') {
                *//*String ip = scanner.next();
                System.out.print(":");
                String username = scanner.next();
                System.out.print(":");
                String money = scanner.next();
                int moneyINT = Integer.parseInt(money);*//*

                string[]
                chars = s.substr(1).split(":");
                int money_int = Integer.parseInt(chars[2]);

                konub k = users.get(chars[0]);
                // konub k1 = users.get(chars[1]);
                k.money -= money_int;
                //k1.money += money_int;
                for (konub k1 : users.values()) {
                    if (k1.username.equals(chars[1]))
                        // k.money(k.money + Integer.parseInt(chars[2]));
                        k1.money += Integer.parseInt(chars[2]);
                }
            } else if (cases == '3') {
                // String ip = scanner.next();
                konub k = users.get(s.substring(1));
                cout << k.money << endl;
            }
        }
    } catch (IOException e) {
        e.printStackTrace();
    }*/
    return 0;
}