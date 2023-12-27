#include "conf_parser.hpp"
#include <iostream>
#include <QApplication>

ConfInfo read_conf(const std::string file_name) {
    std::string line;
    std::ifstream conf_file(file_name);
    ConfInfo conf_info;
    if (!conf_file.is_open()) {
        std::cout << "ERROR: Can't open split config file" << "\n";
        std::exit(EXIT_FAILURE);
    }
    while (std::getline(conf_file, line)) {
        remove_unnecessary_whitespaces(line);
        std::cout << line << "\n";
    }
    conf_file.close();
    return conf_info;
}

void remove_unnecessary_whitespaces(std::string& string) {
    bool prev_is_ws = false;
    for (int i = 0; i < string.length(); ++i) {
        if (string[i] == ' ') {
            if (prev_is_ws) {
               string.erase(i, 1);
               --i;
            }
            prev_is_ws = true;
        } else {
            prev_is_ws = false;
        }
    }
    if (string[0] == ' ')
        string.erase(0, 1);
    if (string[string.length() - 1] == ' ')
        string.erase(string.length() - 1, 1);
}
