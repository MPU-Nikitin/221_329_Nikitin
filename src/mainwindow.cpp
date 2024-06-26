#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

  ui->setupUi(this);

  ui->stackedWidget->setCurrentIndex(1);
  state = State::Unauthorized;

  loadFile();

  connect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::loadFile);
}

MainWindow::~MainWindow() { delete ui; }

// Function to load transactions from a file
void MainWindow::loadFile() {
  QString fileName;
  if (!firstOpen) {
    fileName = QFileDialog::getOpenFileName(this, "Открыть файл транзакций", "",
                                            "Text Files (*.txt)");
    if (fileName.isEmpty()) {
      return;
    }
  } else {
    fileName = DATA_FILE_PATH;
    firstOpen = false;
  }

  QFile file(fileName);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл");
    return;
  }

  QTextStream in(&file);
  trxs.clear();
  while (!in.atEnd()) {
    QString line = in.readLine();
    if (!line.isEmpty()) {
      trxs.append(Trx(line));
    }
  }
  file.close();
  displayTrxs();
}

void MainWindow::displayTrxs() {
  ui->trxTable->clearContents();
  ui->trxTable->setRowCount(0);
  ui->trxTable->setColumnCount(4);
  ui->trxTable->setHorizontalHeaderLabels(
      {"Сумма", "Номер кошелька", "Дата", "Хеш"});

  bool is_valid = true;
  for (int i = 0; i < trxs.length(); i++) {
    Trx trx = trxs[i];

    int row = ui->trxTable->rowCount();
    ui->trxTable->insertRow(row);

    ui->trxTable->setItem(row, 0, new QTableWidgetItem(trx.sum));
    ui->trxTable->setItem(row, 1, new QTableWidgetItem(trx.walletNumber));
    ui->trxTable->setItem(row, 2, new QTableWidgetItem(trx.date));
    ui->trxTable->setItem(row, 3, new QTableWidgetItem(trx.hash));

    if ((i > 0 && !trx.compareHash(trxs[i - 1].hash.toUtf8())) ||
        (i == 0 && !trx.compareHash(""))) {
      is_valid = false;
    }
    if (!is_valid) {
      ui->trxTable->item(i, 3)->setBackground(Qt::red);
    }
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
