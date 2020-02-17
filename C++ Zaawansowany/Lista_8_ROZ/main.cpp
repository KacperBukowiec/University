#include <iostream>
#include <string>
#include <regex>


using namespace std;

int main()
{


    string data1("On 2015-01-23, 21:37  23:80  30:11 21:37:22 the shop will be closed, but on 2016-01-03, it will be open. Invalid date: 2016-12-31. ID: 1022015-12-233333.");
    std::regex pattern1("\\b(0[1-9]|1\\d|2[0-3])[:](0[1-9]|[1-6]\\d)([:]\\d{2})?\\b");
    std::smatch result1;

    while (regex_search(data1, result1, pattern1)) {
        std::cout << result1[0] << std::endl;
        data1 = result1.suffix().str();
    }

    struct tm tm;
    string data("On 23-10-2015, the shop will be closed, but on 03-01-2016, it will be open. Invalid date: 31-12-2016 . ID: 1022015-12-233333.");
   // std::regex pattern("\\b(0[1-9]|[1-2]\\d|3[0-1])[-](0[1-9]|1[0-2])[-]\\d{4,}\\b");
    std::regex pattern("\\b((0[1-9]|[1-2]\\d[-](0[1-9]|1[0-2]))"
                       "|(3[0-1]-(01|03|05|07|08|10|12))"
                       "|(30-(02|04|06|09|11)))"
                       "[-]\\d{4,}\\b");

    std::smatch result;


    while (regex_search(data, result, pattern)) {
        std::cout << result[0] << std::endl;
        data = result.suffix().str();
    }

    string data2("On 2015-01-23, 21:37 Śreslau -cos Blabla 23:80  30:11 21:37:5 The     Shop Will be closed, but on 2016-01-03, it Will be open. Invalid Date: 2016-12-31. ID: 1022015-12-233333.");
    std::regex pattern2("([A-Z]|Ś|Ż|Ź|Ł|Ń|Ą|Ó|Ć|Ę)[a-z]{2,}"
                        "(\\s*([A-Z]|Ś|Ż|Ź|Ł|Ń|Ą|Ó|Ć|Ę)[a-z]{2,})*"
                        "([-][a-z]{2,})?(\\s*([A-Z]|Ś|Ż|Ź|Ł|Ń|Ą|Ó|Ć|Ę)[a-z]{2,})*");
    std::smatch result2;

    while (regex_search(data2, result2, pattern2)) {
        std::cout << result2[0] << std::endl;
        data2 = result2.suffix().str();

    }
    string data3("On 2015-01-23, 21:37 Breslau-cos Blabla 23:80  30:11 21:37:22 The (  -21.34324  + -4.23432I  )    Shop Will be closed, but on 2016-01-03, it Will be open. Invalid Date: 2016-12-31. ID: 1022015-12-233333.");
    std::regex pattern3("\\b\\s*\\(\\s*[-]?\\d+[.]?\\d*\\s*[+]\\s*[-]?\\d+[.]?\\d*[iI]\\s*\\)\\s*\\b");
    std::smatch result3;

    while (regex_search(data3, result3, pattern3)) {
        std::cout << result3[0] << std::endl;
        data3 = result3.suffix().str();
    }
}

