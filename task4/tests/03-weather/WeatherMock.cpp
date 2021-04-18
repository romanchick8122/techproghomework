//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include <sstream>
#include "WeatherMock.h"
cpr::response WeatherMock::Get(const std::string& city, const int& url) {
    std::stringstream s;
    s.str(city);
    int t1, t2;
    s >> t1 >> t2;
    cpr::response ret;
    ret.status_code = 200;
    ret.text = "{'main':{'temp':" + std::to_string(t1) + "}, 'list':['','','','','','',{'main':{'temp': " +
        std::to_string(t2) + "}}]}";
    return ret;
}