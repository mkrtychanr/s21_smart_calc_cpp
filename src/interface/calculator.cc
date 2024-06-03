#include "calculator.h"

#include <QtCore>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stack>

#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Calculator) {
  ui->setupUi(this);
  str = "";
  ui->textEdit->setText(str);
}

Calculator::~Calculator() { delete ui; }

void Calculator::fillMomentsAfterCalcualte(
    const std::string &resultOfCalculation) {
  std::cout << c.GetExpression() << std::endl;
  for (auto i : resultOfCalculation) {
    c.AddToExression(QString(i).toStdString());
  }
  std::cout << c.GetExpression() << std::endl;
}

void Calculator::almostAnyButton(const std::string &handeledString) {
  bool status = c.AddToExression(handeledString);
  if (status) {
    str += QString(handeledString.c_str());
  }
  ui->textEdit->setText(str);
  ui->textEdit->setAlignment(Qt::AlignRight);
}

void Calculator::on_acButton_clicked() {
  c.Reset();
  str = "";
  ui->textEdit->setText(str);
}

void Calculator::on_backSpaceButton_clicked() {
  c.DeleteFromExpression();
  str = c.GetExpression().c_str();
  ui->textEdit->setText(str);
  ui->textEdit->setAlignment(Qt::AlignRight);
}

void Calculator::on_dotButton_clicked() { almostAnyButton("."); }

void Calculator::on_zeroButton_clicked() { almostAnyButton("0"); }

void Calculator::on_oneButton_clicked() { almostAnyButton("1"); }

void Calculator::on_twoButton_clicked() { almostAnyButton("2"); }

void Calculator::on_threeButton_clicked() { almostAnyButton("3"); }

void Calculator::on_fourButton_clicked() { almostAnyButton("4"); }

void Calculator::on_fiveButton_clicked() { almostAnyButton("5"); }

void Calculator::on_sixButton_clicked() { almostAnyButton("6"); }

void Calculator::on_sevenButton_clicked() { almostAnyButton("7"); }

void Calculator::on_eightButton_clicked() { almostAnyButton("8"); }

void Calculator::on_nineButton_clicked() { almostAnyButton("9"); }

void Calculator::on_plusButton_clicked() {
  std::string push = "+";
  if (str.size() == 0 || str.back() == '(') {
    push.push_back('(');
  }
  almostAnyButton(push);
}

void Calculator::on_minusButton_clicked() {
  std::string push = "-";
  if (str.size() == 0 || str.back() == '(') {
    push.push_back('(');
  }
  almostAnyButton(push);
}

void Calculator::on_mulButton_clicked() { almostAnyButton("*"); }

void Calculator::on_divButton_clicked() { almostAnyButton("/"); }

void Calculator::on_powButton_clicked() { almostAnyButton("^"); }

void Calculator::on_modButton_clicked() { almostAnyButton("%"); }

void Calculator::on_closeBracketButton_clicked() { almostAnyButton(")"); }

void Calculator::on_openBracketButton_clicked() { almostAnyButton("("); }

void Calculator::on_xButton_clicked() { almostAnyButton("x"); }

void Calculator::on_sqrtButton_clicked() { almostAnyButton("sqrt("); }

void Calculator::on_sinButton_clicked() { almostAnyButton("sin("); }

void Calculator::on_cosButton_clicked() { almostAnyButton("cos("); }

void Calculator::on_tanButton_clicked() { almostAnyButton("tan("); }

void Calculator::on_asinButton_clicked() { almostAnyButton("asin("); }

void Calculator::on_acosButton_clicked() { almostAnyButton("acos("); }

void Calculator::on_atanButton_clicked() { almostAnyButton("atan("); }

void Calculator::on_lnButton_clicked() { almostAnyButton("ln("); }

void Calculator::on_logButton_clicked() { almostAnyButton("log("); }

void Calculator::on_equalsButton_clicked() {
  if (c.IsReadyToCalculate()) {
    c.Compile();
    if (c.GetXStatus()) {
      auto temp = new graphic(&c);
      temp->show();
      str = "";
      c.Reset();
    } else {
      str = QString(std::to_string(c.Calculate(0, 0).second.front()).c_str());
      ui->textEdit->setText(str);
      ui->textEdit->setAlignment(Qt::AlignRight);
      c.Reset();
      if (str != "nan" && str != "inf") {
        fillMomentsAfterCalcualte(str.toStdString());
      } else {
        str = "";
      }
    }
  }
}

void Calculator::on_eButton_clicked() { almostAnyButton("E"); }
