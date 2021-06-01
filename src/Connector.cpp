//
// Created by xsan on 01.06.2021.
//

#include <unistd.h>
#include <csignal>
#include <sys/wait.h>
#include <cstring>
#include <fstream>
#include "Connector.h"

std::string Connector::getNextMove(std::string position) {
    std::ofstream myfile;
    myfile.open ("tmp.txt");
    myfile << "position startpos moves " + position + '\n';
    myfile << "go\n";
    for(int i = 0; i < 500; i++) {
        myfile << "\n";
    }
    myfile.close();

std::string str = " ./stockfish_13_linux_x64_avx2 < tmp.txt";
//
//    position = "printf \"position startpos moves " + position + "\ngo\" | stockfish";
    const char *c = str.c_str();
    //popen(c, "r");
    //popen("stockfish go movetime 400", "r");

    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(c, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    int n = result.find("bestmove");
    if (n != -1) return result.substr(n + 9, 4);
    return "";


//    pid_t pid = 0;
//    int inpipefd[2];
//    int outpipefd[2];
//    char buf[256];
//    char msg[256];
//    int status;
//
//    pipe(inpipefd);
//    pipe(outpipefd);
//    pid = fork();
//    if (pid == 0)
//    {
//        // Child
//        dup2(outpipefd[0], STDIN_FILENO);
//        dup2(inpipefd[1], STDOUT_FILENO);
//        dup2(inpipefd[1], STDERR_FILENO);
//
//        //ask kernel to deliver SIGTERM in case the parent dies
//        //prctl(PR_SET_PDEATHSIG, SIGTERM);
//
//        //replace tee with your process
//        execl("stockfish", (char*) NULL);
//        // Nothing below this line should be executed by child process. If so,
//        // it means that the execl function wasn't successfull, so lets exit:
//        exit(1);
//    }
//    // The code below will be executed only by parent. You can write and read
//    // from the child using pipefd descriptors, and you can send signals to
//    // the process using its pid by kill() function. If the child process will
//    // exit unexpectedly, the parent process will obtain SIGCHLD signal that
//    // can be handled (e.g. you can respawn the child process).
//
//    //close unused pipe ends
//    close(outpipefd[0]);
//    close(inpipefd[1]);
//
//    // Now, you can write to outpipefd[1] and read from inpipefd[0] :
//    position = "position startpos moves " + position + '\n';
//    const char *c = position.c_str();
//    write(outpipefd[1], c, strlen(c));
//
//    position= "go";
//    const char *d = position.c_str();
//    write(outpipefd[1], d, strlen(d));
//
//    sleep(1);
//    read(inpipefd[0], buf, 256);
//
//    printf("%s\n", buf);
//    std::cout<< "DZIALAJ KURWO\n";
//    //kill(pid, SIGKILL); //send SIGKILL signal to the child process
//    //waitpid(pid, &status, 0);
//    return "";
}
