#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"QNetworkAccessManager"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

void read_data1(QNetworkReply *);

void on_pushButton_clicked();


void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
     QNetworkAccessManager *http2;

};
#endif // MAINWINDOW_H
