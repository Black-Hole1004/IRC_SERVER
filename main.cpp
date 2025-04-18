# include "HEADERS/all_headers.hpp"
# include "HEADERS/server.hpp"
# include "HEADERS/client.hpp"
# include "HEADERS/channel.hpp"
# include "HEADERS/socket.hpp"


bool check_port(char *port)
{
    int i = 0;
    if (strlen(port) > 5)
        return false;
    while (port[i])
    {
        if (!isdigit(port[i]))
            return false;
        i++;
    }
    return true;
}


int main(int argc, char **argv)
{
    try {

        if (argc != 3)
        {
            std::cerr << "Usage: ./server <password> <port> " << std::endl;
            return 1;
        }
        std::string password = argv[1];
        if (password.empty() || !check_port(argv[2]))
        {
            std::cerr << "Password Empty Or Port Not Valid" << std::endl;
            return 1;
        }
        int port = atoi(argv[2]);
        std::cout << password << std::endl;

        Server server(port, password);
        server.startServer();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
