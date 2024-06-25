#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QByteArray>
#include <QClipboard>
#include <QCryptographicHash>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <openssl/evp.h>

#include <trx.h>

const QString DATA_FILE_PATH = "records.txt";

namespace Ui {
class MainWindow;
}

enum State { Unauthorized };

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:

private:
  int getHash(QByteArray &hash);

  void displayTrxs();
  void router();

  Ui::MainWindow *ui;
  QVector<QString> trxs;
  State state;
};

#endif // MAINWINDOW_H
