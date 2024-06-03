/*!
\file
\brief Заголовочный файл с объявлениям класса графика
*/

#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QWidget>
#include <vector>

#include "../controller/controller.h"

namespace Ui {
class graphic;
}

class graphic : public QWidget {
  Q_OBJECT

public:
  /**
   * @brief Конструктор нового графика
   *
   * @param p – Вектор строк
   * @param parent – Родительский объект
   */
  explicit graphic(s21::Controller *c, QWidget *parent = nullptr);

  /**
   * @brief Деструктор объекта
   *
   */
  ~graphic();

private slots:

  /**
   * @brief Кнопка Calculate
   *
   */
  void on_pushButton_clicked();

private:
  /**
   * @brief Объект графического интерфейса
   *
   */
  Ui::graphic *ui;
  s21::Controller *c;
};

#endif // GRAPHIC_H
