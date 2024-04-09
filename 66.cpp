#include <iostream>
#include <ostream>
#include <string>

using namespace std;

int main() {
    string _reset = "reset";
    string _board = "board";
    string _add = "add";
    string _delete = "delete";
    string _reboot = "reboot";
    string _backplane = "backplane";
    string _abort = "abort";
    string cmd;
    while (getline(cin, cmd)) { // 注意 while 处理多个 case
        bool flag = false;
        bool invalid = false;
        string result;
        long space =cmd.find(" ");
        if (space == string::npos) {
            if (_reset.find(cmd) == 0) {
                result = "reset what";
            } else {
                invalid = true;
            }
        } else {
            invalid = true;
            string s1 = cmd.substr(0, space);
            string s2 = cmd.substr(space + 1);
            if (_reset.find(s1) == 0) {
                if (_board.find(s2) == 0) {
                    if (!flag) {
                        result = "board fault";
                        flag = true;
                        invalid = false;
                    } else {
                        invalid = true;
                    }
                }
            }
            if (_board.find(s1) == 0) {
                if (_add.find(s2) == 0) {
                    if (!flag) {
                        result = "where to add";
                        flag = true;
                        invalid = false;
                    } else {
                        invalid = true;
                    }
                }
                if (_delete.find(s2) == 0) {
                    if (!flag) {
                        result = "no board at all";
                        flag = true;
                        invalid = false;
                    } else {
                        invalid = true;
                    }
                }
            }
            if (_reboot.find(s1) == 0) {
                if (_backplane.find(s2) == 0) {
                    if (!flag) {
                        result = "impossible";
                        flag = true;
                        invalid = false;
                    } else {
                        invalid = true;
                    }
                }
            }
            if (_backplane.find(s1) == 0) {
                if (_abort.find(s2) == 0) {
                    if (!flag) {
                        result = "install first";
                        flag = true;
                        invalid = false;
                    } else {
                        invalid = true;
                    }
                }
            }
        }
        if (invalid) {
            cout << "unknown command" << endl;
        } else {
            cout << result << endl;
        }
    }
}
// 64 位输出请用 printf("%lld")
