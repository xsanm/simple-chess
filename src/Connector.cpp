//
// Created by xsan on 01.06.2021.
//

#include <unistd.h>
#include <fstream>
#include "Connector.h"

std::string Connector::getNextMove(std::string position) {
    std::ofstream myfile;
    myfile.open("tmp.txt");
    myfile << "position startpos moves " + position + '\n';
    myfile << "go\n";
    for (int i = 0; i < 500; i++) {
        myfile << "\n";
    }
    myfile.close();

    std::string str = " ./stockfish_13_linux_x64_avx2 < tmp.txt";

    const char *c = str.c_str();

    std::array<char, 1024> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(c, "r"), pclose);
    sleep(0.5);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    int n = result.find("bestmove");
    if (n != -1) return result.substr(n + 9, 4);
    return "";


}
