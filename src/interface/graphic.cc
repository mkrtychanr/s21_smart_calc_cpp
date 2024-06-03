#include "graphic.h"

#include <iostream>

#include "../controller/controller.h"
#include "calculator.h"
#include "ui_graphic.h"

graphic::graphic(s21::Controller *c, QWidget *parent)
    : QWidget(parent), ui(new Ui::graphic) {
  ui->setupUi(this);
  this->c = c;
}

graphic::~graphic() { delete ui; }

void graphic::on_pushButton_clicked() {
  ui->graph->removeGraph(ui->graph->graph());
  if (ui->xFrom->text() == "" || ui->xTo->text() == "" ||
      ui->yFrom->text() == "" || ui->yTo->text() == "" ||
      ui->fFrom->text() == "" || ui->fTo->text() == "") {
    return;
  }
  ui->graph->xAxis->setRange(ui->xFrom->text().toInt(),
                             ui->xTo->text().toInt());
  ui->graph->yAxis->setRange(ui->yFrom->text().toInt(),
                             ui->yTo->text().toInt());
  QVector<double> x;
  QVector<double> y;
  double fromFunctionX = ui->fFrom->text().toDouble();
  double toFunctionX = ui->fTo->text().toDouble();
  std::pair<std::vector<double>, std::vector<double>> data =
      c->Calculate(fromFunctionX, toFunctionX);
  x = QVector<double>(data.first.begin(), data.first.end());
  y = QVector<double>(data.second.begin(), data.second.end());
  ui->graph->addGraph();
  ui->graph->graph(0)->addData(x, y);
  ui->graph->replot();
}
