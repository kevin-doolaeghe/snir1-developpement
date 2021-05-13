#ifndef TRAMEMANIP_H
#define TRAMEMANIP_H

#include <string>

using namespace std;

class TrameManip
{
public:
    TrameManip(string dataTrame = "");
    void setTrame(string dataTrame);
    void setHeadBalise(string balise);
    void setEndBalise(string balise);
    string setData(string data, string idHead = "", string idEnd = "", string dataTrame = "");
    string getTrame();
    string getData(string idHead = "", string idEnd = "", string dataTrame = "");
    bool modifData(string data, string idHead = "", string idEnd = "", string dataTrame = "");
    bool supprimeData(string idHead = "", string idEnd = "", string dataTrame = "");

protected:
    string trame;
    string headBalise;
    string endBalise;
};

#endif // TRAMEMANIP_H
