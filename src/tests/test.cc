#include <gtest/gtest.h>

#include <vector>

#include "../controller/controller.h"

namespace {

s21::Controller &c = s21::Controller::Instance();

struct Testing {
  std::pair<std::vector<double>, std::vector<double>> data;
  double GetData() { return data.second.front(); }
  void SetData(std::vector<std::string> v) {
    c.Reset();
    for (auto &i : v) {
      c.AddToExression(i);
    }
    c.Compile();
    data = c.Calculate(0, 0);
  }
};

TEST(Base, Plus) {
  Testing t;
  t.SetData({"1", "+", "1"});
  EXPECT_EQ(2, t.GetData());
}

TEST(Base, Minus) {
  Testing t;
  t.SetData({"1", "-", "1"});
  EXPECT_EQ(0, t.GetData());
}

TEST(Base, UnaryPlus) {
  Testing t;
  t.SetData({"+(", "5", ")"});
  EXPECT_EQ(5, t.GetData());
}

TEST(Base, UnaryMinus) {
  Testing t;
  t.SetData({"-(", "5", ")"});
  EXPECT_EQ(-5, t.GetData());
}

TEST(Base, Delete) {
  Testing t;
  t.SetData({"1", "-", "1"});
  c.DeleteFromExpression();
  c.DeleteFromExpression();
  c.DeleteFromExpression();
  c.AddToExression({"2"});
  c.AddToExression({"+"});
  c.AddToExression({"2"});
  c.Compile();
  auto data = c.Calculate(0, 0);
  EXPECT_EQ(4, data.second.front());
}

TEST(E, Plus) {
  Testing t;
  t.SetData({"1", "E", "+", "1"});
  EXPECT_EQ(10, t.GetData());
}

TEST(E, Minus) {
  Testing t;
  t.SetData({"1", "E", "-", "1"});
  EXPECT_EQ(0.1, t.GetData());
}

TEST(Base, X) {
  c.Reset();
  c.AddToExression("x");
  c.AddToExression("/");
  c.AddToExression("3");
  EXPECT_EQ(true, c.IsReadyToCalculate());
  c.Compile();
  EXPECT_EQ(true, c.GetXStatus());
  auto data = c.Calculate(3, 3.1);
  EXPECT_EQ(1, data.second.front());
}

TEST(Utils, GetExpression) {
  Testing t;
  t.SetData({"1", "3", ".", "4", "+", "(", "5", ".", "1", ")"});
  EXPECT_EQ("13.4+(5.1)", c.GetExpression());
}

TEST(E, NumbersAfterSign) {
  Testing t;
  t.SetData({"1", "E", "+", "1", "0"});
  EXPECT_EQ(10000000000, t.GetData());
}

TEST(E, Bracket) {
  Testing t;
  t.SetData({"(", "1", "E", "+", "1", ")"});
  EXPECT_EQ(10, t.GetData());
}

TEST(E, Dot) {
  Testing t;
  t.SetData({"1", ".", "1", "E", "+", "1"});
  EXPECT_EQ(11, t.GetData());
}

TEST(Super, SuperTest) {
  Testing t;
  t.SetData({"sin(",  "cos(", "tan(", "asin(", "acos(", "atan(", "ln(", "log(",
             "sqrt(", "-(",   "1",    "2",     "3",     "*",     "4",   ".",
             "5",     "6",    "-",    "0",     ".",     "5",     "6",   "7",
             "8",     "9",    "*",    "0",     "^",     "0",     "%",   "1",
             ")",     ")",    ")",    ")",     ")",     ")",     ")",   ")",
             ")",     "*",    "0"});
  EXPECT_EQ(0, t.GetData());
}

} // namespace

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}