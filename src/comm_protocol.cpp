#include <iostream>
#include <fstream>

std::string user_input() {
    std::string text;
    std::getline(std::cin, text);
    return text;
}



void write_file() {
    std::ofstream file;
    file.open("../text.txt");
    file << user_input();
    file.close();
}


void read_file() {
    std::ifstream file;
    std::string message;
    file.open("../text.txt");
    std::getline(file, message);
    std::cout << message << std::endl;
    file.close();
}




int main() {
    write_file();
    read_file();
    
}


