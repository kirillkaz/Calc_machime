#include <gtest/gtest.h>
#include "longInteger/BigInt/Include/bigInt.h"
#include "calculator.h"

void run_tests(){
    RUN_ALL_TESTS();
}

TEST(calc,test1){
    bigInt num;
    num.num = "123";

    calculator* calc = new calculator("test1");

    calc->calculate(num);

    std::string checkNum = "-3703703596297037035962970370358026";

    EXPECT_EQ(num.num,checkNum);

}

TEST(calc,test2){
    bigInt num;
    num.num = "123";

    calculator* calc = new calculator("test2");

    calc->calculate(num);

    std::string checkNum = "-3703703596297037035962970370358026";

    EXPECT_EQ(num.num,checkNum);

}

TEST(calc,test3){
    bigInt num;
    num.num = "123";

    calculator* calc = new calculator("test3");

    calc->calculate(num);

    std::string checkNum = "-14814814385188148143851881481432473";

    EXPECT_EQ(num.num,checkNum);

}

TEST(calc,test4){
    bigInt num;
    num.num = "123";

    calculator* calc = new calculator("test4");

    calc->calculate(num);

    std::string checkNum = "-148148143851881481438518814814325837";

    EXPECT_EQ(num.num,checkNum);

}