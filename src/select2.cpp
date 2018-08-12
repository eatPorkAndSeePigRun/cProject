#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <arpa/inet.h>
#include <netinet/in.h>

using namespace std;

class RedisServer {
private:
    uint32_t ip;
    uint16_t port;
    struct sockaddr_in servaddr;
    int listenfd;
    map <string, string> db;
    fd_set *readfds;
    fd_set *writefds;
    map<int, string> msg;
public:
    RedisServer(uint32_t ip, uint16_t port) {
        this->ip = ip;
        this->port = port;
        this->listenfd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
    }

    ~RedisServer();

    void encode();

    string execute(string str){

    }
}

    void run() {
        bzero(&(this->servaddr), sizeof(this->servaddr));
        this->servaddr.sin_family = AF_INET;
        this->servaddr.sin_addr.s_addr = htonl(this->ip);
        this->servaddr.sin_port = htons(this->port);
        bind(this->listenfd, (struct sockaddr *) &(this->servaddr), sizeof(this->servaddr));
        listen(this->listenfd, 20);
        while (true) {
            nready = select(this->listenfd, &this->readfds, &this->writefds, NULL, NULL);
            if (nready < 0) {
                cout << "select error" << endl;
                exit();
            }
            for (auto fd : *this->readfds) {
                if (fd == this->listenfd) {
                    struct sockaddr_in cliaddr;
                    socklen_t cliaddr_len;
                    int connfd = accept4(this->listenfd, (struct sockaddr *) cliaddr, &cliaddr_len, SOCK_NONBLOCK);
                    FD_SET(connfd, &this->readfds);
                    vector <string> temp;
                    this->msg[conn] = temp;
                } else {
                    string data;
                    read(fd, data, 1024);
                    if (data != NULL) {
                        string temp = this->execute(data);
                        this->msg[fd].push_back(temp);
                        if (FD_ISSET(fd, &this->writefds) {
                            FD_SET(fd, &writefds);
                        }
                    }
                }
                for (auto fd : *this->writefds) {
                    if (this->msg.count() != 1) {
                        break;
                    }
                    string msg = this->msg[fd].pop_back();
                    write(fd, msg, strlen(msg));
                }
            }
        }
    };

    int main() {
        //TODO......
        return 0;
    }