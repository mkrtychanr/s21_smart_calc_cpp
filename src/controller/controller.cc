#include "controller.h"

s21::Controller &s21::Controller::Instance() {
  static Controller c;
  return c;
}

bool s21::Controller::AddToExression(const std::string &str) {
  return m_.AddToExression(str);
}

size_t s21::Controller::DeleteFromExpression() {
  return m_.DeleteFromExpression();
}

void s21::Controller::Reset() { m_.Reset(); }

std::string s21::Controller::GetExpression() { return m_.GetExpression(); }

bool s21::Controller::IsReadyToCalculate() { return m_.IsReadyToCalculate(); }

bool s21::Controller::GetXStatus() { return m_.GetXStatus(); }

std::pair<std::vector<double>, std::vector<double>>
s21::Controller::Calculate(double from, double to) {
  return m_.Calculate(from, to);
}

void s21::Controller::Compile() { return m_.Compile(); }