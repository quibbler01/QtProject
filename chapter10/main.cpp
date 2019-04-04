#include "mainwindow.h"
#include "networkinformation.h"
#include "udpserver.h"
#include "udpclient.h"
#include "tcpserver.h"
#include "tcpclient.h"
#include "myhttp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*
     * Based on UDP Socket Chat Program
     */
//    UDPServer s;
//    s.show();

//    UDPClient c;
//    c.show();

    /**
      Chat TCP Client and Server
      **/
//    TCPServer t;
//    t.show();

//    TCPClient c;
//    c.show();
//    TCPClient c1;
//    c1.show();

    /**
      get http://www.baidu.com
    **/
    myHTTP m;
    m.show();


    return a.exec();
}
