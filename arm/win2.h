#ifndef WIN2_H
#define WIN2_H

#include <QMainWindow>

namespace Ui {
class win2;
}

class win2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit win2(QWidget *parent = nullptr);
    ~win2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::win2 *ui;
};

#endif // WIN2_H
