//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"

TEST(Weather, Mocked) {
    WeatherMock mock;
    mock.SetApiKey("key");
    EXPECT_THROW(mock.GetTemperature("bad"), std::invalid_argument);
    EXPECT_EQ(mock.GetTemperature("1 2"), 1);
    EXPECT_EQ(mock.GetDifferenceString("1 2", "2 3"), "Weather in 1 2 is colder than in 2 3 by 1 degrees");
    EXPECT_EQ(mock.GetDifferenceString("2 2", "1 3"), "Weather in 2 2 is warmer than in 1 3 by 1 degrees");
    EXPECT_EQ(mock.GetTomorrowDiff("10 100"), "The weather in 10 100 tomorrow will be much warmer than today.");
    EXPECT_EQ(mock.GetTomorrowDiff("10 11"), "The weather in 10 11 tomorrow will be warmer than today.");
    EXPECT_EQ(mock.GetTomorrowDiff("10 10"), "The weather in 10 10 tomorrow will be the same than today.");
    EXPECT_EQ(mock.GetTomorrowDiff("10 9"), "The weather in 10 9 tomorrow will be colder than today.");
    EXPECT_EQ(mock.GetTomorrowDiff("10 5"), "The weather in 10 5 tomorrow will be much colder than today.");
}