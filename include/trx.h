#ifndef TRX_H
#define TRX_H
#include <QByteArray>
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
};
#endif // TRX_H
