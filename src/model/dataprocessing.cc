#include "dataprocessing.h"
#include "datarecognizer.h"

#include <cmath>
#include <stack>

double s21::Binary(const double rhs, const double lhs, const char op) {
  if (op == '+') {
    return lhs + rhs;
  } else if (op == '-') {
    return lhs - rhs;
  } else if (op == '*') {
    return lhs * rhs;
  } else if (op == '/') {
    return lhs / rhs;
  } else if (op == '^') {
    return std::pow(lhs, rhs);
  } else if (op == '%') {
    return std::fmod(lhs, rhs);
  }
  return 0;
}

double s21::Unary(const double number, const char op) {
  if (op == '~') {
    return -1 * number;
  } else if (op == 'p') {
    return number;
  } else if (op == 'a') {
    return std::sin(number);
  } else if (op == 's') {
    return std::cos(number);
  } else if (op == 'd') {
    return std::tan(number);
  } else if (op == 'g') {
    return std::sqrt(number);
  } else if (op == 'h') {
    return std::log(number);
  } else if (op == 'j') {
    return std::asin(number);
  } else if (op == 'k') {
    return std::acos(number);
  } else if (op == 'l') {
    return std::atan(number);
  } else if (op == 'z') {
    return std::log10(number);
  }
  return 0;
}

int s21::Check(char c) {
  int result = -1;
  if (c == '(')
    result = 0;
  if (c == '+')
    result = 1;
  if (c == '-')
    result = 1;
  if (c == '*')
    result = 2;
  if (c == '/')
    result = 2;
  if (c == '%')
    result = 3;
  if (c == '^')
    result = 3;
  if (c == '~')
    result = 4;
  if (c == 'a')
    result = 5;
  if (c == 's')
    result = 5;
  if (c == 'd')
    result = 5;
  if (c == 'f')
    result = 5;
  if (c == 'g')
    result = 5;
  if (c == 'h')
    result = 5;
  if (c == 'j')
    result = 5;
  if (c == 'k')
    result = 5;
  if (c == 'l')
    result = 5;
  if (c == 'z')
    result = 5;
  return result;
}

double s21::CalculateOneStep(const std::vector<std::string> &tokens, double x) {
  std::stack<double> numbers;
  for (auto &token : tokens) {
    if ('0' <= token[0] && token[0] <= '9') {
      numbers.push(::atof(token.c_str()));
    } else if (token[0] == 'x') {
      numbers.push(x);
    } else {
      if (IsBinary(token[0])) {
        numbers.push(Binary(StackWrap(numbers), StackWrap(numbers), token[0]));
      } else {
        numbers.push(Unary(StackWrap(numbers), token[0]));
      }
    }
  }
  return numbers.top();
}

double s21::StackWrap(std::stack<double> &number) {
  auto result = number.top();
  number.pop();
  return result;
}
