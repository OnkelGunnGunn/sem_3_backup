#include <iostream>
#include <fstream>

std::string user_input()
{
    std::string text;
    std::getline(std::cin, text);
    return text;
}

void check_ack(int expected_seq)
{
    std::ifstream ack_file("../ack.txt");

    std::string ack_packet;
    std::getline(ack_file, ack_packet);

    if (ack_packet.empty())
    {
        return;
    }

    size_t separator = ack_packet.find('|');

    if (separator == std::string::npos)
    {
        return;
    }

    std::string ack_type =
        ack_packet.substr(0, separator);

    std::string ack_seq =
        ack_packet.substr(separator + 1);

    if (ack_type != "ACK")
    {
        return;
    }

    if (std::stoi(ack_seq) == expected_seq)
    {
        std::cout
            << "ACK received for SEQ "
            << expected_seq
            << '\n';
    }
}

void write_file()
{
    static int seq = 0;

    std::string text = user_input();

    if (text.empty())
    {
        return;
    }

    std::ofstream file("../text.txt");

    file << seq << "|" << text;

    file.close();

    check_ack(seq);

    seq++;
}

int main()
{
    while (true)
    {
        write_file();
    }
}