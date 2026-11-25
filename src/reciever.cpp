#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>


void send_ack(const std::string& seq) {
    std::ofstream ack_file("../ack.txt");

    ack_file << "ACK|" << seq;
}

void read_file() {
    static std::string previous;

    std::ifstream file("../text.txt");

    std::string packet;
    std::getline(file, packet);

    if(packet.empty() || packet == previous)
    {
        return;
    }

    previous = packet;

    size_t separator = packet.find('|');

    if(separator == std::string::npos)
    {
        std::cout << "Malformed packet\n";
        return;
    }

    std::string seq =
        packet.substr(0, separator);

    std::string data =
        packet.substr(separator + 1);

    std::cout
        << "SEQ=" << seq
        << " DATA=" << data
        << '\n';

    send_ack(seq);
}

int main() {

    while (true)
    {
        read_file();

        std::this_thread::sleep_for(std::chrono::milliseconds(500));


    }
    
}


// næste skridt er at få lavet threads så user A kan både modtage og sende beskeder
// og det samme for user B