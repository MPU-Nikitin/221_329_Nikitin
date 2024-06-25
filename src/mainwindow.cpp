#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

  ui->setupUi(this);

  ui->stackedWidget->setCurrentIndex(1);
  state = State::Unauthorized;
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::displayTrxs() {
  ui->trxTable->clearContents();
  ui->trxTable->setRowCount(0);
  for (int i = 0; i < trxs.length(); i++) {
    QString trxText = trxs[i];
    Trx trx(trxText);

    int row = ui->trxTable->rowCount();
    ui->trxTable->insertRow(row);

    ui->trxTable->setItem(row, 0, new QTableWidgetItem(trx.sum));
    ui->trxTable->setItem(row, 1, new QTableWidgetItem(trx.walletNumber));
    ui->trxTable->setItem(row, 2, new QTableWidgetItem(trx.date));
    ui->trxTable->setItem(row, 3, new QTableWidgetItem(trx.hash));
  }
}

// main function that handle states
void MainWindow::router() {
  QByteArray hash;
  switch (state) {
  // entry point
  case State::Unauthorized:
    ui->stackedWidget->setCurrentIndex(1);
    displayTrxs();
    break;
  }
}

//
// SLOTS
//

// Empty
