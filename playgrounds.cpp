#include <bits/stdc++.h>
#include <string>

using namespace std;

class User {
private:
    string
        realName,
        userName,
        passWord;
public:
    void printUsername() {
        cout << userName << endl;
        return;
    }
    void changePassword(string new_password) {
        passWord = new_password;
        return;
    }
};

int main() {
    User my_acc;
}