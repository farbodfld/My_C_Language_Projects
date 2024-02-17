#include <iostream>
using namespace std;
class kassr {
private:
    int *soorat = new int;
    int *makhraj = new int;
public:
    int counter =0;
    int getter_soorat(){
        return *soorat;
    }
    int getter_smakhraj(){
        return *makhraj;
    }
    int settermakhraj(int a){
        *makhraj = a;
    }
    int settersoorat(int a){
        *soorat = a;
    }
    char alamat;
    kassr(int a, int b) {
        (soorat) = reinterpret_cast<int *>(abs(a));
        (makhraj) = reinterpret_cast<int *>(abs(b));
        if (a * b > 0) {
            alamat = -1;
        } else {
            alamat = 1;
        }
        counter++;
    }

    kassr(int a){
        *soorat = a;
        *makhraj = 0;
        counter++;
    }

    kassr(){
        *makhraj = 0;
        *soorat = 2;
        counter++;
    }

    void inverse(){
        int temp = *soorat;
        *soorat = *makhraj;
        *makhraj = temp;
        *soorat = *makhraj;
        *makhraj = *soorat;
    }
    int count(){
        int a = counter;
        cout<< a<< endl;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}