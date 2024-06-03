#include "model.h"
#include "dataprocessing.h"
#include "datarecognizer.h"

#include <cmath>

std::vector<std::string>
s21::Model::ToSimpleForm(const std::string &expression) {
  std::vector<std::string> result;
  int status = 0;
  size_t i = 0;
  while (i < expression.length()) {
    if (status == 0 && IsMinus(expression, i)) {
      result.push_back("~");
      i++;
      status = 1;
    } else if (status == 0 && IsPlus(expression, i)) {
      result.push_back("p");
      i++;
      status = 1;
    } else if (IsValidForDigit(expression, i)) {
      result.push_back("");
      bool e = false;
      while (i < expression.length() &&
             (IsValidForDigit(expression, i) || expression[i] == 'E')) {
        result.back().push_back(expression[i]);
        if (expression[i] == 'E') {
          e = true;
          result.back().push_back(expression[i + 1]);
          i++;
        }
        i++;
      }
      if (e) {
        result.back() = std::to_string(std::stod(result.back()));
      }
      status = 2;
    } else if (IsPlus(expression, i)) {
      result.push_back("+");
      i++;
    } else if (IsMinus(expression, i)) {
      result.push_back("-");
      i++;
    } else if (IsMultiply(expression, i)) {
      result.push_back("*");
      i++;
    } else if (IsDivide(expression, i)) {
      result.push_back("/");
      i++;
    } else if (IsPow(expression, i)) {
      result.push_back("^");
      i++;
    } else if (IsMod(expression, i)) {
      result.push_back("%");
      i++;
    } else if (IsBrClose(expression, i)) {
      result.push_back(")");
      i++;
    } else if (IsBrOpen(expression, i)) {
      result.push_back("(");
      status = 0;
      i++;
    } else if (IsSin(expression, i)) {
      result.push_back("a");
      i += 3;
    } else if (IsCos(expression, i)) {
      result.push_back("s");
      i += 3;
    } else if (IsTan(expression, i)) {
      result.push_back("d");
      i += 3;
    } else if (IsCtg(expression, i)) {
      result.push_back("f");
      i += 3;
    } else if (IsSqrt(expression, i)) {
      result.push_back("g");
      i += 4;
    } else if (IsLn(expression, i)) {
      result.push_back("h");
      i += 2;
    } else if (IsLog(expression, i)) {
      result.push_back("z");
      i += 3;
    } else if (IsAsin(expression, i)) {
      result.push_back("j");
      i += 4;
    } else if (IsAcos(expression, i)) {
      result.push_back("k");
      i += 4;
    } else if (IsAtan(expression, i)) {
      result.push_back("l");
      i += 4;
    } else if (expression[i] == 'x') {
      result.push_back("x");
      i++;
    } else {
      i++;
    }
  }
  return result;
}

s21::Model &s21::Model::Instance() {
  static Model m;
  return m;
}

bool s21::Model::AddToExression(const std::string &str) {
  bool status = false;
  if (snapshots_.back().status == 0) {
    if (IsUnary(str) || str == "+(" || str == "-(" || str == "(") {
      snapshots_.push_back(
          Snapshot(snapshots_.back().bracketCounter + 1, str.length(), 0));
      status = true;
    } else if ('0' <= str[0] && str[0] <= '9') {
      snapshots_.push_back(Snapshot(snapshots_.back().bracketCounter, 1, 1));
      status = true;
    } else if (str == "x") {
      snapshots_.push_back(Snapshot(snapshots_.back().bracketCounter, 1, 8));
      status = true;
    }
  } else if (snapshots_.back().status == 1) {
    if (str == "E") {
      snapshots_.push_back(Snapshot(snapshots_.back().bracketCounter, 1, 3));
      status = true;
    } else if (IsBinary(str[0])) {
      snapshots_.push_back(Snapshot(snapshots_.back().bracketCounter, 1, 5));
      status = true;
    } else if (str == ")" && snapshots_.back().bracketCounter != 0) {
      snapshots_.push_back(
          Snapshot(snapshots_.back().bracketCounter - 1, 1, 4));
      status = true;
    } else if ('0' <= str[0] && str[0] <= '9') {
      snapshots_.push_back(Snapshot(snapshots_.back().bracketCounter, 1, 1));
      status = true;
    } else if (str == ".") {
      snapshots_.push_back(Snapshot(snapshots_.back().bracketCounter, 1, 2));
      status = true;
    }
  } else if (snapshots_.back().status == 2) {
    if (str == "E") {
      snapshots_.push_back(Snapshot(snapshots_.back().bracketCounter, 1, 3));
      status = true;
    } else if (IsBinary(str[0])) {
      snapshots_.push_back(Snapshot(snapshots_.back().bracketCounter, 1, 5));
      status = true;
    } else if (str == ")" && snapshots_.back().bracketCounter != 0) {
      snapshots_.push_back(
          Snapshot(snapshots_.back().bracketCounter - 1, 1, 4));
      status = true;
    } else if ('0' <= str[0] && str[0] <= '9') {
      snapshots_.push_back(Snapshot(snapshots_.back().bracketCounter, 1, 2));
      status = true;
    }
  } else if (snapshots_.back().status == 3) {
    if (str == "+" || str == "-") {
      snapshots_.push_back(Snapshot(snapshots_.back().bracketCounter, 1, 6));
      status = true;
    }
  } else if (snapshots_.back().status == 4) {
    if (str == ")" && snapshots_.back().bracketCounter != 0) {
      snapshots_.push_back(
          Snapshot(snapshots_.back().bracketCounter - 1, 1, 4));
      status = true;
    } else if (IsBinary(str[0])) {
      snapshots_.push_back(Snapshot(snapshots_.back().bracketCounter, 1, 5));
      status = true;
    }
  } else if (snapshots_.back().status == 5) {
    if (IsUnary(str) || str == "(") {
      snapshots_.push_back(
          Snapshot(snapshots_.back().bracketCounter + 1, str.length(), 0));
      status = true;
    } else if ('0' <= str[0] && str[0] <= '9') {
      snapshots_.push_back(Snapshot(snapshots_.back().bracketCounter, 1, 1));
      status = true;
    } else if (str == "x") {
      snapshots_.push_back(Snapshot(snapshots_.back().bracketCounter, 1, 8));
      status = true;
    }
  } else if (snapshots_.back().status == 6) {
    if ('0' <= str[0] && str[0] <= '9') {
      snapshots_.push_back(Snapshot(snapshots_.back().bracketCounter, 1, 7));
      status = true;
    }
  } else if (snapshots_.back().status == 7) {
    if (IsBinary(str[0])) {
      snapshots_.push_back(Snapshot(snapshots_.back().bracketCounter, 1, 5));
      status = true;
    } else if (str == ")" && snapshots_.back().bracketCounter != 0) {
      snapshots_.push_back(
          Snapshot(snapshots_.back().bracketCounter - 1, 1, 4));
      status = true;
    } else if ('0' <= str[0] && str[0] <= '9') {
      snapshots_.push_back(Snapshot(snapshots_.back().bracketCounter, 1, 7));
      status = true;
    }
  } else if (snapshots_.back().status == 8) {
    if (IsBinary(str[0])) {
      snapshots_.push_back(Snapshot(snapshots_.back().bracketCounter, 1, 5));
      status = true;
    } else if (str == ")" && snapshots_.back().bracketCounter != 0) {
      snapshots_.push_back(
          Snapshot(snapshots_.back().bracketCounter - 1, 1, 4));
      status = true;
    }
  }
  if (status) {
    expression_ += str;
  }
  return status;
}

void s21::Model::Compile() {
  x_status_ = false;
  for (auto c : expression_) {
    if (c == 'x') {
      x_status_ = true;
    }
  }
  CompileExpression(ToSimpleForm(expression_));
}

bool s21::Model::GetXStatus() { return x_status_; }

std::pair<std::vector<double>, std::vector<double>>
s21::Model::Calculate(double from, double to) {
  std::pair<std::vector<double>, std::vector<double>> data;
  if (GetXStatus()) {
    for (auto x = from; std::fabs(x - to) > 1E-07; x += 0.1) {
      data.first.push_back(x);
      data.second.push_back(CalculateOneStep(compiled_expression_, x));
    }
  } else {
    data.first.push_back(0);
    data.second.push_back(CalculateOneStep(compiled_expression_, 0));
  }

  return data;
}

void s21::Model::CompileExpression(const std::vector<std::string> &tokens) {
  std::vector<std::string> result;
  result.reserve(tokens.size());
  std::stack<char> temp;
  for (auto token : tokens) {
    if (IsValidForDigit(token, 0)) {
      result.push_back(token);
    } else if (token[0] == '(') {
      temp.push('(');
    } else if (token[0] == ')') {
      while (!temp.empty() && temp.top() != '(') {
        result.push_back(std::string(1, temp.top()));
        temp.pop();
      }
      temp.pop();
    } else if (Check(token[0]) != -1) {
      while (!temp.empty() && Check(token[0]) <= Check(temp.top())) {
        result.push_back(std::string(1, temp.top()));
        temp.pop();
      }
      temp.push(token[0]);
    } else if (token[0] == 'x') {
      result.push_back("x");
    }
  }
  while (!temp.empty()) {
    result.push_back(std::string(1, temp.top()));
    temp.pop();
  }
  compiled_expression_ = result;
}

void s21::Model::Reset() {
  expression_ = "";
  snapshots_.clear();
  snapshots_.push_back(Snapshot(0, 0, 0));
}

size_t s21::Model::DeleteFromExpression() {
  size_t result = 0;
  if (snapshots_.size() > 1) {
    result = snapshots_.back().tokenSize;
    for (size_t i = 0; i < result; i++) {
      expression_.pop_back();
    }
    snapshots_.pop_back();
  }
  return result;
}

std::string s21::Model::GetExpression() { return expression_; }

bool s21::Model::IsReadyToCalculate() {
  Snapshot &last = snapshots_.back();
  return expression_.size() != 0 && last.bracketCounter == 0 &&
         last.status != 3 && last.status != 5 && last.status != 6 &&
         last.status != 0;
}
