#include "trx.h"

Trx::Trx() : sum(""), walletNumber(""), date(""), hash("") {}

Trx::Trx(const QString &text) {
  QStringList fields = text.split('\n');
  if (fields.size() == 4) {
    sum = fields[0];
    walletNumber = fields[1];
    date = fields[2];
    hash = fields[3];
  } else {
    sum = "";
    walletNumber = "";
    date = "";
    hash = "";
  }
}

QString Trx::toText() const {
  return sum + "\n" + walletNumber + "\n" + date + "\n" + hash;
}
