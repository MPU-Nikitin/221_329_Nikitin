#ifndef TRX_H
#define TRX_H
#include <QByteArray>
#include <QCryptographicHash>
#include <QDebug>
#include <QString>
#include <QStringList>

struct Trx {
  Trx();
  Trx(const QString &text);

  QString sum;
  QString walletNumber;
  QString date;
  QString hash;

  QString toText() const;
  bool compareHash(QByteArray prevHash);
};
#endif // TRX_H
