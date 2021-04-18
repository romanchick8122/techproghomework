//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include <sstream>
#include "WeatherMock.h"
cpr::Response WeatherMock::Get(const std::string& city, const cpr::Url& url) {
    std::stringstream s;
    s.str(city);
    int t1, t2;
    s >> t1 >> t2;
    cpr::Response ret;
    ret.status_code = 200;
    ret.text = "{\"main\":{\"temp\":" + std::to_string(t1) + "}, \"list\":[\"\",\"\",\"\",\"\",\"\",\"\",{\"main\":{\"temp\": " +
        std::to_string(t2) + "}}]}";
    std::cerr << ret.text << "\n";
    return ret;
}