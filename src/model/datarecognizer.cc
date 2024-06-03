#include "datarecognizer.h"
#include <string>

bool s21::IsBrOpen(const std::string &expression, size_t i) {
  return expression[i] == '(';
}

bool s21::IsBrClose(const std::string &expression, size_t i) {
  return expression[i] == ')';
}

bool s21::IsPlus(const std::string &expression, size_t i) {
  return expression[i] == '+';
}

bool s21::IsMinus(const std::string &expression, size_t i) {
  return expression[i] == '-';
}

bool s21::IsMultiply(const std::string &expression, size_t i) {
  return expression[i] == '*';
}

bool s21::IsDivide(const std::string &expression, size_t i) {
  return expression[i] == '/';
}

bool s21::IsPow(const std::string &expression, size_t i) {
  return expression[i] == '^';
}

bool s21::IsMod(const std::string &expression, size_t i) {
  return expression[i] == '%';
}

bool s21::IsSin(const std::string &expression, size_t i) {
  return expression[i] == 's' && expression[i + 1] == 'i' &&
         expression[i + 2] == 'n';
}
bool s21::IsAsin(const std::string &expression, size_t i) {
  return expression[i] == 'a' && expression[i + 1] == 's' &&
         expression[i + 2] == 'i' && expression[i + 3] == 'n';
}
bool s21::IsCos(const std::string &expression, size_t i) {
  return expression[i] == 'c' && expression[i + 1] == 'o' &&
         expression[i + 2] == 's';
}
bool s21::IsAcos(const std::string &expression, size_t i) {
  return expression[i] == 'a' && expression[i + 1] == 'c' &&
         expression[i + 2] == 'o' && expression[i + 3] == 's';
}
bool s21::IsTan(const std::string &expression, size_t i) {
  return expression[i] == 't' && expression[i + 1] == 'a' &&
         expression[i + 2] == 'n';
}
bool s21::IsAtan(const std::string &expression, size_t i) {
  return expression[i] == 'a' && expression[i + 1] == 't' &&
         expression[i + 2] == 'a' && expression[i + 3] == 'n';
}
bool s21::IsCtg(const std::string &expression, size_t i) {
  return expression[i] == 'c' && expression[i + 1] == 't' &&
         expression[i + 2] == 'g';
}
bool s21::IsSqrt(const std::string &expression, size_t i) {
  return expression[i] == 's' && expression[i + 1] == 'q' &&
         expression[i + 2] == 'r' && expression[i + 3] == 't';
}
bool s21::IsLn(const std::string &expression, size_t i) {
  return expression[i] == 'l' && expression[i + 1] == 'n';
}

bool s21::IsLog(const std::string &expression, size_t i) {
  return expression[i] == 'l' && expression[i + 1] == 'o' &&
         expression[i + 2] == 'g';
}

bool s21::IsDigit(const std::string &expression, size_t i) {
  return 48 <= expression[i] && expression[i] <= 57 && expression[i] != '\0';
}

bool s21::IsValidForDigit(const std::string &expression, size_t i) {
  return s21::IsDigit(expression, i) ||
         (expression[i] == 46 && s21::IsDigit(expression, i + 1));
}

bool s21::IsBinary(const char op) {
  return op == '+' || op == '-' || op == '*' || op == '/' || op == '^' ||
         op == '%';
}

bool s21::IsUnary(const std::string &str) {
  return str == "sin(" || str == "asin(" || str == "cos(" || str == "acos(" ||
         str == "tan(" || str == "atan(" || str == "ln(" || str == "log(" ||
         str == "sqrt(";
}